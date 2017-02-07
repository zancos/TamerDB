#include <QWidget>
#include "myglwidget.h"
#include <iostream>

MyGLWidget::MyGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	xRot = 0;
    yRot = 0;
    zRot = 0;
}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::initializeGL()
{

	//qglClearColor(Qt::black);
	glClearColor(0.1, 0, 0.2, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void MyGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
	glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
	glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
	glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

	draw();
}


void MyGLWidget::resizeGL(int w, int h)
{
	/*
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w/h, 0.01, 100.0);
	*/


	int side = qMin(w, h);
	glViewport((w - side) / 2, (h - side) / 2, side, side);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

#ifdef QT_OPENGL_ES_1
	glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
	glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
	glMatrixMode(GL_MODELVIEW);
	
}


void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		setXRotation(xRot + 8 * dy);
		setYRotation(yRot + 8 * dx);
		std::cout << "Mouse moved: " << dx << " " << dy << std::endl;
	}
	else if (event->buttons() & Qt::RightButton) {
		setXRotation(xRot + 8 * dy);
		setZRotation(zRot + 8 * dx);
		std::cout << "Mouse moved: " << dx << " " << dy << std::endl;
	}

	lastPos = event->pos();
	std::cout << "xRot: " << xRot;
	std::cout << " yRot: " << xRot;
	std::cout << " zRot: " << xRot << std::endl;
}

void MyGLWidget::setXRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != xRot) {
		xRot = angle;
		//emit xRotationChanged(angle);
		update();
	}
}

void MyGLWidget::setYRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != yRot) {
		yRot = angle;
		//emit yRotationChanged(angle);
		update();
	}
}

void MyGLWidget::setZRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != zRot) {
		zRot = angle;
		//emit zRotationChanged(angle);
		update();
	}
}

void MyGLWidget::qNormalizeAngle(int &angle)
{
	while (angle < 0)
		angle += 360 * 16;
	while (angle > 360)
		angle -= 360 * 16;
}

QSize MyGLWidget::minimumSizeHint() const
{
	return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
	return QSize(400, 400);
}

void MyGLWidget::draw()
{
	glColor3f(1, 0, 0);
	//qglColor(Qt::red);
	/*
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glVertex3f(-1, -1, 0);
	glVertex3f(-1, 1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(1, -1, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glNormal3f(0, -1, 0.707);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);
	glVertex3f(0, 0, 1.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glNormal3f(1, 0, 0.707);
	glVertex3f(1, -1, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 0, 1.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glNormal3f(0, 1, 0.707);
	glVertex3f(1, 1, 0);
	glVertex3f(-1, 1, 0);
	glVertex3f(0, 0, 1.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glNormal3f(-1, 0, 0.707);
	glVertex3f(-1, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(0, 0, 1.2);
	glEnd();
	*/

	drawPoint(1.5, 0, 0.8);
	drawPoint(-1.5, 0, 0.8);
	pointSpiral();

	glFlush();
}

void MyGLWidget::drawPoint(double x_pt, double y_pt, double z_pt) const
{
	glBegin(GL_POINTS);
	glVertex3f(x_pt, y_pt, z_pt);
	glEnd();
}

void MyGLWidget::pointSpiral()
{
	int i;

	for (i = 0; i < 30; i++)
	{
		double x = i;
		double y = i * 0.2;
		double z = i * 0.15;
		drawPoint(x, y, z);
	}
}