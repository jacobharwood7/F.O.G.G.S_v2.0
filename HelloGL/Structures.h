#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

struct Vector3 
{
	float x;
	float y;
	float z;
};

struct Vector4 
{
	float x, y, z, w;
};

struct Camera 
{
	//camera location in world space
	Vector3 eye;
	//where the camera looks at regardless of position
	Vector3 center;
	//orientation of the camera
	Vector3 up;
};

struct Colour
{
	GLfloat r, g, b;
};
struct Vertex
{
	GLfloat x, y, z;
};
struct TexCoord
{
	GLfloat u, v;
};
struct Mesh
{
	Vertex* Vertices;
	//Colour* Colours;
	Vector3* Normals;
	GLushort* Indices;
	TexCoord* TexCoords;
	int vertexCount, normalCount, indexCount, texCoordCount;
};

struct Lighting {
	Vector4 ambient, diffuse, specular;
};
struct Material {
	Vector4 ambient, diffuse, specular;
	GLfloat shine;
};


