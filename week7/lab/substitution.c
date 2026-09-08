#include <stdio.h>

char encrypt_char(char c, char *key);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    char *key = argv[1];

    printf("Enter text:\n");

    char c;
    while (scanf("%c", &c) == 1) {
        printf("%c", encrypt_char(c, key));
    }

    return 0;
}


char encrypt_char(char c, char *key) {
    if (c >= 'a' && c <= 'z') {
        return key[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        char lower = key[c - 'A'];
        return lower - 'a' + 'A';
    } else {
        return c;
    }
}
