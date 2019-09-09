#include <stdio.h>
#include <graphics.h>
#include <math.h>

void setPoints(int xc, int yc, int xp, int yp)
{
    putpixel(xc + xp, yc + yp, 1);
    putpixel(xc - xp, yc + yp, 2);
    putpixel(xc + xp, yc - yp, 3);
    putpixel(xc - xp, yc - yp, 4);
}

void MidPtCircle(int xc, int yc, int rx, int ry)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    int rx2 = rx * rx, ry2 = ry * ry, tworx2 = 2 * rx2, twory2 = 2 * ry2;
    int x = 0, y = ry, p, px = 0, py = tworx2 * y;

    setPoints(xc, yc, x, y);

    p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
    while (px < py)
    {
        x++;
        px += twory2;

        if (p < 0)
        {
            p += ry2 + px;
        }
        else
        {
            y--;
            py -= tworx2;
            p += ry2 + px - py;
        }
        setPoints(xc, yc, x, y);
    }
    p = round(ry2 * (0.5 + x) * (0.5 + x) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y > 0)
    {
        y--;
        py -= tworx2;

        if (p > 0)
        {
            p += rx2 - py;
        }
        else
        {
            x++;
            px += twory2;
            p += rx2 + px - py;
        }
        setPoints(xc, yc, x, y);
    }
    getch();
    closegraph();
}

int main()
{
    int xc, yc, rx, ry;
    printf("\nEnter xc, yc, x-radius, y-radius\n");
    scanf("%d%d%d%d", &xc, &yc, &rx, &ry);
    printf("\nxc = %d, yc = %d, rx = %d, ry = %d\n", xc, yc, rx, ry);
    MidPtCircle(xc, yc, rx, ry);
    return 0;
}
