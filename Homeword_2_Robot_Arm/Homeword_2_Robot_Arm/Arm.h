#pragma once
#include <windows.h>  
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <iostream>

#include "Hand.h"

class Arm
{
public:
	Arm(GLfloat shoulderSocketRadius, GLfloat elbowSocketRadius, GLfloat wristSocketRadius, GLfloat upperArmLength, GLfloat lowerArmLength, Hand hand);
	Arm();
	~Arm();
	void RotateShoulder();
	void RotateElbow();
	void RotateHand();
private:
	GLfloat shoulderSocketRadius;
	GLfloat elbowSocketRadius;
	GLfloat wristSocketRadius;

	GLfloat upperArmLength;
	GLfloat lowerArmLength;

	Hand hand;
};

