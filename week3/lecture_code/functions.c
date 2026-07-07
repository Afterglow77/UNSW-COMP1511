#include <stdio.h>

enum weekday {
    Mon,
    Tue,
    Wed,
    Thu,
    Fri
};

enum weekday get_weekday(void) {

    enum weekday day;
    printf("Enter day of week (Mon = 0): ");
    scanf("%d", &day);

    printf("%d", day);

    return day;
}


int main(void) {
    enum weekday day = get_weekday();

    printf("%d", day);

    return 0;
}