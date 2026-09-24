#include <stdio.h>
#include <stdlib.h>

 // the node
struct node {
    // the data!
    int data;
    // a pointer to the next node in the linked lists
    struct node *next;
};

struct node *create_node(int data_to_add) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data_to_add;
    new_node->next = NULL;

    return new_node;
}

void print_linked_list(struct node *head) {
    struct node *current = head;

    printf("Linked list: ");

    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void) {

    struct node *head = create_node(11);
    struct node *second_node = create_node(8);
    struct node *third_node = create_node(7);

    head->next = second_node;

    second_node->next = third_node;

    print_linked_list(head);
    return 0;
}