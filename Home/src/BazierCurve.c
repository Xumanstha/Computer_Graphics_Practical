#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Function to compute factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to compute binomial coefficient C(n, k)
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to compute a point on the Bézier curve
void computeBezierPoint(float t, int n, int controlPoints[][2], int *x, int *y) {
    *x = 0;
    *y = 0;
    for (int i = 0; i <= n; i++) {
        float blending = binomialCoefficient(n, i) * pow(1 - t, n - i) * pow(t, i);
        *x += controlPoints[i][0] * blending;
        *y += controlPoints[i][1] * blending;
    }
}

// Function to draw the Bézier curve
void drawBezierCurve(int n, int controlPoints[][2]) {
    float t;
    int x, y;
    for (t = 0.0; t <= 1.0; t += 0.001) {
        computeBezierPoint(t, n, controlPoints, &x, &y);
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");

    // Number of control points
    int n = 3; // Cubic Bézier curve (n = 3)

    // Control points for the Bézier curve
    int controlPoints[4][2] = {
        {100, 400}, // P0
        {200, 100}, // P1
        {400, 100}, // P2
        {500, 400}  // P3
    };

    // Draw the control points
    for (int i = 0; i <= n; i++) {
        circle(controlPoints[i][0], controlPoints[i][1], 5);
        if (i > 0) {
            line(controlPoints[i - 1][0], controlPoints[i - 1][1],
                 controlPoints[i][0], controlPoints[i][1]);
        }
    }

    // Draw the Bézier curve
    drawBezierCurve(n, controlPoints);

    getch();
    closegraph();
    return 0;
}