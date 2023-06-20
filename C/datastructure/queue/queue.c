#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// insert element in queue
node* enqueue(node* tail, int value) {

    node* new_node = malloc(sizeof(node));  // create a new_node

    if (new_node != NULL) {
        new_node->data = value;  // insert data into node
        new_node->link = NULL;  // link of last node is NULL
        if (tail != NULL)  // if list is not empty
            tail->link = new_node;  // point previous last node to new_node
        tail = new_node;  // point tail to new last node
    }

    return tail;  // return link to new tail
}

// delete element from queue
node* dequeue(node* head) {

    // if queue is not empty
    if (is_empty(head) != -1) {
        node* temp = head;
        head = head->link;
        free(temp);
    }
    else  // if queue is empty
        printf("List is empty!! Nothing to delete.\n");

    return head;
}

// check if queue is empty
int is_empty(node* head) {

    if (head == NULL)
        return -1;
    else
        return 1;
}

// print queue
void print_queue(node *head) {

    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->link;
    }
}

// list of operations on queue
void instructions() {

    printf(
        "1. Press 1 to insert elements in queue.\n"
        "2. Press 2 to remove elements from queue.\n"
        "*. Press 0 to exit.\n"
    );
}

// the main function
int main(void) {

    node* head = NULL;  // initially the list is empty
    node* tail = NULL;  // initially the list is empty

    int value = 0;
    int choice = 1;
    int count = 0;

    instructions();
    while (choice != 0) {

        printf("Enter the choice: ");
        scanf("%d", &choice);

        //
        if (choice == 1) {
            printf("Enter the value: ");
            scanf("%d", &value);
            count++;
        }

        //
        if (choice == 2) {
            if (is_empty(head) != -1)
                count--;
        }

        switch (choice) {
            case 0:
                break;
            case 1:
                tail = enqueue(tail, value);
                break;
            case 2:
                tail = enqueue(tail, value);
                break;
            default:
                printf("Please enter the valid choice.\n");
                break;
        }
    }

    return 0;
}
