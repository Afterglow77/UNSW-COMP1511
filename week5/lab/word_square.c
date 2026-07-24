#include <stdio.h>

#define MAX_LENGTH 100
int main(void) {
    char letter[MAX_LENGTH];
    printf("Input word: ");
    fgets(letter, MAX_LENGTH, stdin);
    int i = 0;
    int length = 0;
    while (letter[i] != '\n' && letter[i] != '\0') {
        length++;
        i++;
    }
    letter[length] = '\0';
    printf("\nWord square is:\n");
    i = 0;
    while (i < length) {
        printf("%s\n", letter);
        i++;
    }

    return 0;
}
