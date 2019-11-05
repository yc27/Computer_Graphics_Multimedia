#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

void plot_point(int x, int y, int xc, int yc)
{
    glBegin(GL_POINTS);
    glVertex2i( xc + x, yc + y );
    glVertex2i( xc + x, yc - y );
    glVertex2i( xc + y, yc + x );
    glVertex2i( xc + y, yc - x );
    glVertex2i( xc - x, yc - y );
    glVertex2i( xc - y, yc - x );
    glVertex2i( xc - x, yc + y );
    glVertex2i( xc - y, yc + x );
    glEnd();
}

void bresenham_circle(int r)
{
    int x = 0, y = r, dx;

    plot_point(x, y, 0, 0);
    dx = 3 - 2 * r;

    x += 1;
    if(dx >= 0)
        y -= 1;

    while(x < y)
    {
        plot_point(x, y, 0, 0);
        if(dx < 0)
            dx += 4 * x + 6;
        else
            dx += 4 * (x - y) + 10;

        if(dx >= 0)
            y -= 1;
        x += 1;
    }
}

void display()
{
    glClearColor(0.5, 0.5, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    bresenham_circle(50);

    glutSwapBuffers();
}

int main( int argc, char** argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow("Bresenham's Circle");
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
