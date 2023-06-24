#ifndef LINKED_LIST
#define LINKED_LIST

// synonym for struct node
typedef struct node node;

// self referential struct
struct node {
    int data;  // data for node
    node *link;  // link to next node
};

// function prototypes
// opertations to perfrom on linked list
void insert_element(node **head, node **tail, int value, char ch);
void remove_element(node **head, node **tail, char ch);
int is_empty(node *head);
void print_list(node *head);
void instructions();
void delete_list_on_exiting(node **head);

#endif // !LINKED_LIST
