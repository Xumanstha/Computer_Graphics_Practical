#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

// Function to calculate Bezier curve points
void bezierCurve(int x[], int y[]) {
    int i;
    double t;
    int xt, yt;

    // Loop through values of t from 0 to 1
    for (t = 0.0; t <= 1.0; t += 0.001) {
        // Calculate Bezier blending functions
        double u = 1 - t;
        double uu = u * u;
        double uuu = uu * u;
        double tt = t * t;
        double ttt = tt * t;

        // Compute x and y coordinates using cubic Bezier equation
        xt = (int)(uuu * x[0] + 3 * uu * t * x[1] + 3 * u * tt * x[2] + ttt * x[3]);
        yt = (int)(uuu * y[0] + 3 * uu * t * y[1] + 3 * u * tt * y[2] + ttt * y[3]);

        // Plot the point
        putpixel(xt, yt, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int x[4], y[4];
    int i;
    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");

    printf("Enter 4 control points (x, y):\n");
    for (i = 0; i < 4; i++) {
        printf("Point %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Draw the Bezier Curve
    bezierCurve(x, y);

    // Display control points
    for (i = 0; i < 4; i++) {
        putpixel(x[i], y[i], RED);
    }

    getch(); // Wait for key press
    closegraph(); // Close graphics mode

    return 0;
}
