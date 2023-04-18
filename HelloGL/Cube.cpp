#include "Cube.h"
#include <iostream>
#include <fstream>


Cube::Cube(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	rotation = 0;
	rotationDir = (rand() % 2);
	if (rotationDir == 0)
	{
		rotationDir = -1;
	}
	rotateFactor = rotationDir*((rand() % 100)/10.0f);
	
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	
	if (objMesh->Colours!=nullptr&& objMesh->Vertices!=nullptr&& objMesh->Indices!=nullptr)
	{
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(rotation * rotateFactor, 1.0f, 1.0f, 1.0f);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, objMesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, objMesh->Colours);

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, objMesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		glPopMatrix();
	}
	
}

void Cube::Update()
{
	rotation += 0.1f;
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
	_position.z += 1;
	if (_position.z >= 0)
	{
		_position.z = -500;
	}
}

