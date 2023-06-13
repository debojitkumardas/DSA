#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node* insert_at_head(node* ptr, int val) {

    node* new_node = malloc(sizeof(node));
    node* curr_head = ptr;

    if (new_node != NULL) {
        new_node->item = val;
        new_node->link = curr_head;
        ptr = new_node;  // head points to the new node
    }

    free(curr_head);

    return ptr;
}

void print_list(node *ptr) {

    node* temp = ptr;
    while (temp != NULL) {
        printf("%d\n", temp->item);
        temp = temp->link;
    }

    free(temp);
}

void delete_list_from_head(node *ptr) {

    node* temp = NULL;

    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->link;
        free(temp);
    }
}

int main (void) {

    node* head = NULL;  // initially there are no nodes
    int value = 6;  // users choice, value and position

    node* first = malloc(sizeof(node));

    first->item = 5;
    first->link = NULL;
    head = first;

    printf("Hello.\n");

    print_list(head);

    head = insert_at_head(head, value);

    print_list(head);

    delete_list_from_head(head);

    return 0;
}


/*
typedef struct node* link;

struct node {
    int item;
    link next;
};

int main() {

    int i, N = 5, M = 3;

    link t = malloc(sizeof *t), x = t;

    t->item = 1;
    t->next = t;

    for (i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof *x));
        x->item = i;
        x->next = t;
    }

    while (x != x->next) {
        for (i = 1; i < M; i++) {
            x = x->next;
        }

        x->next = x->next->next;
        N--;
    }

    printf("%d\n", x->item);

    return 0;
}
*/
