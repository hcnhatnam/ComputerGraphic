// Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<glut.h>

#define screenHeight 480
#define screenWidth 640
#define pointSize	2

class GLintPoint {
public:
	GLint x;
	GLint y;
};

void drawDot(GLint x,GLint  y) {
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
GLintPoint Point[3];
void myMouse(int button,int state,int x,int y) {
	static int numberPoint = -1;
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		numberPoint++;
		Point[numberPoint].x = x;
		Point[numberPoint].y = y;
		if (numberPoint == 2) {
			glBegin(GL_LINE_LOOP);
			
				glVertex2i(Point[0].x,screenHeight- Point[0].y);
				glVertex2i(Point[1].x, screenHeight - Point[1].y);
				glVertex2i(Point[2].x, screenHeight - Point[2].y);
			glEnd();
			numberPoint = -1;
		}		
		drawDot(x,screenHeight- y);
	}
	else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN  ) {
		exit(-1);
	}
}
void myMouseMove(int x, int y) {
	drawDot(x, screenHeight - y);
}
int main(int argc,char ** argv)
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("The Big Dipper");//open the screen window

	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutMotionFunc(myMouseMove);
	myInit();
	glutMainLoop();
	return 0;
}

