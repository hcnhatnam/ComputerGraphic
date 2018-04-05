
#include <glut.h>
#include<time.h>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#define PI			3.1415926

int		screenWidth = 600;
int		screenHeight = 600;
using namespace std;
# define CUBOID_HEIGHT 0.06
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
void myInit()
{
	float	fHalfSize = 2.5;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}


void cuboid()
 {
	 float vertices[8][3] = { { 0 , 0, 0 },{ 2, 0, 0 },{ 2, 0, 2 },{ 0 ,0 ,2 } ,
		{0, CUBOID_HEIGHT , 0},{ 2, CUBOID_HEIGHT , 0 },{ 2, CUBOID_HEIGHT ,2},{ 0, CUBOID_HEIGHT , 2 }
	 };
	 float line[12][2] = { { 0 , 1 },{ 1, 2 },{ 2, 3 },{ 3, 0 } ,{ 4 , 5 } ,{ 5 , 6 },
	{ 6, 7 } ,{ 7 , 4 },
		 {0, 4},{ 1, 5 },{ 2, 6 },{ 3, 7 }
	 };
	 int i, p1, p2;
	 glBegin(GL_LINES);
	 for (i = 0; i < 12; i++)
		 {
		 p1 = line[i][0];
		 p2 = line[i][1];
		 glVertex3f(vertices[p1][0], vertices[p1][1], vertices[p1][2]);
		 glVertex3f(vertices[p2][0], vertices[p2][1], vertices[p2][2]);
		}
	 glEnd();
}
void wireframe() {
	float maxScale = 20;
	for (int scale = 0; scale <= maxScale; scale++)
	{
		glPushMatrix();
		glTranslatef(1, CUBOID_HEIGHT*scale, 1);
		glScaled(1-scale/ maxScale,1, 1 - scale / maxScale);
		glRotated(5*scale, 0, 1, 0);
		glTranslatef(-1, 0, -1);
		cuboid();
		glPopMatrix();
	}
	
}
void myDisplay() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(6, 4, 6, 0, 1, 0, 0, 1, 0);
	gluLookAt(-0.8, 1.8, -0.8, 0, 0, 0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(100,-100, screenWidth, screenHeight);
	
	drawAxis();

	wireframe();
	

	
	glFlush();
	glutSwapBuffers();
}
int main(int argc, char** argv) {
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Lab 3 - Demo (2017-2018)"); // open the screen window
	myInit();



	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
