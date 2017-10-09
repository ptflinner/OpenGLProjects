#pragma once

#include "Finger.h"
class Hand
{
public:
	Hand(GLfloat handRadius,Finger pinky, Finger ring, Finger middle, Finger index);
	Hand();
	~Hand();

	void RotateWristUpX();
	void RotateWristDownX();
	void RotateWristUpZ();
	void RotateWristDownZ();
	void CloseHand();
	void OpenHand();
	void DrawHand();
private:
	const GLfloat xStartLimit=0;
	const GLfloat xEndLimit = 90;
	const GLfloat zStartLimit = 0;
	const GLfloat zEndLimit = 90;
	Finger pinky;
	Finger ring;
	Finger middle;
	Finger index;

	GLfloat handRadius;

	GLfloat wristRotationX;
	GLfloat wristRotationZ;
};

