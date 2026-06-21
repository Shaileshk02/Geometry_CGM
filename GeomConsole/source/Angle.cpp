#include <Angle.h>
#include <Core.h>

float cgm::angleLinePlanes(Plane& p1, Line&	 l1)
{

	Vector v1 = p1.normal();
	Vector v2 = l1.direction();

	float dot = Vector::DotProduct(v1, v2);
	float angleLinePlanes = acosf(dot / (v1.magnitude() * v2.magnitude()));

	return (90 - (angleLinePlanes * 180.0f / PI));



}
