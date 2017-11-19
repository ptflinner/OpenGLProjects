//Patrick Flinner
//Lab 9
//October 31, 2017

//Lab: Camera Control
#pragma once
#include <windows.h>  //suitable when using Windows 95/98/NT

#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <iostream>

#include "Lab_Camera.h"


//<<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>>>
void myInit()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // background is black
	glColor3f(1.0f, 1.0f, 1.0f);    // drawing color is white
	teapotAngle = 0;
	teapotTranslate = 0;
					
	cam.setShape(50.0f, (float)screenWidth / screenHeight, 0.5f, 200.0f);// set the view volume shape ----
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f, (float)screenWidth / screenHeight, 0.5f, 200.0f);*/
	//---------------------------

	//make the initial camera
	cam.set(Point3(4, 4, 4), Point3(0, 0, 0), Vector3(0, 1, 0));
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	glEnable(GL_DEPTH_TEST);
	

	glLightfv(GL_LIGHT0,GL_AMBIENT,lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightIntensity);
}

void myIdle() {
	if (rotate) {
		litePos[0]= 0 + 5 * cos(2 * 3.14*i);
		litePos[2] = 0 + 5 * sin(2 * 3.14*i);
		i += 1;

		std::cout << litePos[0] << std::endl;
	}
	glutPostRedisplay();
}
//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>>>>>>>>>
void mySpecialKeyboard(int theKey, int mouseX, int mouseY)
{
	switch (theKey)
	{
	case GLUT_KEY_LEFT:
		std::cout << "Camera move left" << std::endl;
		cam.slide(-0.2, 0, 0);
		break;
	case GLUT_KEY_RIGHT:
		std::cout << "Camera move right" << std::endl;
		cam.slide(0.2, 0, 0);
		break;
	case GLUT_KEY_UP:
		std::cout << "Camera move up" << std::endl;
		cam.slide(0, 0.2, 0);
		break;
	case GLUT_KEY_DOWN:
		std::cout << "Camera move down" << std::endl;
		cam.slide(0, -0.2, 0);
		break;
	case GLUT_KEY_PAGE_UP:		// slide camera forward
		std::cout << "Camera zoom-in" << std::endl;
		cam.slide(0, 0, 0.2);
		break;
	case GLUT_KEY_PAGE_DOWN:
		// slide camera backward
		std::cout << "Camera zoom-out" << std::endl;
		cam.slide(0, 0, -0.2);
		break;
	default:
		break;
	}
	glutPostRedisplay(); // draw it again
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		std::cout << "Camera roll counter clock-wise " << std::endl;
		cam.roll(1.0);
		break; // roll the camera 
	case 'R':
		std::cout << "Camera roll clock-wise" << std::endl;
		cam.roll(-1.0);
		break; // roll the camera back	
	case 'p':
		std::cout << "Camera pitch up" << std::endl;
		// complete pitch function in camera.cpp and invoke cam.pitch() function
		cam.pitch(1.0);
		break;
	case 'P':
		std::cout << "Camera pitch down" << std::endl;
		cam.pitch(-1.0);
		// complete pitch function in camera.cpp and invoke cam.pitch() function
		break;
	case 'y':
		std::cout << "Camera yaw left" << std::endl;
		cam.yaw(1.0);
		// complete yaw function in camera.cpp and invoke cam.yaw() function
		break;
	case 'Y':
		std::cout << "Camera yaw right" << std::endl;
		cam.yaw(-1.0);
		// complete yaw function in camera.cpp and invoke cam.yaw() function
		break;
	case 'w':
		teapotTranslate += 1;
		break;
	case 'W':
		teapotTranslate -= 1;
		break;
	case 'e':
		teapotAngle += 1;
		break;
	case 'E':
		teapotAngle -= 1;
		break;
	case 'a':
	case 'A':
		rotate = !rotate;
		break;
	default:
		break;
	}
	glutPostRedisplay(); // draw it again
}


//<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
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
	glLightfv(GL_LIGHT0, GL_POSITION, litePos);
	glPushMatrix();
		GLfloat specular[] = { .628281, 0.555802f, 0.366065f, 1.0f };
		GLfloat ambient[] = { 0.24725f, 0.1995f, 0.0745f, 1.0f };
		GLfloat diffuse[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
		GLfloat shiny[] = { .4f * 128 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
		glTranslatef(teapotTranslate, 0, 0);
		glRotatef(teapotAngle, 0, 1,0);
		glutSolidTeapot(1.0); // draw the teapot
	glPopMatrix();
	glPushMatrix();
		GLfloat specular2[] = { 0.508273f, 0.508273f, 0.508273f, 1.0f };
		GLfloat ambient2[] = { 0.19225f, 0.19225f, 0.19225f, 1.0f };
		GLfloat diffuse2[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse2);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
		glTranslatef(teapotTranslate, 0, -2);
		glRotatef(teapotAngle, 0, 1, 0);
		glutSolidTeapot(1.0); // draw the teapot
	glPopMatrix();
	glutSwapBuffers();
}
//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Lab - Manipulate a camera around a teapot"); // open the screen window
	glutIdleFunc(myIdle);
																   // register callback functions
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecialKeyboard);
	glutDisplayFunc(myDisplay);

	myInit();

	glutMainLoop();

	return(0);
}