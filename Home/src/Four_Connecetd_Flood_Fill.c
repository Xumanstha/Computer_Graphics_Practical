#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

// Structure to represent a pixel
typedef struct {
    int x, y;
} Pixel;

// Stack implementation
Pixel stack[10000];
int top = -1;

void push(int x, int y) {
    if (top < 9999) {
        top++;
        stack[top].x = x;
        stack[top].y = y;
    }
}

Pixel pop() {
    Pixel p;
    if (top >= 0) {
        p = stack[top];
        top--;
    }
    return p;
}

// Non-recursive 4-connected flood fill using a stack
void floodFill4(int x, int y, int new_color, int old_color) {
    push(x, y); // Push the seed point onto the stack

    while (top >= 0) {
        Pixel p = pop(); // Pop a pixel from the stack
        int x = p.x;
        int y = p.y;

        // Check if the current pixel is within the screen bounds
        if (x < 0 || x >= getmaxx() || y < 0 || y >= getmaxy())
            continue;

        // Get the color of the current pixel
        int current_color = getpixel(x, y);

        // If the current pixel is the old color, fill it with the new color
        if (current_color == old_color) {
            putpixel(x, y, new_color); // Fill the pixel with the new color

            // Push the 4-connected neighbors onto the stack
            push(x + 1, y); // Right
            push(x - 1, y); // Left
            push(x, y + 1); // Bottom
            push(x, y - 1); // Top
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a"); // Initialize graphics mode

    // Draw a rectangle filled with a specific color
    setcolor(WHITE);
    rectangle(100, 100, 300, 300);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(150, 150, WHITE);

    // Perform flood fill starting from a seed point inside the rectangle
    floodFill4(150, 150, RED, GREEN);

    getch();      // Wait for a key press
    closegraph(); // Close graphics mode
    return 0;
}