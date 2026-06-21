#pragma once

#include <array>
#include <iostream>
#include <math.h>
#include <cstddef>

namespace cgm {
class Vector
{
private:



public:
	std::array<float, 3> m_coords = {0,0,0};
#define X 0
#define Y 1
#define Z 2

	Vector() = default;
	Vector(float x, float y, float z):m_coords{x,y,z}
	{

	}
	Vector(const std::array<float, 3> &coords) :m_coords(coords)
	{

	}

	//equality
	bool operator==(const Vector & v1) const;
	//not equality
	bool operator!=(const Vector&)const;
	//addition
	Vector operator +(const Vector&)const;
	//substraction
	Vector operator -(const Vector&)const;
	//less than
	bool operator <(const Vector&)const;
	//greater than
	bool operator >(const Vector&)const;
	//indexing operator
	float operator [] (const unsigned int) const;
	//dot product
	static float DotProduct(const Vector& v1, const Vector& v2);
	//Assign
	void assign(const unsigned int index, Vector& value);
	//cross product
	static Vector CrossProduct3D(const Vector& a, const Vector& b);
	static float CrossProduct2D(const Vector& a, const Vector& b);
	//magnitude
	float magnitude()const;
	//normalize
	void normalize();
	//scale
	Vector operator *(const float multiplier)const;
};

inline float Vector::magnitude() const
{
	float value = 0.0f;
	for (size_t i = 0; i < 3; i++)
		value += pow(m_coords[i], 2.0);
	return sqrt(value);
}

inline void Vector::normalize()
{
	auto mag = magnitude();
	if (mag <= 1e-8f)
	    return;
	    
	std::array<float, 3> temp_array = {0,0,0};

	for (size_t i = 0; i < 3; i++)
	{
		temp_array[i] = m_coords[i]/mag;
	}

	m_coords = temp_array;
}


inline Vector Vector::operator*(const float multiplier)const 
{
	std::array<float, 3> temp_array;
	for (size_t i = 0; i < 3; i++)
	{
		temp_array[i] = m_coords[i] * multiplier;
	}
	return temp_array;

}

inline Vector Vector::operator+(const Vector& _other)const
{
	std::array<float, 3> temp_array;
	for (size_t i = 0; i < 3; i++)
	{
		temp_array[i] = m_coords[i] + _other.m_coords[i];
	}
	return temp_array;
}

inline Vector Vector::operator-(const Vector& _other)const
{
	std::array<float, 3> temp_array;
	for (size_t i = 0; i < 3; i++)
	{
		temp_array[i] = m_coords[i] -  _other.m_coords[i];
	}
	return temp_array;
}

inline bool Vector::operator==(const Vector & v1)const
{
	for(size_t i = 0; i < 3; i++)
	{
		if (this->m_coords[i] == v1.m_coords[i])
		{
			continue;
		}
		else
			return false;
	}

	return true;
}

inline bool Vector::operator!=(const Vector& v1)const
{
	return  !(*this == v1);
}

inline void Vector::assign(const unsigned int index, Vector& value)
{
	if(index >= m_coords.size())
		std::cout << "index out of bound";

	m_coords = value.m_coords;

}

inline float Vector::DotProduct(const Vector& v1, const Vector& v2)
{
	return (v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2]);
}

inline float Vector::operator[](const unsigned int index) const
{
	if (index >= m_coords.size())
	{
		std::cout << "Index out of bound";
		return 0;
	}

	return m_coords[index];
}

inline bool Vector::operator >(const Vector& v1)const
{
	for (size_t i = 0; i< 3 ; i++)
	{
		if(this->m_coords[i] > v1.m_coords[i])
			continue;
		else
			return false;
	}

	return true;
}

inline bool Vector::operator <(const Vector& v1)const
{
	for (size_t i = 0; i< 3 ; i++)
	{
		if(this->m_coords[i] < v1.m_coords[i])
			continue;
		else
			return false;
	}

	return true;
}
} // namespace cgm