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
	glPushMatrix();
		glScalef(1, 1, 1);
		glRotatef(shoulderRotationAngleX, 1, 0, 0);
		glRotatef(shoulderRotationAngleY, 0, 1, 0);
		glutSolidSphere(shoulderSocketRadius, 20, 8);
		glPushMatrix();
			glTranslatef(1, upperArmLength/2, 1);
			glPushMatrix();
				glScalef(shoulderSocketRadius/2, upperArmLength, shoulderSocketRadius/2);
				glutSolidCube(1);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(1, upperArmLength/2, 1);
				glRotatef(elbowRotationAngle, 1, 0, 0);
				glPushMatrix();
					glutSolidSphere(elbowSocketRadius,20,8);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(1, lowerArmLength / 2, 1);
					glPushMatrix();
						glScalef(shoulderSocketRadius / 2, lowerArmLength, shoulderSocketRadius / 2);
						glutSolidCube(1);
					glPopMatrix();
					glScalef(.4, .4, .4);
					glTranslatef(1, lowerArmLength , 1);
					hand.DrawHand();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
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
