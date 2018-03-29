// Bai1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <glut.h>
#include <math.h>
#include <stdio.h>
#define R 0.5
#define DEG2RAD (3.14159f/180.0f)
#define  pointSize  3
#pragma region Menu  
void Cau1();
void Cau2();
void Cau3();
void Cau4();

enum { CAU1, CAU2, CAU3, CAU4,QUIT_ITEM };


// Menu callback: choice is value of the chosen menu entry
void menu(int choice) {
	switch (choice) {
	case CAU1:
		glutDisplayFunc(Cau1);
		break;
	case CAU2:
		glutDisplayFunc(Cau2);
		break;
	case CAU3:
		glutDisplayFunc(Cau3);
		break;
	case CAU4:
		glutDisplayFunc(Cau4);
		break;
	case QUIT_ITEM:
		exit(0);
		break;
	default:
		break;
	}
}

// Create the menu, add the items, and attach to the mouse button
void createMenu() {
	// create menu
	int	m = glutCreateMenu(menu); // simultaneously registers callback

								  //add entries: 2nd parameter is value returned when entry is selected

	glutAddMenuEntry("Cau1", CAU1);
	glutAddMenuEntry("Cau2", CAU2);
	glutAddMenuEntry("Cau3", CAU3);
	glutAddMenuEntry("Cau4", CAU4);
	glutAddMenuEntry("Quit", QUIT_ITEM);

	// attach button to menu: overrides mouse callback for RIGHT button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}



#pragma endregion Menu  

#pragma region Cau1 
void Cau1() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	glColor3f(1.0f, 0.0f, 0.0f);
	float temp = 0;
	
	while (temp<=360)
	{
		glBegin(GL_POINTS);
		glVertex2f(R*cos(DEG2RAD*temp), R*sin(DEG2RAD*temp));
		glEnd();
		temp += 10;
	}
	glFlush();
	glutSwapBuffers();
}
#pragma endregion Cau1  

#pragma region Cau2 
void Cau2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	glColor3f(1.0f, 0.0f, 0.0f);
	float temp = 0;
	glBegin(GL_LINE_STRIP);
	while (temp <= 360)
	{
		glVertex2f(R*cos(DEG2RAD*temp), R*sin(DEG2RAD*temp));
		temp += 10;
	}
	glEnd();
	glFlush();
	glutSwapBuffers();
}
#pragma endregion Cau2  


#pragma region Cau3 
void drawLine(GLfloat x1, GLfloat  y1, GLfloat x2, GLfloat  y2) {
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
	glFlush();
}
void Cau3() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	glColor3f(1.0f, 0.0f, 0.0f);
	float temp = 0;
	while (temp <= 360)
	{
		glBegin(GL_LINE_STRIP);
		//glVertex2f(R*cos(DEG2RAD*temp), R*sin(DEG2RAD*temp));
		glVertex2f(0.0, 0.0);
		glVertex2f( R*cos(DEG2RAD*temp), R*sin(DEG2RAD*temp));
		temp += 10;
		glVertex2f(R*cos(DEG2RAD*temp), R*sin(DEG2RAD*temp));
		glEnd();
		
	}
	glFlush();
	glutSwapBuffers();
}
#pragma endregion Cau3  


#pragma region Cau4 
float angle = 0;
void Cau4() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(pointSize);
	glColor3f(1.0f, 0.0f, 0.0f);
	int temp = 0;
	while (temp <= 360)
	{
		if ((temp - (int)angle) % 120==0)
		{
			glBegin(GL_POLYGON);
			//glVertex2f(R*cos(DEG2RAD*temp), R*sin(DEG2RAD*temp));
			glVertex2f(0.0, 0.0);
			glVertex2f(R*cos(DEG2RAD*temp), R*sin(DEG2RAD*temp));
			temp += 10;
			glVertex2f(R*cos(DEG2RAD*temp), R*sin(DEG2RAD*temp));
			glVertex2f(0.0, 0.0);
			glEnd();
		}
		else
		{
			temp += 10;
		}

	}
	glFlush();
	glutSwapBuffers();
}


void processTimer(int value) {
	angle += (GLfloat)value;
	if (angle > 360.0f) angle -= 360.0f;
	glutTimerFunc(100, processTimer, value);
	glutPostRedisplay();
}
#pragma endregion Cau4

int main(int argc, char** argv) {
	angle = 0.0f;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("simple");
	createMenu();
	glutDisplayFunc(Cau1);
	glutTimerFunc(100, processTimer, 10);
	glutMainLoop();
}


















