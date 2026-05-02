#include <stdio.h>

// Define the region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Function to compute region code for a point (x, y)
int computeCode(int x, int y, int x_min, int y_min, int x_max, int y_max) {
    int code = INSIDE;

    if (x < x_min)       // to the left of rectangle
        code |= LEFT;
    else if (x > x_max)  // to the right of rectangle
        code |= RIGHT;
    if (y < y_min)       // below the rectangle
        code |= BOTTOM;
    else if (y > y_max)  // above the rectangle
        code |= TOP;

    return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2, int x_min, int y_min, int x_max, int y_max) {
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1, x_min, y_min, x_max, y_max);
    int code2 = computeCode(x2, y2, x_min, y_min, x_max, y_max);

    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints lie inside the rectangle
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside the rectangle in the same region
            break;
        } else {
            // Some segment of the line lies within the rectangle
            int code_out;
            int x, y;

            // At least one endpoint is outside the rectangle, pick it
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find the intersection point
            if (code_out & TOP) {
                // Point is above the rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                // Point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                // Point is to the right of the rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                // Point is to the left of the rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace the outside point with the intersection point
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, x_min, y_min, x_max, y_max);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, x_min, y_min, x_max, y_max);
            }
        }
    }
    if (accept) {
        printf("Line accepted from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
    } else {
        printf("Line rejected\n");
    }
}

int main() {
    int x1, y1, x2, y2;
    int x_min, y_min, x_max, y_max;

    printf("Enter the clipping window boundaries (xmin ymin xmax ymax): ");
    scanf("%d %d %d %d", &x_min, &y_min, &x_max, &y_max);

    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    cohenSutherlandClip(x1, y1, x2, y2, x_min, y_min, x_max, y_max);
    return 0;
}

