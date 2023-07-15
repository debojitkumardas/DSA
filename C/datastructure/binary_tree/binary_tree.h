#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node node;

struct node {
    int data;
    node *left;
    node *right;
};

void insert_node(node **root, int value, char opt);  // to insert node
void inorder(node *root);  // traverse the tree inorder
// void preorder(node *ptr);
// void postorder(node *ptr);
void delete_tree(node **root);
void instructions();

void get_val(char ch[], void *ptr);  // utility function to resolve scanf's issue

#endif // !BINARY_TREE_H
