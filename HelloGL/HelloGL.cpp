#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	
	camera = new Camera();
	camera->eye.x = 0.0f;camera->eye.y = 0.0f;camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;



	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Program ");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE,GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	glFlush();
	glutSwapBuffers();
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	/*glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 0.0f, -1.0f, 0.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.5);

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.5, -0.5);

		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.5, -0.5);
		
		

		glEnd();
	}
	*/
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glutWireTeapot(0.1);
	glPopMatrix();

}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, 
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if(key == 'd')
	{
		//rotation += 0.5f;
		camera->eye.x += 0.1f;
		camera->center.x += 0.1f;

	}

	if (key == 'a')
	{
		//rotation -= 0.5f;
		camera->eye.x -= 0.1f;
		camera->center.x -= 0.1f;


	}
	if (key == 'w')
	{
		camera->eye.y += 0.1f;
		camera->center.y += 0.1f;


	}
	if (key == 's')
	{
		camera->eye.y -= 0.1f;
		camera->center.y -= 0.1f;

	}
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
}

HelloGL::~HelloGL(void)
{
	delete camera;
}