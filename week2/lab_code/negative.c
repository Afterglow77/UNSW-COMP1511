#include<stdio.h>

int main(void) {

    int number;
    scanf("%d", &number);

    if (number > 0) {
        printf("You have entered a positive number.\n");
    } else if (number == 0) {
        printf("You have entered zero.\n");
    } else {
        printf("Dont't be so negative!\n");
    }

    return 0;
}