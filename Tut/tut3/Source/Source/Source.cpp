#include"stdafx.h"
#include <glut.h>
#include<time.h>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#define PI			3.1415926

int		screenWidth = 600;
int		screenHeight = 600;
using namespace std;
time_t rawtime;
struct tm * timeinfo;
void drawAxis()
{
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);//x
	glVertex3f(4, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);//y
	glVertex3f(0, 4, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);//z
	glVertex3f(0, 0, 4);
	glEnd();
}
void myInit()
{
	float	fHalfSize = 4;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}

int radius = 3;
void drawPoint() {
	glColor3f(0.0, 0.0, 0.0);
	
	for (int i = 0; i < 360; i+=30)
	{
		glPushMatrix();
		glRotated(i,0,0,1);
		glTranslated(0, radius, 0);
		glutSolidSphere(0.1f, 15, 15);
		//glutWireSphere(0.1f, 15, 15);
		glPopMatrix();
	}
	
}
int lenghtArrow = 3;
int angle =0;
void drawArrow(float lenghtArrow,float angle) {
	glPushMatrix();
	glRotated(-angle,0, 0, 1);
	glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(0, lenghtArrow, 0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(-0.1, lenghtArrow, 0);
		glVertex3f(0, lenghtArrow+0.5, 0);
		glVertex3f(0.1, lenghtArrow, 0);
	glEnd();
	glPopMatrix();
}

void processTimer(int value) {
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	glutTimerFunc(10, processTimer, value);
	glutPostRedisplay();
}
void myDisplay() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(6, 4, 6, 0, 1, 0, 0, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, screenWidth, screenHeight);

	//drawAxis();
	drawPoint();
	//seconds//Red
	glColor3f(1.0, 0.0, 0.0);
	drawArrow(2.2, (timeinfo->tm_sec) * 6);
	//Minute//Green
	glColor3f(0.0, 1.0, 0.0);
	drawArrow(1.7, (timeinfo->tm_min) * 6);
	//Hour
	glColor3f(0.0, 0.0, 1.0);
	drawArrow(1.3, (timeinfo->tm_hour)  * 30+ (timeinfo->tm_min)*0.5);
	glFlush();
	glutSwapBuffers();
}
int main(int argc, char** argv) {
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Lab 3 - Demo (2017-2018)"); // open the screen window
	myInit();
	
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	
	glutDisplayFunc(myDisplay);
	glutTimerFunc(10, processTimer, 10);
	glutMainLoop();
	return 0;
}
