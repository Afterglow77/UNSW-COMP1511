// debug_stringcmp.c
//
// This program takes in two strings as input and checks if they are the same
// Wrriten by Rhys Yang

#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    // Read input from user
    printf("Enter the first string: ");
    scanf("%s", &str1);

    printf("Enter the second string: ");
    scanf("%c", &str2);

    // Check if the strings are equal
    if (str1 == str2) {
        printf("Strings are equal!\n");
    } else {
        printf("Strings are not equal!\n");
    }

    return 0;
}