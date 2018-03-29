// tut1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#define  pointSize  3	
#define PI 3.14159265

void drawSquareCaro(float x1, float y1, float len);
class GLfloatPoint {
public:
	float x;
	float y;
};
float chieucao = 400, chieurong = 400;
void init() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(-chieurong / 2, chieurong / 2.0, -chieucao / 2.0, chieucao / 2.0, -5.0, 5.0);
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
void Cau2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	for (int i = -chieurong/2; i <= chieurong/2; i += size)
		for (int j = -chieucao/2; j < chieucao/2; j+=size)
			drawSquareCaro(i, j, size);
	//drawDot(0, 0);

	float temp=3;
	for (int x1 = -chieurong / 2; x1 <= chieurong / 2; x1 += size)
		for (int y1 = -chieucao / 2; y1 <= chieucao / 2; y1 += size)
		{
			GLfloatPoint arrPoint[4] = { {x1 + temp,y1 + temp},{x1 + size - temp,y1 + temp},{x1 + size - temp,y1 + size - temp},{x1+temp,y1+size-temp} };
			for (int i=0;i<4;i++)
			{
				if (pow(arrPoint[i].x, 2) + pow(arrPoint[i].y, 2) <= pow(120, 2) && pow(arrPoint[i].x, 2) + pow(arrPoint[i].y, 2) >= pow(120 - 11 , 2))
					drawDot(arrPoint[i].x, arrPoint[i].y);
			}
		}
	glFlush();
}

void drawSquareCaro(float x1, float y1, float len) {
	GLfloatPoint arrPoint[11] = { { x1,y1 } };
	if (((int)(x1 / len) + (int)(y1 / len)) % 2 == 0) {
		glColor3f(0.0f, 0.0f, 0.0f);
	}
	else 
		glColor3f(1.0f, 1.0f, 1.0f);
	
	
	glBegin(GL_POLYGON);
	glVertex2f(arrPoint[0].x, arrPoint[0].y);
	for (int i = 1; i < 4; i++)
	{
		arrPoint[i].x = len*cos(90 * i*PI / 180.0) + arrPoint[i - 1].x;
		arrPoint[i].y = len*sin(90 * i * PI / 180.0) + arrPoint[i - 1].y;
		glVertex2f(arrPoint[i].x,arrPoint[i].y);
	}
	glEnd();
	glFlush();


}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(chieurong, chieucao);
	glutCreateWindow("simple");
	glutDisplayFunc(Cau2);
	init();
	glutMainLoop();
}

