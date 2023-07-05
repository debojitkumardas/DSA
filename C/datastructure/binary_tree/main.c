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
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting!!\n");
                exit(1);
                break;
            case 1:
                printf("Enter value for node: ");
                scanf("%d", &value);
                // printf("Enter choice for the subtree <l: left, r: right>: ");
                // scanf("%c", &option);
                insert_node(&root, value, option);
                break;
            case 2:
                printf("Traversing the tree inorder!!\n");
                inorder(root);
                break;
            default:
                printf("Enter a valid choice!!\n");
                break;
        }
    }

    return 0;
}
