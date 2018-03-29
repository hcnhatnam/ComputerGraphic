#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
GLfloat angle;
#define DEG2RAD (3.14159f/180.0f)

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0f, 0.0f, 0.0f);

	GLfloat cx, cy;
	cx = 0.5*cos(DEG2RAD*angle); cy = 0.5*sin(DEG2RAD*angle);

	glBegin(GL_POLYGON);        
		glVertex2f(cx - 0.5, cy - 0.5);        
		glVertex2f(cx - 0.5, cy + 0.5);        
		glVertex2f(cx + 0.5, cy + 0.5);        
		glVertex2f(cx + 0.5, cy - 0.5);    
	glEnd();
	glFlush();
	glutSwapBuffers();
	
}
void processTimer(int value){
	angle	+= (GLfloat)value;
	if(angle > 360) angle = angle - 360.0f;

	glutTimerFunc(100, processTimer, 10);
	glutPostRedisplay();
}

int main(int argc, char** argv){
	angle = 0.0f;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("simple");     
	glutDisplayFunc(mydisplay);
	glutTimerFunc(100, processTimer, 10);
	glutMainLoop();
}
