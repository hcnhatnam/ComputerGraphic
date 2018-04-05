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
int		screenHeight = 600;

bool	bWireFrame = false;


Mesh	base;
Mesh	column;
Mesh	scrollBarT1Ovan;
Mesh	scrollBarT1Column;
Mesh	scrollBarT2Ovan;
Mesh	scrollBarT2Column;

Mesh	shelf1Sloid;
Mesh	shelf1Empty;

Mesh	shelf2Column;
Mesh	shelf2Sloid;
Mesh	shelf2Empty;
Mesh	crankOvan;
Mesh	crankCylinderIn;
Mesh	crankCylinderOut;


float	baseRadius = 0.8*base.scaleX;

float	baseHeight = 0.2;
float	baseRotateStep = 5;

float	columnSizeX = 0.25;
float	columnSizeZ = columnSizeX;
float	columnSizeY = 5;


float	scrollBarT1OvanRadius = 0.15;
float	scrollBarT1OvanHeight = columnSizeX;
float	scrollBarT1OvanLenght =2.3;

float	scrollBarT1ColumnHeight = 1*columnSizeY/2;

float	crankOvanRadius = 0.13;
float	crankOvanHeight = 0.14;
float	crankOvanLenght = 1.2;

float	crankCylinderRadius = 0.12;
float	crankCylinderHeightIn = 0.1;
float	crankCylinderHeightOut = 0.5;
float	crankCylinderRotateStep = 5;



void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		base.rotateY += baseRotateStep;
		if (base.rotateY > 360)
			base.rotateY -= 360;
		break;
	case '2':
		base.rotateY -= baseRotateStep;
		if (base.rotateY < 0)
			base.rotateY += 360;
		break;
	case '3':
		crankOvan.rotateZ += baseRotateStep;
		if (crankOvan.rotateZ < 0)
			crankOvan.rotateZ += 360;
		break;
	case '4':
		crankOvan.rotateZ -= baseRotateStep;
		if (crankOvan.rotateY < 0)
			crankOvan.rotateY += 360;
		break;
	case 'r':
	case 'R':
		crankOvan.rotateZ = -30;
		base.rotateY = 0;
		break;
	case 'w':
	case 'W':
		bWireFrame =!bWireFrame;
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
	//glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0, baseHeight / 2.0, 0);
	

	if (bWireFrame)
		base.DrawWireframe();
	else
		base.DrawColor();

	glPopMatrix();
}
void drawColumn()
{
	glPushMatrix();
	//glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0,columnSizeY/2, 0);
	

	if (bWireFrame)
		column.DrawWireframe();
	else
		column.DrawColor();

	glPopMatrix();
}
/*
void drawScrollBarT1OVan()
{
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(-base.rotateY, 0, 0, 1);
	if (bWireFrame)
		scrollBarT1Ovan.DrawWireframe();
	else
		scrollBarT1Ovan.DrawColor();

	glPopMatrix();
}
void drawScrollBarT1Column()
{
	glPushMatrix();
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0,scrollBarT1ColumnHeight/2+scrollBarT1OvanRadius, 0);
	

	if (bWireFrame)
		scrollBarT1Column.DrawWireframe();
	else
		scrollBarT1Column.DrawColor();

	glPopMatrix();
}
*/

void drawScrollBarT1() {
	glPushMatrix();
	
	//glRotatef(base.rotateY, 0, 1, 0);
	//Nâng lên 1 đoạn crankOvanLenght*sin(30 * PI / 180)
	//glTranslated(0,1/3.0*columnSizeY + crankOvanLenght*sin(30 * PI / 180), columnSizeZ + scrollBarT1OvanHeight / 2 + crankOvanHeight+scrollBarT1OvanHeight);
	//glTranslated(-(crankOvanLenght*cos(30*PI/180)), (columnSizeY - scrollBarT1ColumnHeight - scrollBarT1OvanRadius), columnSizeZ + scrollBarT1OvanHeight / 2 + crankOvanHeight);
	glTranslated(0, 0, scrollBarT1OvanHeight / 2);
	glRotatef(90, 1, 0, 0);
	if (bWireFrame)
		scrollBarT1Ovan.DrawWireframe();
	else
		scrollBarT1Ovan.DrawColor();

	glRotatef(-90, 1, 0, 0);
	glTranslated(0, scrollBarT1ColumnHeight / 2 + scrollBarT1OvanRadius, 0);
	if (bWireFrame)
		scrollBarT1Column.DrawWireframe();
	else
		scrollBarT1Column.DrawColor();

	glPopMatrix();
}

void drawScrollBarT2(){
	glPushMatrix();
	//glRotatef(base.rotateY, 0, 1, 0);
	//Xoay rồi tịnh tiến nên xoay ở dưới
	//glTranslated(-(crankOvanLenght*cos(30*PI/180)), (columnSizeY - scrollBarT1ColumnHeight - scrollBarT1OvanRadius), columnSizeZ + scrollBarT1OvanHeight / 2 + crankOvanHeight);
	glTranslated(0, 0, scrollBarT1OvanHeight / 2);
	glRotatef(-90, 0, 0, 1);
	glRotatef(90, 1, 0, 0);
	if (bWireFrame)
		scrollBarT2Ovan.DrawWireframe();
	else
		scrollBarT2Ovan.DrawColor();

	glRotatef(-90, 1, 0, 0);
	glTranslated(0, scrollBarT1ColumnHeight / 2 + scrollBarT1OvanRadius, 0);
	if (bWireFrame)
		scrollBarT2Column.DrawWireframe();
	else
		scrollBarT2Column.DrawColor();
	glPopMatrix();
}
float	shelf1SizeX = columnSizeX-0.1;
float	shelf1SizeZ = crankCylinderHeightIn + crankOvanHeight + scrollBarT1OvanHeight-0.4/2*columnSizeX;// vì float shelf1EmptySize = columnSizeX*1.3;
float	shelf1SizeY = shelf1SizeX;
/*
void drawShelf1Sloid() {
	if (bWireFrame)
		shelf1Sloid.DrawWireframe();
	else
		shelf1Sloid.DrawColor();
}
void drawShelf1Empty() {
	glPushMatrix();
	glTranslated(0, 0, columnSizeZ / 2 + shelf1SizeZ / 2);
	//glRotatef(base.rotateY, 0, 1, 0);
	if (bWireFrame)
		shelf1Empty.DrawWireframe();
	else
		shelf1Empty.DrawColor();
	glPopMatrix();
}
*/
float shelf1EmptySize = columnSizeX*1.4;
void drawShelf1() {
	glPushMatrix();
	//glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0,1/3.0*columnSizeY,shelf1SizeZ/2);
	
	if (bWireFrame)
		shelf1Sloid.DrawWireframe();
	else
		shelf1Sloid.DrawColor();
	glTranslated(0, 0, shelf1SizeZ/2+shelf1EmptySize/2);
	if (bWireFrame)
		shelf1Empty.DrawWireframe();
	else
		shelf1Empty.DrawColor();
	glPopMatrix();
}
float	shelf2ColumnSizeX = 1/2.0*columnSizeY;
float	 shelf2SloidSizeZ = crankCylinderHeightIn + crankOvanHeight-0.4 / 2 * columnSizeX;//cho rộng ra hơn 1 đoạn 0.4/2columnSizeX
void drawShelf2() {
	glPushMatrix();
	//glRotatef(base.rotateY, 0, 1, 0);
	//glTranslated(0, shelf2SizeY / 2 + 2 / 3.0*columnSizeY, columnSizeZ / 2 + shelf1SizeZ / 2);
	glTranslated(shelf2ColumnSizeX / 2 + columnSizeX / 2, 1 / 3.0*columnSizeY, 0);
	if (bWireFrame)
		shelf2Column.DrawWireframe();
	else
		shelf2Column.DrawColor();

	glTranslated(0, 0, columnSizeX / 2+ shelf2SloidSizeZ/2);
	if (bWireFrame)
		shelf2Sloid.DrawWireframe();
	else
		shelf2Sloid.DrawColor();
	

	glTranslated(0, 0, shelf2SloidSizeZ/2+ shelf1EmptySize/2);
	glRotated(-90, 0, 0, 1);
	if (bWireFrame)
		shelf2Empty.DrawWireframe();
	else
		shelf2Empty.DrawColor();
	glPopMatrix();
}
void drawCrank() {
	glPushMatrix();
	glTranslated(0,0, crankCylinderHeightIn/2);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	
	if (bWireFrame)
		crankCylinderIn.DrawWireframe();
	else
		crankCylinderIn.DrawColor();
	glPopMatrix();
	
	//glRotatef(-90, 1, 0, 0);
	
	//glRotatef(30, 0, 1, 0);//góc quay của Tay quay
	//glRotatef(crankOvan.rotateZ, 0, 0, 1);
	glRotatef(crankOvan.rotateZ, 0, 0, 1);
	glTranslated(-crankOvanLenght / 2, 0, crankCylinderHeightIn/2+crankOvanHeight/2);
	glRotatef(-90, 1, 0, 0);
	
	if (bWireFrame)
		crankOvan.DrawWireframe();
	else
		crankOvan.DrawColor();
	
	glTranslated(-crankOvanLenght/2,- crankCylinderHeightOut / 2- crankOvanHeight / 2, 0);
	if (bWireFrame)
		crankCylinderOut.DrawWireframe();
	else
		crankCylinderOut.DrawColor();
	
	glPopMatrix();
}
void myDisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(6, 4, 6, 0, 1, 0, 0, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, screenWidth, screenHeight);
	/*
	drawAxis();
	glPushMatrix();
	//glRotatef(base.rotateY, 0, 1, 0);
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0, 0, 0);
	
	drawColumn();
	drawBase();
	drawShelf2();
	glTranslated(0, 1 / 3.0*columnSizeY,columnSizeX / 2);
	drawShelf1();
	drawCrank();
	glTranslated(-(crankOvanLenght*cos(crankOvan.rotateZ * PI / 180)), 0,crankCylinderHeightIn+crankOvanHeight);
	drawScrollBarT2();
	glTranslated(crankOvanLenght*cos(crankOvan.rotateZ * PI / 180), crankOvanLenght*sin(-crankOvan.rotateZ * PI / 180),scrollBarT1OvanHeight);
	drawScrollBarT1();
	
	glPopMatrix();
	*/
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Lab 3 - Demo (2017-2018)"); // open the screen window
	/*
	base.CreateCylinder(baseRadius,baseHeight,baseRotateStep); //CreateCylinder(Ban kinh,chieu cao,ban kinh(Don vi Do))
	base.SetColor(6);

	column.CreateCuboid(columnSizeX, columnSizeY, columnSizeZ);
	column.SetColor(1);

	scrollBarT1Ovan.CreateOvanAdvan(scrollBarT1OvanRadius, scrollBarT1OvanHeight, scrollBarT1OvanLenght);
	scrollBarT1Ovan.SetColor(0);
	scrollBarT1Column.CreateCuboid(columnSizeZ, scrollBarT1ColumnHeight, columnSizeZ); //CreateCylinder(Ban kinh,chieu cao,ban kinh(Don vi Do))
	scrollBarT1Column.SetColor(0);

	scrollBarT2Ovan.CreateOvanAdvan(scrollBarT1OvanRadius, scrollBarT1OvanHeight, scrollBarT1OvanLenght);
	scrollBarT2Ovan.SetColor(2);
	scrollBarT2Column.CreateCuboid(columnSizeZ, scrollBarT1ColumnHeight, columnSizeZ); //CreateCylinder(Ban kinh,chieu cao,ban kinh(Don vi Do))
	scrollBarT2Column.SetColor(2);

	shelf1Sloid.CreateCuboid(shelf1SizeX, shelf1SizeY, shelf1SizeZ);//scrollBarT2OvanHeight=scrollBarT1OvanHeight
	shelf1Sloid.SetColor(2);
	shelf1Empty.CreateCuboWithThick(shelf1EmptySize, shelf1EmptySize, shelf1EmptySize,0.01);//shelf1EmptySize
	shelf1Empty.SetColor(2);

	shelf2Column.CreateCuboid(shelf2ColumnSizeX, columnSizeX, columnSizeZ);
	shelf2Column.SetColor(8);
	shelf2Sloid.CreateCuboid(shelf1SizeX, shelf1SizeY, shelf2SloidSizeZ);
	shelf2Sloid.SetColor(8);
	shelf2Empty.CreateCuboWithThick(shelf1EmptySize, shelf1EmptySize, shelf1EmptySize, 0.01);
	shelf2Empty.SetColor(8);

	crankOvan.CreateOvan(crankOvanRadius,crankOvanHeight,crankOvanLenght);
	crankOvan.SetColor(6);
	crankOvan.rotateZ = -30;//Mặc định góc này đẹp

	crankCylinderIn.CreateCylinder(crankCylinderRadius,crankCylinderHeightIn,crankCylinderRotateStep);
	crankCylinderIn.SetColor(4);
	crankCylinderOut.CreateCylinder(crankCylinderRadius, crankCylinderHeightOut, crankCylinderRotateStep);
	crankCylinderOut.SetColor(4);
	*/
	myInit();
	
	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}

