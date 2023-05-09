#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc,argv);
	InitObjects();
	InitLight(); 
	
	glutMainLoop();
}

void HelloGL::InitObjects()
{
	Texture2D* cubeText = new Texture2D();
	cubeText->Load((char*)"Penguins.raw", 512, 512);

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");

	//Mesh* pyraMesh = MeshLoader::Load((char*)"pyramid.txt");

	camera = new Camera();
	for (int i = 0; i < 500; i++)
	{
		objects[i] = new Cube(cubeMesh, cubeText,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 500));
	}
	/*for (int i = 500; i < 1000; i++)
	{
		objects[i] = new Pyramid(pyraMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 500));
	}*/
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -50.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	
}

void HelloGL::InitLight()
{
	lightPosition = new Vector4();
	lightPosition->x = 0.0;
	lightPosition->y = 0.0;
	lightPosition->z = 10.0;
	lightPosition->w = 0.0;

	lightData = new Lighting();
	lightData->ambient.x = 0.2;
	lightData->ambient.y = 0.2;
	lightData->ambient.z = 0.2;
	lightData->ambient.w = 1.0;
	lightData->diffuse.x = 0.8;
	lightData->diffuse.y = 0.8;
	lightData->diffuse.z = 0.8;
	lightData->diffuse.w = 1.0;
	lightData->specular.x = 0.2;
	lightData->specular.y = 0.2;
	lightData->specular.z = 0.2;
	lightData->specular.w = 1.0;



}

void HelloGL::InitGL(int argc, char* argv[])
{	
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Program ");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE,GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 500);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
}


void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < 500; i++)
	{
		objects[i]->Draw();
	}
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	//
	//gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
	//	camera->center.x, camera->center.y, camera->center.z,
	//	camera->up.x, camera->up.y, camera->up.z);
	
	for (int i = 0; i < 500; i++)
	{
		objects[i]->Update();
	}
	
	/*Light*/
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(lightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(lightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(lightData->specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(lightPosition->x));


	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if(key == 'd')
	{
		//rotation += 0.5f;
		camera->eye.x += 0.1f;
		//camera->center.x += 0.1f;

	}

	if (key == 'a')
	{
		//rotation -= 0.5f;
		camera->eye.x -= 0.1f;
		//camera->center.x -= 0.1f;


	}
	if (key == 'w')
	{
		camera->eye.y += 0.1f;
		//camera->center.y += 0.1f;


	}
	if (key == 's')
	{
		camera->eye.y -= 0.1f;
		//camera->center.y -= 0.1f;

	}
	
}





HelloGL::~HelloGL(void)
{
	delete camera;
}