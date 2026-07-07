#include <stdio.h>

int main (void) {
    int num = 0;
    int factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    int counter = num;

    while (counter > 0) {

    factorial *= counter;
    counter--;
    }
    printf("The factorial of %d is %d\n", num, factorial);

    return 0;
}