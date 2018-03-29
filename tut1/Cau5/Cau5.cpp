// tut1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#define  pointSize  10
#define PI 3.14159265

void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2);
void drawSquare(float x1, float y1, float len, float angle);
class GLfloatPoint {
public:
	float x;
	float y;
};
void init() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}

void Cau2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(pointSize);
	glBegin(GL_POINTS);
	glVertex2f(0, 0);
	glEnd();
	glFlush();
	float x2, y2;
	for (int i = 0; i < 360; i += 30)
	{
		drawSquare(0, 0, 3.0, i);
	}
	glFlush();
}
void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2) {
	x2 = len*cos(angle*PI / 180.0) + x1;
	float temp = cos(angle*PI / 180.0);
	y2 = len*sin(angle*PI / 180.0) + y1;
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
	glFlush();
}

void drawSquare(float x1, float y1, float len, float angle) {
	GLfloatPoint arrPoint[11] = { { x1,y1 } };
	for (int i = 0; i < 10; i++)
	{
		drawLine(arrPoint[i].x, arrPoint[i].y, len, angle + 90 * i, arrPoint[i + 1].x, arrPoint[i + 1].y);
	}
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("simple");

	glutDisplayFunc(Cau2);
	init();
	glutMainLoop();
}

