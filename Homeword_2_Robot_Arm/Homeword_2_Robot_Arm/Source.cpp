//Patrick Flinner
//304607711

#include "Source.h"


/*********** PROTOTYPES ***********/
void myInit(int shadingChoice, int colorChoice);
void drawAxes();
void drawBase();
void displayRobotArm();
void myKeyboard(unsigned char key, int x, int y);
void myIdle();

//<<<<<<<<<< MAIN >>>>>>>>>>
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

	myInit(shadingChoice, colorChoice);

	glutDisplayFunc(displayRobotArm);
	glutKeyboardFunc(myKeyboard);

	glutMainLoop();

	return(0);
}
//<<<<<<<<< INITIALIZERS >>>>>>>>>>
void myInit(int shadingChoice, int colorChoice)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // background is white

	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	glOrtho(-(worldWidth / 2), (worldWidth / 2), -(worldHeight / 2), (worldHeight / 2), -(worldHeight / 2), (worldHeight / 2));
}

//<<<<<<<<<< DRAWING FUNCTIONS >>>>>>>>>>

void displayRobotArm()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, lookx, looky, lookz, 0.0, 1.0, 0.0);
	glPushMatrix();
	drawAxes();

	hand.DrawHand();
	glPopMatrix();
	glutSwapBuffers();
}

void drawAxes()
{
	glBegin(GL_LINES);
	//x
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(250, 0, 0);
	//y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 250, 0);
	//z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 250);
	glEnd();
}

void drawBase() {

}

//<<<<<<<<<< USER INPUT FUNCTIONS >>>>>>>>>>
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
	case 'm':
		hand.CloseHand();
		break;
	case 'M':
		hand.OpenHand();
		break;
	case 'n':
		hand.RotateWristDownX();
		break;
	case 'N':
		hand.RotateWristUpX();
		break;
	default:
		break;
	}

	glutPostRedisplay();

}
void myIdle() {

	glutPostRedisplay();
}
