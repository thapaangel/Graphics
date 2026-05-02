#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)""); // Initialize graphics mode

    // Center coordinates and radius of the circle
    int x = 300, y = 200, radius = 100;

    // Draw circle
    circle(x, y, radius);
     delay(5000);
    // Close graphics mode
    closegraph();
    getch();
    return 0;
}

