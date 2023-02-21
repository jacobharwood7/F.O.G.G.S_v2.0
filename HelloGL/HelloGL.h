#pragma once //stops circular dependency
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

class HelloGL
{
private:
	float rotation;
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);
	//destructor definition
	~HelloGL(void);
	void Display();
	void DrawPolygon();
	void Update();
};

