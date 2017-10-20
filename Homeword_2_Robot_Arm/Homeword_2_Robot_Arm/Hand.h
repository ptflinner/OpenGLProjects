#pragma once

#include "Finger.h"
#include "Thumb.h"

class Hand
{
public:
	Hand(GLfloat wristRadius,GLfloat handRadius,Finger pinky, Finger ring, Finger middle, Finger index);
	Hand();
	~Hand();

	void RotateWristUpX();
	void RotateWristDownX();
	void RotateWristUpZ();
	void RotateWristDownZ();
	void CloseHand();
	void OpenHand();
	void DrawHand();

	//Getters
	Finger GetPinky();
	Finger GetRing();
	Finger GetMiddle();
	Finger GetIndex();
	Thumb GetThumb();

	GLfloat GetRadius();
	//Operator Overload
	void operator=(Hand& rhs);
private:
	const GLfloat XSTARTLIMIT =0;
	const GLfloat XENDLIMIT = 45;
	const GLfloat ZSTARTLIMIT = 0;
	const GLfloat ZENDLIMIT = 90;
	Finger pinky;
	Finger ring;
	Finger middle;
	Finger index;
	Thumb thumb;

	GLfloat handRadius;
	GLfloat wristRadius;
	GLfloat wristRotationX;
	GLfloat wristRotationZ;
};

