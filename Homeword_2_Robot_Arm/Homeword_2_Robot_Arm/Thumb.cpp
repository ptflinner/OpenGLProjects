#include "Thumb.h"



Thumb::Thumb()
{
	thumbUpperLength=50;
	thumberBaseLength=50;
	thumbUpperSocketRadius=thumbUpperLength/4;
	thumbLowerSocketRadius=thumberBaseLength/4;
}


Thumb::~Thumb()
{
}

void Thumb::RotateThumbXIn()
{
	if (baseXAngle + 5 <= ENDXANGLE) {
		baseXAngle += 5;
	}
}

void Thumb::RotateThumbXOut()
{
	if (baseXAngle - 5 >= STARTANGLE) {
		baseXAngle -= 5;
	}
}

void Thumb::RotateThumbYIn()
{
	if (baseYAngle + 5 <= ENDYANGLE) {
		baseYAngle += 5;
	}
}

void Thumb::RotateThumbYOut()
{
	if (baseYAngle - 5 >= STARTANGLE) {
		baseYAngle -= 5;
	}
}

void Thumb::RotateUpperThumbUp()
{
	if (upperYAngle- 5 >= STARTANGLE) {
		upperYAngle -= 5;
	}
}

void Thumb::RotateUpperThumbDown()
{
	if (upperYAngle + 5 <= ENDXANGLE) {
		upperYAngle += 5;
	}
}

GLfloat Thumb::GetThumbBaseRadius()
{
	return thumbLowerSocketRadius;
}

GLfloat Thumb::GetThumbUpperRadius()
{
	return thumbUpperSocketRadius;
}

void Thumb::DrawThumb()
{
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);
	glRotatef(baseXAngle, 1, 0, 0);
	glutSolidSphere(thumbLowerSocketRadius, 20, 8);
	glPushMatrix();
		glScaled(thumbLowerSocketRadius/2, thumberBaseLength, thumbLowerSocketRadius/2);
		glTranslated(0, .5, 0);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslated(0, thumberBaseLength, 0);
		glRotatef(upperYAngle, 1, 0, 0);
		glutSolidSphere(thumbUpperSocketRadius, 20, 8);
		glPushMatrix();
			glScaled(thumbLowerSocketRadius/2, thumbUpperLength, thumbLowerSocketRadius/2);
			glTranslated(0, .5, 0);
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

GLfloat Thumb::GetUpperLength()
{
	return this->thumbUpperLength;
}

GLfloat Thumb::GetBaseLength()
{
	return this->thumberBaseLength;
}

GLfloat Thumb::GetUpperRadius()
{
	return this->thumbUpperSocketRadius;
}

GLfloat Thumb::GetBaseRadius()
{
	return this->thumbLowerSocketRadius;
}

void Thumb::operator=(Thumb & rhs)
{
	this->thumbUpperLength = rhs.GetUpperLength();
	this->thumberBaseLength = rhs.GetBaseLength();
	this->thumbUpperSocketRadius = rhs.GetUpperRadius();
	this->thumbLowerSocketRadius = rhs.GetBaseRadius();

	this->baseXAngle=0;
	this->baseYAngle=0;
	this->upperYAngle=0;
}

