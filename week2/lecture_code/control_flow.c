#include <stdio.h>

#define MAIN_AGE 18
int main(void)
{

    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age <= 0)
    {
        printf("That is invalid!\n");
    }
    else{

        if (age < MAIN_AGE){
        printf("You are too young\n");
        }else{
            printf("OK, valid!\n");
        }

    }
    

    return 0;
}