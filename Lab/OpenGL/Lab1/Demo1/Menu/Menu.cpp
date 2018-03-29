// Menu.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <windows.h>
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
	for (int i = 0; i < strlen(str); i++)
	{
		glutBitmapCharacter(font, str[i]);
	}
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawText(100, 300, "OpenGL - OPEN GRAPHICS LANGUAGE");

	glFlush();
}


// Constants and variables...
// Menu item constants
enum { RED_ITEM, GREEN_ITEM, BLUE_ITEM, QUIT_ITEM };


// Menu callback: choice is value of the chosen menu entry
void menu(int choice) {
	switch (choice) {
	case RED_ITEM:
		glColor3f(1.0, 0.0, 0.0); // Red
		myDisplay();
		break;
	case GREEN_ITEM:
		glColor3f(0.0, 1.0, 0.0); // Green
		myDisplay();
		break;
	case BLUE_ITEM:
		glColor3f(0.0, 0.0, 1.0); // Blue
		myDisplay();
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

	glutAddMenuEntry("Red", RED_ITEM);
	glutAddMenuEntry("Green", GREEN_ITEM);
	glutAddMenuEntry("Blue", BLUE_ITEM);
	glutAddMenuEntry("Quit", QUIT_ITEM);

	// attach button to menu: overrides mouse callback for RIGHT button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int _tmain(int argc, _TCHAR* argv[])
{

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode
	glutInitWindowSize(640, 480); //set window size
	glutInitWindowPosition(100, 150); //set window position on screen
	glutCreateWindow("Output Text"); //open the screen window

	createMenu();

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}


