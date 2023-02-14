#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Cool Square");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	glFlush();

}

void HelloGL::DrawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.5, 0.5);
		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.5, 0.5);
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.5, -0.5);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(-0.5, -0.5);
		glEnd();
	}
}

HelloGL::~HelloGL(void)
{

}