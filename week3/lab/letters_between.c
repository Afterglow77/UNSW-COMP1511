/*这个letter_between对我目前水平来说确实有点难度，
*逻辑嵌套很复杂，也许是我想多了，可以参考我的code逻辑，
*可能走弯路了，我把字母换成ASCII 码之后来比较大小
*/

#include <stdio.h>

int main(void) {
    char starting_letter;
    char target_letter;

    printf("Please enter starting letter: ");
    scanf("%c", &starting_letter);

    printf("Please enter target letter: ");
    scanf(" %c", &target_letter);

    //sld means start letter length with 'A'
    //tld means target_letter length with 'A'
    char base = 'A'; 
    if (starting_letter >= 'a') {
        base = 'a';
    }
    int sld;
    int tld;
    sld = starting_letter - base;
    tld = target_letter - base;

    //cwn means clockwise number
    int cwn;
    int ccwn;
    if (sld < tld){
        cwn = tld - sld;
        ccwn = 26 - cwn;

        if (cwn <= ccwn) {
 
            int count = 0;
            while (count < cwn + 1) {

                printf("%c", (sld + count) % 26 + base);
                count++;
            }
        } else {
            
            int count = 0;
            while (count < ccwn + 1) {

                printf("%c", (sld - count + 26) % 26 + base);
                count++;
            }
        }
    } else {
        ccwn = sld - tld;
        cwn = 26 - ccwn;
        if (cwn <= ccwn) {

            int count = 0;
            while (count < cwn + 1) {
                printf("%c", (sld + count) % 26 + base);
                count++;
            }
        } else {
  
            int count = 0;
            while (count < ccwn + 1) {
                printf("%c", (sld - count + 26) % 26 + base);
                count++;
            }
        }
    }

    return 0;
}