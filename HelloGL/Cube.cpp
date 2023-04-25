#include "Cube.h"
#include <iostream>
#include <fstream>


Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh,texture)
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
		//glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, objTexture->GetID());
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		
		glColorPointer(3, GL_FLOAT, 0, objMesh->Colours);
		glVertexPointer(3, GL_FLOAT, 0, objMesh->Vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, objMesh->TexCoords);
		
		
		glPushMatrix();
			glTranslatef(_position.x, _position.y, _position.z);
			glRotatef(rotation * rotateFactor, 1.0f, 1.0f, 1.0f);
			glDrawElements(GL_TRIANGLES, objMesh->indexCount, GL_UNSIGNED_SHORT, objMesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		//glPopMatrix();
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

