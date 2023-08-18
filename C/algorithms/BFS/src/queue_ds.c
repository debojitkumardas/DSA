#include "../hdr/queue_ds.h"
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

void Enqueue(Node **head, Node **tail, int value) {
    Node* node = CreateNode(value);

    if (*head == NULL) {
        *head = node;
    }
    else {
        (*tail)->next = node;
    }
    *tail = node;
}

void Dequeue(Node **head, Node **tail) {
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);

    // if queue is empty
    if (*head == NULL) {
        *tail = NULL;
    }
}

void PrintQueue(Node *head) {
    while (head != NULL) {
        printf("%d\n", head->value);
        head = head->next;
    }
}

void DeleteQueue(Node **head, Node** tail) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    if (*head == NULL) {
        *tail = NULL;
    }
}
