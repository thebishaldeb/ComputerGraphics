#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
int main()
{
	int x1, y1, x2, y2, p, x, y, s1 = 1, s2 = 1;
	printf("Enter x1, y1, x2, y2\n");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	printf("\nx1 = %d, y1 = %d, x2 = %d, y2 = %d\n", x1, y1, x2, y2);
	x = x1;
	y = y1;
	int dx = x2 - x1;
	int dy = y2 - y1;

	if (dx > 0)
		s1 = 1;
	else
		s2 = -1;
	if (dy > 0)
		s2 = 1;
	else
		s1 = -1;
	int swap = 0;
	int temp = 0;

	if (dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		swap = 1;
	}

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	p = 2 * dy - dx;
	int i;
	for (i = 0; i < dx; i++)
	{
		putpixel(x, y, i % 16);
		while (p >= 0)
		{
			if (swap == 1)
				x += s1;
			else
				y += s2;
			p += 2 * dy - 2 * dx;
		}
		if (swap == 1)
			y += s2;
		else
			x += s1;
		p += 2 * dy;
	}
	getch();
	closegraph();
	return 0;
}
