// DrawPolygon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <glut.h>
#define screenHeight 480
#define screenWidth 640

#define sizeRand 100000
int pointSize = 1;
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
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	/*glBegin(GL_POINTS);
		for (int i = 0; i < sizeRand; i++)
		{
			glVertex2i(rand()%screenWidth, rand()%screenHeight);
		}
	glEnd();
	

	for (int i = 0; i < sizeRand; i++)
	{
		Sleep(1);
		if (i>1000)
		{
			pointSize++;
		}
		drawDot(rand() % screenWidth, rand() % screenHeight);
	}
	
	GLintPoint pt[11];
	pt[0].x = 495;
	pt[0].y = 55;
	pt[1].x = 514;
	pt[1].y = 55;
	pt[2].x = 520;
	pt[2].y = 40;
	pt[3].x = 526;
	pt[3].y = 55;
	pt[4].x = 550;
	pt[4].y = 55;
	pt[5].x = 530;
	pt[5].y = 65;
	pt[6].x = 540;
	pt[6].y = 85;
	pt[7].x = 520;
	pt[7].y = 72;
	pt[8].x = 500;
	pt[8].y = 85;
	pt[9].x = 510;
	pt[9].y = 65;
	pt[10].x = 495;
	pt[10].y = 55;
	glBegin(GL_LINES);
	for (int i = 0; i < sizeof(pt); i++)
	{
		glVertex2i(pt[i].x,pt[i].y);
	}
	glEnd();*/

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Cloud Random");//open the screen window

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
