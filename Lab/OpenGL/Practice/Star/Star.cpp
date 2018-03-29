// DrawPolygon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#define screenHeight 480
#define screenWidth 640
#define pointSize	2

class GLintPoint {
public:
	GLint x;
	GLint y;
};

void drawDot(GLint x, GLint  y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void myInit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(pointSize);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
int R = 100;
double pi = 3.1415926535897;
int x=500, y=500;
void drawStar() {
	glBegin(GL_LINES);
	for (int i=0;i<5;i++)
	{
		glVertex2i(x = x*cos(72 * pi / 180.0), y = y*sin(72 * pi / 180.0));
		glVertex2i(x = x*cos(72 * pi / 180.0), y = y*sin(72 * pi / 180.0));
	}
	glEnd();
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawStar();
	glFlush();
}

void myMouse(int button, int state, int x, int y) {
	static GLintPoint _lastPoint = { x,y };
	drawDot(x, screenHeight - y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		glBegin(GL_LINES);
		glVertex2i(_lastPoint.x, screenHeight - _lastPoint.y);
		glVertex2i(x, screenHeight - y);
		glEnd();
		_lastPoint = { x,y };
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		exit(-1);
	}
}

int main(int argc, char ** argv)
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("The Big Dipper");//open the screen window

	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
	return 0;
}
