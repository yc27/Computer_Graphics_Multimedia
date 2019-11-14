#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

float x1 = -0.2, yy1 = 0.0, x2 = 0.2, y2 = 0.0, x3 = 0.0, y3 = 0.5;
bool flag = 1;

void idle()
{
    if(flag)
    {
        x1 -= 0.0001;
        x2 += 0.0001;
        x3 = (x1+x2) / 2;

        if(x2 >= 0.9f)
            flag = 0;
    }

    else
    {
        x1 += 0.0001;
        x2 -= 0.0001;
        x3 = (x1+x2) / 2;

        if(x2 <= 0.2f)
            flag = 1;
    }

    glutPostRedisplay();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0, 0, 1.0);

    glBegin(GL_POLYGON); //Begin triangle coordinates
    //Triangle
    glVertex2f(x1, yy1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd(); //End triangle coordinates


    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Animation");
    glClearColor(0.1f, 0.5f, 0.9f, 1.0f);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
