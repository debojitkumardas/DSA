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
void preorder(node *root);  // traverse the tree preorder
void postorder(node *root);  // traverser the tree postorder
void delete_tree(node **root);  // delete tree
void instructions();  // list relevant operations that can be performed

void get_val(char ch[], void *ptr);  // utility function to resolve scanf's issue

#endif // !BINARY_TREE_H
