//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2
#include "Hand.h"



Hand::Hand(GLfloat wristRadius,GLfloat handRadius,Finger pinky, Finger ring, Finger middle, Finger index)
{
	this->wristRadius = wristRadius;
	this->handRadius = handRadius;
	this->pinky = pinky;
	this->ring = ring;
	this->middle = middle;
	this->index = index;
	this->ballScale = 0;
}

Hand::Hand()
{
	this->wristRadius = 25;
	this->handRadius = 40;
	this->pinky = Finger(50,30,20);
	this->ring = Finger(80,48,32);
	this->middle = Finger();
	this->index = Finger(80, 48, 32);
	this->ballScale = 0;
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
	thumb.RotateUpperThumbDown();
	thumb.RotateThumbXIn();
	thumb.RotateThumbYIn();

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
	thumb.RotateUpperThumbUp();
	thumb.RotateThumbXOut();
	thumb.RotateThumbYOut();
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
	//Draws the hand
	glPushMatrix();
		glScalef(1, 1, 1);
		glTranslatef(0, wristRadius/2, 0);
		glRotatef(wristRotationX, 1, 0, 0);
		glRotatef(wristRotationZ, 0, 0, 1);
		
		//Draws the wrist
		glPushMatrix();
			glutSolidSphere(this->wristRadius, 20, 8);
		glPopMatrix();
		if (animation) {
			glPushMatrix();
				glTranslatef(0, ballScale*4, ballScale*4);
				glScalef(ballScale, ballScale, ballScale);
				glutSolidSphere(4, 20, 8);
			glPopMatrix();
		}
		//Draws the main hand
		glPushMatrix();
			glTranslatef(0, handRadius/2, 0);
			glPushMatrix();
			glutSolidSphere(this->handRadius,20,8);
			glPopMatrix();
				//Scales the finger
				glPushMatrix();
					glScalef(.8, .8, .8);

					//Places the fingers on the hand
					glPushMatrix();
						glTranslatef(0, handRadius,0);

						glPushMatrix();
							glTranslatef((middle.GetKnuckleBaseRadius()+pinky.GetKnuckleBaseRadius()+ring.GetKnuckleBaseRadius()),0, 0);
							glRotatef(-15, 0, 0, 1);
							this->pinky.DrawFinger();
						glPopMatrix();
						glPushMatrix();
							glTranslatef((middle.GetKnuckleBaseRadius()+ring.GetKnuckleBaseRadius()/2), 0, 0);
							this->ring.DrawFinger();
						glPopMatrix();
						glPushMatrix();
							glTranslatef(0, 0, 0);
							this->middle.DrawFinger();
						glPopMatrix();
						glPushMatrix();
							glTranslatef(-(index.GetKnuckleBaseRadius()+ middle.GetKnuckleBaseRadius()/2), -handRadius/10, 0);
							this->index.DrawFinger();
						glPopMatrix();
					glPopMatrix();
					glTranslatef(-(handRadius+thumb.GetThumbBaseRadius()),0,0);
					glRotatef(30, 0, 0, 1);
					this->thumb.DrawThumb();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
}

void Hand::ScaleBall()
{
	ballScale+=1.25;
	OpenHand();
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

void Hand::SetAnimation(bool animate)
{
	this->animation = animate;
}

void Hand::ResetScale()
{
	ballScale = 0;
}

GLfloat Hand::GetRadius()
{
	return this->handRadius;
}

Thumb Hand::GetThumb()
{
	return this->thumb;
}

void Hand::operator=(Hand & rhs)
{
	this->pinky = rhs.GetPinky();
	this->ring = rhs.GetRing();
	this->middle = rhs.GetMiddle();
	this->index = rhs.GetIndex();
	this->thumb = rhs.GetThumb();
	this->handRadius = rhs.GetRadius();
	this->wristRotationX = 0;
	this->wristRotationZ = 0;
}
