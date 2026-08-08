#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_elements = 5;

    int *data = malloc(num_elements * sizeof(int));
    num_elements += 40;

    data = realloc(data, num_elements * sizeof(int));

    free(data);

    return 0;
}
