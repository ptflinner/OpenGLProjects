//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2

#include "Vector.h"



Vector::Vector(float x, float y,float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}


Vector::~Vector()
{
}

void Vector::SetX(float newX)
{
	x = newX;
}

void Vector::SetY(float newY)
{
	y = newY;
}

void Vector::SetZ(float newZ)
{
	z = newZ;
}
void Vector::SetCoordinates(float x, float y,float z)
{
	SetX(x);
	SetY(y);
	SetZ(z);
}

float Vector::GetX()
{
	return x;
}

float Vector::GetY()
{
	return y;
}
float Vector::GetZ()
{
	return z;
}

//Overloaded operators

//Vector Subtraction
Vector Vector::operator-(Vector & rhs)
{
	Vector subtracted;
	subtracted.SetX(x - rhs.GetX());
	subtracted.SetY(y - rhs.GetY());
	subtracted.SetZ(z - rhs.GetZ());
	return subtracted;
}

//Vector Addition
Vector Vector::operator+(Vector & rhs)
{
	Vector added;
	added.SetX(x + rhs.GetX());
	added.SetY(y + rhs.GetY());
	added.SetZ(z + rhs.GetZ());
	return added;
}

//Dot Product
float Vector::operator*(Vector & rhs)
{
	float dot;

	dot = x*rhs.GetX() + y*rhs.GetY()+ z*rhs.GetZ();
	return dot;
}

//Vector times a scalar
Vector Vector::operator*(float& rhs)
{
	Vector newVector;
	newVector.SetX(x*rhs);
	newVector.SetY(y*rhs);
	newVector.SetZ(z*rhs);
	return newVector;
}

//Sets a vector to another
void Vector::operator=(Vector & rhs)
{
	x = rhs.GetX();
	y = rhs.GetY();
	z = rhs.GetZ();
}

//Divides a vector by float value
Vector Vector::operator/(float & rhs)
{
	return Vector(x / rhs, y / rhs,z/rhs);
}

Vector Vector::operator/(int & rhs)
{
	return Vector(x / rhs, y / rhs, z / rhs);
}

//Prints the vector
std::ostream & operator<<(std::ostream & os, Vector & rhs)
{
	os << rhs.GetX() << " " << rhs.GetY() << " " <<rhs.GetZ() <<std::endl;
	return os;
}