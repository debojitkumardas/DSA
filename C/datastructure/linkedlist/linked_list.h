typedef struct node node;

// self referential structure
struct node {
    int item;  // each node contains an integer
    node* link;  // pointer to the next node
};  // end structure node


// function prototypes
node* insert_at_head (node* ptr, int val);  // insert value at beginning of list
node* insert_at_tail (node* ptr, int val);  // insert value at the end of list
node* delete_from_head (node* ptr);  // delete value from beginning of list
node* delete_from_tail (node* ptr);  // delete value from end of list
int is_empty (node* ptr);  // check if list is empty
void print_list (node* ptr);  // print list
void instructions ();  // has instructions on insetion, deletion of list elements
