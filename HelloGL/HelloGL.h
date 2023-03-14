#pragma once //stops circular dependency
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"


#define REFRESHRATE 16


class HelloGL
{
private:

	Camera* camera;

	Cube* cube[200];
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);
	//destructor definition
	~HelloGL(void);
	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
};

