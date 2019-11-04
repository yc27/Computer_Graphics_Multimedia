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

    point a(0.0, -0.5, 0.2, 0.2, 1), b(0.0, 0.5, 0.2, 0.2, 1), c(-0.5, 0.0, 0.2, 0.2, 1), d(0.5, 0.0, 0.2, 0.2, 1);
    drawTriangle(a, b, c);  // left triangle
    drawTriangle(a, b, d);  // right triangle

    glFlush();

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rhombus");
    glClearColor(0.1f, 0.5f, 0.9f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



