#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// insert element
void insert_element(node **head, node **tail, int value, char ch) {

    node *new_node = malloc(sizeof(node));  // create a new node

    // check if it's not NULL
    if (new_node != NULL) {
        new_node->data = value;  // assign data to node

        // if it's empty and insertion is via head/tail
        if (is_empty(*head) && (ch == 'H' || ch == 'T')) {
            new_node->link = NULL;  // last node points to NULL
            if (ch == 'T')
                *head = *tail = new_node;  // insert via tail; assign head to tail
            else
                *tail = *head = new_node;  // insert via head; assign tail to head
        }
        // list is not empty and insert via head
        else if (ch == 'H') {
            new_node->link = *head;  // point new node to previous head
            *head = new_node;  // make new node new head
        }
        // list is not empty and insert via tail
        else if (ch == 'T') {
            new_node->link = NULL;  // last node points to NULL
            (*tail)->link = new_node;  // previous last node points to new node
            *tail = new_node;  // tail points to new node
        }
        // for wrong entry
        else {
            printf("Please enter a valid choice.\n");
            free(new_node);
        }
    }
}

// remove element
void remove_element(node **head, node **tail, char ch) {

    // is list is not empty
    if (!is_empty(*head)) {
        node *temp = *head;  // hold onto node being removed; temporary node
        // list has only one element
        if ((temp->link == NULL) && (ch == 'H' || ch == 'T')) {
            *head = NULL;
            *tail = NULL;
            free(temp);
        }
        // remove from head
        else if (ch == 'H') {
            *head = (*head)->link;  // head point to next node
            free(temp);  // remove previous head
        }
        // remove from tail
        else if (ch == 'T') {
            node *var = NULL;  // temporary node

            while (temp != NULL) {
                var = temp->link;  // point to next node (till it reaches second last node)
                if (var->link == NULL) {  // if second last node is reached
                    temp->link = NULL;  // second last node becomes the last node; last node points to NULL
                    *tail = temp;  // tail points to new last node
                    free(var);  // previous last node is removed
                }
                temp = temp->link;  // points to next node
            }

            free(temp); // free temporary node
        }
        // wrong entry
        else {
            printf("Please enter a valid choice.\n");
            free(temp);  // free temporary node
        }
    }
    // list is empty
    else
        printf("List is empty!! Nothing to remove.\n");
}

// check if list is empty
int is_empty(node *head) {

    if (head == NULL)
        return 1;
    else
        return 0;
}

// print list
void print_list(node *head) {

    while (head != NULL) {
        printf("%d->", head->data);
        head = head->link;
    }

    printf("\\0\n");
}

// list possible operations
void instructions() {

    printf(
        "1. Press 1 to insert data, also provide a choice on where to insert (H: head; T: tail).\n"
        "2. Press 2 to remove data, also provide a choice from where to remove (H: head; T: tail).\n"
        "*. Press 0 to exit.\n"
    );
}

// remove remaining nodes, if any, after performing relevant operations
void delete_list_on_exiting(node **head) {

    while (*head != NULL) {  // while list is not empty
        node *temp = *head;  // hold onto the node being removed
        *head = (*head)->link;  // points to next node
        free(temp);  // remove node
    }
}
