typedef struct node node;

// self referential structure
struct node {
    int data;
    node* link;
};

// function prototypes
// stack operations: push, pop, isempty
node* push(node* head, int value);  // insert value at head of list
node* pop(node* head);  // remove value from head of list
int is_empty(node* head);  // check if list is empty
void print_stack(node* head);  // display elements of stack
void instructions();  // list available operations on stack
void delete_stack_on_exit(node* head);  // delete stack after performing relevant operations
