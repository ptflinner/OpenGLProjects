//Patrick Flinner
//304607711

#include "Source.h"


/*********** PROTOTYPES ***********/
void myInit(int shadingChoice, int colorChoice);
void drawAxes();
void drawBase();
void displayRobotArm();
void myKeyboard(unsigned char key, int x, int y);
void MySpecialKeyboard(int theKey, int mouseX, int mouseY);
void MoveArm();
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
	glutSpecialFunc(MySpecialKeyboard);				// Special Keyboard Keys

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
	glOrtho(-(worldWidth / 2), (worldWidth / 2), -(worldHeight / 2), (worldHeight / 2), -500,500);
}

//<<<<<<<<<< DRAWING FUNCTIONS >>>>>>>>>>

void displayRobotArm()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, lookx, looky, lookz, 0.0, 1.0, 0.0);
	glPushMatrix();
	if(showAxis)drawAxes();

	glTranslatef(xMove, 0, zMove);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	GLUquadric *quad = gluNewQuadric();
	gluCylinder(quad, baseRadius, baseRadius, 10, 20, 8);
	glPopMatrix();
	
	glRotatef(baseAngle, 0, 1, 0);
	
	arm.DrawArm();

	glPopMatrix();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	for (double t = 0; t < 1; t += .01) {
		float x = xMove + baseRadius*cos(2 * PI*t);
		float z = zMove + baseRadius*sin(2 * PI*t);
		glVertex3f(x, 0, z);
	}
	glEnd();
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
	if (robotOn) {
		Hand hand=arm.GetHand();
		switch (key) {
		case 'a':
			break;
		case 's':
			animateCamera = !animateCamera;
			break;
		case 'c':
			animateCamera = false;
			showAxis = !showAxis;
			break;
		case 'v':
			animateCamera = false;
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
			animateCamera = false;
			arm.CloseHand();
			break;
		case 'M':
			animateCamera = false;
			arm.OpenHand();
			break;
		case 'n':
			animateCamera = false;
			arm.RotateWristDownX();
			break;
		case 'N':
			animateCamera = false;
			arm.RotateWristUpX();
			break;
		case 'o':
			animateCamera = false;
			robotOn = !robotOn;
			break;
		case 'i':
			animateCamera = false;
			arm.RotateShoulderDown();
			break;
		case 'I':
			animateCamera = false;
			arm.RotateShoulderUp();
			break;
		case 'j':
			animateCamera = false;
			arm.RotateElbowDown();
			break;
		case 'J':
			animateCamera = false;
			arm.RotateElbowUp();
			break;
		case 'r':
			animateCamera = false;
			if (robotOn) {
				baseAngle += 5;
			}
			break;
		case 'R':
			animateCamera = false;
			if (robotOn) {
				baseAngle -= 5;
			}
			break;
		case 'u':
			animateCamera = false;
			if (filled) {
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				filled = !filled;
			}
			else {
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				filled = !filled;
			}
			break;
		case 27:
			animateCamera = false;
			arm = Arm();
			xMove = 0;
			zMove = 0;
			break;
		case 'q':
		case 'Q':
			animateCamera = false;
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
	}
	else {
		switch (key) {
		case 'a':
			break;
		case 's':
			animateCamera = !animateCamera;
			break;
		case 'o':
			animateCamera = false;
			robotOn = !robotOn;
			break;
		case 'c':
			animateCamera = false;
			showAxis = !showAxis;
			break;
		case 'u':
			animateCamera = false;
			if (filled) {
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				filled = !filled;
			}
			else {
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				filled = !filled;
			}
			break;
		case 27:
			animateCamera = false;
			arm = Arm();
			xMove = 0;
			zMove = 0;
			break;
		case 'q':
		case 'Q':
			animateCamera = false;
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}

	}
	

	glutPostRedisplay();

}
void MySpecialKeyboard(int theKey, int mouseX, int mouseY) {

	//Special function key presses
	if (robotOn) {
		switch (theKey){
		case GLUT_KEY_UP:
			animateCamera = false;
			total += distance;
			MoveArm();
			break;
		case GLUT_KEY_DOWN:
			animateCamera = false;
			total -= distance;
			MoveArm();
			break;
		default:
			break;
		}

	}
}
void MoveArm() {
	float x;
	float z;
	x = total*sin(baseAngle);
	z = total*cos(baseAngle);

	xMove += x;
	zMove += z;
}
void myIdle() {

	if (animateCamera) {
		eyex = centerX + width * cos(2 * PI*i);
		eyez = centerY + width * sin(2 * PI*i);
		i += 50;
	}
	else {
		eyex = initEyeX;
		eyey = initEyeY;
		eyez = initEyeZ;
	}
	glutPostRedisplay();
}
