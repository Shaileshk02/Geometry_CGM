#include <Point.h>

namespace cgm
{
  int orientation2D(const Point3D & a, const Point3D& b, const Point3D& c);
  int orientation3D(const Point3D & a, const Point3D& b, const Point3D& c);
  
  
  // area
  double areaTriangle2D(const Point3D& a, const Point3D& b, const Point3D& c);
  double areaTriangle3D(const Point3D& a, const Point3D& b, const Point3D& c);
  
  bool left(const Point3D& a, const Point3D& b, const Point3D& c);
  
    
    
}