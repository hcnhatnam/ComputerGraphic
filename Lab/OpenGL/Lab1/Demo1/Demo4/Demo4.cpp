// Demo4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <glut.h>
#include <math.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define DEG2RAD (3.14159f/180.0f)
float tetra_vertices[][3] = {
	{ 0.0, 0.0, 1.0 },
	{ 0.0, 0.942809, -0.33333 },
	{ -0.816497, -0.471405, -0.33333 },
	{ 0.816497, -0.471405, -0.33333 }
};
GLfloat angle;
void mydisplay() {
	//setup viewwer - camera parameter:
	//i.e., location (eye),
	//direction (from eye to the reference point), and orientation (up vector)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		1.5*cos(DEG2RAD*angle), //eyeX
		1.5*sin(DEG2RAD*angle), //eyeY
		3.5, //eyeZ
		0.0, //reference point X
		0.0, //reference point Y
		0.0, //reference point Z
		0.0, //up vector X
		1.0, //up vector Y
		0.0 //up vector Z
	);
	//clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//the order of the vertices in a triangle is important!
	glBegin(GL_TRIANGLES);
	//Face 1: defined by vertices: 0, 2, 1; colored: red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(tetra_vertices[0]);
	glVertex3fv(tetra_vertices[2]);
	glVertex3fv(tetra_vertices[1]);
	//Face 2: defined by vertices: 0, 1, 3; colored: red
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(tetra_vertices[0]);
	glVertex3fv(tetra_vertices[1]);
	glVertex3fv(tetra_vertices[3]);
	//Face 3: defined by vertices: 0, 3, 2; colored: red
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(tetra_vertices[0]);
	glVertex3fv(tetra_vertices[3]);
	glVertex3fv(tetra_vertices[2]);
	//Face 4: defined by vertices: 3, 1, 2; colored: red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(tetra_vertices[3]);
	glVertex3fv(tetra_vertices[1]);
	glVertex3fv(tetra_vertices[2]);
	glEnd();
	glFlush();
	glutSwapBuffers();
}
void reshape(int width, int height) {
	//setup viewport
	int size = min(width, height);
	glViewport(0, 0, size, size);
}
void processTimer(int value) {
	angle += (GLfloat)value;
	if (angle > 360.0f) angle -= 360.0f;
	glutTimerFunc(100, processTimer, value);
	glutPostRedisplay();
}
void initOpenGL() {
	//setup projection type
	//glFrustrum: define viewing volume
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(
		-2.0, //left
		2.0, //right
		-2.0, //bottom
		2.0, //top
		2.0, //near
		10.0 //far
	);
	//Default MatrixMode is MODELVIEW
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}
int main(int argc, char** argv) {
	angle = 0.0f;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Drawing a Tetrahedron");
	initOpenGL();
	glutDisplayFunc(mydisplay);
	glutReshapeFunc(reshape);
	glutTimerFunc(100, processTimer, 10);
	glutMainLoop();
}