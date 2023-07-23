#ifndef HASH_SET_H
#define HASH_SET_H

#define SET_SIZE 3

typedef enum {FALSE, TRUE} bool_;

typedef struct node node;
typedef struct hash_set hash_set;

struct node {
    int num;
    node *next;
};

bool_ is_empty(node *head);
void insert_node_at_tail(node **head, node **tail, int num);
void remove_node(node **head, node **tail, int num);

struct hash_set {
    node* set_list[SET_SIZE];
};

int hash_func(int key);
bool_ contains(hash_set *hash_set_head, int key);
void insert_data(hash_set *hash_set_head, hash_set *hash_set_tail, int key);
void remove_data(hash_set *hash_set_head, hash_set *hash_set_tail, int key);
void print_set(hash_set *hash_set_head);
void delete_set(hash_set *hash_set_head);

#endif // !HASH_SET_H
