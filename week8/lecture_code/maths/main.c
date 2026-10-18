#include <stdio.h>
#include "maths.h"

int main(void) {
    double width;
    double height;

    printf("please enter a width and height for your rectangle: ");
    scanf("%lf, %lf", &width, &height);

    double result = calc_area_rect(width, height);
    printf("The area of the rectangle is %.2f! \n", result);

    double radius;
    printf("Enter a radius for your circle: ");
    scanf("%lf", &radius);
    
    result = calc_area_circle(radius);
    printf("The area of the circle is %.2f\n", result); 
    return 0;
}