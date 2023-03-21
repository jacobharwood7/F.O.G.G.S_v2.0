#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include"Structures.h"

class Cube
{
private:
	static Vertex* indexedVertices;
	static Colour* indexedColours;
	static GLushort* indices;
	
	static int numVertices, numColours, numIndices;

	Vector3 _position;

	GLfloat rotation;
	float rotateFactor;

public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	static bool Load(char* path);
};

