#pragma once //stops circular dependency
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "Pyramid.h"
#include "MeshLoader.h"


#define REFRESHRATE 16


class HelloGL
{
private:

	Camera* camera;

	SceneObject* objects[1000];

	Vector4* lightPosition;
	Lighting* lightData;

public:
	//constructor definition
	HelloGL(int argc, char* argv[]);
	//destructor definition
	~HelloGL(void);
	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);

	void InitObjects();
	void InitLight();
	void InitGL(int argc, char* argv[]);

};

