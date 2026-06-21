#include <Core.h>
#include <Intersection.h>
#include <GeoUtils.h>

using namespace std;
using namespace cgm;

bool cgm::intersect(Point3D& a, Point3D& b, Point3D& c, Point3D& d)
{
    if(cgm::orientation2D(a,b,c) == int(cgm::RELATIVE_POSITION::BETWEEN)
      || cgm::orientation2D(a,b,d) == int(cgm::RELATIVE_POSITION::BETWEEN)
      || cgm::orientation2D(c,d,a) == int(cgm::RELATIVE_POSITION::BETWEEN)
      || cgm::orientation2D(c,d,b) == int(cgm::RELATIVE_POSITION::BETWEEN))
      
      return true;
    
    /*
    | A | B | A XOR B |
    | - | - | ------- |
    | 0 | 0 | 0       |
    | 0 | 1 | 1       |
    | 1 | 0 | 1       |
    | 1 | 1 | 0       |

    */
    return (cgm::_xor(cgm::left(a,b,c), cgm::left(a,b,d)) && cgm::_xor(cgm::left(c,d,a), cgm::left(c,d,b)));
}


int cgm::intersectionPoint(Point3D& a, Point3D& b, Point3D& c, Point3D& d, Point3D& intersectPt)
{
	//formula being considered for intersection point of two lines in 2D is as below
    // for intersection of line AB & CD...parameter t is given by t = n.(c - d) / n.(b - a)
    // Now putting t in parametric line equation p(t) = v.t + a...we can find intersection point 

	Vector AB = b - a; // direction vector of line AB
	Vector CD = d - c; // direction vector of line CD

	Vector n(CD[Y], -CD[X], 0.0); // normal vector to line CD in 2D (perpendicular to CD)

	auto denominator = Vector::DotProduct(n, AB);  // If the denominator is zero, it means the lines are parallel (or coincident)   
    if (denominator == 0)
    {
        std::cout << "Lines are parallel, no intersection point." << std::endl;
        return -1; // Lines are parallel, no intersection point
	}

        // Calculate the intersection point
	auto AC = c - a;  // Vector from point A to point C..it is based on the formula t = n.(c - a) / n.(b - a)
	auto nume = Vector::DotProduct(n, AC); // Numerator for calculating t
	auto t = nume / denominator; // Parameter t for line AB at the intersection point


	auto x = a[X] + t * AB[X];  //  Calculate the x-coordinate of the intersection point using the parametric equation of line AB
	auto y = a[Y] + t * AB[Y]; // Calculate the y-coordinate of the intersection point using the parametric equation of line AB

    return 0;
}


int cgm::intersectionPoint2(Point3D& a, Point3D& b, Point3D& c, Point3D& d, Point3D& intersectPt)
{    
    Vector r = b - a;
	Vector s = d - c;
	Vector w = a - c;

	double EPS = 1e-2;

	double r_dot_r = Vector::DotProduct(r, r);
	double r_dot_s = Vector::DotProduct(r, s);
	double s_dot_s = Vector::DotProduct(s, s);
	double r_dot_w = Vector::DotProduct(r, w);
	double s_dot_w = Vector::DotProduct(s, w);

	double denominator = r_dot_r * s_dot_s - r_dot_s * r_dot_s;

    //parallel or coincident lines
    if(std::fabs(denominator) < EPS)
    {
		Vector cross = Vector::CrossProduct3D(w,r);

        if (cross.magnitude() < EPS)
			return -5; // Lines are coincident

        std::cout << "Lines are parallel or coincident, no unique intersection point." << std::endl;
		return -5; // Lines are parallel, no intersection point
        
     
	}

	double t = (r_dot_s * s_dot_w - s_dot_s * r_dot_w) / denominator;
	double u = (r_dot_r * s_dot_w - r_dot_s * r_dot_w) / denominator;

	Point3D P1 = a + r * t;
	Point3D P2 = c + s * u;


    if((P1 - P2).magnitude() < EPS)
    {
        intersectPt = P1;
        return 0; // Lines intersect
	}

	return -1; // Lines do not intersect skew
}