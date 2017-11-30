//Patrick Flinner
//Homework 3
//November 30, 2017

#include <windows.h>
#include <gl/Gl.h>
#include <iostream>
#include "Mesh.h"


// constructor
Mesh::Mesh()
{
	numVerts = 0;
	ready2draw = 0;
	numFaces = 0;
	norm = NULL;
	face = NULL;
}

// destructor
Mesh:: 	~Mesh()
{
	if (numVerts != 0) {
		delete[] pt;
		delete[] norm;
		delete[] face;
	}
}

// use OpenGL to draw this mesh in solid object mode
void Mesh::drawSolid() // use OpenGL to draw this mesh
{
	if (ready2draw) {
		for (int f = 0; f < numFaces; f++) // draw each face
		{
			glColor3f(f / (float)10, f / (float)10, f / (float)10);
			glBegin(GL_POLYGON);
			for (int v = 0; v < face[f].nVerts; v++) // for each one..
			{
				int in = face[f].vert[v].normIndex; // index of this normal
				int iv = face[f].vert[v].vertIndex; // index of this vertex
													//glNormal3f(norm[in].x, norm[in].y, norm[in].z);
				glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
			}
			glEnd();
		}
	}
}

void Mesh::createRevolution(std::vector<Point3> base, int noVerts)
{

	initRev(base.size(), noVerts);

	// create the vertex list
	for (int i = 0; i < base.size(); i++) {
		for (int j = 0; j < noVerts; j++) {
			pt[noVerts*i+j] = Point3(centerX + base[i].x * cos(2 * PI*i), base[i].y, centerY + base[i].x * sin(2 * PI*i));
		}
	}

	// create side faces

	for (int i = 0; i < noVerts; i++) {
		face[i].nVerts = 4;
		face[i].vert = new VertexID[4];
		if (i < noVerts - 1) {
			face[i].vert[0].vertIndex = i;
			face[i].vert[1].vertIndex = i + 1;
			face[i].vert[2].vertIndex = i + numFaces + 1;
			face[i].vert[3].vertIndex = i + numFaces;
		}
		else {
		face[i].vert[0].vertIndex = i;
		face[i].vert[1].vertIndex = 0;
		face[i].vert[2].vertIndex = 0 + 3;
		face[i].vert[3].vertIndex = i + 3;
		}
	}

	ready2draw = 1;
}

void Mesh::initRev(int initSize, int noVerts)
{
	numVerts = initSize*noVerts;
	numFaces = noVerts;
	numNormals = noVerts;

	pt = new Point3[numVerts];
	norm = new Vector3[numNormals];
	face = new Face[numFaces];

	centerX = 0;
	centerY = 0;
}


// use OpenGL to draw this mesh in wireframe mode
void Mesh::drawWireframe()
{
	if (ready2draw) {
		for (int f = 0; f <numFaces; f++) // draw each face
		{
			glColor3f(0.0f, 0.0f, 0.0f);
			glBegin(GL_LINE_LOOP);
			for (int v = 0; v < face[f].nVerts; v++) // for each one..
			{
				int iv = face[f].vert[v].vertIndex; // index of this vertex
				glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
			}
			glEnd();
		}
	}
}