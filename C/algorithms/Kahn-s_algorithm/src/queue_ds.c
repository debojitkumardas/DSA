#include "../hdr/queue_ds.h"
#include <stdlib.h>
#include <stdio.h>

Node* CreateNode(int value) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node != 0) {
        new_node->value = value;
        new_node->next = NULL;
    }

    return new_node;
}

void Enqueue(Node **head, Node **tail, int value) {
    Node* node = CreateNode(value);

    if (node != NULL) {
        if (*head == NULL) {
            *head = node;
        }
        else {
            (*tail)->next = node;
        }
        *tail = node;
    }
}

void Dequeue(Node **head, Node **tail) {
    if (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (*head == NULL) {
        *tail = NULL;
    }
}

void PrintQueue(Node *head) {
    while (head != NULL) {
        printf("%d, ", head->value);
        head = head->next;
    }
    printf("\b\b\n");
}

void DeleteQueue(Node **head, Node **tail) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (*head == NULL) {
        *tail = NULL;
    }
}
