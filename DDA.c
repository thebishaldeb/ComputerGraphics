#include <stdio.h>
#include <graphics.h>
#include <math.h>

void lineDDA(double x1, double y1, double x2, double y2)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    double dx, dy, x, y, del, delx, dely;
    int i;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    if (abs(dx) > abs(dy))
        del = abs(dx);
    else
        del = abs(dy);
    delx = dx / del;
    dely = dy / del;
    putpixel(round(x), round(y), RED);
    for (i = 0; i < del; i++)
    {
        x += delx;
        y += dely;
        int color = i < del / 2 ? 2 : 4;
        putpixel(round(x), round(y), color);
    }
    getch();
    closegraph();
}

int main()
{
    double x1, y1, x2, y2;
    printf("\nEnter x1, y1, x2, y2\n");
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    printf("\nx1 = %lf, y1 = %lf, x2 = %lf, y2 = %lf\n", x1, y1, x2, y2);
    lineDDA(x1, y1, x2, y2);
    return 0;
}
