#include <GL/glut.h>
#define min(a,b) ((a)<(b)?(a):(b))

float tetra_vertices[][3] = {
	{0.0, 0.0, 1.0},
	{0.0, 0.942809, -0.33333},
	{-0.816497, -0.471405, -0.33333},
	{0.816497, -0.471405, -0.33333}
};

void mydisplay(){
	//setup viewwer - camera parameter: 
	//i.e., location (eye), 
	//direction (from eye to the reference point), and orientation (up vector)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		1.5,	//eyeX
		1.5,	//eyeY
		1.5,	//eyeX
		0.0,	//reference point X
		0.0,	//reference point Y
		0.0,	//reference point Z
		0.0,	//up vector X
		1.0,	//up vector Y
		0.0		//up vector Z
		);
	
	//clear screen
    glClear(GL_COLOR_BUFFER_BIT); 
	
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
void reshape(int width, int height){
	//setup viewport
	int size = min(width, height);
	glViewport(0, 0, size, size);
}
void initOpenGL(){
	//setup projection type
	//glFrustrum: define viewing volume
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(
				-1.0,	//left
				1.0,	//right
				-1.0,	//bottom
				1.0,	//top
				2.0,	//near
				10.0	//far
				);
	//Default MatrixMode is MODELVIEW 
	glMatrixMode(GL_MODELVIEW);

	//setup background color, or clear color
	glClearColor(0.1f, 0.7f, 0.7f, 1.0f);
}

int main(int argc, char** argv){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Drawing a Tetrahedron"); 
	initOpenGL();
	glutDisplayFunc(mydisplay);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
