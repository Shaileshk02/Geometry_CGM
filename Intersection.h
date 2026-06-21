#include <Plane.h>
#include <Line.h>
#include <Point.h>
//#include <Vector.h>


namespace cgm{
    
    //lines segmentws formed by 4 points is intersecting?
    bool intersect(Point3D&, Point3D&, Point3D&, Point3D&);

	int intersectionPoint(Point3D& a, Point3D& b, Point3D& c, Point3D& d, Point3D& intersection);
    int intersectionPoint2 (Point3D& a, Point3D& b, Point3D& c, Point3D& d, Point3D& intersection);

    
    
    
    
}