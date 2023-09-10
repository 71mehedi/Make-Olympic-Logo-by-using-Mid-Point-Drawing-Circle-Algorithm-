#include <windows.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + pntX1, y + pntY1);
    glEnd();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircleAlgo(int xCenter, int yCenter, int radius, float r, float g, float b)
{
    int x = 0;
    int y = radius;
    float decision = 5.0 / 4 - radius;
    glColor3f(r, g, b); // Set the color for the circle
    plot(x + xCenter, y + yCenter);

    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            decision += 2 * (x - y) + 1;
        }
        plot(x + xCenter, y + yCenter);
        plot(x + xCenter, -y + yCenter);
        plot(-x + xCenter, y + yCenter);
        plot(-x + xCenter, -y + yCenter);
        plot(y + xCenter, x + yCenter);
        plot(-y + xCenter, x + yCenter);
        plot(y + xCenter, -x + yCenter);
        plot(-y + xCenter, -x + yCenter);
    }
}

void drawOlympicLogo()
{

    midPointCircleAlgo(150, 300, 60, 0.0f, 0.0f, 1.0f);  // Blue
    midPointCircleAlgo(450, 300, 60, 0.0f, 1.0f, 0.0f);  // Green
    midPointCircleAlgo(225, 240, 60, 1.0f, 1.0f, 0.0f);  // Yellow
    midPointCircleAlgo(300, 300, 60, 0.0f, 0.0f, 0.0f);  // Black
    midPointCircleAlgo(375, 240, 60, 1.0f, 0.0f, 0.0f);  // Red
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);

    drawOlympicLogo();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Olympic Logo");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}
