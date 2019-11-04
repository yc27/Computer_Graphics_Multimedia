#include <GL/glut.h>
using namespace std;

void set_pixel(double x,double y)
{
    glColor3f(0.0f,0.0f,0.0f);

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    double x1 = 0, y1 = 0, x2 = 1, y2 = 1, dx, dy, dT, dS, d;
    dx = x2-x1;
    dy = y2-y1;
    dT = 2 * dy - dx;
    dS = 2 * dy;
    d = 2 * dy - dx;
    set_pixel(x1,y1);
    while(x1 <= x2 && y1 <= y2)
    {
        x1 += 0.0001;
        if(d < 0)
            d += dS;

        else
        {
            y1 += 0.0001;
            d += dT;
        }
        set_pixel(x1,y1);
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Bresenham's Line");
    glClearColor(0.1f, 0.5f, 0.9f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


