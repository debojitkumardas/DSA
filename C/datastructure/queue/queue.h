typedef struct node node;

// self referential structure
struct node {
    int data;
    node* link;
};

// function prototypes
// list of queue operations
node* enqueue(node* tail, int value);  //
node* dequeue(node* head);
int is_empty(node* head);
void print_queue(node* head);
void instructions();
