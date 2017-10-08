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
	Arm();
	~Arm();
	void RotateShoulder();
	void RotateElbow();
	void RotateHand();
private:
	GLfloat elbowSocketRadius;
	GLfloat shoulderSocketRadius;
	GLfloat wristSocketRadius;

	GLfloat upperArmLength;
	GLfloat lowerArmLength;

	Hand hand;
};

