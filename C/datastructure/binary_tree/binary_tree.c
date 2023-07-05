#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void insert_node(node **ptr, int value, char opt) {

    if (*ptr == NULL) {
        *ptr = malloc(sizeof(node));

        if (*ptr != NULL) {
            (*ptr)->data = value;
            (*ptr)->left = NULL;
            (*ptr)->right = NULL;
        }
        else
            printf("%d not inserted. No memory available.\n", value);
    }
    else {
        if (opt == 'L' || opt == 'l')
            insert_node(&((*ptr)->left), value, opt);
        else if (opt == 'R' || opt == 'r')
            insert_node(&((*ptr)->right), value, opt);
    }
}

void inorder(node *ptr) {

    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d->", ptr->data);
        inorder(ptr->right);
    }
    else
        printf("\\0\n");
}

void instructions() {

    printf(
        "1. Press 1 to insert elements in the tree.\n"
        "2. Press 2 to traverse the tree inorder.\n"
        "3. Press 3 to traverse the tree preorder.\n"
        "4. Press 4 to traverse the tree postorder.\n"
        "*. Press 0 to exit.\n"
    );
}
