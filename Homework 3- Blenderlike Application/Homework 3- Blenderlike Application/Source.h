//Patrick Flinner
//304607711
//Homework 3
//November 30, 2017

#ifndef SOURCE_H
#define SOURCE_H

#include "Camera.h"
#include "Mesh.h"

//Global Variables
const int screenWidth = 500;	   // width of screen window in pixels
const int screenHeight = 500;	   // height of screen window in pixels
const float worldWidth = 20.0;
const float worldHeight = 20.0;
GLfloat lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat litePos[] = { 0.0f, 20.0f, 0.0f, 0.0f };
GLfloat mouseX = 0;
GLfloat mouseY = 0;

//PolyLine
int NoOfPts = 0;
int displayMode = 0;
std::vector<Point3> base;
Mesh revolution;
bool revolve = false;

Camera cam; // global camera object

//Camera Controls
bool panCamera = false;
bool dragCamera = false;
bool zoomCamera = false;
bool animate = false;
GLfloat camRotateX=0;
GLfloat camRotateY=0;
#endif