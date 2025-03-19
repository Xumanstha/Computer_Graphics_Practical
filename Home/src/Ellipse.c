#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

void DrawEllipse(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, YELLOW);
    putpixel(xc - x, yc + y, YELLOW);
    putpixel(xc + x, yc - y, YELLOW);
    putpixel(xc - x, yc - y, YELLOW);
}

int main() {
    int gdriver = DETECT, gmode, i;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gdriver, &gmode, data);

    int a, b, xc, yc, x, y;
    float p1, p2;

    printf("Enter the semi-major axis and semi-minor axis\n");
    scanf("%d%d", &a, &b);

    printf("Enter the Center Coordinates of ellipse\n");
    scanf("%d%d", &xc, &yc);

    // Region 1
    x = 0;
    y = b;
    p1 = b * b - a * a * b + 0.25 * a * a;
    int param1 = 2 * b * b * x;
    int param2 = 2 * a * a * y;

    while (param1 <= param2) {
        DrawEllipse(xc, yc, x, y);
        x++;
        param1 += 2 * b * b;

        if (p1 < 0) {
            p1 += param1 + b * b;
        } else {
            y--;
            param2 -= 2 * a * a;
            p1 += param1 - param2 + b * b;
        }
    }

    // Region 2
    p2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y >= 0) {
        DrawEllipse(xc, yc, x, y);
        y--;
        param2 -= 2 * a * a;

        if (p2 > 0) {
            p2 += a * a - param2;
        } else {
            x++;
            param1 += 2 * b * b;
            p2 += param1 - param2 + a * a;
        }
    }

    getch();
    closegraph();
    return 0;
}