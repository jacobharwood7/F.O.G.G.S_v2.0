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
	delete objMesh;
	objMesh = nullptr;

	delete objTexture;
	objTexture = nullptr;

	delete material;
	material = nullptr;

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
		
		DefineMats();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->ambient.x));
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->ambient.y));
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->ambient.z));
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->ambient.w));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->diffuse.y));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->diffuse.z));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->diffuse.w));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->specular.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->specular.y));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->specular.z));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->specular.w));//problem here read access violation 
		glMaterialf(GL_FRONT, GL_SHININESS, material->shine);


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

void Cube::DefineMats()
{
	material = new Material();
	material->ambient.x = 0.8;material->ambient.y = 0.05;material->ambient.z = 0.05;
	material->ambient.w = 1.0;
	material->diffuse.x = 0.8; material->diffuse.y = 0.05; material->diffuse.z = 0.05;
	material->diffuse.w = 1.0;
	material->specular.x = 1.0; material->specular.y = 1.0; material->specular.z = 1.0;
	material->specular.w = 1.0;
	material->shine = 100.0f;

}


