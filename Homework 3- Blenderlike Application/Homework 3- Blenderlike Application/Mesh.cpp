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
			GLfloat specular[] = { .628281, 0.555802f, 0.366065f, 1.0f };
			GLfloat ambient[] = { 0.24725f, 0.1995f, 0.0745f, 1.0f };
			GLfloat diffuse[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
			GLfloat shiny[] = { .4f * 128 };
			glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
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
			double t = j;
			t /= (noVerts - 1);
			pt[noVerts*i+j] = Point3(centerX + sqrt(base[i].x*base[i].x) * cos(2 * PI*t), base[i].y, centerY + sqrt(base[i].x*base[i].x) * sin(2 * PI*t));
			std::cout << pt[noVerts*i + j];
		}
	}

	// create side faces

	std::cout << numFaces << std::endl;
	for (int i = 0; i < base.size(); i++) {
		for (int j = 0; j < noVerts;j++) {
			int k = i*noVerts + j;
			std::cout << k << std::endl;
			face[k].nVerts = 4;
			face[k].vert = new VertexID[4];
			if (j < noVerts - 1) {

				face[k].vert[0].vertIndex = i*noVerts;
				face[k].vert[1].vertIndex = i*noVerts + j;
				face[k].vert[2].vertIndex = i*noVerts + noVerts + j;
				face[k].vert[3].vertIndex = i*noVerts + noVerts;
			}
			else {
			face[k].vert[0].vertIndex = i*noVerts;
			face[k].vert[1].vertIndex = 0;
			face[k].vert[2].vertIndex = noVerts;
			face[k].vert[3].vertIndex = i*noVerts + noVerts;
			}
		}
	}
	ready2draw = true;
}

void Mesh::initRev(int initSize, int noVerts)
{
	numVerts = initSize*noVerts;
	numFaces = noVerts*initSize/(initSize-1);
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