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
#include <vector>
#include "Source.h"
#include "Mesh.h"

//***************PROTOTYPES***************
void myInit();
void myDisplay(void);
void DrawAxis();
void DrawBase();
void DrawMesh();
void moveCamera(void);
void myKeyboard(unsigned char key, int x, int y);
void mySpecialKeyboard(int theKey, int mouseX, int mouseY);
void myMouse(int button, int state, int x, int y);
void myMouseWheel(int wheel, int direction, int x, int y);
void DragMotion(int x, int y);
void myIdle();
void Print();

//***************MAIN/INIT***************
int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(250, 250); // set window position on screen
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
	cam.setShape(50.0f, (float)screenWidth / screenHeight, 0.5f, 200.0f);// set the view volume shape ----
	cam.set(Point3(0, 2, 4), Point3(0, 2, 0), Vector3(0, 1, 0));
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);


	glLightfv(GL_LIGHT0, GL_AMBIENT, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightIntensity);
}

//**************DISPLAY FUNCTIONS***************
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(camRotateY, .1, 0, 0);
	glRotatef(camRotateX, 0, .1, 0);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	DrawAxis();


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	DrawBase();
	glLightfv(GL_LIGHT0, GL_POSITION, litePos);
	DrawMesh();
	
	glPopMatrix();
	glutSwapBuffers();
}

void DrawAxis() {
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(5, 0, 0);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 5, 0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 5);
	glEnd();
}

void DrawBase() {
	
	for (int i = -20; i < 20; i++) {
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex3f(i, 0, -20);
		glVertex3f(i, 0, 20);
		glEnd();
	}
	for (int i = -20; i < 20; i++) {
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex3f(-20, 0, i);
		glVertex3f(20, 0, i);
		glEnd();
	}
}

void DrawMesh() {
	if (!revolve) {
		glBegin(GL_LINE_STRIP );
		for (int i = 0; i<NoOfPts; i++)
			glVertex3f(base[i].x, base[i].y, base[i].z);
		glEnd();
	}
}

void moveCamera(void) {

}
//***************INPUT FUNCTIONS***************
void myKeyboard(unsigned char key, int x, int y)
{
	
	switch (key) {
	case 'E':
	case 'e':
		cam.set(Point3(4, 4, 4), Point3(0, 0, 0), Vector3(0, 1, 0));
		revolve = false;
		NoOfPts = 0;
		base.clear();
		break;
	case 'F':
	case 'f':
		break;
	case 'G':
	case 'g':
		break;
	case 'M':
	case 'm':
		break;
	default:
		break;
	}

	glutPostRedisplay(); // draw it again
}

void mySpecialKeyboard(int theKey, int mouseX, int mouseY)
{	
	switch (theKey) {
	case GLUT_KEY_PAGE_UP:		// slide camera forward
		std::cout << "Camera zoom-in" << std::endl;

		break;
	case GLUT_KEY_PAGE_DOWN:
		// slide camera backward
		std::cout << "Camera zoom-out" << std::endl;
	
		break;
	default:
		break;
	}
	glutPostRedisplay(); // draw it again
}

void myMouse(int button, int state, int x, int y) {

	//Transfers mouse coordinate to window coordinate
	mouseX = x;
	mouseY = y;

	int mod = glutGetModifiers();
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !revolve) {
		int ry = screenHeight - y;
		base.push_back(Point3(x*worldWidth / (float)screenWidth - worldWidth / 2,
			ry*worldHeight / (float)screenHeight - worldHeight / 2,
			0));
		NoOfPts++;

		Print();
	}

	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		dragCamera = true;
		panCamera = false;
		zoomCamera = false;
		if (mod == GLUT_ACTIVE_SHIFT) {
			panCamera = true;
		}
		else if (mod == GLUT_ACTIVE_CTRL) {
			std::cout << "PURPLE" << std::endl;
			zoomCamera = true;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		revolve = true;
	}

	glutPostRedisplay();
}

void DragMotion(int x, int y) {
	double newX = (x - mouseX);
	double newY = (y - mouseY);
	
	mouseX = x;
	mouseY = y;
	if (newX < 0) {
		newX = -1;
	}
	else if (newX == 0) {
		newX = 0;
	}
	else {
		newX = 1;
	}
	if (newY < 0) {
		newY = -1;
	}
	else if (newY == 0) {
		newY = 0;
	}
	else {
		newY = 1;
	}

	if (dragCamera && panCamera) {
	
		cam.slide(-newX/10, newY/10, 0);
	}
	else if (dragCamera && zoomCamera) {
		std::cout << "DA" << std::endl;
		if (newY<0) {
			cam.slide(0, 0, 0.2);
		}
		else if (newY > 0) {
			cam.slide(0, 0, -0.2);
		}
	}
	else if (dragCamera && !panCamera) {
		camRotateX -= newX;
		camRotateY += newY;
	}
	

}

void Print() {
	for (unsigned int i = 0; i < base.size(); i++) {
		std::cout << base[i];
	}
	std::cout << std::endl;
}
