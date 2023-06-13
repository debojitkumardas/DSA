#include <stdio.h>
#include <stdlib.h>

// self referential structure
struct node {
    int item;  // each node contains an integer
    struct node* link;  // pointer to the next node
};  // end structure node

typedef struct node node;

// function prototypes
void insert (node* ptr, int val);  // insert value at the end of list
char delete (node* ptr, int pos);  // delete value at any position in list
int is_empty (node* ptr);  // check if list is empty
void print_list (node* ptr);  // print list
void instructions (void);  // has instructions on insetion, deletion of list elements

int main (void) {

    node* head = NULL;  // initially there are no nodes
    int choice, value, position;  // users choice, value and position

    instructions();
    printf("? ");
    scanf("%d", &choice);

    // while user doesn't choose 3
    while (choice != 3) {

        switch (choice) {
            case 1:
                printf("enter a value: ");
                scanf("%d", &value);
                insert(head, value);
                print_list(head);
                break;
            case 2:
                // if list is not empty
                if (!is_empty(head)) {
                    printf("enter the postion of the element to be deleted: ");
                    scanf("%d", &position);
                }
        }
    }
}



/*
typedef struct node* link;

struct node {
    int item;
    link next;
};

int main() {

    int i, N = 5, M = 3;

    link t = malloc(sizeof *t), x = t;

    t->item = 1;
    t->next = t;

    for (i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof *x));
        x->item = i;
        x->next = t;
    }

    while (x != x->next) {
        for (i = 1; i < M; i++) {
            x = x->next;
        }

        x->next = x->next->next;
        N--;
    }

    printf("%d\n", x->item);

    return 0;
}
*/
