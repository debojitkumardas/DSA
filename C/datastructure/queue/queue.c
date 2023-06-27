#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// insert element in queue
void enqueue(node **head, node **tail, int value) {

    node* new_node = malloc(sizeof(node));  // create a new_node

    if (new_node != NULL) {
        new_node->data = value;  // insert data into node
        new_node->link = NULL;  // link of last node is NULL
        if (is_empty(*head))
            *head = new_node;
        else
            (*tail)->link = new_node;
        *tail = new_node;
    }
}

// remove element from queue
void dequeue(node **head, node **tail) {

    // if queue is not empty
    if (!is_empty(*head)) {
        node* temp = *head;
        *head = (*head)->link;
        free(temp);
    }
    else  // if queue is empty
        printf("Queue is empty!! Nothing to remove.\n");

    if (is_empty(*head))
        *tail = NULL;
}

// check if queue is empty
int is_empty(node *head) {

    if (head == NULL)
        return 1;
    else
        return 0;
}

// print queue
void print_queue(node *head) {

    while (head != NULL) {
        printf("%d->", head->data);
        head = head->link;
    }

    printf("\\0\n");
}

// list of operations on queue
void instructions() {

    printf(
        "1. Press 1 to insert elements in queue.\n"
        "2. Press 2 to remove elements from queue.\n"
        "*. Press 0 to exit.\n"
    );
}

// delete nodes, if any, after operations
void delete_queue(node **head, node **tail) {

    while (*head != NULL) {
        node *temp = *head;
        *head = (*head)->link;
        free(temp);
    }

    if (is_empty(*head))
        *tail = NULL;
}
