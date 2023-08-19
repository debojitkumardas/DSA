#include "../hdr/2D_list_ds.h"
#include "hdr/stack_ds.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* CreateListNode(void) {
    ListNode* new_list = malloc(sizeof(ListNode));

    if (new_list != NULL) {
        new_list->List = NULL;
        new_list->next = NULL;
    }

    return new_list;
}

void PushValue(ListNode** head, int* list, int len) {
    ListNode* new_list = CreateListNode();

    if (new_list != NULL) {
        for (int i = len - 1; i >= 0; --i) {
            if (list[i] != -1)
                PushNode(&(new_list->List), list[i]);
        }
        new_list->next = *head;
        *head = new_list;
    }
}

void PrintList(ListNode* head) {
    while (head != NULL) {
        Node* temp = head->List;
        printf("[");
        if (temp == NULL)
            printf("  ");
        while (temp != NULL) {
            printf("%d, ", temp->value);
            temp = temp->next;
        }
        printf("\b\b]\n");
        head = head->next;
    }
}

void DeleteList(ListNode **head) {
    while (*head != NULL) {
        // This one gave me a lot of headace; need to remember to free head as well before it reaches null
        // What I did was: Node* temp = (*head)->List; which was wrong as the head pointer was not freed
        ListNode* temp = *head;
        *head = (*head)->next;
        DeleteStack(&(temp->List));
        free(temp);
    }

    free(*head);
}
