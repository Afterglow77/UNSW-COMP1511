#include <stdio.h>

int main(void) {

    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    int i = 0;

    if (n > 0) {
        while (i <= n) {
            printf("%d\n", i);
            i++;
        }
    } else {
        while (i >= n) {
            printf("%d\n", i);
            i--;
        }
    }

    return 0;
}