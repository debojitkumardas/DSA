#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    node *root = NULL;
    int value, choice;
    char option;

    instructions();
    value = 0;
    choice = 1;
    option = 'r';
    while (choice != 0) {
        printf("Enter your choice: ");
        get_val("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting!!\n");
                break;
            case 1:
                printf("Enter value for node: ");
                get_val("%d", &value);
                insert_node(&root, value, option);
                break;
            case 2:
                printf("Traversing the tree inorder!!\n");
                inorder(root);
                break;
            case 3:
                printf("Traversing the tree preorder!!\n");
                preorder(root);
                break;
            case 4:
                printf("Traversing the tree postorder!!\n");
                postorder(root);
                printf("\n");
                break;
            default:
                printf("Enter a valid choice!!\n");
                break;
        }
    }

    return 0;
}
