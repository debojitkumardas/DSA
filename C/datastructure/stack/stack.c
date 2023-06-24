#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push_element(node **head, int value) {

    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->data = value;
        if (is_empty(*head))
            new_node->link = NULL;
        else
            new_node->link = *head;

        *head = new_node;
    }
}

void pop_element(node **head) {

    if (!is_empty(*head)) {
        node *temp = *head;
        *head = (*head)->link;
        free(temp);
    }
    else
        printf("Stack is empty!! Nothing to pop.\n");
}

int is_empty(node *head) {

    if (head == NULL)
        return 1;
    else
        return 0;
}

void print_stack_elements(node *head) {

    while (head != NULL) {
        printf("%d->", head->data);
        head = head->link;
    }

    printf("\\0\n");
}

void stack_instructions() {

    printf(
        "1. Press 1 to push element into stack.\n"
        "2. Press 2 to pop element from stack.\n"
        "*. Press 0 to exit.\n"
    );
}

void delete_stack(node **head) {

    while (*head != NULL) {
        node *temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}
