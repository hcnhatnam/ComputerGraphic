// tut1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#define  pointSize  10
#define PI 3.14159265


void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2);
void drawTriangle(float x1, float y1, float len, float angle);
void Cau234();
void Cau51();
void drawSquare(float x1, float y1, float len, float angle);
void Cau52();
void draw10edge(float x1, float y1, float len, float angle);
enum {CAU234, CAU51, CAU52, QUIT};

void menu(int choice) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	switch (choice) {
	case CAU234:
		Cau234();
		break;
	case CAU51:
		Cau51();
		break;
	case CAU52:
		Cau52();
		break;
	case QUIT:
		exit(0);
		break;
	default:
		break;
	}
	glFlush();
}

void createMenu() {
	int	m = glutCreateMenu(menu); 
	glutAddMenuEntry("Cau 234", CAU234);
	glutAddMenuEntry("Cau 5.1", CAU51);
	glutAddMenuEntry("Cau 5.2", CAU52);
	glutAddMenuEntry("Quit", QUIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


class GLfloatPoint {
public:
	float x;
	float y;
};
void init() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}

float size = 20;
void drawDot(float x, float y) {
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(pointSize);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}


void Cau234(){
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i=0;i<360;i+=36)
		drawTriangle(0, 0, 3, i);
}

void Cau51() {
	for (int i = 0; i < 360; i += 30)
		drawSquare(0, 0, 3.0, i);
}
void Cau52() {
	for (int i = 0; i < 360; i += 30)
		draw10edge(0, 0, 1, i);
}
void draw10edge(float x1, float y1, float len, float angle) {
	GLfloatPoint arrPoint[11] = { { x1,y1 } };
	for (int i = 0; i < 10; i++)
	{
		drawLine(arrPoint[i].x, arrPoint[i].y, len, angle + 36 * i, arrPoint[i + 1].x, arrPoint[i + 1].y);
	}
}
void drawSquare(float x1, float y1, float len, float angle) {
	GLfloatPoint arrPoint[11] = { { x1,y1 } };
	for (int i = 0; i < 10; i++)
		drawLine(arrPoint[i].x, arrPoint[i].y, len, angle + 90 * i, arrPoint[i + 1].x, arrPoint[i + 1].y);
}
void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2) {
	x2 = len*cos(angle*PI/180.0) + x1;
	y2 = len*sin(angle*PI / 180.0) + y1;
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	glEnd();
	glFlush();
}

void drawTriangle(float x1, float y1,float len, float angle) {
	GLfloatPoint arrPoint[11] = { { x1,y1 } };
	for (int i = 0; i < 10; i++)
		drawLine(arrPoint[i].x, arrPoint[i].y, len, angle + 120 * i, arrPoint[i + 1].x, arrPoint[i + 1].y);
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("simple");
	createMenu();
	glutDisplayFunc(Cau234);
	init();
	glutMainLoop();
}


