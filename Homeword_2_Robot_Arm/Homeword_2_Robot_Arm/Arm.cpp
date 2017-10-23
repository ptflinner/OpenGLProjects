//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2
#include "Arm.h"



Arm::Arm(GLfloat shoulderSocketRadius, GLfloat elbowSocketRadius, GLfloat upperArmLength, GLfloat lowerArmLength, Hand hand)
{
	this->shoulderSocketRadius = shoulderSocketRadius;
	this->elbowSocketRadius = elbowSocketRadius;
	this->upperArmLength = upperArmLength;
	this->lowerArmLength = lowerArmLength;
	this->hand = hand;
}

Arm::Arm()
{
	this->shoulderSocketRadius = 25;
	this->elbowSocketRadius = 12.5;
	this->upperArmLength = 100;
	this->lowerArmLength = 90;
	this->hand = Hand();
}


Arm::~Arm()
{
}

void Arm::RotateShoulderDown()
{
	if (shoulderRotationAngleX + 5 <= SHOULDERENDLIMITX) {
		shoulderRotationAngleX += 5;
	}
}

void Arm::RotateShoulderUp()
{
	if (shoulderRotationAngleX - 5 >= SHOULDERSTARTLIMITX) {
		shoulderRotationAngleX -= 5;
	}
}

void Arm::RotateShoulderClockWise()
{
		shoulderRotationAngleY += 5;
}

void Arm::RotateShoulderCounterClockWise()
{
	shoulderRotationAngleY -= 5;
}

void Arm::RotateElbowDown()
{
	if (elbowRotationAngle + 5 <= ELBOWENDLIMIT) {
		elbowRotationAngle += 5;
	}
}

void Arm::RotateElbowUp()
{
	if (elbowRotationAngle - 5 >= ELBOWSTARTLIMIT) {
		elbowRotationAngle -= 5;
	}
}

void Arm::DrawArm()
{
	//Draws the arm
	glPushMatrix();
	//Draws the shoulder socket
		glScalef(1, 1, 1);
		glRotatef(shoulderRotationAngleX, 1, 0, 0);
		glRotatef(shoulderRotationAngleY, 0, 1, 0);
		glPushMatrix();
			glutSolidSphere(shoulderSocketRadius, 20, 8);
		glPopMatrix();

		//Draws the shoulder to elbow bars
		glPushMatrix();
			glTranslatef(0, upperArmLength/2, 0);
			glPushMatrix();
				glTranslatef(-shoulderSocketRadius/4, 0, 0);
				glScalef(shoulderSocketRadius/4, upperArmLength, shoulderSocketRadius/4);
				glutSolidCube(1);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(shoulderSocketRadius / 4, 0, 0);
				glScalef(shoulderSocketRadius / 4, upperArmLength, shoulderSocketRadius / 4);
				glutSolidCube(1);
			glPopMatrix();

			//Draws the elbow socket
			glPushMatrix();
				glTranslatef(0, upperArmLength/2, 0);
				glRotatef(elbowRotationAngle, 1, 0, 0);
				glPushMatrix();
					glutSolidSphere(elbowSocketRadius,20,8);
				glPopMatrix();

				//Draws the elbow arm bar
				glPushMatrix();
					glTranslatef(1, lowerArmLength / 2, 1);
					glPushMatrix();
						glScalef(shoulderSocketRadius / 2, lowerArmLength, shoulderSocketRadius / 2);
						glutSolidCube(1);
					glPopMatrix();
					glScalef(.4, .4, .4);
					glTranslatef(1, lowerArmLength , 1);

					//Draws the hand
					hand.DrawHand();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

GLfloat Arm::GetUpperArmLength()
{
	return this->upperArmLength;
}

GLfloat Arm::GetLowerArmLength()
{
	return this->lowerArmLength;
}

GLfloat Arm::GetShoulderSocketRadius()
{
	return this->shoulderSocketRadius;
}

GLfloat Arm::GetElbowSocketRadius()
{
	return this->elbowSocketRadius;
}

Hand Arm::GetHand()
{
	return this->hand;
}

void Arm::CloseHand()
{
	this->hand.CloseHand();
}

void Arm::OpenHand()
{
	this->hand.OpenHand();
}

void Arm::ScaleBall()
{
	this->hand.ScaleBall();
}

void Arm::RotateWristUpX()
{
	this->hand.RotateWristUpX();
}

void Arm::RotateWristDownX()
{
	this->hand.RotateWristDownX();
}

void Arm::RotateWristUpZ()
{
	this->hand.RotateWristUpZ();
}

void Arm::RotateWristDownZ()
{
	this->hand.RotateWristDownZ();
}

void Arm::operator=(Arm & rhs)
{
	this->shoulderSocketRadius = rhs.GetShoulderSocketRadius();
	this->elbowSocketRadius = rhs.GetElbowSocketRadius();
	this->upperArmLength = rhs.GetUpperArmLength();
	this->lowerArmLength = rhs.GetLowerArmLength();
	this->hand = rhs.GetHand();

	this->shoulderRotationAngleX=0;
	this->shoulderRotationAngleY=0;
	this->elbowRotationAngle=0;
}

void Arm::SetAnimation(bool animate)
{
	this->hand.SetAnimation(animate);
}

void Arm::ResetScale()
{
	this->hand.ResetScale();
}
