#include "maths.h"

double calc_area_rect(double width, double height) {
    return width * height;
}

double calc_area_circle(double radius) {
    double result = PI * radius * radius; 
    return result;
}