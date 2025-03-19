#include <stdio.h>
#include <graphics.h>

// Function to perform 8-connected boundary fill
void boundaryFill8(int x, int y, int fill_color, int boundary_color) {
    // Check if the current pixel is within the screen bounds
    if (x < 0 || x >= getmaxx() || y < 0 || y >= getmaxy())
        return;

    // Get the color of the current pixel
    int current_color = getpixel(x, y);

    // If the current pixel is not part of the boundary and not already filled
    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color); // Fill the pixel with the fill color

        // Recursively fill the 8-connected neighbors
        boundaryFill8(x + 1, y, fill_color, boundary_color);     // Right
        boundaryFill8(x - 1, y, fill_color, boundary_color);     // Left
        boundaryFill8(x, y + 1, fill_color, boundary_color);     // Bottom
        boundaryFill8(x, y - 1, fill_color, boundary_color);     // Top
        boundaryFill8(x + 1, y + 1, fill_color, boundary_color); // Bottom-Right
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color); // Bottom-Left
        boundaryFill8(x + 1, y - 1, fill_color, boundary_color); // Top-Right
        boundaryFill8(x - 1, y - 1, fill_color, boundary_color); // Top-Left
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a"); // Initialize graphics mode

    // Draw a rectangle as the boundary
    rectangle(100, 100, 300, 300);

    // Perform boundary fill starting from a seed point inside the rectangle
    boundaryFill8(150, 150, RED, WHITE);

    getch();      // Wait for a key press
    closegraph(); // Close graphics mode
    return 0;
}