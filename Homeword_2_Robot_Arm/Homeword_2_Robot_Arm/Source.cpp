//Patrick Flinner
//304607711
//Date: 10/22/2017
//Assignment: Homework 2
#include "Source.h"


/*********** PROTOTYPES ***********/
void myInit(int shadingChoice, int colorChoice);
void drawAxes();
void drawBase();
void displayRobotArm();
void myKeyboard(unsigned char key, int x, int y);
void MySpecialKeyboard(int theKey, int mouseX, int mouseY);
void myIdle();
Vector ReflectVector(Vector velocity, Vector n);
Vector NormalizeVector(Vector normalize);
void CheckCollisionWall(Ball* ball);
void Animate();
//<<<<<<<<<< MAIN >>>>>>>>>>
int main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Robot Arm"); // open the screen window

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
	ball = new Ball(25, 210, 0, 0, 0, 0, 20);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // background is white

	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	cam.setShape(100.0f, (float)screenWidth/screenHeight , 0.5f, 500.0f);// set the view volume shape ----
	cam.set(Point3(250, 250, 250), Point3(0, 0, 0), Vector3(0, 1, 0));
}

//<<<<<<<<<< DRAWING FUNCTIONS >>>>>>>>>>

void displayRobotArm()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen
	
	glPushMatrix();
	if (throwing) {
		if (initialThrow) {
			glRotatef(90, 0, 1, 0);
			glRotatef(baseAngle, 0, 1, 0);
		}
		glTranslatef(ball->GetCenterX(), ball->GetCenterY(), ball->GetCenterZ());
		glutSolidSphere(ball->GetRadius(), 8, 20);
	}
	glPopMatrix();
	glPushMatrix();
	if(showAxis)drawAxes();

	glTranslatef(xMove, 0, zMove);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	GLUquadric *quad = gluNewQuadric();
	gluCylinder(quad, baseRadius, baseRadius, 10, 20, 8);
	glPopMatrix();
	
	glRotatef(90, 0, 1, 0);
	glRotatef(baseAngle, 0, 1, 0);
	
	arm.DrawArm();



	glPopMatrix();
	

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
	float theta = baseAngle*PI / 180;
	if (robotOn) {
		Hand hand=arm.GetHand();
		switch (key) {
		case 'w':
			animateCamera = false;
			xMove += 5 * cos(-1 * theta);
			zMove += 5 * sin(-1 * theta);
			break;
		case 'd':
			animateCamera = false;
			xMove -= 5 * cos(-1 * theta);
			zMove -= 5 * sin(-1 * theta);
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
		default:
			break;
		}
	}
		switch (key) {
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
		case 'a':
			if(!animate)arm = Arm();
			arm.ResetScale();
			animate = !animate;
			throwing = false;
			initialThrow = true;
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
			throwing = false;
			delete(ball);
			break;
		case 'q':
		case 'Q':
			animateCamera = false;
			exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
	glutPostRedisplay();

}
void MySpecialKeyboard(int theKey, int mouseX, int mouseY) {

	//Special function key presses
		switch (theKey){
		case GLUT_KEY_LEFT:
			std::cout << "Camera move left" << std::endl;
			cam.slide(-10, 0, 0);
			break;
		case GLUT_KEY_RIGHT:
			std::cout << "Camera move right" << std::endl;
			cam.slide(10, 0, 0);
			break;
		case GLUT_KEY_UP:
			std::cout << "Camera move up" << std::endl;
			cam.slide(0, 0.2, 0);
			break;
		case GLUT_KEY_DOWN:
			std::cout << "Camera move down" << std::endl;
			cam.slide(0, -0.2, 0);
			break;
		case GLUT_KEY_PAGE_UP:
			// slide camera forward
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
	glutPostRedisplay();
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
	if (animate) {
		Animate();
	}
	CheckCollisionWall(ball);
	ball->MoveCoordinate(1);
	glutPostRedisplay();
}

void Animate() {
	
	arm.SetAnimation(true);
	if (handInit<18) {
		arm.CloseHand();
		handInit++;
	}
	if (elbowInit < elbowTrigger) {
		arm.RotateElbowDown();
		elbowInit++;
	}
	if (shoulderInit < shoulderTrigger) {
		arm.RotateShoulderUp();
		shoulderInit++;
	}
	
	if (handInit >=18 && elbowInit >= elbowTrigger && shoulderInit >= shoulderTrigger) {
		if (handCount > 8)
		{
			arm.ScaleBall();
			handCount--;
		}
		else {
			
			if (elbowCount > 0) {
				arm.RotateElbowUp();
				elbowCount--;
			}
			if (shoulderCount > 0) {
				arm.RotateShoulderDown();
				shoulderCount--;
			}
			if (elbowCount == 0 && shoulderCount == 0) {
				arm.SetAnimation(false);
				animate = false;
				handInit = 0;
				elbowInit = 0;
				shoulderInit = 0;
				handCount = 18;
				elbowCount = 8;
				shoulderCount = 14;
				
				ball = new Ball(xMove, 210, zMove, 5, 5, 5, 20);
				throwing = true;
			}
		}
	}
	glutPostRedisplay();
}
//<<<<<<<< Collision Checkers >>>>>>>>>>>>

//Checks if a ball collides with a wall
void CheckCollisionWall(Ball* ball) {
	float x = ball->GetVelocity().GetX();
	float y = ball->GetVelocity().GetY();
	float z = ball->GetVelocity().GetZ();
	float radius = ball->GetRadius();
	Vector velocity = ball->GetVelocity();

	//If statements for all 4 sides of the screen
	if (ball->GetCenterX() + radius >= topWall) {
		if (DEBUG) {
			cout << "REFLECT RIGHT" << endl;
			cout << "OLD VELOCITY: " << x << " " << y << endl;
		}
		ball->SetCenter(topWall- radius, ball->GetCenterY(),ball->GetCenterZ());
		ball->SetVelocity(ReflectVector(velocity, Vector(topWall, 0,0)));
	}
	if (ball->GetCenterX() - radius <= bottomWall) {
		if (DEBUG) {
			cout << "REFLECT LEFT" << endl;
			cout << "OLD VELOCITY: " << x << " " << y << endl;
		}
		ball->SetCenter(bottomWall + radius, ball->GetCenterY(), ball->GetCenterZ());
		ball->SetVelocity(ReflectVector(velocity, Vector(bottomWall, 0,0)));
	}
	if (ball->GetCenterY() + radius >= roomCeiling) {
		if (DEBUG) {
			cout << "REFLECT TOP" << endl;
			cout << "OLD VELOCITY: " << x << " " << y << endl;
		}
		ball->SetCenter(ball->GetCenterX(), roomCeiling - radius, ball->GetCenterZ());
		ball->SetVelocity(ReflectVector(velocity, Vector(0,roomCeiling,0)));
	}
	if (ball->GetCenterY() - radius <= roomFloor) {
		if (DEBUG) {
			cout << "REFLECT BOTTOM" << endl;
			cout << "OLD VELOCITY: " << x << " " << y << endl;
		}
		ball->SetCenter(ball->GetCenterX(), roomFloor + radius, ball->GetCenterZ());
		ball->SetVelocity(ReflectVector(velocity, Vector(0,roomFloor,0)));
	}
	if (ball->GetCenterZ() + radius >= rightWall) {
		if (DEBUG) {
			cout << "REFLECT TOP" << endl;
			cout << "OLD VELOCITY: " << x << " " << y << endl;
		}
		ball->SetCenter(ball->GetCenterX(), ball->GetCenterY(), rightWall - radius);
		ball->SetVelocity(ReflectVector(velocity, Vector(0, 0, rightWall)));
	}
	if (ball->GetCenterZ() - radius <= leftWall) {
		if (DEBUG) {
			cout << "REFLECT BOTTOM" << endl;
			cout << "OLD VELOCITY: " << x << " " << y << endl;
		}
		ball->SetCenter(ball->GetCenterX(), ball->GetCenterY(), leftWall + radius);
		ball->SetVelocity(ReflectVector(velocity, Vector(0, 0, leftWall)));
	}
}

//<<<<<<<<<<< VECTOR MATH >>>>>>>>>>>
//Normalizes the vector (x/sqrt(x^2+y^2),y/sqrt(x^2+y^2))
Vector NormalizeVector(Vector normalize)
{
	Vector normalized;
	float magnitude;
	magnitude = sqrt(pow(normalize.GetX(), 2) + pow(normalize.GetY(), 2)+ pow(normalize.GetZ(), 2));
	normalized.SetX(normalize.GetX() / magnitude);
	normalized.SetY(normalize.GetY() / magnitude);
	normalized.SetZ(normalize.GetZ() / magnitude);
	if (DEBUG)cout << "NORMALIZED: " << normalized.GetX() << " " << normalized.GetY()<< " " << normalized.GetZ() << endl;
	return normalized;
}

//Formula for reflecting a vector. Used when a ball contacts a wall
//r=a-2(a*n)n
Vector ReflectVector(Vector velocity, Vector n)
{
	Vector r;
	Vector a;
	float base;

	base = velocity*NormalizeVector(n);
	if (DEBUG)cout << "BASE: " << base << endl;
	base = base * 2;
	if (DEBUG)cout << "BASE2: " << base << endl;
	a = NormalizeVector(n)*base;
	if (DEBUG)cout << "A: " << a.GetX() << " " << a.GetY() << endl;
	r = velocity - a;

	return r;
}
