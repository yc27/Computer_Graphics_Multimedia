#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

int n;
double xx[100], yy[100];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);

    //square
    glVertex2f(0.2f,0.2f);
    glVertex2f(0.8f,0.2f);

    glVertex2f(0.2,0.8f);
    glVertex2f(0.8f,0.8f);

    glVertex2f(0.2f,0.2f);
    glVertex2f(0.2,0.8f);


    glVertex2f(0.8f,0.2f);
    glVertex2f(0.8f,0.8f);
    //--------------

    double x_min = 0.2, y_min = 0.2, x_max = 0.8, y_max = 0.8, x, y;
    //lines
    for(int i = 0; i < 2*n; ++i)
    {
        x = xx[i];
        x = x < x_min ? x_min : x;
        x = x > x_max ? x_max : x;

        y = yy[i];
        y = y < y_min ? y_min : y;
        y = y > y_max ? y_max : y;
        glVertex2f(x, y);
    }
    //----------

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    cin >> n;
    for(int i = 0; i < 2*n; ++i)
        cin >> xx[i] >> yy[i];

    glutInit(&argc, argv);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Square");
    glClearColor(1.1f, 1.5f, 0.9f, 1.5f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


/*
4
0.7 0.5
1.0 0.5
0.4 0.4
0.4 0.1
0.4 0.6
0.1 0.6
0.6 1.0
0.6 0.6
*/

