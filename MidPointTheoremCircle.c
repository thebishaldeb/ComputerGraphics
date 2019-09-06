#include <stdio.h>
#include <graphics.h>
#include <math.h>

void setPoints(int xc, int yc, int xp, int yp)
{
    putpixel(xc + xp, yc + yp, 1);
    putpixel(xc - xp, yc + yp, 2);
    putpixel(xc + xp, yc - yp, 3);
    putpixel(xc - xp, yc - yp, 4);
    putpixel(xc + yp, yc + xp, 5);
    putpixel(xc - yp, yc + xp, 6);
    putpixel(xc + yp, yc - xp, 7);
    putpixel(xc - yp, yc - xp, 8);
}

void MidPtCircle(int xc, int yc, int radius)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    int x = 0, y = radius, p = 1 - radius;

    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        setPoints(xc, yc, x, y);
    }
    getch();
    closegraph();
}

int main()
{
    int x, y, radius;
    printf("\nEnter x, y and radius\n");
    scanf("%d%d%d", &x, &y, &radius);
    printf("\nx = %d, y = %d, radius = %d, y2 = %d\n", x, y, radius);
    MidPtCircle(x, y, radius);
    return 0;
}
