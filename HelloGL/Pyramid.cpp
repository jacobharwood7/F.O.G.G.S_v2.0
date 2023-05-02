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

	if (objMesh->Normals != nullptr && objMesh->Vertices != nullptr && objMesh->Indices != nullptr)
	{
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, objMesh->Vertices);
		glNormalPointer( GL_FLOAT, 0, objMesh->Normals);

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, objMesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		glPopMatrix();
	}

}

void Pyramid::Update()
{
	
}

