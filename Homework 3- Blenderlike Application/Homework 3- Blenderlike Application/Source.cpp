//Patrick Flinner
//Lab 9
//October 31, 2017

//Lab: Camera Control
#pragma once
#include <windows.h>  //suitable when using Windows 95/98/NT

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>

#include "Source.h"

//***************PROTOTYPES***************
void myInit();
void myDisplay(void);
void myKeyboard(unsigned char key, int x, int y);
void mySpecialKeyboard(int theKey, int mouseX, int mouseY);
void myMouse(int button, int state, int x, int y);
void DragMotion(int x, int y);
void myIdle();

//***************MAIN/INIT***************
int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Blender Lite"); // open the screen window
	glutIdleFunc(myIdle);
	// register callback functions
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecialKeyboard);
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutMotionFunc(DragMotion);
	myInit();

	glutMainLoop();

	return(0);
}

void myIdle() {

	glutPostRedisplay();
}

void myInit()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // background is black
	glColor3f(1.0f, 1.0f, 1.0f);    // drawing color is white

	cam.setShape(50.0f, (float)screenWidth / screenHeight, 0.5f, 200.0f);// set the view volume shape ----
	cam.set(Point3(4, 4, 4), Point3(0, 0, 0), Vector3(0, 1, 0));
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	glEnable(GL_DEPTH_TEST);


	glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightIntensity);
}

//**************DISPLAY FUNCTIONS***************
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);

	glutSwapBuffers();
}

//***************INPUT FUNCTIONS***************
void myKeyboard(unsigned char key, int x, int y)
{
	glutPostRedisplay(); // draw it again
}

void mySpecialKeyboard(int theKey, int mouseX, int mouseY)
{
	glutPostRedisplay(); // draw it again
}

void myMouse(int button, int state, int x, int y) {

	//Transfers mouse coordinate to window coordinate
	mouseX = x - (screenWidth / 2);
	mouseY = (screenHeight / 2 - y);


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	}

	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	}
	glutPostRedisplay();

}

void DragMotion(int x, int y) {
	x = x - (screenWidth / 2);
	y = (screenHeight / 2 - y);
	
}

