#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture)
{
	objMesh = mesh;
	objTexture = texture;
}

SceneObject::~SceneObject()
{
	
}

void SceneObject::Update()
{
}

void SceneObject::Draw()
{
}
