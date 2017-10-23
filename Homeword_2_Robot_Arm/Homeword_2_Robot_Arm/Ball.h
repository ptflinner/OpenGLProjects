//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2

#pragma once
#ifndef CIRCLE_PHYSICS
#define CIRCLE_PHYSICS
#include "Vector.h"

class Ball
{

private:
	//Variables needed for the  ball
	double radius;
	double mass;
	Vector velocity;
	Vector center;

public:
	Ball();
	Ball(float x, float y,float z, float vx, float vy,float vz, float r);
	~Ball();

	//Getters and setters
	double GetRadius();
	void SetRadius(double radius);
	double GetMass();
	Vector GetVelocity();
	void SetVelocity(Vector newVelocity);
	void SetVelocity(float x, float y,float z);
	void SetCenter(float x, float y,float z);
	void SetCenter(Vector vector);
	float GetCenterX();
	float GetCenterY();
	float GetCenterZ();
	Vector GetCenter();

	//Moves the ball
	void MoveCoordinate(float t);
};

#endif