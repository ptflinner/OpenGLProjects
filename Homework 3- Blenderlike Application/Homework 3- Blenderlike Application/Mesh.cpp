//Patrick Flinner
//304607711
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
			Material();
			glBegin(GL_POLYGON);
			for (int v = 0; v < face[f].nVerts; v++) // for each one..
			{
				int in = face[f].vert[v].normIndex; // index of this normal
				int iv = face[f].vert[v].vertIndex; // index of this vertex
				glNormal3f(norm[in].x, norm[in].y, norm[in].z);
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
	CalculateVerts(base, noVerts);
	// create faces
	CalculateFaceVerts(base.size(), noVerts);
	//Create normal list
	CalculateNormal(base.size(),noVerts);
	CalculateFaceNorms(base.size(), noVerts);
	
	
	ready2draw = true;
}
void Mesh::CalculateVerts(std::vector<Point3> base,int noVerts) {
	for (int i = 0; i < base.size(); i++) {
		for (int j = 0; j < noVerts; j++) {
			double t = j;
			t /= (noVerts - 1);
			if (j == noVerts - 1) t = 1;
			pt[noVerts*i + j] = Point3(centerX + sqrt(base[i].x*base[i].x) * cos(2 * PI*t), base[i].y, centerY + sqrt(base[i].x*base[i].x) * sin(2 * PI*t));
		}
	}
}
void Mesh::CalculateNormal(int bSize,int noVerts) {
	int faceVert = 3;
	
	for (int f = 0; f < numFaces; f++) // draw each face
	{
		float normX = 0;
		float normY = 0;
		float normZ = 0;
		int j = 0;
		for (int v = 0; v < face[f].nVerts; v++) // for each one..
		{
			int iv = face[f].vert[v].vertIndex; // index of this vertex
			int iw = 0;
			
			if (j == face[f].nVerts-1){
				iw = face[f].vert[0].vertIndex;
			}
			else {
				iw = face[f].vert[v + 1].vertIndex;
			}

			normX += (((pt[iv].z) + (pt[iw].z)) * ((pt[iv].y) - (pt[iw].y)));
			normY += (((pt[iv].x) + (pt[iw].x)) * ((pt[iv].z) - (pt[iw].z)));
			normZ += (((pt[iv].y) + (pt[iw].y)) * ((pt[iv].x) - (pt[iw].x)));
			j++;
		}		
		norm[f] = Vector3(normX, normY, normZ);
		
	}
}
void Mesh::CalculateFaceVerts(int bSize, int noVerts) {
	for (int i = 0; i < bSize - 1; i++) {
		for (int j = 0; j < noVerts; j++) {
			int k = i*noVerts + j;
			face[k].nVerts = 4;
			face[k].vert = new VertexID[4];
			if (j < noVerts - 1) {

				face[k].vert[0].vertIndex = i*noVerts + j;
				face[k].vert[1].vertIndex = i*noVerts + j + 1;
				face[k].vert[2].vertIndex = (i + 1)*noVerts + j + 1;
				face[k].vert[3].vertIndex = (i + 1)*noVerts + j;
			}
			else {
				face[k].vert[0].vertIndex = i*noVerts + j;
				face[k].vert[1].vertIndex = i*noVerts;
				face[k].vert[2].vertIndex = (i + 1)*noVerts;
				face[k].vert[3].vertIndex = (i + 1)*noVerts + j;
			}
		}
	}
}
void Mesh::CalculateFaceNorms(int bSize, int noVerts)
{
	for (int i = 0; i < bSize - 1; i++) {
		for (int j = 0; j < noVerts; j++) {
			int k = i*noVerts + j;
			if (j < noVerts - 1) {

				face[k].vert[0].normIndex = i*noVerts + j;
				face[k].vert[1].normIndex = i*noVerts + j + 1;
				face[k].vert[2].normIndex = (i + 1)*noVerts + j + 1;
				face[k].vert[3].normIndex = (i + 1)*noVerts + j;
			}
			else {
				face[k].vert[0].normIndex = i*noVerts + j;
				face[k].vert[1].normIndex = i*noVerts;
				face[k].vert[2].normIndex = (i + 1)*noVerts;
				face[k].vert[3].normIndex = (i + 1)*noVerts + j;
			}
		}
	}
}
void Mesh::initRev(int initSize, int noVerts)
{
	numVerts = initSize*noVerts;
	numFaces = noVerts*(initSize-1);
	numNormals = noVerts*(initSize - 1);

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

Point3 Mesh::Focus() {
	int maxX=0;
	int maxY=0;
	int maxZ=0;
	for (int i = 0; i < numVerts; i++) {
		if (pt[i].x > maxX) maxX = pt[i].x;
		if (pt[i].y > maxX) maxY = pt[i].y;
		if (pt[i].z > maxX) maxZ = pt[i].z;
	}

	return Point3(maxX, maxY/2, maxZ);
}

void Mesh::ChangeMaterial() {
	material++;
	material=material % 7;
}

void Mesh::Material() {
	if (material == 0) {
		GLfloat specular[] = { .628281, 0.555802f, 0.366065f, 1.0f };
		GLfloat ambient[] = { 0.24725f, 0.1995f, 0.0745f, 1.0f };
		GLfloat diffuse[] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
		GLfloat shiny[] = { .4f * 128 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
	}
	else if (material == 1) {
		GLfloat specular[] = { .5, 0.5f, 0.5f, 1.0f };
		GLfloat ambient[] = { 0.0f, 0.0f, 0.00f, 1.0f };
		GLfloat diffuse[] = { 0.01f, 0.01f, 0.01f, 1.0f };
		GLfloat shiny[] = { .25f * 128 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
	}
	else if (material == 2) {
		GLfloat specular[] = { .50196078, 0.50196078f, 0.050196078f, 1.0f };
		GLfloat ambient[] = { 0.0f, 0.1f, 0.06f, 1.0f };
		GLfloat diffuse[] = { 0.0f, 0.50980392f, 0.50980392f, 1.0f };
		GLfloat shiny[] = { .25f * 128 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
	}
	else if (material == 3) {
		GLfloat specular[] = { .45, 0.55f, 0.45f, 1.0f };
		GLfloat ambient[] = { 0.0f, 0.0f, 0.00f, 1.0f };
		GLfloat diffuse[] = { 0.1f, 0.35f, 0.1f, 1.0f };
		GLfloat shiny[] = { .25f * 128 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
	}
	else if (material == 4) {
		GLfloat specular[] = { .7, 0.6f, 0.6f, 1.0f };
		GLfloat ambient[] = { 0.0f, 0.0f, 0.00f, 1.0f };
		GLfloat diffuse[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat shiny[] = { .25f * 128 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
	}
	else if (material == 5) {
		GLfloat specular[] = { .7, 0.7f, 0.7f, 1.0f };
		GLfloat ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat diffuse[] = { 0.55f, 0.55f, 0.55f, 1.0f };
		GLfloat shiny[] = { .25f * 128 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
	}
	else if (material == 6) {
		GLfloat specular[] = { .6, 0.6f, 0.5f, 1.0f };
		GLfloat ambient[] = { 0.0f, 0.f, 0.0f, 1.0f };
		GLfloat diffuse[] = { 0.5f, 0.5f, 0.0f, 1.0f };
		GLfloat shiny[] = { .4f * 128 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shiny);
	}

}