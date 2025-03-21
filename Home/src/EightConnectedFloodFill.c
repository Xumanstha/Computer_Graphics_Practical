#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to implement 8-connected flood fill algorithm
void floodFill8(int x, int y, int fillColor, int oldColor) {
    // Check if the current pixel is within the screen boundaries
    if (x < 0 || x >= getmaxx() || y < 0 || y >= getmaxy()) {
        return;
    }

    // Check if the current pixel is the old color
    if (getpixel(x, y) == oldColor) {
        // Set the pixel to the fill color
        putpixel(x, y, fillColor);

        // Recursively call floodFill8 for all 8 neighbors
        floodFill8(x + 1, y, fillColor, oldColor);     // Right
        floodFill8(x - 1, y, fillColor, oldColor);     // Left
        floodFill8(x, y + 1, fillColor, oldColor);     // Bottom
        floodFill8(x, y - 1, fillColor, oldColor);     // Top
        floodFill8(x + 1, y + 1, fillColor, oldColor); // Bottom Right
        floodFill8(x - 1, y + 1, fillColor, oldColor); // Bottom Left
        floodFill8(x + 1, y - 1, fillColor, oldColor); // Top Right
        floodFill8(x - 1, y - 1, fillColor, oldColor); // Top Left
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a"); // Initialize graphics mode

    // Draw a rectangle
    rectangle(50, 50, 200, 200);

    // Fill the rectangle using the 8-connected flood fill algorithm
    floodFill8(100, 100, 12, 0); // Fill with color 12 (light red)

    getch(); // Wait for a key press
    closegraph(); // Close graphics mode
    return 0;
}