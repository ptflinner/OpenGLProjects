//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2
#include "Finger.h"



Finger::Finger()
{
	this->lowerLength = 100;
	this->middleLength = 60;
	this->upperLength = 40;
	this->knuckleBaseRadius = lowerLength/5;
	this->knuckleMiddleRadius = lowerLength/6.5;
	this->knuckleUpperRadius = lowerLength/8;
	this->knuckleBaseAngle=0;
	this->knuckleMiddleAngle=0;
	this->knuckleUpperAngle=0;
}

Finger::Finger(GLfloat lowerLength, GLfloat middleLength, GLfloat upperLength, GLfloat knuckleBaseRadius, GLfloat knuckleMiddleRadius, GLfloat knuckleUpperRadius)
{
	this->lowerLength = lowerLength;
	this->middleLength = middleLength;
	this->upperLength = upperLength;
	this->knuckleBaseRadius = knuckleBaseRadius;
	this->knuckleMiddleRadius = knuckleMiddleRadius;
	this->knuckleUpperRadius = knuckleUpperRadius;
	this->knuckleBaseAngle = 0;
	this->knuckleMiddleAngle = 0;
	this->knuckleUpperAngle = 0;
}

Finger::Finger(GLfloat lowerLength, GLfloat middleLength, GLfloat upperLength)
{
	this->lowerLength = lowerLength;
	this->middleLength = middleLength;
	this->upperLength = upperLength;
	this->knuckleBaseRadius = lowerLength / 5;
	this->knuckleMiddleRadius = lowerLength / 6.5;
	this->knuckleUpperRadius = lowerLength / 8;
	this->knuckleBaseAngle = 0;
	this->knuckleMiddleAngle = 0;
	this->knuckleUpperAngle = 0;
}

Finger::~Finger()
{
}

void Finger::DrawFinger()
{
	//Draws the first knuckle
	glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glRotatef(knuckleBaseAngle, 1, 0, 0);
		glutSolidSphere(knuckleBaseRadius,20,8);
		//Draws the base of the finger
		glPushMatrix();
			glScaled(knuckleMiddleRadius, lowerLength, knuckleMiddleRadius);
			glTranslated(0, .5, 0);
			glutSolidCube(1);
		glPopMatrix();

		//Draws the second knuckle
		glPushMatrix();
			glTranslated(0, lowerLength, 0);
			glRotatef(knuckleMiddleAngle, 1, 0, 0);
			glutSolidSphere(knuckleMiddleRadius, 20, 8);

			//Draws the middle length
			glPushMatrix();
				glScaled(knuckleMiddleRadius, middleLength, knuckleMiddleRadius);
				glTranslated(0, .5, 0);
				glutSolidCube(1);
			glPopMatrix();
			//Draws the final knuckle
			glTranslated(0, middleLength, 0);
			glRotatef(knuckleUpperAngle, 1, 0, 0);
			glutSolidSphere(knuckleUpperRadius, 20, 8);

			//Draws the final finger length
			glPushMatrix();
				glScaled(knuckleUpperRadius, upperLength, knuckleUpperRadius);
				glTranslated(0, .5, 0);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void Finger::RotateBaseDown()
{
	if ((knuckleBaseAngle+5) <= 90) {
		knuckleBaseAngle +=5;
	}
}

void Finger::RotateBaseUp()
{
	if ((knuckleBaseAngle - 5) >= 0) {
		knuckleBaseAngle -= 5;
	}
}

void Finger::RotateMiddleDown()
{
	if ((knuckleMiddleAngle + 5) <= 90) {
		knuckleMiddleAngle += 5;
	}
}

void Finger::RotateMiddleUp()
{
	if ((knuckleMiddleAngle - 5) >= 0) {
		knuckleMiddleAngle -= 5;
	}
}

void Finger::RotateUpperDown()
{
	if ((knuckleUpperAngle + 5) <= 90) {
		knuckleUpperAngle += 5;
	}
}

void Finger::RotateUpperUp()
{
	if ((knuckleUpperAngle - 5) >= 0) {
		knuckleUpperAngle -= 5;
	}
}

GLfloat Finger::GetLowerLength()
{
	return this->lowerLength;
}

GLfloat Finger::GetMiddleLength()
{
	return this->middleLength;
}

GLfloat Finger::GetUpperLength()
{
	return this->upperLength;
}

GLfloat Finger::GetKnuckleBaseRadius()
{
	return this->knuckleBaseRadius;
}

GLfloat Finger::GetKnuckleMiddleRadius()
{
	return this->knuckleMiddleRadius;
}

GLfloat Finger::GetKnuckleUpperRadius()
{
	return this->knuckleUpperRadius;
}

void Finger::operator=(Finger & rhs)
{
	this->lowerLength = rhs.GetLowerLength();
	this->middleLength = rhs.GetMiddleLength();
	this->upperLength = rhs.GetUpperLength();
	this->knuckleBaseRadius = rhs.GetKnuckleBaseRadius();
	this->knuckleMiddleRadius = rhs.GetKnuckleMiddleRadius();
	this->knuckleUpperRadius = rhs.GetKnuckleUpperRadius();

	this->knuckleBaseAngle=0;
	this->knuckleMiddleAngle=0;
	this->knuckleUpperAngle=0;
}

