#include <GeoUtils.h>
#include "Intersection.h"
#include <Core.h>

using namespace cgm;

#define TOLERANCE 0.0000001
#define ZERO 0

int cgm::orientation2D(const Point3D& a, const Point3D& b, const Point3D& c)
{
    float area = areaTriangle2D(a,b,c);
    
    if((area > 0) && (area < TOLERANCE))
        area = 0;
    if(area < 0 && (area > TOLERANCE))
        area = 0;    
    
    Vector ab = b - a;
    Vector ac = a - c;

	if (area > 0.0)
		return int(cgm::RELATIVE_POSITION::LEFT);
	if (area < 0.0)
		return int(cgm::RELATIVE_POSITION::RIGHT);
	if ((ab[X] * ac[X] < 0.0) || (ab[Y] * ac[Y] < 0.0))
		return int(cgm::RELATIVE_POSITION::BEHIND);
	if (ab.magnitude() < ac.magnitude())
		return int(cgm::RELATIVE_POSITION::BEYOND);
	if (a == c)
		return int(cgm::RELATIVE_POSITION::ORIGIN);
	if (b == c)
		return int(cgm::RELATIVE_POSITION::DESTINATION);
	
	return int(cgm::RELATIVE_POSITION::BETWEEN);

}

bool cgm::left(const Point3D& a, const Point3D& b, const Point3D& c)
{
    return orientation2D(a,b,c) == int(cgm::RELATIVE_POSITION::LEFT);
}


int cgm::orientation3D(const Point3D& a, const Point3D& b, const Point3D& c)
{
	float area = areaTriangle3D(a, b, c);
	if (area > 0 && area < TOLERANCE)
		area = 0;

	if (area < 0 && area > TOLERANCE)
		area = 0;
		
		
	Point3D p1 = b - a;
	Point3D p2 = c - a;

	double p1x, p1y, p2x, p2y;

	p1x = p1[X];
	p1y = p1[Y];
	p2x = p2[X];
	p2y = p2[Y];	
	
	if (area > 0.0)
		return int(cgm::RELATIVE_POSITION::LEFT);
	if (area < 0.0)
		return int(cgm::RELATIVE_POSITION::RIGHT);
	if ((p1x * p2x < 0.0) || (p1y * p2y < 0.0)) //as reached here it means, vectors are colinear....and 
	//because x or y of vector are in opposite direction answer is BEHIND
		return int(cgm::RELATIVE_POSITION::BEHIND);
	if (p1.magnitude() < p2.magnitude())//for colinear lines, vectors, if p2 has bigger length it lies BEYOND
		return int(cgm::RELATIVE_POSITION::BEYOND);
	if (a == c)
		return int(cgm::RELATIVE_POSITION::ORIGIN);
	if (b == c)
		return int(cgm::RELATIVE_POSITION::DESTINATION);
	
	
	
	return int(cgm::RELATIVE_POSITION::BETWEEN);
}


double cgm::areaTriangle2D(const Point3D& a, const Point3D& b, const Point3D& c)
{
    return 0.5*((b[X] - a[X])*(c[Y] - a[Y]) - (c[X] - a[X])*(b[Y]-a[Y]));
    
}

double cgm::areaTriangle3D(const Point3D& a, const Point3D& b, const Point3D& c)
{
    Vector AB = b - a;
    Vector AC = c - a;
    
    float ni, nj, nz;
	ni = AB[Y] * AC[Z] - AB[Z] * AC[Y];
	nj = AB[X] * AC[Z] - AB[Z] * AC[X];
	nz = AB[X] * AC[Y] - AB[Y] * AC[X];
    
    float sum_of_powers = pow(ni,2.0) + pow(nj, 2.0) + pow(nz, 2.0);
	float root = sqrtf(sum_of_powers);
	return root / 2;
}

