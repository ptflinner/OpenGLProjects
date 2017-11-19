//Patrick Flinner
//Lab 9
//October 31, 2017

#ifndef LAB_CAMERA_H
#define LAB_CAMERA_H

#include "Camera.h"

//Global Variables
const int screenWidth = 500;	   // width of screen window in pixels
const int screenHeight = 500;	   // height of screen window in pixels
GLfloat lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat litePos[] = { 0.0f, 5.0f, 0.0f, 0.0f };
boolean rotate = false;
int i = 0;
Camera cam; // global camera object
GLfloat teapotTranslate;
GLfloat teapotAngle;
#endif