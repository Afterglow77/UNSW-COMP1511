#include <stdio.h>

#define MAX_POINTS 10

struct point {
    double x;
    double y;
};

// Prints a point out.
void print_point(int point_no, double x, double y);

int main(void) { 
    struct point shape[MAX_POINTS];

    printf("How many points in the shape? ");

    int num_number;
    scanf("%d", &num_number);
    printf("Enter points:\n");

    int i = 0;
    while (i < num_number) {
        scanf("%lf %lf", &shape[i].x, &shape[i].y);
        i++;
    }

    printf("\nShape Points:\n");
    i = 0;
    while (i < num_number) {
        print_point(i + 1, shape[i].x, shape[i].y);
        i++;
    }

    return 0;
}

// Prints a single point in the correct format.
//
// Parameters:
// - `point_no` -- The point number
// - `x`        -- The x-coordinate of the point
// - `y`        -- The y-coordinate of the point
//
// Returns: nothing.
void print_point(int point_no, double x, double y) {
    printf("%2d: x = %.3lf, y = %.3lf\n", point_no, x, y);
}