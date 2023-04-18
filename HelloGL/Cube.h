#pragma once
#include "Structures.h"
#include "SceneObject.h"

class Cube : public SceneObject
{
private:
	Vector3 _position;

	GLfloat rotationDir;
	GLfloat rotation;
	float rotateFactor;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

