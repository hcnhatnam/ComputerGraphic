// DrawPolygon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <glut.h>
#define screenHeight 480
#define screenWidth 640
#define pointSize	10

class GLintPoint {
public:
	GLint x;
	GLint y;
};


void deletePoint(int, int);
void movePoint(int , int );
void drawAllLinesAndDot(std::vector<GLintPoint>);


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
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

bool _reset = true;
GLintPoint _lastPoint;
std::vector<GLintPoint> Point;
void myMouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_RIGHT_BUTTON)
		{
			_reset = true;
			glFlush();
			return;
		}
		drawDot(x, screenHeight - y);
		Point.push_back({ x, y });
		if (!_reset&&button == GLUT_LEFT_BUTTON) {

			glBegin(GL_LINES);
			glVertex2i(_lastPoint.x, screenHeight - _lastPoint.y);
			glVertex2i(x, screenHeight - y);
			glEnd();
		}
		else {
			_reset = false;
		}
		_lastPoint = { x,y };
		glFlush();
	}
}
void markPoint(unsigned char key,int x,int y) {
	if (key == 'o')
	{
		_reset = true;
		glFlush();
		return;
	}
	drawDot(x, screenHeight - y);
	Point.push_back({ x, y });
	if (!_reset&&key == 'p') {

		glBegin(GL_LINES);
		glVertex2i(_lastPoint.x, screenHeight - _lastPoint.y);
		glVertex2i(x, screenHeight - y);
		glEnd();
	}
	else {
		_reset = false;
	}
	_lastPoint = { x,y };
	glFlush();
}
void myKeyboard(unsigned char key,int x,int y) {
	switch (key)
	{
	case 'p':
	case 'o':
		markPoint(key, x, y);
		break;
	case 'd':
		if (Point.size()>0)
		{
			deletePoint(x, y);
		}
		break;
	case 'm':
		if (Point.size()>0)
		{
			movePoint(x, y);
		}
		break;
	case 'r':
		drawAllLinesAndDot(Point);
		break;
	case 'q':
		exit(1);
		break;
	default:
		break;
	}
}

void myMotion(int x,int y) {
	if (Point.size>=1)
	{
		movePoint(x, y);
		glutSwapBuffers();
	}

}

float distance(GLintPoint p1, GLintPoint p2) {
	return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}
void drawAllLinesAndDot(std::vector<GLintPoint> listPoint) {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i=0;i<listPoint.size();i++)
	{
		drawDot(listPoint[i].x,screenHeight- listPoint[i].y);
	}
	if (listPoint.size() != 1)
	{
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < listPoint.size(); i++)
		{
			glVertex2i(listPoint[i].x, screenHeight - listPoint[i].y);
		}
		glEnd();
		glFlush();
	}
}
int searchPointNearest(std::vector<GLintPoint> listPoint, int x, int y) {
	float min = distance(GLintPoint{ x,y }, Point[0]);
	int result = 0;
	for (int i = 1; i < Point.size(); i++)
	{
		float dis = distance(GLintPoint{ x,y }, Point[i]);
		if (dis < min)
		{
			min = dis;
			result = i;
		}
	}
	return result;
}
void movePoint(int x, int y) {
	int result = searchPointNearest(Point, x, y);
	Point[result] = GLintPoint{ x,y };
	if (result==Point.size()-1)
	{
		_lastPoint = GLintPoint{ x,y };
	}
	drawAllLinesAndDot(Point);
}
void deletePoint(int x,int y) {
	int result = searchPointNearest(Point, x, y);
	Point.erase(Point.begin() + result, Point.begin() + result+1);
	if (Point.size() == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		_reset = true;
		return;
	}
	drawAllLinesAndDot(Point);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("The Big Dipper");//open the screen window

	glutDisplayFunc(myDisplay);
	//glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutMotionFunc(myMotion);
	myInit();
	glutMainLoop();
	return 0;
}
