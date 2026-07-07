#include <stdio.h>

int main(void) {

    int number;

    printf("How many layers: ");
    scanf("%d", &number);

    int row = 0;
    while (row < number) {
        char cake_char;
        printf("Please enter layers:");
        scanf("%c", &cake_char);
        
        int col = 0;
        while(col < number) {

            printf(" %c", cake_char);
            col ++;
        }
        row ++;
        printf("\n");
    }

    return 0;
}