#include "Hand.h"



Hand::Hand(GLfloat handRadius,Finger pinky, Finger ring, Finger middle, Finger index)
{
	this->handRadius = handRadius;
	this->pinky = pinky;
	this->ring = ring;
	this->middle = middle;
	this->index = index;
}

Hand::Hand()
{
	this->handRadius = 50;
	this->pinky = Finger(50,30,20);
	this->ring = Finger(80,48,32);
	this->middle = Finger();
	this->index = Finger(80, 48, 32);
}


Hand::~Hand()
{
}

void Hand::RotateWristUpX()
{
	if (wristRotationX-5 >= XSTARTLIMIT) {
		wristRotationX -= 5;
	}
}

void Hand::RotateWristDownX()
{
	if (wristRotationX <= XENDLIMIT) {
		wristRotationX += 5;
	}
}

void Hand::RotateWristUpZ()
{
	if (wristRotationZ >= ZSTARTLIMIT) {
		wristRotationZ -= 5;
	}
}

void Hand::RotateWristDownZ()
{
	if (wristRotationZ <= ZENDLIMIT) {
		wristRotationZ += 5;
	}
}

void Hand::CloseHand()
{
	pinky.RotateBaseDown();
	pinky.RotateMiddleDown();
	pinky.RotateUpperDown();

	ring.RotateBaseDown();
	ring.RotateMiddleDown();
	ring.RotateUpperDown();

	middle.RotateBaseDown();
	middle.RotateMiddleDown();
	middle.RotateUpperDown();

	index.RotateBaseDown();
	index.RotateMiddleDown();
	index.RotateUpperDown();
}

void Hand::OpenHand()
{
	pinky.RotateBaseUp();
	pinky.RotateMiddleUp();
	pinky.RotateUpperUp();

	ring.RotateBaseUp();
	ring.RotateMiddleUp();
	ring.RotateUpperUp();

	middle.RotateBaseUp();
	middle.RotateMiddleUp();
	middle.RotateUpperUp();

	index.RotateBaseUp();
	index.RotateMiddleUp();
	index.RotateUpperUp();
}

void Hand::DrawHand()
{
	glPushMatrix();
	glScalef(1, 1, 1);
	glRotatef(wristRotationX, 1, 0, 0);
	glRotatef(wristRotationZ, 0, 0, 1);
	glutSolidSphere(this->handRadius,20,8);
	glPushMatrix();
	glTranslatef(handRadius-(pinky.GetKnuckleBaseRadius()), handRadius,1);
	glPushMatrix();
	glRotatef(-30, 0, 0, 1);
	this->pinky.DrawFinger();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(ring.GetKnuckleBaseRadius()*1.2), 1, 1);
	glPushMatrix();
	this->ring.DrawFinger();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(middle.GetKnuckleBaseRadius()*1.2), 1, 1);
	glPushMatrix();
	this->middle.DrawFinger();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-(index.GetKnuckleBaseRadius()*1.2), -handRadius/10, 1);
	glPushMatrix();
	this->index.DrawFinger();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

Finger Hand::GetPinky()
{
	return this->pinky;
}

Finger Hand::GetRing()
{
	return this->ring;
}

Finger Hand::GetMiddle()
{
	return this->middle;
}

Finger Hand::GetIndex()
{
	return this->index;
}

GLfloat Hand::GetRadius()
{
	return this->handRadius;
}

void Hand::operator=(Hand & rhs)
{
	this->pinky = rhs.GetPinky();
	this->ring = rhs.GetRing();
	this->middle = rhs.GetMiddle();
	this->index = rhs.GetIndex();

	this->handRadius = rhs.GetRadius();
}
