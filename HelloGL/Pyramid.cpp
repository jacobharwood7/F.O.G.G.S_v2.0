#include "Pyramid.h"
#include <iostream>
#include <fstream>


Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

}

Pyramid::~Pyramid()
{
}

void Pyramid::Draw()
{

	if (objMesh->Colours != nullptr && objMesh->Vertices != nullptr && objMesh->Indices != nullptr)
	{
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

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

void Pyramid::Update()
{
	
}

