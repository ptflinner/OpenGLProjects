#pragma once
#include <windows.h>  
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <iostream>
class Thumb
{
public:
	Thumb();
	~Thumb();

	void RotateThumb();
private:
	GLfloat thumbLength;
	GLfloat thumbUpperSocketRadius;
	GLfloat thumbLowerSocketRadius;
};

