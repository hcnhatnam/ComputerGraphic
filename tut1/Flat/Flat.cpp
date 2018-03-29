// tut1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#define  pointSize  10
#define PI 3.14159265

void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2);
void drawFlat(float x1, float y1, float len, float angle);

float chieucao = 400, chieurong = 600;
void init() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(-chieurong/2, chieurong/2.0, -chieucao/2.0, chieucao/2.0, -5.0, 5.0);
}

void Cau2() {
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < 360; i += 72)
	{
		drawFlat(0, 0, chieucao/3, i);
	}
	glFlush();
}
void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2) {
	x2 = len*cos(angle*PI / 180.0) + x1;
	y2 = len*sin(angle*PI / 180.0) + y1;
}
void drawFlat(float x1, float y1, float len, float angle) {

	float x2, y2, x3, y3,x4,y4;
	float canhngan = len*sin(18 * PI / 180) / sin(126 * PI / 180);
	float canhdai = len*sin(36 * PI / 180) / sin(126 * PI / 180);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	drawLine(x1, y1, canhngan, angle + 54, x2, y2);
	glVertex2f(x2, y2);
	drawLine(x2, y2, canhdai, angle + 108, x3, y3);
	glVertex2f(x3, y3);
	drawLine(x3, y3, canhdai, angle + 252, x4, y4);
	glVertex2f(x4, y4);
	glEnd();
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(chieurong, chieucao);
	glutCreateWindow("simple");
	glutDisplayFunc(Cau2);
	init();
	glutMainLoop();
}

