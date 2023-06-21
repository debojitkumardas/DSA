#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node node;

struct node {
    int data;
    node *link;
};

void insert_element(node **head, node **tail, int value, char ch);
void remove_element(node **head, node **tail, char ch);
int is_empty(node *head);
void print_list(node *head);
void instructions();
void delete_list_on_exiting(node **head);

#endif // !LINKED_LIST
