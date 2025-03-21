#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Define a structure for 3D points
typedef struct {
    float x, y, z;
} Point3D;

// Function to translate a 3D point
void translate(Point3D *p, float tx, float ty, float tz) {
    p->x += tx;
    p->y += ty;
    p->z += tz;
}

// Function to rotate a 3D point around the X-axis
void rotateX(Point3D *p, float angle) {
    float rad = angle * (M_PI / 180.0);
    float y = p->y * cos(rad) - p->z * sin(rad);
    float z = p->y * sin(rad) + p->z * cos(rad);
    p->y = y;
    p->z = z;
}

// Function to rotate a 3D point around the Y-axis
void rotateY(Point3D *p, float angle) {
    float rad = angle * (M_PI / 180.0);
    float x = p->x * cos(rad) + p->z * sin(rad);
    float z = -p->x * sin(rad) + p->z * cos(rad);
    p->x = x;
    p->z = z;
}

// Function to rotate a 3D point around the Z-axis
void rotateZ(Point3D *p, float angle) {
    float rad = angle * (M_PI / 180.0);
    float x = p->x * cos(rad) - p->y * sin(rad);
    float y = p->x * sin(rad) + p->y * cos(rad);
    p->x = x;
    p->y = y;
}

// Function to scale a 3D point
void scale(Point3D *p, float sx, float sy, float sz) {
    p->x *= sx;
    p->y *= sy;
    p->z *= sz;
}

// Function to project a 3D point onto a 2D plane (orthographic projection)
void project(Point3D p, int *x, int *y) {
    *x = (int)(p.x + p.z * 0.5); // Simple orthographic projection
    *y = (int)(p.y + p.z * 0.5);
}

// Function to draw a 3D cube
void drawCube(Point3D vertices[], int edges[][2]) {
    int i, x1, y1, x2, y2;
    for (i = 0; i < 12; i++) {
        project(vertices[edges[i][0]], &x1, &y1);
        project(vertices[edges[i][1]], &x2, &y2);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");

    // Define the vertices of a 3D cube
    Point3D vertices[8] = {
        {100, 100, 100}, {200, 100, 100}, {200, 200, 100}, {100, 200, 100},
        {100, 100, 200}, {200, 100, 200}, {200, 200, 200}, {100, 200, 200}
    };

    // Define the edges of the cube (connecting vertices)
    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, // Bottom face
        {4, 5}, {5, 6}, {6, 7}, {7, 4}, // Top face
        {0, 4}, {1, 5}, {2, 6}, {3, 7}  // Connecting edges
    };

    int choice;
    float tx, ty, tz, angle, sx, sy, sz;

    while (1) {
        cleardevice();
        drawCube(vertices, edges);

        printf("Choose a 3D transformation:\n");
        printf("1. Translation\n");
        printf("2. Rotation around X-axis\n");
        printf("3. Rotation around Y-axis\n");
        printf("4. Rotation around Z-axis\n");
        printf("5. Scaling\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter translation factors (tx, ty, tz): ");
                scanf("%f %f %f", &tx, &ty, &tz);
                for (int i = 0; i < 8; i++) {
                    translate(&vertices[i], tx, ty, tz);
                }
                break;

            case 2:
                printf("Enter rotation angle around X-axis (in degrees): ");
                scanf("%f", &angle);
                for (int i = 0; i < 8; i++) {
                    rotateX(&vertices[i], angle);
                }
                break;

            case 3:
                printf("Enter rotation angle around Y-axis (in degrees): ");
                scanf("%f", &angle);
                for (int i = 0; i < 8; i++) {
                    rotateY(&vertices[i], angle);
                }
                break;

            case 4:
                printf("Enter rotation angle around Z-axis (in degrees): ");
                scanf("%f", &angle);
                for (int i = 0; i < 8; i++) {
                    rotateZ(&vertices[i], angle);
                }
                break;

            case 5:
                printf("Enter scaling factors (sx, sy, sz): ");
                scanf("%f %f %f", &sx, &sy, &sz);
                for (int i = 0; i < 8; i++) {
                    scale(&vertices[i], sx, sy, sz);
                }
                break;

            case 6:
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