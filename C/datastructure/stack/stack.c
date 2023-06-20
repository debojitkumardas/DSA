#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// insert elements in stack
node* push(node* head, int value) {

    node* new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->data = value;  // insert value for new node
        new_node->link = head;  // point new_node to top of stack
        head = new_node;  // point head at new_node
    }

    return head;  // return link to new head
}

// remove element from stack
node* pop(node* head) {

    // if stack is not empty
    if (is_empty(head) != -1) {
        node* temp = head;  // hold onto top element that is to be removed
        head = head->link;  // point head to next element of stack
        free(temp);  // delete previous head
    }
    else
        printf("Stack is empty. Nothing to delete.\n");

    return head;  // return link to new heead
}

// check if list is empty
int is_empty(node *head) {

    if (head == NULL)
        return -1;
    else
        return 1;
}

// print elements of stack
void print_stack(node *head) {

    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->link;
    }
}

// delete stack
void delete_stack_on_exit(node *head) {

    while (head != NULL) {
        node* temp = head;
        head = head->link;
        free(temp);
    }
}

void instructions() {

    printf(
           "1. Press 1 to push element into stack.\n"
           "2. Press 2 to pop element from stack. \n"
           "*. Press 0 to exit. \n"
          );
}

// the main function
int main(void) {

    node* head = NULL;  // stack is initially empty
    int value = 0;  // data to be inserted in stack
    int choice = 1;  // choice of operation to be preformed on stack
    int count = 0;  // count the number of elements in stack

    instructions();

    while (choice != 0) {

        printf("Enter the choice: ");
        scanf("%d", &choice);


        if (choice == 1) {
            printf("Enter the value: ");
            scanf("%d", &value);
            count++;  // count number of elements as they are pushed into stack
        }

        if (choice == 2) {
            if (is_empty(head) == -1)  // check if stack is empty
                count--;  // update count as elements are removed from stack
        }

        switch (choice) {
            case 0:
                    break;
            case 1:
                    head = push(head, value);
                    break;
            case 2:
                    head = pop(head);
                    break;
            default:
                    printf("Please enter a valid choice.\n");
                    break;
        }

        // print element of stack
        if (is_empty(head) == 1)
            print_stack(head);
    }

    // deleting any remaining elements of stack
    delete_stack_on_exit(head);

    return 0;
}
