//Patrick Flinner
//Homework 3
//November 30, 2017

#ifndef SOURCE_H
#define SOURCE_H

#include "Camera.h"

//Global Variables
const int screenWidth = 500;	   // width of screen window in pixels
const int screenHeight = 500;	   // height of screen window in pixels
GLfloat lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat litePos[] = { 0.0f, 5.0f, 0.0f, 0.0f };
GLfloat mouseX = 0;
GLfloat mouseY = 0;

Camera cam; // global camera object

#endif