#include <stdio.h>

int main(void) {
    char starting_letter;
    char target_letter;

    printf("Please enter starting letter: ");
    scanf("%c", &starting_letter);

    printf("Please enter target letter: ");
    scanf(" %c", &target_letter);

    //sld means start letter lenth with 'A'
    //tld means target_letter lenth with 'A'
    int sld;
    int tld;
    sld = starting_letter - 'A';
    tld = target_letter - 'A';

    //cwn means clockwise number
    int cwn;
    int ccwn;
    if (sld < tld){
        cwn = tld - sld;
        ccwn = 26 - cwn;
    } else {
        ccwn = sld - tld;
        cwn = 26- ccwn;
    }
    
    return 0;
}