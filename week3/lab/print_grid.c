#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int row = 0;
    while (row < size) {
        int col = 0;

        while (col < size) {
            printf("(%d, %d) ", row, col);
            col++;
        }
        printf("\n");
        row++;
    }

    return 0;
}