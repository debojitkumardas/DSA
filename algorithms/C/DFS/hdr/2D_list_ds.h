#ifndef LIST_H
#define LIST_H

#include "stack_ds.h"

typedef struct ListNode ListNode;

struct ListNode {
    Node* List;
    ListNode* next;
};

ListNode* CreateListNode(void);
void PushValue(ListNode** head, int* list, int len);
void PrintList(ListNode* head);
void DeleteList(ListNode** head);

#endif // !LIST_H
