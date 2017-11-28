//Patrick Flinner
//Homework 3
//November 30, 2017

#include "Point3.h"
#include "Vector3.h"

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

public:
	int ready2draw;
	Mesh();
	~Mesh();

	void initPrism(int noVerts);
	void createPrism(int noVerts, Point3 *p, float length);
	void drawWireframe();
	void drawSolid();

};
