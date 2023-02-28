#pragma once //stops circular dependency
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

struct Vector3 {
	float x;
	float y;
	float z;
};

struct Camera {
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

class HelloGL
{
private:
	float rotation;

	Camera* camera;

	static Vertex vertices[];
	static Colour colours[];

	static Vertex indexedVertices[];
	static Colour indexedColours[];
	static GLushort indices[];
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);
	//destructor definition
	~HelloGL(void);
	void Display();
	void DrawPolygon();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void DrawCube();
	void DrawIndexedCube();
	void DrawCubeArrayAlt();
	void DrawIndexedCubeAlt();
};

