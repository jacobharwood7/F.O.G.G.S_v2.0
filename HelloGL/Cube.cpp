#include "Cube.h"
#include <iostream>
#include <fstream>
#include <string>
Vertex* Cube::indexedVertices = nullptr; // v6,v7

Colour* Cube::indexedColours = nullptr; //v6,v7

GLushort* Cube::indices = nullptr;    // back

int Cube::numVertices = 0;
int Cube::numColours = 0;
int Cube::numIndices = 0;


Cube::Cube(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	rotation = 0;
	rotateFactor = ((rand() % 100)/10.0f);
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	if (indexedColours!=nullptr&&indexedVertices!=nullptr&&indices!=nullptr)
	{
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(rotation * rotateFactor, 1.0f, 1.0f, 1.0f);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
		glColorPointer(3, GL_FLOAT, 0, indexedColours);

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
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
}

bool Cube::Load(char* path)
{
	std::ifstream inFile(path);
	std::string line;
	if (!inFile.good())
	{
		std::cerr << "I cannot open the text file! HELP! " << path << std::endl;
		return false;
	}

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{  
		std::getline(std::cin, line);
		for (int j = 0; j < size(line); i++)
		{

		}
	}

	inFile >> numColours;
	indexedColours = new Colour[numColours];
	for (int i = 0; i < numColours; i++)
	{
		blank = inFile.get();
		indexedColours[i].r = inFile.get();
		blank = inFile.get();
		indexedColours[i].g = inFile.get();
		blank = inFile.get();
		indexedColours[i].b = inFile.get();
	}
	
	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++)
	{
		blank = inFile.get();
		indices[i] = inFile.get();
	}
	
	inFile.close();


	return true;
}
