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

	void RotateThumbXIn();
	void RotateThumbXOut();
	void RotateThumbYIn();
	void RotateThumbYOut();

	void RotateUpperThumbUp();
	void RotateUpperThumbDown();

	void DrawThumb();
private:
	const GLfloat STARTANGLE = 0;
	const GLfloat ENDXANGLE = 90;
	const GLfloat ENDYANGLE = 150;

	GLfloat baseXAngle;
	GLfloat baseYAngle;
	GLfloat upperYAngle;

	GLfloat thumbUpperLength;
	GLfloat thumberBaseLength;
	GLfloat thumbUpperSocketRadius;
	GLfloat thumbLowerSocketRadius;
};

