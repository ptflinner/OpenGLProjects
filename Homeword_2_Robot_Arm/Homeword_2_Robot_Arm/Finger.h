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
	~Finger();

private:
	GLfloat indexFingerLowerLength;
	GLfloat middleFingerLowerLength;
	GLfloat ringFingerLowerLength;
	GLfloat pinkyFingerLowerLength;

	GLfloat indexFingerMiddleLength;
	GLfloat middleFingerMiddleLength;
	GLfloat ringFingerMiddleLength;
	GLfloat pinkyFingerMiddleLength;

	GLfloat indexFingerUpperLength;
	GLfloat middleFingerUpperLength;
	GLfloat ringFingerUpperLength;
	GLfloat pinkyFingerUpperLength;

	GLfloat knuckleBaseRadius;
	GLfloat knuckleMiddleRadius;
	GLfloat knuckleLowerRadius;
};

