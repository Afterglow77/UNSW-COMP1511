#include <stdio.h>

void print_at_address(int *memory_address);

int main(void) {

    int number = 42;

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////// ONLY MODIFY CODE BELOW //////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    int *number_pointer = &number;
    printf("Passing the memory address %p to the function\n", number_pointer);
    print_at_address(number_pointer);

    return 0;
}

/*
param: memory_address - is an integer pointer that points to a memory address
return: void
Prints the memory address and the value at the memory address
*/
void print_at_address(int *memory_address) {
    // TODO
    printf("The memory address passed to this function is %p\n", memory_address);
    printf("The value at the memory address is %d\n", *memory_address);
}
