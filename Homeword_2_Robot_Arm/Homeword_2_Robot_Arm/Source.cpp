//Patrick Flinner
//304607711

#include <windows.h>  //suitable when using Windows 95/98/NT
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <iostream>


#include "Source.h"

void myInit(int shadingChoice, int colorChoice)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	if (shadingChoice == 0) {
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	}
	else if (shadingChoice == 1) {
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	}

	if (colorChoice == 1) {
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);
	}


	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // background is white

	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	glOrtho(-3.5*worldWidth / worldHeight, 3.5*worldWidth / worldHeight, -3.5, 3.5, 0.1, 100);
}


void drawAxes()
{
	glBegin(GL_LINES);
	//x
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	//y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 100, 0);
	//z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 100);
	glEnd();
}

void drawSun()
{	// Sun
	glPushMatrix();
	glRotatef(sunRotation, 0, 1, 0);
	glColor3f(1.0f, 0.5f, 0.0f);    // sun is orange
	glutSolidSphere(0.5, 20, 16);	// locate the sun at the origin
	glPopMatrix();
}

void drawEarthAndMoon()
{
	// Earth
	glColor3f(0.0f, 1.0f, 0.0f); // earth is green
	glPushMatrix();
	glRotatef(earthRotation, 0, 1, 0);
	glTranslated(0, 0, 2);
	// Moon
	glColor3f(0.5f, 0.5f, 0.5f);
	glPushMatrix();

	glRotatef(moonRotation, 0, 1, 0);
	glTranslated(0, 0, .3);
	glRotatef(moonRevolution, 0, 1, 0);
	glutSolidSphere(0.05, 10, 4);
	glPopMatrix();


	glRotatef(earthRevolution, 0, 1, 0);
	glutSolidSphere(0.2, 20, 8);
	glPopMatrix();
}

void drawMars()
{
	// Mars
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glRotatef(marsRotation, 0, 1, 0);
	glTranslated(0, 0, 3);
	glRotatef(marsRevolution, 0, 1, 0);
	glutSolidSphere(0.15, 20, 8);
	glPopMatrix();
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< displayWire >>>>>>>>>>>>>>>>>>>>>>
void displaySolarSystem()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, lookx, looky, lookz, 0.0, 1.0, 0.0);
	glPushMatrix();
	drawAxes();
	drawSun();
	drawEarthAndMoon();
	drawMars();
	glPopMatrix();
	glutSwapBuffers();
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'v':
		view++;
		view %= 3;
		if (view == 0) {
			eyex = 25;
			eyey = 25;
			eyez = 25;
		}
		else if (view == 1) {
			eyex = 25;
			eyey = 0;
			eyez = 0;
		}
		else if (view == 2) {
			eyex = 0;
			eyey = 25;
			eyez = 25;
		}
		break;
	case 'r':
		rotateCamera = !rotateCamera;
		break;
	default:
		break;
	}

	glutPostRedisplay();

}
void myIdle() {

	if (!rotateCamera) {
		sunRotation += 10;
		earthRotation += 1;
		earthRevolution += 2;
		moonRotation += 2;
		moonRevolution += 4;
		marsRotation += .5;
		marsRevolution += 1;

	}
	else {

		eyex = centerX + width * cos(2 * PI*i);
		eyez = centerY + height * sin(2 * PI*i);
		i += 50;
	}
	glutPostRedisplay();
}
//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Inner Solar System"); // open the screen window

	glutIdleFunc(myIdle);
	int shadingChoice = 0;
	int colorChoice = 0;
	std::cout << "Enter Shading Choice (0 for Diffuse, 1 for Specular):\n";
	std::cin >> shadingChoice;

	std::cout << "Enter Color Option (0 for No Color, 1 for Color):\n";
	std::cin >> colorChoice;

	myInit(shadingChoice, colorChoice);

	glutDisplayFunc(displaySolarSystem);
	glutKeyboardFunc(myKeyboard);

	glutMainLoop();

	return(0);
}