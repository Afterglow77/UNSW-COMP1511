#include <stdio.h>

void double_array_of_ints(int data[], int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] * 2;
    }
}

int main(void) {
    int data[5] = {1, 2, 3, 4, 5};
    double_array_of_ints(data, 5);
    // is data doubled?
    for (int i = 0; i < 5; i++) {
        printf("%d\n", data[i]);
    }

    printf("%p\n", data);

//  array decays to a pointer
//  they are same!!!!!!!!!
    printf("data[0] is: %d\n", data[0]);
    printf("*data is: %d\n", *data);


//  they are same!!!!!!!!!!!
    printf("data[1] is: %d\n", data[1]);
    printf("*(data + 1) is: %d\n", *(data + 1));
    return 0;
}
