#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// insert data at head of linked list
node* insert_at_head(node* head, int value) {

    node* new_node = malloc(sizeof(node));  // create a new node

    if (new_node != NULL) {
        new_node->data = value;  // insert data in the created node
        new_node->link = head;  // make it point to the previous head
        head = new_node;  // head points to the new node
    }

    return head;  // return the pointer to new head
}

// insert data at tail of linked list
node* insert_at_tail(node* tail, int value) {

    node* new_node = malloc(sizeof(node));  // create a new node

    if (new_node != NULL) {
        new_node->data = value;  // insert data in the created node
        new_node->link = NULL;  // as it's the last node, therefore the last link points to NULL
        if (tail != NULL)
            tail->link = new_node;  // point the previous node's link to this created node
        tail = new_node;  // tail points to the new node
    }

    return tail;  // return pointer to new tail
}

// delete data from head of linked list
node* delete_from_head(node* head) {

    node* temp = head;  // assign head to a temporary pointer

    if (head != NULL) {
        head = head->link;  // make the next node as head
        free(temp);  // delete the previous head
    }

    return head;  // return the pointer to new head
}

// delete data from tail of linked list
node* delete_from_tail(node* ptr) {

    node* temp = NULL;  // create a temporary pointer

    // if list has only one element
    if (ptr->link == NULL) {  // check if list has only one element
        temp = ptr;  // this line is technically not required as the pointer (ptr is passed as a copy); one could just do free(ptr) and that would be correct as well
        free(temp);  // deleting the node
        return NULL;
    }

    // if list has more than one element
    while (ptr != NULL) {
        temp = ptr->link;  // go to the next node
        if (temp->link == NULL) {  // check if it's the last node
            ptr->link = NULL;  // point the link of the second last node to NULL
            free(temp);  // delete the last node
            break;
        }

        ptr = ptr->link;  // go to the next node
    }

    return ptr;  // return link for the new last node
}

// check if linked list is empty
int is_empty(node* head) {

    if (head == NULL)  // check if list is empty
        return -1;
    else
        return 1;
}

// print linked list
void print_list(node* head) {

    // first check if list is empty
    if (is_empty(head) == -1) {
        printf("List is empty!!\n");
        return;
    }

    // if list is not empty print the elements of list
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->link;
    }
}

// list of available operations
void instructions() {

    printf(
           "1. Press 1 to enter element at head of list. \n"
           "2. Press 2 to enter element at tail of list. \n"
           "3. Press 3 to delete element from head of list. \n"
           "4. Press 4 to delete element from tail of list. \n"
           "*. Press 0 to exit. \n"
           );
}

// after all the required operations are done delete any remains of the list
void delete_list_on_exit(node* head) {

    while (head != NULL) {
        node* temp = head;
        head = head->link;
        free(temp);
    }
}

int main (void) {

    node* head = NULL;  // initially there are no nodes
    node* tail = NULL;  // initially there are no nodes
    int value = 0;  // users input value; initializing it to 0
    int choice = 1;  // users input choice; initializing to 1
    int count = 0;  // count the number of elements in list

    instructions();  // calling the instructions function to list the available operations

    // the process of creating the linked list begins here
    while (choice != 0) {

        printf("Please enter the choice: ");  // enter the choice from the set of instructions
        scanf("%d", &choice);

        // to insert values in list
        if (choice == 1 || choice == 2) {
            printf("enter the value of the element: ");
            scanf("%d", &value);
            count++;  // update the value of count as an element is inserted
        }

        // to delete values form list
        if (choice == 3 || choice == 4) {
            // check if the list is empty
            if (is_empty(head) == -1) {
                printf("List is empty!! Nothing to delete.\n");
                continue;  // if it's empty go to the start of the loop
            }
            count--;  // update the value of count as an element is deleted
        }

        // given the user's choice perform the operations
        switch (choice) {
            case 1:
                    head = insert_at_head(head, value);  // insert data at head of list and update head pointer
                    break;
            case 2:
                    tail = insert_at_tail(tail, value);  // insert data at tail of list and update tail pointer
                    break;
            case 3:
                    head = delete_from_head(head);  // delete data from head of list and update head pointer
                    break;
            case 4:
                    tail = delete_from_tail(head);  // delete data from tail of list and update tail pointer
                    break;
            default:
                    printf("Wrong choice!! Please enter a vaild choice from the ones listed.\n");
                    break;

        }

        // when list has only one element; update head and tail pointer accordingly
        // as for the fist element head and tail both are equal (i.e., point at the same node)
        if (count == 1) {
            if (tail == NULL)
                tail = head;  // when first insertion is done via head pointer
            if (head == NULL)
                head = tail;  // when first insertion is done via tail pointer
        }

        // when list is empty and one of the pointer is not NULL
        // happens when elements of the list is deleted via one or the other
        if (count == 0) {
            head = NULL;
            tail = NULL;
        }

        // printing the linked list
        if (is_empty(head) == 1)  // check if list is not empty
            print_list(head);  // print element of list
    }

    // delete any remaining nodes of list
    delete_list_on_exit(head);

    return 0;
}
