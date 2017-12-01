//Patrick Flinner
//304607711
//Homework 3
//November 30, 2017

#include "Point3.h"
#include "Vector3.h"
#include <vector>
#define PI 3.1415
//################# VertexID ###################
class VertexID {
public:
	int vertIndex; // index of this vert in the vertex list
	int normIndex; // index of this vertex's normal
};


//#################### Face ##################
class Face {
public:
	int nVerts; // number of vertices in this face
	VertexID * vert; // the list of vertex and normal indices
	Face() { nVerts = 0; vert = NULL; } // constructor
	~Face() { delete[] vert; nVerts = 0; } // destructor
};

//##################### SURFACE ################
class Surface {
public:

};
//###################### Mesh #######################
class Mesh {
private:
	int numVerts;	// number of vertices in the mesh
	Point3* pt;	      // array of 3D vertices
	int numNormals;   // number of normal vectors for the mesh
	Vector3 *norm;    // array of normals 
	int numFaces; 	// number of faces in the mesh
	Face* face;	      // array of face data
	int centerX;
	int centerY;
	int material;
public:
	int ready2draw;
	Mesh();
	~Mesh();

	void drawWireframe();
	void drawSolid();
	void createRevolution(std::vector<Point3> base,int noVerts);
	void CalculateNormal(int bSize,int noVerts);
	void CalculateVerts(std::vector<Point3> base,int noVerts);
	void CalculateFaceVerts(int bSize, int noVerts);
	void CalculateFaceNorms(int bSize, int noVerts);
	void initRev(int initSize, int noVerts);
	Point3 Focus();
	void ChangeMaterial();
	void Material();
};
