#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void insert_element(node **head, node **tail, int value, char ch) {

    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->data = value;

        if (is_empty(*head) && (ch == 'H' || ch == 'T')) {
            new_node->link = NULL;
            if (ch == 'T') {
                (*tail)->link = new_node;
                *tail = new_node;
            }
            else
                *tail = *head = new_node;
        }
        else if (ch == 'H') {
            new_node->link = *head;
            *head = new_node;
        }
        else {
            printf("Please enter a valid choice.\n");
            free(new_node);
        }
    }
}

void remove_element(node **head, node **tail, char ch) {

    if (!is_empty(*head)) {
        node *temp = *head;
        if ((temp->link == NULL) && (ch == 'H' || ch == 'T')) {
            *head = NULL;
            *tail = NULL;
            free(temp);
        }
        else if (ch == 'H') {
            *head = (*head)->link;
            free(temp);
        }
        else if (ch == 'T') {
            while (temp != NULL) {
                if (temp->link != NULL) {
                    if (temp->link->link == NULL) {
                        *tail = temp;
                        (*tail)->link = NULL;
                    }
                }
                else {
                    free(temp);
                    break;
                }
                temp = temp->link;
            }
        }
        else {
            printf("Please enter a valid choice.\n");
            free(temp);
        }
    }
}

int is_empty(node *head) {

    if (head == NULL)
        return 1;
    else
        return 0;
}

void print_list(node *head) {

    while (head != NULL) {
        printf("%d->", head->data);
        head = head->link;
    }

    printf("\\0\n");
}

void instructions() {

    printf(
        "1. Press 1 to insert data, also provide a choice on where to insert (H: head; T: tail).\n"
        "2. Press 2 to remove data, also provide a choice from where to remove (H: head; T: tail).\n"
        "*. Press 0 to exit.\n"
    );
}

void delete_list_on_exiting(node **head) {

    while (head != NULL) {
        node *temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}
