#include "hdr/stack_ds.h"
#include <stdio.h>
#include <stdlib.h>

Node* CreateNode(int value) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node != NULL) {
        new_node->value = value;
        new_node->next = NULL;
    }

    return new_node;
}

void PushNode(Node** head, int value) {
    Node* new_node = CreateNode(value);

    new_node->next = *head;
    *head = new_node;
}

void PopNode(Node** head) {
    Node* temp = *head;

    *head = (*head)->next;

    free(temp);
}

void PrintStack(Node* head) {
    while (head != NULL) {
        printf("%d->", head->value);
        head = head->next;
    }
    printf("\b\b\n");
}

void DeleteStack(Node** head) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
