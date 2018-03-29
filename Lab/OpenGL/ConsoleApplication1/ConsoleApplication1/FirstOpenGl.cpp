#include "stdafx.h"
#include <windows.h>
//#include <gl.h>
#include <glut.h>

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(9.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(289, 190); // Dubhe
	glVertex2i(320, 128); // Merak
	glVertex2i(239, 67); // Phecda
	glVertex2i(194, 101); // Megrez
	glVertex2i(129, 83); // Alioth
	glVertex2i(75, 73); // Mizar
	glVertex2i(74, 74); // Alcor
	glVertex2i(20, 20); // Alkaid

	glEnd();
	glFlush();
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(640, 480); //set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("The Big Dipper");//open the screen window
		
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}