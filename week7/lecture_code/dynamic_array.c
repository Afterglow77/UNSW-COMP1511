#include <stdio.h>
#include <stdlib.h>
int main(void) {

    int num_elements;
    scanf("%d", &num_elements);

    int *data = malloc(num_elements * sizeof(int));

    int i = 0;
    while (i < num_elements) {
        data[i] = i;
        i++;
    }

    i = 0;
    while (i < num_elements) {
        printf("%d\n", data[i]);
        i++;
    }

    free(data);

    return 0;
}
