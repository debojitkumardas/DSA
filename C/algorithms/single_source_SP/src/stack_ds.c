#include "hdr/stack_ds.h"
#include <stdlib.h>
#include <stdio.h>

Node* CreateNode(int value) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node != NULL) {
        new_node->value = value;
        new_node->next = NULL;
    }

    return new_node;
}

void PushNode(Node **head, int value) {
    Node* node = CreateNode(value);

    if (node != NULL) {
        node->next = *head;
        *head = node;
    }
}

void PopNode(Node **head) {
    if (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void PrintStack(Node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void DeleteStack(Node **head) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
