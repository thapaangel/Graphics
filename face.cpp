#include <graphics.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw face
    setfillstyle(SOLID_FILL, YELLOW);
    circle(300, 200, 100);
    floodfill(300, 200, WHITE);

    // Draw eyes
    setfillstyle(SOLID_FILL, WHITE);
    circle(250, 170, 10);
    floodfill(250, 170, WHITE);
    circle(350, 170, 10);
    floodfill(350, 170, WHITE);

    // Draw mouth
    setfillstyle(SOLID_FILL, RED);
    ellipse(300, 220, 180, 360, 40, 20);
    floodfill(300, 220, WHITE);
    getch();
    closegraph();
    return 0;
}

