#pragma once

#include <QWidget>
#include <QOpenGLWidget>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <math.h>
#include <QTimer>
#include <QKeyEvent>
#include <QWheelEvent>

class MyGLWidget : public QOpenGLWidget
{
public:
	MyGLWidget(QWidget *parent = 0);
	~MyGLWidget();
	//float angle;

//	QTimer updateTimer;

//	void setAngle(float a) { angle = a; }

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

	//void perspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);

	QSize minimumSizeHint() const;
	QSize sizeHint() const;
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);

	static void qNormalizeAngle(int &angle);

public slots:
	// slots for xyz-rotation slider
	void setXRotation(int angle);
	void setYRotation(int angle);
	void setZRotation(int angle);

signals:
	void xRotationChanged(int angle);
	void yRotationChanged(int angle);
	void zRotationChanged(int angle);

private:
	

	int xRot;
	int yRot;
	int zRot;

	void draw();
	void drawPoint(double x, double y, double z) const;
	void pointSpiral();

	QPoint lastPos;

};