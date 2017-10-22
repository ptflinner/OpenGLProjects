//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2

#pragma once
#include <iostream>

class Vector
{
private:
	float x, y,z;
public:
	Vector(float x, float y,float z);
	Vector();
	~Vector();
	void SetX(float newX);
	void SetY(float newY);
	void SetZ(float newZ);
	void SetCoordinates(float x, float y,float z);
	float GetX();
	float GetY();
	float GetZ();

	//Operator Overload
	Vector operator-(Vector& rhs);
	Vector operator+(Vector& rhs);
	Vector operator*(float& rhs);
	Vector operator/(float& rhs);
	float operator*(Vector& rhs);
	void operator=(Vector& rhs);

	friend std::ostream& operator<<(std::ostream& os, Vector& rhs);
};
