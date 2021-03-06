//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2
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
	void ScaleBall();
	//Getters
	Finger GetPinky();
	Finger GetRing();
	Finger GetMiddle();
	Finger GetIndex();
	Thumb GetThumb();

	void SetAnimation(bool animate);
	void ResetScale();
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
	bool animation;
	float ballScale;
	GLfloat handRadius;
	GLfloat wristRadius;
	GLfloat wristRotationX;
	GLfloat wristRotationZ;
};

