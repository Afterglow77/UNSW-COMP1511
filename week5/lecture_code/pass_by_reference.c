#include <stdio.h>

void change_value(int *x) {
    *x = *x * 2;
}

int main(void) {
    int x = 5;
    change_value(&x);
    printf("%d", x);

    return 0;
}
