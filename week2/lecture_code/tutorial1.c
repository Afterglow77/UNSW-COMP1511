#include<stdio.h>

int main(void) {
    // 1. declare the variables
    double radius;
    double pi;
    double area;

    // 2. Initalise the variables
    pi = 3.141592653589793;
    radius = 2.38;

    // 3. Calculate the area of the circle
    area = pi * radius * radius;
    
    printf("当半径为%.2f的时候，圆的面积为%.2f\n", radius, area);

    return 0;

}