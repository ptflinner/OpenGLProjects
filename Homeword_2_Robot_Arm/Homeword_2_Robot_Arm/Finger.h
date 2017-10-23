//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2
#pragma once
#include <windows.h>  
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <iostream>
class Finger
{
public:
	Finger();
	Finger(GLfloat lowerLength, GLfloat middleLength, GLfloat upperLength);
	Finger(GLfloat lowerLength, GLfloat middleLength, GLfloat upperLength,
		GLfloat knuckleBaseRadius,GLfloat knuckleMiddleRadius,GLfloat knuckleUpperRadius);
	~Finger();
	void DrawFinger();
	void RotateBaseDown();
	void RotateBaseUp();
	void RotateMiddleDown();
	void RotateMiddleUp();
	void RotateUpperDown();
	void RotateUpperUp();

	//Getters
	GLfloat GetLowerLength();
	GLfloat GetMiddleLength();
	GLfloat GetUpperLength();

	GLfloat GetKnuckleBaseRadius();
	GLfloat GetKnuckleMiddleRadius();
	GLfloat GetKnuckleUpperRadius();

	//Operator Overload
	void operator=(Finger& rhs);
private:
	const GLfloat angleLimitStart=0;
	const GLfloat angleLimitEnd=90;
	
	GLfloat lowerLength;
	GLfloat middleLength;
	GLfloat upperLength;

	GLfloat knuckleBaseRadius;
	GLfloat knuckleMiddleRadius;
	GLfloat knuckleUpperRadius;

	GLfloat knuckleBaseAngle;
	GLfloat knuckleMiddleAngle;
	GLfloat knuckleUpperAngle;
};

