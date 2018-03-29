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


void Mesh::SetColor(int colorIdx){
	for (int f = 0; f < numFaces; f++){
		for (int v = 0; v < face[f].nVerts; v++){
		face[f].vert[v].colorIndex = colorIdx;
		}
	}
}



void Mesh::CreateCube(float	fSize)//Vẽ hình lập phương
{
	CreateCuboid(fSize, fSize, fSize);
}
void Mesh::CreateCuboid(float fSizeX, float fSizeY,float fSizeZ){
	
	int arr[4];
	numVerts = 8;
	pt = new Point3[numVerts];
	fSizeX /= 2;
	fSizeY /= 2;
	fSizeZ /= 2;
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
	arr[0] = 1; arr[1] = 5; arr[2] = 6; arr[3] = 2;
	setUpFace(0, arr, 4);
	//Right face
	arr[0] = 0; arr[1] = 3; arr[2] = 7; arr[3] = 4;
	setUpFace(1, arr, 4);
	//top face
	arr[0] = 0; arr[1] = 1; arr[2] = 2; arr[3] = 3;
	setUpFace(2, arr, 4);
	//bottom face
	arr[0] = 7; arr[1] = 6; arr[2] = 5; arr[3] = 4;
	setUpFace(3, arr, 4);
	//near face
	arr[0] = 4; arr[1] = 5; arr[2] = 1; arr[3] = 0;
	setUpFace(4, arr, 4);
	//Far face
	arr[0] = 3; arr[1] = 2; arr[2] = 6; arr[3] = 7;
	setUpFace(5, arr, 4);
		
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
	int arr[4];
	//Mặt trước
	arr[0] = 1+i; arr[1] = 5+i; arr[2] = 6+i; arr[3] = 2+i;
	setUpFace(0+i, arr, 4);
	//Mặt sau
	arr[0] = 0+i; arr[1] = 3+i; arr[2] = 7+i; arr[3] = 4+i;
	setUpFace(1+i, arr, 4);
	//Mặt trái
	arr[0] = 4+i; arr[1] = 5+i; arr[2] = 1+i; arr[3] = 0+i;
	setUpFace(2+i, arr, 4);
	//Mặt phải
	arr[0] = 3+i; arr[1] = 2+i; arr[2] = 6+i; arr[3] = 7+i;
	setUpFace(3+i, arr, 4);
}
void Mesh::CreateCuboWithThick(float fSizeX, float fSizeY, float fSizeZ,float thick) {

	fSizeX /= 2;
	fSizeY /= 2;
	fSizeZ /= 2;	float fSizeXthick, fSizeYthick, fSizeZthick;
	fSizeXthick = fSizeX - thick;
	fSizeYthick = fSizeY - thick;
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
	int arr[4];
	for (int index=0;index<3;index++){
		arr[0] = 0+index; arr[1] = 8 + index; arr[2] = 9 + index; arr[3] = 1 + index;
		setUpFace(4+index, arr, 4);

		arr[0] = 0+4 + index; arr[1] = 8+4 + index; arr[2] = 9+4 + index; arr[3] = 1+4 + index;
		setUpFace(12 + index, arr, 4);
	}
	arr[0] = 0 +3; arr[1] = 8 + 3; arr[2] =0+8; arr[3] = 0;
	setUpFace(4+3, arr, 4);	
}

void Mesh::CreateCylinder(float radius, float height, float rotation) {
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
	int arr[4];
	for (j = 1; j <numFaces - numVerts + 3; j++){
		arr[0] = j * 2 + 0; arr[1] = j * 2 + 2; arr[2] = j * 2 + 3; arr[3] = j * 2 + 1;
		setUpFace(j + numVerts - 3, arr, 4);
	}
	face[j + numVerts - 4].vert[1].vertIndex = 2;
	face[j + numVerts - 4].vert[2].vertIndex = 3;
}

void Mesh::TopDownCylinder(int index,int center,int vertex) {
	int arr[3] = {center,vertex,vertex+2};
	setUpFace(index, arr, 3);
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
void Mesh::CreateOvanAdvan(float R1, float height, float lenght) {
	float R2 = 0.8*R1;
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
	int arr[4];
	int i;
	for (i = start/2; i <numVerts / 4+start/2; i += 1){
		arr[0] = i * 2; arr[1] = i * 2 + 2; arr[2] = i * 2 + 3; arr[3] = i * 2 + 1;
		setUpFace(i, arr, 4);
	}
	face[i - 1].vert[1].vertIndex = 0+start;
	face[i - 1].vert[2].vertIndex = 1+start;
}

void Mesh::DrawTopDownBai5(int start) {
	int arr[4];
	int i,index,k;
	if (start > numVerts/2) k = 1;
	else k = 0;
	for (i = 0; i <numVerts / 4; i += 1){
		index = start + i;
		arr[0] = i * 2 + k; arr[1] = i * 2 + 2 + k; arr[2] = numVerts / 2 + i * 2 + 2 + k; arr[3] = numVerts / 2 + i * 2 + k;
		setUpFace(index, arr, 4);
	
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
	int arr[3];
	numVerts=4;
	pt = new Point3[numVerts];
	pt[0].set(0, 0, 0);
	pt[1].set(1, 0, 0);
	pt[2].set(0, 1, 0);
	pt[3].set(0, 0, 1);

	numFaces= 4;
	face = new Face[numFaces];

	arr[0] = 1, arr[1] = 2; arr[2] = 3;
	setUpFace(0, arr, 3);

	arr[0] = 0, arr[1] = 2; arr[2] = 1;
	setUpFace(1, arr, 3);

	arr[0] = 0, arr[1] = 3; arr[2] = 2;
	setUpFace(1, arr, 3);

	arr[0] = 1, arr[1] = 3; arr[2] = 0;
	setUpFace(1, arr, 3);
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
			
			ic = ic % COLORNUM;

			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]); 
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}



