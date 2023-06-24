#ifndef STACK_H
#define STACK_H

typedef struct node node;

struct node {
    int data;
    node *link;
};

// function prototypes
// operations to perform on stack
void push_element(node **head, int value);
void pop_element(node **head);
int is_empty(node *head);
void print_stack_elements(node *head);
void stack_instructions();
void delete_stack(node **head);

#endif // !STACK_H
