// debug_letter_search.c
//
// Write a C program that takes in a letter from the user, and then searches 
// more input given by the user for that letter, or until CTRL+D is entered.
//
// This program was written by YOUR-NAME-HERE (zXXXXXXX)
// on INSERT-DATE-HERE

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void) {
    // Get the letter we are trying to find
    printf("Which letter are we searching for?: ");
    char target;
    scanf(" %c", &target);

    // Loop through input until we get the target, or ctrl+d
    char letter;
    int found = FALSE;
    while (scanf("%c", &letter) == 1 && found == FALSE) {
        // Check if we found the letter
        if (letter == target) {
            found = TRUE;
        }
    }

    // Tell the user if we found it or not
    if (found == TRUE) {
        printf("We found %d!!!\n", target);
    } else {
        printf("The mission was not successful :(");
    }

    return 0;
}