#include "Thumb.h"



Thumb::Thumb()
{
	thumbUpperLength=20;
	thumberBaseLength=20;
	thumbUpperSocketRadius=thumbUpperLength;
	thumbLowerSocketRadius;
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
	if (upperYAngle + 5 <= STARTANGLE) {
		upperYAngle += 5;
	}
}

void Thumb::DrawThumb()
{

}

