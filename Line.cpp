#include <stdio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    // Coordinates of starting and ending points
    int x1 = 100, y1 = 100, x2 = 300, y2 = 300;
    
    // Draw a line
    line(x1, y1, x2, y2);
    
    // Wait for a key press
    getch();
    
    // Close the graphics window
    closegraph();
    
    return 0;
}

