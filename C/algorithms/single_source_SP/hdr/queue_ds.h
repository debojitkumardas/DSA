#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node Node;

struct Node {
    int value;
    Node* next;
};

Node* CreateNode(int value);
void Enqueue(Node** head, Node** tail, int value);
void Dequeue(Node** head, Node** tail);
void PrintQueue(Node* head);
void DeleteQueue(Node** head, Node** tail);

#endif // !QUEUE_H
