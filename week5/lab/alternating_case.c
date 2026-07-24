// Written by Rhys Yang
// July, 2026

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
void make_alternating(char string[MAX_STRING_LENGTH]);

int main (void) {
    //You don't need to understand this code to complete the exercise.

    //Scans in a string from the user.
    char buffer[MAX_STRING_LENGTH];
    fgets(buffer, MAX_STRING_LENGTH, stdin);

    // Runs your function
    make_alternating(buffer);

    // Prints resulting string.
    printf("%s", buffer);

    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

// Modifies `string` so that the first letter is converted to lowercase,
// and the case of each following letter alternates.
// i.e. in the resulting string:
//      the first letter is lowercase,
//      second letter is uppercase,
//      third letter is lower case,
//      etc.
//
// e.g.: "Hello" -> "hElLo"
void make_alternating(char string[MAX_STRING_LENGTH]) {
    int i = 0;
    int letter_count = 0;

    while (string[i] != '\0' && string[i] != '\n') {
        if (isalpha(string[i])) {
            if (letter_count % 2 == 0) {
                string[i] = tolower(string[i]);
                letter_count++;
            } else {
                string[i] = toupper(string[i]);
                letter_count++;
            }
        }
        i++;
    }
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
