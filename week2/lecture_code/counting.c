#include<stdio.h>

int main(void) {

    int finished = 0;
    
    while(!finished) {

        printf("1\n");
        printf("Enter 1 if finished:\n");

        scanf("%d", &finished);
    }
    printf("Program finishing\n");

    return 0;
}