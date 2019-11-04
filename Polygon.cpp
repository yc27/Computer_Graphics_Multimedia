#include <GL/glut.h>
#include<bits/stdc++.h>
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

void drawPolygon(vector<point*> points)
{
    glBegin(GL_POLYGON);

    for(int i = 0; i < points.size(); ++i)
    {
        glColor3f(points[i]->r, points[i]->g, points[i]->b);
        glVertex2f(points[i]->x, points[i]->y);
    }

    glEnd();
}

void drawPolygon(vector<point> points)
{
    glBegin(GL_POLYGON);

    for(int i = 0; i < points.size(); ++i)
    {
        glColor3f(points[i].r, points[i].g, points[i].b);
        glVertex2f(points[i].x, points[i].y);
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    vector<point*> points;
    points.push_back( new point(-0.4, 0.2, 0.2f, 0.2f, 1.0f) );
    points.push_back( new point(0.0, 0.6, 0.2f, 0.2f, 1.0f) );
    points.push_back( new point(0.4, 0.2, 0.2f, 0.2f, 1.0f) );
    points.push_back( new point(0.4, -0.2, 0.2f, 0.2f, 1.0f) );
    points.push_back( new point(0.0, -0.6, 0.2f, 0.2f, 1.0f) );
    points.push_back( new point(-0.4, -0.2, 0.2f, 0.2f, 1.0f) );
    drawPolygon(points);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Polygon");
    glClearColor(0.1f, 0.5f, 0.9f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
