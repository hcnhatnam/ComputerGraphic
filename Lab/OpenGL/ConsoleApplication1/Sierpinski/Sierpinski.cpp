#include "stdafx.h"
#include <windows.h>
//#include <gl.h>
#include <glut.h>

class GLintPoint
{
public:
	GLint	x, y;
};
int random(int m)
{
	return rand() % m;
}
void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}
void Sierpinski() {
	GLintPoint  T[3] = { { 10, 10 },{ 300, 30 },{ 200, 300 } };

	int 		index = random(3);
	GLintPoint	point = T[index];

	glClear(GL_COLOR_BUFFER_BIT);
	drawDot(point.x, point.y);
	for (int i = 0; i<5000; i++)
	{
		index = random(3);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
	glFlush();
}
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode
	glutInitWindowSize(400, 400); //set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Sierpinski gasket"); // open the screen window
	glutDisplayFunc(Sierpinski);
	myInit();
	glutMainLoop();
	return 0;
}