#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXSIZE 30

float xpos = -1,
      speedAngle = -30,
      limbsFlag = 1,
      incre = -1,
      HumanSpeed[MAXSIZE],
      HumanSpeedIncre[MAXSIZE];

int HouseOrTree[MAXSIZE];

class Point
{
public:
    float x, y;
    Point(float x1, float y1)
    {
        x = x1;
        y = y1;
    };
    Point()
    {
        x = 0;
        y = 0;
    };
};

void drawHouse(float, float),
    drawTrees(float, float),
    drawLines(float, float),
    drawHuman(float, float, float);

Point rotateAroundPt(float, float, float, float, float, int);

void idle()
{
    int f, var;
    float u;

    if (xpos <= 10)
    {
        for (f = 0; f < MAXSIZE; f++)
            HumanSpeedIncre[f] += HumanSpeed[f];
        xpos += 0.001;
    }
    else
    {
        xpos = xpos - 12;
        incre = 0;
        srand(time(0));
        for (f = 0; f < MAXSIZE; f++)
        {
            var = rand() % 2;
            HouseOrTree[f] = var;
            u = (rand() % 10) / 10000.0;
            HumanSpeed[f] = u;
            var = rand() % 14 - 7;
            HumanSpeedIncre[f] = var;
        }
    }
    if (speedAngle < -60 || speedAngle > 60)
    {
        limbsFlag = -limbsFlag;
        speedAngle += limbsFlag * 0.4;
    }
    else
        speedAngle += limbsFlag * 0.4;
    glutPostRedisplay();
}

void drawthis()
{
    glClearColor(1, 1, 1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPushMatrix();

    glPointSize(3);

    drawLines(0, 0.1);
    drawLines(0, -0.015);
    int k;
    for (k = 0; k < MAXSIZE; k++)
    {
        incre = 0.4 * k - 2.4;
        glTranslatef(-xpos, 0, 0);
        if (HouseOrTree[k] == 1)
            drawHouse(incre, 0.1);
        else
            drawTrees(incre, 0.1);
        glTranslatef(xpos, 0, 0);
        drawHuman(incre, 0.01, HumanSpeedIncre[k]);
    }
    glTranslatef(-xpos, 0, 0);
    drawHuman(0.4, 0.01, xpos);

    glPopMatrix();
    glutSwapBuffers();
    return;
}

void drawHouse(float x, float y)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + 1, 0 + y);
    glVertex2f(x + 1, 0.03 + y);
    glVertex2f(x + 0.7, 0.03 + y);
    glVertex2f(x + 0.7, 0 + y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(x + 0.99, 0.2 + y);
    glVertex2f(x + 0.85, 0.27 + y);
    glVertex2f(x + 0.71, 0.2 + y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(x + 0.97, 0.03 + y);
    glVertex2f(x + 0.97, 0.2 + y);
    glVertex2f(x + 0.73, 0.2 + y);
    glVertex2f(x + 0.73, 0.03 + y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(x + 0.88, y + 0.03);
    glVertex2f(x + 0.88, y + 0.12);
    glVertex2f(x + 0.82, y + 0.12);
    glVertex2f(x + 0.82, y + 0.03);
    glEnd();
}

void drawTrees(float x, float y)
{
    glColor3f(0.0, 1.0, y + 0.0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(x + 0.9, y + 0.0);
    glVertex2f(x + 0.9, y + 0.20);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(x + 1, y + 0.20);
    glVertex2f(x + 0.96, y + 0.31);
    glVertex2f(x + 0.98, y + 0.31);
    glVertex2f(x + 0.94, y + 0.4);
    glVertex2f(x + 0.96, y + 0.4);
    glVertex2f(x + 0.9, y + 0.5);
    glVertex2f(x + 0.84, y + 0.4);
    glVertex2f(x + 0.86, y + 0.4);
    glVertex2f(x + 0.82, y + 0.31);
    glVertex2f(x + 0.84, y + 0.31);
    glVertex2f(x + 0.8, y + 0.20);
    glEnd();
}

void drawLines(float x, float y)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + -1, y + 0.0);
    glVertex2f(x + 1, y + 0.0);
    glEnd();
}

Point rotateAroundPt(float px, float py, float cx, float cy, float speed, int flag)
{
    float xf, yf,
        theta = (0 + speed) * 3.14159 / 180;

    theta = flag == 1 ? theta : -theta;

    if (theta >= (2.0 * 3.14159))
        theta = theta - (2.0 * 3.14159);
    xf = cx + ((px - cx) * cos(theta)) - ((py - cy) * sin(theta));
    yf = cy + ((px - cx) * sin(theta)) + ((py - cy) * cos(theta));
    return Point(xf, yf);
}

void drawHuman(float x, float y, float speed)
{
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(speed, 0, 0);

    // Head
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2f(x + -1, y + 0.15);
    glEnd();

    // Body
    glPointSize(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + -1, y + 0.15);
    glVertex2f(x + -1, y + 0.06);
    glEnd();

    // Hands
    Point p = rotateAroundPt(x + -1, y + 0.10, x + -1, y + 0.14, speedAngle, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + -1, y + 0.14);
    glVertex2f(p.x, p.y);
    glEnd();
    Point p1 = rotateAroundPt(x + -1, y + 0.14, p.x, p.y, 120, -1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(p.x, p.y);
    glVertex2f(p1.x, p1.y);
    glEnd();

    Point q = rotateAroundPt(x + -1, y + 0.1, x + -1, y + 0.14, speedAngle, -1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + -1, y + 0.14);
    glVertex2f(q.x, q.y);
    glEnd();
    Point q1 = rotateAroundPt(x + -1, y + 0.14, q.x, q.y, 120, -1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(q.x, q.y);
    glVertex2f(q1.x, q1.y);
    glEnd();

    // Legs
    Point r = rotateAroundPt(x + -1, y + 0.02, x + -1, y + 0.06, speedAngle, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + -1, y + 0.06);
    glVertex2f(r.x, r.y);
    glEnd();
    Point r1 = rotateAroundPt(x + -1, y + 0.06, r.x, r.y, 150, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(r.x, r.y);
    glVertex2f(r1.x, r1.y);
    glEnd();

    Point s = rotateAroundPt(x + -1, y + 0.02, x + -1, y + 0.06, speedAngle, -1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x + -1, y + 0.06);
    glVertex2f(s.x, s.y);
    glEnd();
    Point s1 = rotateAroundPt(x + -1, y + 0.06, s.x, s.y, 150, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(s.x, s.y);
    glVertex2f(s1.x, s1.y);
    glEnd();
    glTranslatef(-speed, 0, 0);
}

int main(int argc, char **argv)
{
    int i, var;
    float u;
    srand(time(0));
    for (i = 0; i < MAXSIZE; i++)
    {
        var = rand() % 2;
        HouseOrTree[i] = var;
        u = (rand() % 10) / 10000.0;
        HumanSpeed[i] = u;
        var = rand() % 14 - 10;
        HumanSpeedIncre[i] = var;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(730, 100);
    glutCreateWindow("Scenery");
    glutDisplayFunc(drawthis);
    glutIdleFunc(idle);
    glutMainLoop();
}
