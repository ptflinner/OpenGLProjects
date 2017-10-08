#pragma once
#include <windows.h>  
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <iostream>

#include "Finger.h"
class Hand
{
public:
	Hand();
	~Hand();

private:
	Finger pinky;
	Finger ring;
	Finger middle;
	Finger index;

};

