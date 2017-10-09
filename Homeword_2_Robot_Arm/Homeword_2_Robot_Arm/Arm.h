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
	Arm(GLfloat shoulderSocketRadius, GLfloat elbowSocketRadius, GLfloat upperArmLength, GLfloat lowerArmLength, Hand hand);
	Arm();
	~Arm();
	void RotateShoulderDown();
	void RotateShoulderUp();
	void RotateShoulderClockWise();
	void RotateShoulderCounterClockWise();
	void RotateElbowDown();
	void RotateElbowUp();

	void DrawArm();

	Hand GetHand();

	void CloseHand();
	void OpenHand();

	void RotateWristUpX();
	void RotateWristDownX();
	void RotateWristUpZ();
	void RotateWristDownZ();
private:
	const GLfloat SHOULDERSTARTLIMITX = -90;
	const GLfloat SHOULDERENDLIMITX = 90;
	const GLfloat ELBOWSTARTLIMIT = 0;
	const GLfloat ELBOWENDLIMIT = 90;
	GLfloat shoulderSocketRadius;
	GLfloat elbowSocketRadius;
	
	GLfloat upperArmLength;
	GLfloat lowerArmLength;

	GLfloat shoulderRotationAngleX;
	GLfloat shoulderRotationAngleY;
	GLfloat elbowRotationAngle;
	Hand hand;
};

