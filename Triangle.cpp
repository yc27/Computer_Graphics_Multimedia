#include <GL/glut.h>
using namespace std;

struct point
{
    double x, y, r, g, b;

    point(double _x, double _y)
    {
        x = _x;
        y = _y;
        r = g = b = 0;
    }

    point(double _x, double _y, double _r, double _g, double _b)
    {
        x = _x;
        y = _y;
        r = _r;
        g = _g;
        b = _b;
    }
};

void drawTriangle(point a, point b, point c)
{
    glBegin(GL_TRIANGLES);

    glColor3f(a.r, a.g, a.b);
    glVertex2f(a.x, a.y);

    glColor3f(b.r, b.g, b.b);
    glVertex2f(b.x, b.y);

    glColor3f(c.r, c.g, c.b);
    glVertex2f(c.x, c.y);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // solid color triangle
    point a(0.0, 0.6, 0.0, 0.0, 1.0), b(-0.5, 0.1, 0.0, 0.0, 1.0), c(0.5, 0.1, 0.0, 0.0, 1.0);
    drawTriangle(a, b, c);

    // gradiant color triangle
    point d(-0.5, -0.1, 1.0, 0.0, 0.0), e(0.5, -0.1, 0.0, 1.0, 0.0), f(0.0, -0.6, 0.0, 0.0, 1.0);
    drawTriangle(d, e, f);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Triangle");
    glClearColor(0.1f, 0.5f, 0.9f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}






