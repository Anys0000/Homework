// les22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>

void drawFractalRectangle(double x1, double y1, double x2, double y2, int level)
{
	if (level == 0) {
		glRectd(x1, y1, x2, y2);
	}
	else {
		const double D = (x2 - x1) / 3;
		double xa = x1 + D;
		double xb = x2 - D;
		double ya = y1 + D;
		double yb = y2 - D;
		double x[] = { x1,xa,xb,x2 };
		double y[] = { y1,ya,yb,y2 };
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (i == 1 && j == 1)
					continue;
				drawFractalRectangle(x[i], y[j], x[i + 1], y[j + 1], level - 1);
			}
		}
	}
}

void displayFunction()
{
	glClear( GL_COLOR_BUFFER_BIT );

	const int n = 9;

	glColor3f(0.0, 0, 0);

	drawFractalRectangle(-1.0, -1.0, 1.0, 1.0, n);

	glFlush();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv );
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Fractal");
	glutDisplayFunc(displayFunction);
	glClearColor(1, 1, 1, 0);
	glutMainLoop();
	return 0;
}
	

