#include "../hdr/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

// insert node in tree
void insert_node(node **root, int value, char opt) {

    // if tree is empty
    if (*root == NULL) {
        *root = malloc(sizeof(node));  // create an empty node

        // node created successfully
        if (*root != NULL) {
            (*root)->data = value;  // assign value to node
            (*root)->left = NULL;  // left subtree as NULL
            (*root)->right = NULL;  // right subtree as NULL
        }
        else
            printf("%d not inserted. No memory available.\n", value);
    }
    // if tree has node(s)
    else {
        printf("The current root node of the subtree is: %d\n", (*root)->data);
        printf("Which branch of the subtree do you want your value to be in (l/r)? ");
        get_val("%c", &opt);
        if (opt == 'L' || opt == 'l')
            insert_node(&((*root)->left), value, opt);
        else if (opt == 'R' || opt == 'r')
            insert_node(&((*root)->right), value, opt);
    }
}

void inorder(node *root) {

    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
    else
        printf("\\0\n");
}

void preorder(node *root) {

    if (root != NULL) {
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    else
        printf("\\0\n");
}

void postorder(node *root) {

    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d->", root->data);
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

// the issue with scanf is that it leaves a newline in the buffer which interupts with the following scanf
// for that purpose get_val is created where the getchar after the scanf takes care of the trailing newline
void get_val(char ch[], void *ptr) {
    scanf(ch, ptr);
    getchar();
}
