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

#include "Hand.h"

class Arm
{
public:
	Arm(GLfloat shoulderSocketRadius, GLfloat elbowSocketRadius, GLfloat upperArmLength, GLfloat lowerArmLength, Hand hand);
	Arm();
	~Arm();

	//Rotation of the arm
	void RotateShoulderDown();
	void RotateShoulderUp();
	void RotateShoulderClockWise();
	void RotateShoulderCounterClockWise();
	void RotateElbowDown();
	void RotateElbowUp();

	void DrawArm();

	//Hand animations
	void CloseHand();
	void OpenHand();

	//Rotate the wrist
	void RotateWristUpX();
	void RotateWristDownX();
	void RotateWristUpZ();
	void RotateWristDownZ();

	//Retrieve variables
	GLfloat GetUpperArmLength();
	GLfloat GetLowerArmLength();
	GLfloat GetShoulderSocketRadius();
	GLfloat GetElbowSocketRadius();
	Hand GetHand();

	//Overload for setting new arm
	void operator=(Arm & rhs);

private:
	//Variables that make up the arm
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

