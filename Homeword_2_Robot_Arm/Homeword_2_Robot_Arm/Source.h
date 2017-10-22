#include "Arm.h"

#define PI 3.1415


//Global Variables
const int screenWidth = 500;	   // width of screen window in pixels

const int screenHeight = 500;	   // height of screen window in pixels

const float worldWidth = 500.0;
const float worldHeight = 500.0;

// Initial values
GLdouble scale = 1.0;
GLdouble tx = 0.0, ty = 0.0, tz = 0.0;
GLdouble rotation_angle = 0.0;

// global values for camera
GLfloat initEyeX=25, initEyeY=25, initEyeZ=25;
GLdouble eyex = 25.0, eyey = 25.0, eyez = 25.0;
GLdouble lookx = 0.0, looky = 0.0, lookz = 0.0;

int view = 0;

// global values for shading
GLfloat ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat shininess[] = { 50.0f };

GLfloat position[] = { 2.0f, 6.0f, 3.0f, 0.0f };
GLfloat lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };

GLfloat centerX = 0.5;
GLfloat centerY = 20;
GLfloat centerZ = 16;
GLfloat xMove = 0;
GLfloat zMove = 0;
GLfloat baseRadius = 50;
GLfloat baseAngle = 0;
Arm arm;
//Hand hand;
Thumb thumb;
float height = 50;
float width = 70;
float i = 0;
float total=0;
float distance = 5;
bool rotateCamera = false;
bool robotOn = true;
bool filled = true;
bool showAxis = true;
bool animateCamera = false;

//Boundaries
int top = 100;
int bottom = -100;
int left = -100;
int right = 100;
int roomFloor = 0;