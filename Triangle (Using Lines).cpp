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

void drawLine(point a, point b)
{
    glColor3f(a.r, a.g, a.b);
    glBegin(GL_LINES);

    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    point a(0.5, 0.5), b(-0.5, 0.5), c(-0.5, 0.8);
    
    drawLine(a, b);
    drawLine(a, c);
    drawLine(b, c);

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
