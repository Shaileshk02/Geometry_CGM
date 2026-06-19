#include <Core.h>
#include <Intersection.h>
#include <GeoUtils.h>

using namespace cgm;

bool cgm::intersect(Point3D& a, Point3D& b, Point3D& c, Point3D& d)
{
    if(cgm::orientation3D(a,b,c) == int(cgm::RELATIVE_POSITION::BETWEEN) 
      || cgm::orientation3D(a,b,d) == int(cgm::RELATIVE_POSITION::BETWEEN)
      || cgm::orientation3D(c,d,a) == int(cgm::RELATIVE_POSITION::BETWEEN) 
      || cgm::orientation3D(c,d,b) == int(cgm::RELATIVE_POSITION::BETWEEN))
      
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
