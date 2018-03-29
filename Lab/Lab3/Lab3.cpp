// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <math.h>
#include <iostream>
#include "supportClass.h"
#include "Mesh.h"

using namespace std;

#define PI			3.1415926

int		screenWidth = 600;
int		screenHeight= 600;

bool	bWireFrame = false;

float	baseRadius = 0.8;
float	baseHeight = 0.2;
float	baseRotateStep = 5;

float	columnSizeX = 0.25;
float	columnSizeZ = columnSizeX;
float	columnSizeY = 5;

Mesh	base;
Mesh	column;


void myKeyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
	case '1':
		base.rotateY += baseRotateStep;
		if(base.rotateY > 360)
			base.rotateY -=360;
		break;
	case '2':
		base.rotateY -= baseRotateStep;
		if(base.rotateY < 0)
			base.rotateY +=360;
		break;
	}
    glutPostRedisplay();
}
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

void drawBase()
{
	glPushMatrix();

		glTranslated(0, baseHeight/2.0, 0);
		glRotatef(base.rotateY, 0, 1, 0);

		if(bWireFrame)
			base.DrawWireframe();
		else
			base.DrawColor();

	glPopMatrix();
}
void drawColumn()
{
	glPushMatrix();

		glTranslated(0, baseHeight/2.0 + columnSizeY/2, 0);
		glRotatef(base.rotateY, 0, 1, 0);

		if(bWireFrame)
			column.DrawWireframe();
		else
			column.DrawColor();

	glPopMatrix();
}

void myDisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(6, 4, 6, 0, 1, 0, 0, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, screenWidth, screenHeight);

	drawAxis();

	drawBase();
	drawColumn();

	glFlush();
    glutSwapBuffers();
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

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGB | GLUT_DEPTH);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Lab 3 - Demo (2017-2018)"); // open the screen window

	base.CreateCylinder(20, baseHeight, baseRadius);
	base.SetColor(6);

	column.CreateCuboid(columnSizeZ, columnSizeY, columnSizeZ);
	column.SetColor(1);

	myInit();

	glutKeyboardFunc(myKeyboard);
    glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}

