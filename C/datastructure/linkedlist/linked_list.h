typedef struct node node;

// self referential structure
struct node {
    int data;  // each node contains an integer
    node* link;  // pointer to the next node
};  // end structure node

// function prototypes
node* insert_at_head (node* head, int value);  // insert value at beginning of list
node* insert_at_tail (node* tail, int value);  // insert value at the end of list
node* delete_from_head (node* head);  // delete value from beginning of list
node* delete_from_tail (node* tail);  // delete value from end of list
int is_empty (node* head);  // check if list is empty
void print_list (node* head);  // print list
void instructions ();  // has instructions on insetion, deletion of list elements
void delete_list_on_exit(node* head);  // after doing all required operations delete list
