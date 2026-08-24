#include <stdio.h>

int main(void) {

    int age = 50;

    printf("age is: %d\n", age );
    printf("age is stored at: %p\n", &age);

    int *age_ptr = &age;

    printf("%d\n", *age_ptr);


    return 0;
}
