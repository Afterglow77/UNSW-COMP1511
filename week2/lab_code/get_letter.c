#include <stdio.h>

int main(void) {

    int index;
    char is_uppercase;

    printf("Uppercase: ");
    scanf(" %c", &is_uppercase);

    printf("Index: ");
    scanf("%d", &index);

    if (is_uppercase == 'y') {
        printf("The letter is %c\n", 'A' + index);
    } else if (is_uppercase == 'n') {
        printf("The letter is %c\n", 'a' + index);
    }

    return 0;
}