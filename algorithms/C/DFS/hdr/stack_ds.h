#ifndef STACK_DS
#define STACK_DS

typedef struct Node Node;

struct Node {
    int value;
    Node* next;
};

Node* CreateNode(int value);
void PushNode(Node** head, int value);
void PopNode(Node** head);
void PrintStack(Node* head);
void DeleteStack(Node** head);

#endif // !STACK_DS
