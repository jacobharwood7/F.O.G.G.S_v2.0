#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Cool Square");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE,GLUTCallbacks::Timer, REFRESHRATE);
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
	rotation += 0.5f;

	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
	glutPostRedisplay();
}

HelloGL::~HelloGL(void)
{

}