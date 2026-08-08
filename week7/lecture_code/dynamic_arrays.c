#include <stdio.h>
#include <stdlib.h>

int *creat_data() {
    return malloc(sizeof(int));
}

int *add_data(int *data,int current_size, int value_to_add) {
    data = realloc(data, (current_size + 1) * sizeof(int));
    data[current_size] = value_to_add;
    return data;
}
void print_data(int *data, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\n", data[i]);
    }
}

int main(void) {

    int *data = creat_data();
    int array_size = 0;
    data[0] = 1;
    array_size = 1;

    data = add_data(data, array_size, 5);
    array_size++;
    data = add_data(data, array_size, 6);
    array_size++;
    data = add_data(data, array_size, 7);
    array_size++;

    print_data(data, array_size);
    free(data);
    return 0;
}
