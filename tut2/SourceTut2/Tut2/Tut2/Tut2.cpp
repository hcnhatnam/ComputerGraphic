// Tut2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include<math.h>

#define PI 3.1415926

void setCameraVolume(float l, float r, float b, float t) {//Khung hình
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
}

void setViewport(int l, int r, int b, int t) {
	glViewport(l, b, r - l, t - b);
}

void drawArcs() {
	/*glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	setViewport(0, 5, 0, 5);*/
	glColor3f(0.0, 0, 0);
	glLineWidth(3);
	float R = 0.5;
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 90; i++) {
		float x = R*cos(i*PI / 180.0);
		float y = R*sin(i*PI / 180.0);
		glVertex2f(x, y);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (int i = 180; i <= 270; i++) {
		float x = R*cos(i*PI / 180.0) + 1;
		float y = R*sin(i*PI / 180.0) + 1;
		glVertex2f(x, y);
	}
	glEnd();

	glFlush();
}

void Cau2() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	/*
	setCameraVolume(0, 1, 0, 1);
	glViewport(0,0, 60, 60);
	drawArcs();

	glViewport(0, 60, 60, 60);
	drawArcs();
	setCameraVolume(1, 0, 0, 1);
	glViewport(60, 0, 60, 60);
	drawArcs();
	*/
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++) {
			glViewport(i * 60, j * 60, 60, 60);
			setCameraVolume((i * 6 + 3 * j) % 11 % 2, ((i * 6 + 3 * j) % 11 + 1) % 2, (3 * i + 8 * j) % 10 % 2, ((3 * i + 8 * j) % 10 + 1) % 2);
			//setCameraVolume(1, 0, 0, 1);
			
			drawArcs();
		}
}


void drawArrow(float x) {
	glColor3f(1.0, 0, 0);
	//glLineWidth(3);
	glBegin(GL_POLYGON);
		glVertex2f(x, 1);
		glVertex2f(1, x);
		glVertex2f(1 - x, 0);
		glVertex2f(0, 1 - x);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1, 3 * x);
		glVertex2f(1, 0);
		glVertex2f(1 - 3 * x, 0);
	glEnd();

	glFlush();
}
void rotated2D(double angle) {
	glMatrixMode(GL_MODELVIEW);
	glRotated(angle, 0, 0, 1.0);
}
void supportCau3(float positionX, float positionY) {
	glViewport(positionX, positionY, 150, 150);
	setCameraVolume(1, 0, 0, 1);
	drawArrow(0.3);
	
	glViewport(positionX+150, positionY, 150, 150);
	setCameraVolume(1, 0, 1, 0);
	drawArrow(0.3);
	glViewport(positionX, positionY+150, 150, 150);
	setCameraVolume(0, 1, 0, 1);
	drawArrow(0.3);
	glViewport(positionX+150, positionY+150, 150, 150);
	setCameraVolume(0, 1, 1, 0);
	drawArrow(0.3);
}
void Cau3()
{
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	supportCau3(0,300);
	supportCau3(300,300);
	supportCau3(0,0);
	supportCau3(300,0);
	glFlush;
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("simple");
	glutDisplayFunc(Cau3);
	glutMainLoop();
	return 0;
}

