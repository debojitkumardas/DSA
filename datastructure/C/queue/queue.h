#ifndef QUEUE_H
#define QUEUE_H

typedef struct node node;

// self referential structure
struct node {
    int data;
    node* link;
};

// function prototypes
// list of queue operations
void enqueue(node **head, node **tail, int value);  //
void dequeue(node **head, node **tail);
int is_empty(node *head);
void print_queue(node *head);
void instructions();
void delete_queue(node **head, node **tail);

#endif // !QUEUE_H
