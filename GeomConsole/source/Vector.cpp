#include<Vector.h>

cgm::Vector cgm::Vector::CrossProduct3D(const Vector& a,const Vector& b)
{
    auto x = a[Y] * b[Z] - a[Z] * b[Y];
    auto y = a[Z] * b[X] - a[X] * b[Z];
    auto z = a[X] * b[Y] - a[Y] * b[X];

    return Vector(x, y, z);
}


float cgm::Vector::CrossProduct2D(const Vector& a,const Vector& b)
{
	float result(0.0);

	result = a[X] * b[Y] - b[X] * a[Y];

	return result;
}