#include "Texture2D.h"

#include <iostream>
#include <fstream>
using namespace std;

Texture2D::Texture2D()
{
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
    char* tempTextureData; int fileSize; ifstream inFile;
    _width = width; _height = height;
    inFile.open(path, ios::binary);
    if (!inFile.good())
    {
        cerr << "Can't open the texture file!!!!" << path << endl;
        return false;
    }

    inFile.seekg(0, ios::end);//seek to end of file
    fileSize = (int)inFile.tellg();//get current position- the end, gives total file size
    tempTextureData = new char[fileSize];//new array to store data
    inFile.seekg(0, ios::beg);//back to beginning of file.

    inFile.read(tempTextureData, fileSize);
    inFile.close();
    cout << path << "loaded" << endl;
    
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    delete[] tempTextureData;
    return true;
}
