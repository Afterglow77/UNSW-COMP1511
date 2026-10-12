// List get nth
// list_get_nth.c
//
// This program was written by Rhys Yang
// on 12/10/2026
//
// Prints the nth element in a linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

void create_list(struct node *head);
void get_nth(struct node *head, int n);
void delete_list(struct node *head);

// WARNING: Do not change the main function!
// calls the functions for code to operate
int main(void) {
    struct node *head = malloc(sizeof(struct node));
    create_list(head);

    int n;
    printf("Which nth element would you like to find: ");
    scanf("%d", &n);
    get_nth(head, n);

    delete_list(head);
    return 0;
}

// finds the nth element of a linked list
void get_nth(struct node *head, int n) {
    int count = 0;
    struct node *current = head;

    while (current != NULL) {
        if (n == count) {
            printf("The nth value is %d!\n", current->data);
            return;
        }
        count++;
        current = current->next;
    }
    printf("ERROR: no nth element in list.\n");
    // TODO: complete this function!
}

// WARNING: Do not change this function!
// creates a linked list
void create_list(struct node *head) {
    int num_elements;
    printf("How many elements in the list: ");
    scanf("%d", &num_elements);
    struct node *current = head;

    // always at least one element in list
    int data;
    scanf("%d", &data);
    current->data = data;

    int i = 1;
    while (i < num_elements) {
        current->next = malloc(sizeof(struct node));
        current = current->next;
        scanf("%d", &data);
        current->data = data;
        i++;
    }
    current->next = NULL;
    printf("\n");
}

// WARNING: Do not change this function!
// frees all the memory associated with the linked list
void delete_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *delete = current;
        current = current->next;
        free(delete);
    }
}
