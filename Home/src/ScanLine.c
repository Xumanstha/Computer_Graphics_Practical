#include <stdio.h>
#include <graphics.h>

#define MAX_EDGES 20

// Structure to represent an edge
typedef struct {
    int y_max;   // Maximum y-coordinate of the edge
    float x_min; // x-coordinate of the bottom endpoint
    float inv_m; // Inverse slope (1/m)
} Edge;

// Function to initialize the Edge Table (ET)
void initEdgeTable(Edge ET[], int *num_edges, int polygon[][2], int n) {
    *num_edges = 0;
    for (int i = 0; i < n; i++) {
        int x1 = polygon[i][0];
        int y1 = polygon[i][1];
        int x2 = polygon[(i + 1) % n][0];
        int y2 = polygon[(i + 1) % n][1];

        if (y1 != y2) { // Ignore horizontal edges
            Edge edge;
            edge.y_max = (y1 > y2) ? y1 : y2;
            edge.x_min = (y1 < y2) ? x1 : x2;
            edge.inv_m = (float)(x2 - x1) / (y2 - y1);

            ET[(*num_edges)++] = edge;
        }
    }
}

// Function to fill the polygon using the Scanline Algorithm
void scanlineFill(Edge ET[], int num_edges) {
    int y, i;
    Edge AET[MAX_EDGES];
    int aet_size = 0;

    for (y = 0; y < getmaxy(); y++) {
        // Add edges to AET where y == y_min
        for (i = 0; i < num_edges; i++) {
            if (y == ET[i].x_min) {
                AET[aet_size++] = ET[i];
            }
        }

        // Sort AET by x_min
        for (i = 0; i < aet_size - 1; i++) {
            for (int j = i + 1; j < aet_size; j++) {
                if (AET[i].x_min > AET[j].x_min) {
                    Edge temp = AET[i];
                    AET[i] = AET[j];
                    AET[j] = temp;
                }
            }
        }

        // Fill pixels between pairs of intersections
        for (i = 0; i < aet_size; i += 2) {
            int x_start = (int)AET[i].x_min;
            int x_end = (int)AET[i + 1].x_min;
            for (int x = x_start; x <= x_end; x++) {
                putpixel(x, y, RED); // Fill pixel with red color
            }
        }

        // Remove edges from AET where y == y_max
        for (i = 0; i < aet_size; i++) {
            if (y == AET[i].y_max) {
                for (int j = i; j < aet_size - 1; j++) {
                    AET[j] = AET[j + 1];
                }
                aet_size--;
                i--;
            }
        }

        // Update x_min for edges in AET
        for (i = 0; i < aet_size; i++) {
            AET[i].x_min += AET[i].inv_m;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Initialize graphics mode
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    // Define the polygon vertices
    int polygon[][2] = {{100, 100}, {300, 150}, {200, 300}, {100, 100}};
    int n = sizeof(polygon) / sizeof(polygon[0]);

    // Draw the polygon outline
    for (int i = 0; i < n; i++) {
        int x1 = polygon[i][0];
        int y1 = polygon[i][1];
        int x2 = polygon[(i + 1) % n][0];
        int y2 = polygon[(i + 1) % n][1];
        line(x1, y1, x2, y2); // Draw edges of the polygon
    }

    // Initialize Edge Table (ET)
    Edge ET[MAX_EDGES];
    int num_edges;
    initEdgeTable(ET, &num_edges, polygon, n);

    // Fill the polygon using the Scanline Algorithm
    scanlineFill(ET, num_edges);

    getch();      // Wait for a key press
    closegraph(); // Close graphics mode
    return 0;
}