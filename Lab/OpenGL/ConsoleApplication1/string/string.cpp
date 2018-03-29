#include "stdafx.h"
#include <windows.h>
//#include <gl.h>
#include <glut.h>

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawText(int xPos, int yPos, char str[])
{
	glRasterPos2i(xPos, yPos); //Position

	void * font = GLUT_BITMAP_9_BY_15;

	for (int i = 0; i<strlen(str); i++)
		glutBitmapCharacter(font, str[i]);
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0); // Red
	drawText(100, 300, "OpenGL - OPEN GRAPHICS LANGUAGE");
	glFlush();
}

int _tmain(int argc, _TCHAR* argv[])
{

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode
	glutInitWindowSize(640, 480); //set window size
	glutInitWindowPosition(100, 150); //set window position on screen
	glutCreateWindow("Output Text"); // open the screen window

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}