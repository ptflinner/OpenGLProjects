//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2

#include "Ball.h"
#include <iostream>


Ball::Ball()
{
	radius = 10;
	mass = radius*radius*radius;
	velocity.SetCoordinates(0, 0,0);
	SetCenter(0, 0,0);
}

Ball::Ball(float x, float y, float z, float vx, float vy,float vz, float r)
{
	center.SetCoordinates(x, y,z);
	velocity.SetCoordinates(vx, vy,vz);
	radius = r;
	mass = radius*radius*radius;
}


Ball::~Ball()
{
}

double Ball::GetRadius()
{
	return radius;
}

void Ball::SetRadius(double newRadius)
{
	radius = newRadius;
	mass = radius*radius*radius;
}

double Ball::GetMass()
{
	return mass;
}

Vector Ball::GetVelocity()
{
	return velocity;
}

void Ball::SetVelocity(Vector newVelocity)
{
	velocity.SetX(newVelocity.GetX());
	velocity.SetY(newVelocity.GetY());
	velocity.SetZ(newVelocity.GetZ());
}

void Ball::SetVelocity(float x, float y,float z)
{
	Vector v(x, y,z);
	SetVelocity(v);
}

void Ball::SetCenter(float x, float y,float z)
{
	center.SetX(x);
	center.SetY(y);
	center.SetZ(z);
}

void Ball::SetCenter(Vector vector)
{
	center.SetX(vector.GetX());
	center.SetY(vector.GetY());
	center.SetZ(vector.GetZ());
}

float Ball::GetCenterX()
{
	return center.GetX();
}

float Ball::GetCenterY()
{
	return center.GetY();
}
float Ball::GetCenterZ()
{
	return center.GetZ();
}

Vector Ball::GetCenter()
{
	return center;
}

//Moves the coordinate based on time and velocity
void Ball::MoveCoordinate(float t)
{
	float newX = (center.GetX() + velocity.GetX()*t);
	float newY = (center.GetY() + velocity.GetY()*t);
	float newZ = (center.GetZ() + velocity.GetZ()*t);
	SetCenter(newX, newY,newZ);
}
