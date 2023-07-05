#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node node;

struct node {
    int data;
    node *left;
    node *right;
};

void insert_node(node **ptr, int value, char opt);
void inorder(node *ptr);
// void preorder(node *ptr);
// void postorder(node *ptr);
void instructions();

#endif // !BINARY_TREE_H
