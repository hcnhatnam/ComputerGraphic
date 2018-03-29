#if !defined (_MESH_CLASS)
#define _MESH_CLASS

#include "supportClass.h"


class VertexID
{
public:
	int		vertIndex;
	int		colorIndex;
};

class Face
{
public:
	int		nVerts;
	VertexID*	vert;
	
	Face()
	{
		nVerts	= 0;
		vert	= NULL;
	}
	~Face()
	{
		if(vert !=NULL)
		{
			delete[] vert;
			vert = NULL;
		}
		nVerts = 0;
	}
};

class Mesh
{
public:
	int		numVerts;
	Point3*		pt;
	
	int		numFaces;
	Face*		face;
public:
	Mesh()
	{
		numVerts	= 0;
		pt		= NULL;
		numFaces	= 0;
		face		= NULL;
	}
	~Mesh()
	{
		if (pt != NULL)
		{
			delete[] pt;
		}	
		if(face != NULL)
		{
			delete[] face;
		}
		numVerts = 0;
		numFaces = 0;
	}


	void setUpFace(int indexFace, int arrVretex[], int numVerts);

	void DrawWireframe();
	void DrawColor();
	void CreateCuboid(float fSizeX, float fSizeY, float fSizeZ);
	void CreateCuboWithThick(float fSizeX, float fSizeY, float fSizeZ, float thick);
	void supportCreateCuboWithThick(int i);
	void DrawThick(int indexface,int delta);
	void DrawThickBack(int indexface, int delta, int flat);
	void CreateCylinde(float radius, float height, float rotation);
	void Cylinder(float radius, float height, float rotation);
	void TopDownCylinder(int index, int center,int vertex);
	void AroundCylinder();
	void DrawAroundBai5(int start);
	void DrawTopDownBai5(int start);
    void CreateOvanAdvan(float R1, float R2, float height, float lenght);
	void CreateOvan(float R, float height, float lenght);
	void CreateTetrahedron();
	void CreateCube(float	fSize);
};

#endif