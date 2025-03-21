#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to translate a point
void translate(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

// Function to rotate a point
void rotate(int *x, int *y, float angle, int cx, int cy) {
    float rad = angle * (M_PI / 180.0);
    int x_new = cx + (*x - cx) * cos(rad) - (*y - cy) * sin(rad);
    int y_new = cy + (*x - cx) * sin(rad) + (*y - cy) * cos(rad);
    *x = x_new;
    *y = y_new;
}

// Function to scale a point
void scale(int *x, int *y, float sx, float sy, int cx, int cy) {
    *x = cx + (*x - cx) * sx;
    *y = cy + (*y - cy) * sy;
}

// Function to shear a point
void shear(int *x, int *y, float shx, float shy, int cy) {
    int x_new = *x + shx * (*y - cy);
    int y_new = *y + shy * (*x - cy);
    *x = x_new;
    *y = y_new;
}

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");

    // Original rectangle coordinates
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    // Center of the rectangle for rotation and scaling
    int cx = (x1 + x3) / 2;
    int cy = (y1 + y3) / 2;

    int choice;
    int tx, ty;
    float angle, sx, sy, shx, shy;

    while (1) {
        cleardevice();
        drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

        printf("Choose a transformation:\n");
        printf("1. Translation\n");
        printf("2. Rotation\n");
        printf("3. Scaling\n");
        printf("4. Shearing\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter translation factors (tx, ty): ");
                scanf("%d %d", &tx, &ty);
                translate(&x1, &y1, tx, ty);
                translate(&x2, &y2, tx, ty);
                translate(&x3, &y3, tx, ty);
                translate(&x4, &y4, tx, ty);
                break;

            case 2:
                printf("Enter rotation angle (in degrees): ");
                scanf("%f", &angle);
                rotate(&x1, &y1, angle, cx, cy);
                rotate(&x2, &y2, angle, cx, cy);
                rotate(&x3, &y3, angle, cx, cy);
                rotate(&x4, &y4, angle, cx, cy);
                break;

            case 3:
                printf("Enter scaling factors (sx, sy): ");
                scanf("%f %f", &sx, &sy);
                scale(&x1, &y1, sx, sy, cx, cy);
                scale(&x2, &y2, sx, sy, cx, cy);
                scale(&x3, &y3, sx, sy, cx, cy);
                scale(&x4, &y4, sx, sy, cx, cy);
                break;

            case 4:
                printf("Enter shearing factors (shx, shy): ");
                scanf("%f %f", &shx, &shy);
                shear(&x1, &y1, shx, shy, cy);
                shear(&x2, &y2, shx, shy, cy);
                shear(&x3, &y3, shx, shy, cy);
                shear(&x4, &y4, shx, shy, cy);
                break;

            case 5:
                closegraph();
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                delay(2000);
                break;
        }
    }

    return 0;
}