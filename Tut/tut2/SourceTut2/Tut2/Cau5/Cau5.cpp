#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <glut.h>
#include <math.h>

using namespace std;
#define PI 3.1415926
#define DEGTORAD (PI/180.0)
int nWidth = 600;
int nHeight = 600;
int nCenterX = nWidth / 2;
int nCenterY = nHeight / 2;
int nRadius = 200;
float vertexArr[10][2];
float t = 1;
bool bAuto = false;

//int nCenterX, nCenterY;
void reDraw();

void setWindow(float l, float r, float b, float t)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(l, r, b, t);
}
void setViewport(int l, int r, int b, int t)
{
	glViewport(l, b, r - l, t - b);
} 
void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2) {
	x2 = len*cos(angle*PI / 180.0) + x1;
	y2 = len*sin(angle*PI / 180.0) + y1;
}
float angleStart=0;
void CalcVertexArrs()
{ 
	float longEdge = nRadius;
	float shortEdge = nRadius / sin((180-36-18) * PI / 180) * sin(18 * PI / 180);
	float angle= (angleStart+90) * PI / 180.0;
	for (int i = 0; i < 10; i += 1)
	{
		if (i%2==0)
		{
			vertexArr[i][0] = longEdge*cos(angle);
			vertexArr[i][1] = longEdge*sin(angle);
		}
		else {
			vertexArr[i][0] = shortEdge*cos(angle);
			vertexArr[i][1] = shortEdge*sin(angle);
		}
		angle += 36*PI/180.0;
		if (angle>=2*PI)
			angle -=2*PI;
		
	}
}

void DrawFigure(float t)
{
	/*
	glColor3f(1.0f, 1.0f, 0.0f);
	
	for (int i = 0; i < 2; i++) {
		glBegin(GL_TRIANGLES);

			glVertex2f(vertexArr[i][0], vertexArr[i][1]);
			glVertex2f(vertexArr[(i+1)%10][0], vertexArr[(i+1)%10][1]);
			glVertex2f(0, 0);
		glEnd();
	}
	*/
	//glPointSize(10);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);//đỉnh ở tâm màu trắng
	glVertex2f(0, 0);
	for (int i = 0; i < 11; i++) {
		if (i % 5 == 0) glColor3f(t, t, 0);
		else if (i % 5 == 1) glColor3f(t, 0, 0);
		else if (i % 5 == 2) glColor3f(0, 0, t);
		else if (i % 5 == 3) glColor3f(0, t, 0);
		else glColor3f(0, 0, 0);
		glVertex2f(vertexArr[i % 10][0], vertexArr[i % 10][1]);
	}
	glEnd();
	glFlush();
} 
int distanceMove = 50;
int distanceAngle = 5;
void OnSpecialKey(int key, int x, int y)
{ 
	switch (key)
	{
	case GLUT_KEY_LEFT:
		nCenterX = nCenterX - distanceMove;
		break;
	case GLUT_KEY_RIGHT:
		nCenterX = nCenterX + distanceMove;
		break;
	case GLUT_KEY_UP:
		nCenterY = nCenterY + distanceMove;
		break;
	case GLUT_KEY_DOWN:
		nCenterY = nCenterY - distanceMove;
		break;
	case GLUT_KEY_PAGE_UP:
		angleStart += distanceAngle;
		CalcVertexArrs();
		break;
	case GLUT_KEY_PAGE_DOWN:
		angleStart -= distanceAngle;
		CalcVertexArrs();
		break;
	default:
		return;
	}
	reDraw();
}
bool current = 0;//false :decreament true:increament
float distanceT = 0.01;
void OnTimer(int value)
{ 
	int a = 0;
	if (bAuto == 1)
	{
		angleStart += distanceAngle;
		//CalcVertexArrs();

		if (current) {
			t += distanceT;
			if (t >= 1) {
				t = 1;
				current = 0;
			}
		}
		else {
			t -= distanceT;
			if (t <=0) {
				t = 0;
				current = 1;
			}
		}
		//reDraw();
		
	}
	glutPostRedisplay();
	glutTimerFunc(100, OnTimer, 0);
}


void OnKey(unsigned char key, int x, int y)
{
	if(bAuto==false)
		switch (key)
		{
		case 'i':
		case 'I':
			t += distanceT;
			if (t > 1)
				t = 1;
			break;
		case 'd':
		case 'D':
			t -= distanceT;
			if (t < 0)
				t = 0;
			break;
		default:
			break;
		}
	if (key=='a'||key=='A')
		bAuto = !bAuto;
	reDraw();
}
void reDraw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(nCenterX-nRadius , nCenterY-nRadius, nRadius*2, nRadius*2);
	DrawFigure(t);
	glFlush();
}
void OnMouseClick(int button, int state, int x, int y)
{ 
	nCenterX = x;
	nCenterY = nHeight - y;
	reDraw();
	/*
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(x-nRadius/2, y-nRadius/2, nRadius, nRadius);
	DrawFigure(t);
	glFlush();
	*/
} 
void OnReshape(int w, int h)
{
	nWidth = w;
	nHeight = h;
}
void OnDisplay()
{
	CalcVertexArrs();
	glClearColor(1, 1, 1, 1);
	/*
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0, nRadius, nRadius);
	*/
	setWindow(-nRadius, nRadius, -nRadius, nRadius);
	reDraw();
	//DrawFigure(t);
	glFlush();
}
int main(int argc, char** argv)
{
	cout << "Click mouse to change the Center of the Figure" << endl;
	cout << "Press Left Arrow to move the Figure to the left" << endl;
	cout << "Press Right Arrow to move the Figure to the right" << endl;
	cout << "Press Up Arrow to move the Figure up" << endl;
	cout << "Press Down Arrow to move the Figure down" << endl;
	cout << "Press Page Up to rotate the Figure to the left" << endl;
	cout << "Press Page Down to rotate the Figure to the right" << endl;
	cout << "Press i/I to increase the value of t" << endl;
	cout << "Press d/D to decrease the value of t" << endl;
	cout << "Press a/A to toggle the value of bAuto" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(nWidth, nHeight);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Cau 5 - Tut 2");
	glutSpecialFunc(OnSpecialKey);
	glutKeyboardFunc(OnKey);
	glutReshapeFunc(OnReshape);
	glutMouseFunc(OnMouseClick);
	glutTimerFunc(100, OnTimer, current);
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
	return 0;
}