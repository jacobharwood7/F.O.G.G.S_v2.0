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
	
	mat = new Material();


}

Cube::~Cube()
{
	delete mat;
	mat = nullptr;
}

void Cube::Draw()
{
	
	if (objMesh->Normals!=nullptr&& objMesh->Vertices!=nullptr&& objMesh->Indices!=nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, objTexture->GetID());
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		
		glNormalPointer(GL_FLOAT, 0, objMesh->Normals);
		glVertexPointer(3, GL_FLOAT, 0, objMesh->Vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, objMesh->TexCoords);
		
		DefMat();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(mat->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(mat->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(mat->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, mat->shine);
		
		glPushMatrix();
			glTranslatef(_position.x, _position.y, _position.z);
			glRotatef(rotation * rotateFactor, 1.0f, 1.0f, 1.0f);
			glDrawElements(GL_TRIANGLES, objMesh->indexCount, GL_UNSIGNED_SHORT, objMesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	
}

void Cube::Update()
{
	rotation += 0.1f;
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
	/*_position.z += 1;
	if (_position.z >= 0)
	{
		_position.z = -500;
	}*/
}

void Cube::DefMat()
{
	
	mat->ambient.x = 0.8;mat->ambient.y = 0.05;mat->ambient.z = 0.05;
	mat->ambient.w = 1.0;
	mat->diffuse.x = 0.8; mat->diffuse.y = 0.05; mat->diffuse.z = 0.05;
	mat->diffuse.w = 1.0;
	mat->specular.x = 1.0; mat->specular.y = 1.0; mat->specular.z = 1.0;
	mat->specular.w = 1.0;
	mat->shine = 100.0f;
}

