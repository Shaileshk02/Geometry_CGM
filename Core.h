#pragma once


#include <math.h>

#define  PI 3.14159265358979323846f	
namespace cgm{
    
enum class RELATIVE_POSITION
{
	LEFT, RIGHT, BEHIND, BEYOND, BETWEEN, ORIGIN, DESTINATION
};


#define TOLERANCE 0.0000001
#define ZERO 0

static bool isEqualD(double x, double y)
{
	return fabs(x - y) < TOLERANCE;
}


static bool _xor(bool x, bool y)
{
	return x ^ y;
}    
    
    
}
