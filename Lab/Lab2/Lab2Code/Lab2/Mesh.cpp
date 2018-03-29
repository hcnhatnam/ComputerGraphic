#include "stdafx.h"
#include "Mesh.h"
#include <math.h>

#define PI			3.1415926
#define	COLORNUM		14

void InitialPi(Point3* &pt, float radius, float height, float rotation);
float	ColorArr[COLORNUM][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, { 0.0,  0.0, 1.0}, 
								{1.0, 1.0,  0.0}, { 1.0, 0.0, 1.0},{ 0.0, 1.0, 1.0}, 
								 {0.3, 0.3, 0.3}, {0.5, 0.5, 0.5}, { 0.9,  0.9, 0.9},
								{1.0, 0.5,  0.5}, { 0.5, 1.0, 0.5},{ 0.5, 0.5, 1.0},
									{0.0, 0.0, 0.0}, {0.1, 1.0, 1.0}};



void Mesh::CreateCube(float	fSize)//Vẽ hình lập phương
{
	CreateCuboid(fSize, fSize, fSize);
}
void Mesh::CreateCuboid(float fSizeX, float fSizeY,float fSizeZ){
	
	int i;

	numVerts = 8;
	pt = new Point3[numVerts];
	pt[0].set(-fSizeX, fSizeY, fSizeZ);
	pt[1].set(fSizeX, fSizeY, fSizeZ);
	pt[2].set(fSizeX, fSizeY, -fSizeZ);
	pt[3].set(-fSizeX, fSizeY, -fSizeZ);
	pt[4].set(-fSizeX, -fSizeY, fSizeZ);
	pt[5].set(fSizeX, -fSizeY, fSizeZ);
	pt[6].set(fSizeX, -fSizeY, -fSizeZ);
	pt[7].set(-fSizeX, -fSizeY, -fSizeZ);


	numFaces = 6;
	face = new Face[numFaces];

	//Left face

	
	//setUpFace(0, new int[1, 5, 6, 2], 4);

	//Right face
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 3;
	face[1].vert[2].vertIndex = 7;
	face[1].vert[3].vertIndex = 4;
	for (i = 0; i < face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;

	//top face
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 2;
	face[2].vert[3].vertIndex = 3;
	for (i = 0; i < face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;

	//bottom face
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 5;
	face[3].vert[3].vertIndex = 4;
	for (i = 0; i < face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 4;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 1;
	face[4].vert[3].vertIndex = 0;
	for (i = 0; i < face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 3;
	face[5].vert[1].vertIndex = 2;
	face[5].vert[2].vertIndex = 6;
	face[5].vert[3].vertIndex = 7;
	for (i = 0; i < face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 5;
		
}
void Mesh::setUpFace(int indexFace, int arrVertex[], int numberVerts) {//size=nVerts
	face[indexFace].nVerts = numberVerts;
	face[indexFace].vert = new VertexID[numberVerts];
	for (int i = 0; i < numberVerts; i++){
		face[indexFace].vert[i].vertIndex = arrVertex[i];
		face[indexFace].vert[i].colorIndex = indexFace;
	}	
}

void Mesh::supportCreateCuboWithThick(int i) {
	int j;
	//Mặt trước
	face[0 + i].nVerts = 4;
	face[0 + i].vert = new VertexID[face[0 + i].nVerts];
	face[0 + i].vert[0].vertIndex = 1 + i;
	face[0 + i].vert[1].vertIndex = 5 + i;
	face[0 + i].vert[2].vertIndex = 6 + i;
	face[0 + i].vert[3].vertIndex = 2 + i;
	for (j = 0; j < face[0 + i].nVerts; j++)
		face[0 + i].vert[j].colorIndex = 0;

	//Mặt sau
	face[1 + i].nVerts = 4;
	face[1 + i].vert = new VertexID[face[1 + i].nVerts];
	face[1 + i].vert[0].vertIndex = 0 + i;
	face[1 + i].vert[1].vertIndex = 3 + i;
	face[1 + i].vert[2].vertIndex = 7 + i;
	face[1 + i].vert[3].vertIndex = 4 + i;
	for (j = 0; j < face[1 + i].nVerts; j++)
		face[1 + i].vert[j].colorIndex = 1;

	//Mặt trái
	face[2+i].nVerts = 4;
	face[2+i].vert = new VertexID[face[2 + i].nVerts];
	face[2+i].vert[0].vertIndex = 4 + i;
	face[2+i].vert[1].vertIndex = 5 + i;
	face[2+i].vert[2].vertIndex = 1 + i;
	face[2+i].vert[3].vertIndex = 0 + i;
	for (j = 0; j < face[2 + i].nVerts; j++)
		face[2+i].vert[j].colorIndex = 4;

	//Mặt phải
	face[3 + i].nVerts = 4;
	face[3 + i].vert = new VertexID[face[3].nVerts];
	face[3 + i].vert[0].vertIndex = 3 + i;
	face[3 + i].vert[1].vertIndex = 2 + i;
	face[3 + i].vert[2].vertIndex = 6 + i;
	face[3 + i].vert[3].vertIndex = 7 + i;
	for (j = 0; j < face[3+i].nVerts; j++)
		face[3 + i].vert[j].colorIndex = 5;
}
void Mesh::CreateCuboWithThick(float fSizeX, float fSizeY, float fSizeZ,float thick) {
	
	float fSizeXthick, fSizeYthick, fSizeZthick;
	fSizeXthick = fSizeX - thick;
	fSizeYthick = fSizeY - thick+0.3;
	fSizeZthick = fSizeZ - thick;
	//int i;
	numVerts = 16;
	pt = new Point3[numVerts];
	pt[0].set(-fSizeX, fSizeY, fSizeZ);
	pt[1].set(fSizeX, fSizeY, fSizeZ);
	pt[2].set(fSizeX, fSizeY, -fSizeZ);
	pt[3].set(-fSizeX, fSizeY, -fSizeZ);
	pt[4].set(-fSizeX, -fSizeY, fSizeZ);
	pt[5].set(fSizeX, -fSizeY, fSizeZ);
	pt[6].set(fSizeX, -fSizeY, -fSizeZ);
	pt[7].set(-fSizeX, -fSizeY, -fSizeZ);


	pt[8].set(-fSizeXthick, fSizeYthick, fSizeZthick);
	pt[9].set(fSizeXthick, fSizeYthick, fSizeZthick);
	pt[10].set(fSizeXthick, fSizeYthick, -fSizeZthick);
	pt[11].set(-fSizeXthick, fSizeYthick, -fSizeZthick);
	pt[12].set(-fSizeXthick, -fSizeYthick, fSizeZthick);
	pt[13].set(fSizeXthick, -fSizeYthick, fSizeZthick);
	pt[14].set(fSizeXthick, -fSizeYthick, -fSizeZthick);
	pt[15].set(-fSizeXthick, -fSizeYthick, -fSizeZthick);


	numFaces = 16;
	face = new Face[numFaces];

	supportCreateCuboWithThick(0);
	supportCreateCuboWithThick(8);
	for (int index=0;index<3;index++)
	{
		DrawThick(4 + index, index);
		DrawThick(12+index, 4+index);
	}
	DrawThickBack(4 + 3, 3, 0);
	
	//DrawThickBack(12 + 3, 3, 3);
	
}

void Mesh::DrawThick(int indexface,int delta){
	face[indexface].nVerts = 4;
	face[indexface].vert = new VertexID[face[indexface].nVerts];
	face[indexface].vert[0].vertIndex = 0+delta;
	face[indexface].vert[1].vertIndex = 8+delta;
	face[indexface].vert[2].vertIndex = 9+delta;
	face[indexface].vert[3].vertIndex = 1+delta;
	for (int i = 0; i < face[indexface].nVerts; i++)
		face[indexface].vert[i].colorIndex = 0;
}
void Mesh::DrawThickBack(int indexface, int delta,int flat) {
	face[indexface].nVerts = 4;
	face[indexface].vert = new VertexID[face[indexface].nVerts];
	face[indexface].vert[0].vertIndex = 0 + delta;
	face[indexface].vert[1].vertIndex = 8 + delta;
	face[indexface].vert[2].vertIndex = flat+8;
	face[indexface].vert[3].vertIndex = flat;
	for (int i = 0; i < face[indexface].nVerts; i++)
		face[indexface].vert[i].colorIndex = 0;
}


void Mesh::CreateCylinde(float radius, float height, float rotation) {
	Cylinder(radius, height, rotation);
	int i;
	for (i = 0; i < numVerts - 2; i += 2) {
		TopDownCylinder(i, 0, i + 2);
		TopDownCylinder(i + 1, 1, i + 3);
	}
	face[i - 2].vert[2].vertIndex = 2;
	face[i - 1].vert[2].vertIndex = 3;
	AroundCylinder();
}


void Mesh::Cylinder(float radius, float height, float rotation) {
	numVerts = 360 / rotation*2+2;
	InitialPi(pt, radius, height, rotation);
	numFaces = (numVerts-2)/2 * 3;
	face = new Face[numFaces];

}

void Mesh::AroundCylinder() {
	int i,j;
	for (j = 1; j <numFaces - numVerts + 3; j++)
	{
		face[j + numVerts - 3].nVerts = 4;
		face[j + numVerts - 3].vert = new VertexID[4];
		face[j + numVerts - 3].vert[0].vertIndex = j * 2 + 0;//0 2
		face[j + numVerts - 3].vert[1].vertIndex = j * 2 + 2;//1 4
		face[j + numVerts - 3].vert[2].vertIndex = j * 2 + 3;//2 5
		face[j + numVerts - 3].vert[3].vertIndex = j * 2 + 1;//3 1
		for (i = 0; i < 4; i++) {
			face[j + numVerts - 3].vert[i].colorIndex = j%COLORNUM;
		}
	}
	face[j + numVerts - 4].vert[1].vertIndex = 2;
	face[j + numVerts - 4].vert[2].vertIndex = 3;
}

void Mesh::TopDownCylinder(int index,int center,int vertex) {
	face[index].nVerts = 3;
	face[index].vert = new VertexID[face[index].nVerts];
	face[index].vert[0].vertIndex = center;
	face[index].vert[0].colorIndex = index %COLORNUM;
	face[index].vert[1].vertIndex = vertex;
	face[index].vert[1].colorIndex = index %COLORNUM;
	face[index].vert[2].vertIndex = vertex+2;
	face[index].vert[2].colorIndex = index %COLORNUM;
}


void Mesh::CreateOvan(float R, float height, float lenght) {
	Cylinder(R, height, 18);
	for (int i = 0; i < numVerts; i++) {
		if (pt[i].x > 0)
			pt[i].x += lenght / 2;
		else
			pt[i].x -= lenght / 2;
	}
	AroundCylinder();

	face[0].nVerts = (numVerts - 2) / 2;
	face[0].vert = new VertexID[face[0].nVerts];
	face[1].nVerts = (numVerts - 2) / 2;
	face[1].vert = new VertexID[face[1].nVerts];
	for (int i = 0; i < numVerts-2; i+=2)
	{
		face[0].vert[i / 2].vertIndex = i + 2;
		face[0].vert[i / 2].colorIndex = 22 % COLORNUM;
		face[1].vert[i / 2].vertIndex = i + 3;
		face[1].vert[i / 2].colorIndex = 23 % COLORNUM;
	}
	
}
void Mesh::CreateOvanAdvan(float R1, float R2, float height, float lenght) {
	float rotation = 18;
	numVerts = 360 / rotation *4;
	Point3* pt1;
	InitialPi(pt1, R1, height, rotation);
	Point3* pt2;
	InitialPi(pt2, R2, height, rotation);

	pt = new Point3[numVerts];
	for (int i = 0; i < numVerts/2; i+=1){
		pt[i] = pt1[i+2];
		pt[i +numVerts/2] = pt2[i+2];
	}

	for (int i = 0; i < numVerts; i++) {
		if (pt[i].x > 0)
			pt[i].x += lenght / 2;
		else
			pt[i].x -= lenght / 2;
	}

	numFaces = numVerts ;
	face = new Face[numFaces];
	DrawAroundBai5(0);
	DrawAroundBai5(numVerts / 2);
	DrawTopDownBai5(40);
	DrawTopDownBai5(60);
}
void Mesh::DrawAroundBai5(int start) {
	int i;
	for (i = start/2; i <numVerts / 4+start/2; i += 1)
	{
		face[i].nVerts = 4;
		face[i].vert = new VertexID[4];
		face[i].vert[0].vertIndex = i * 2;//0 2
		face[i].vert[1].vertIndex = i * 2 + 2;//1 4
		face[i].vert[2].vertIndex = i * 2 + 3;//2 5
		face[i].vert[3].vertIndex = i * 2 + 1;//3 1
		for (int j = 0; j < 4; j++) {
			face[i].vert[j].colorIndex = j%COLORNUM;
		}
	}
	face[i - 1].vert[1].vertIndex = 0+start;
	face[i - 1].vert[2].vertIndex = 1+start;
}

void Mesh::DrawTopDownBai5(int start) {
	int i,index,k;
	if (start > numVerts/2) k = 1;
	else k = 0;
	for (i = 0; i <numVerts / 4; i += 1)
	{
		index= start+i;
		face[index].nVerts = 4;
		face[index].vert = new VertexID[4];
		face[index].vert[0].vertIndex = i * 2+k;//0 2 d
		face[index].vert[1].vertIndex = i * 2 + 2+k;//1 4 
		face[index].vert[2].vertIndex = numVerts / 2 +i * 2 + 2+k;//2 5
		face[index].vert[3].vertIndex = numVerts / 2 +i * 2+k;//3 1
		for (int j = 0; j < 4; j++) {
			face[index].vert[j].colorIndex = index%COLORNUM;
		}
	}
	if (k==0)
	{
		face[index].vert[1].vertIndex = 0;//1-0
		face[index].vert[2].vertIndex = numVerts / 2;//2-40
	}
	else
	{
		face[index].vert[1].vertIndex = 1;//1-0
		face[index].vert[2].vertIndex = numVerts / 2+1;//2-40
	}
	

}

void InitialPi(Point3* &pt,float radius,float height,float rotation) {
	int numVerts = 360 / rotation*2 + 2;
	pt = new Point3[numVerts];
	float rotePI = PI*rotation / 180;
	pt[0].set(0, height / 2, 0);
	pt[1].set(0, -height / 2, 0);

	for (int i = 2; i < numVerts; i += 2) {
		pt[i].set(radius*cos(rotePI*((i - 2)/2)), height / 2, radius*sin(rotePI*(i - 2) / 2));//p[i] với i lẽ nằm dưới
		pt[i + 1].set(radius*cos(rotePI*(i - 2) / 2), -height / 2, radius*sin(rotePI*(i - 2) / 2));
	}

}

void Mesh::CreateTetrahedron()//Vẽ hình tứ diện
{
	int i;
	numVerts=4;
	pt = new Point3[numVerts];
	pt[0].set(0, 0, 0);
	pt[1].set(1, 0, 0);
	pt[2].set(0, 1, 0);
	pt[3].set(0, 0, 1);

	numFaces= 4;
	face = new Face[numFaces];

	face[0].nVerts = 3;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 2;
	face[0].vert[2].vertIndex = 3;
	for(i = 0; i<face[0].nVerts ; i++)
		face[0].vert[i].colorIndex = 0;
	

	face[1].nVerts = 3;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;	
	face[1].vert[1].vertIndex = 2;
	face[1].vert[2].vertIndex = 1;
	for(i = 0; i<face[1].nVerts ; i++)
		face[1].vert[i].colorIndex = 1;

	
	face[2].nVerts = 3;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 3;
	face[2].vert[2].vertIndex = 2;
	for(i = 0; i<face[2].nVerts ; i++)
		face[2].vert[i].colorIndex = 2;


	face[3].nVerts = 3;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 1;
	face[3].vert[1].vertIndex = 3;
	face[3].vert[2].vertIndex = 0;
	for(i = 0; i<face[3].nVerts ; i++)
		face[3].vert[i].colorIndex = 3;
}


void Mesh::DrawWireframe()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;

			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}

void Mesh::DrawColor()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;
			int		ic = face[f].vert[v].colorIndex;
			
			ic = f % COLORNUM;

			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]); 
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}



