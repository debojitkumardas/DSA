#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push_element(node **head, int value) {

    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->data = value;
        if (is_empty(*head))
            new_node->link = NULL;
    }

    insert_element(head, NULL, value, 'H');
}

void pop_element(node **head) {

    remove_element(head, NULL, 'H');
}

void print_stack_elements(node *head) {

    print_list(head);
}

void stack_instructions() {

    printf(
        "1. Press 1 to push element into stack.\n"
        "2. Press 2 to pop element from stack.\n"
        "*. Press 0 to exit.\n"
    );
}

void delete_stack(node **head) {

    delete_list_on_exiting(head);
}
