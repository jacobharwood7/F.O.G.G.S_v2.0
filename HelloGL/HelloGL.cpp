#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Program ");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE,GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
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
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
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
	glPopMatrix();

}

void HelloGL::Update()
{
	
	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if(key == 'd')
	{
		rotation += 0.5f;
	}

	if (key == 'a')
	{
		rotation -= 0.5f;
	}
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
}

HelloGL::~HelloGL(void)
{

}