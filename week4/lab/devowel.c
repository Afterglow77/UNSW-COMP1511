#include <stdio.h>

int is_vowel(char vowel);

int main(void) {
    char vowel;
    while (scanf("%c", &vowel) == 1) {
        if (is_vowel(vowel) == 0) {
            printf("%c", vowel);
        }
    }
    return 0;
}

// Check if a character is a vowel
int is_vowel(char vowel) {
    if (vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u') {
        return 1;
    }
    return 0;
}