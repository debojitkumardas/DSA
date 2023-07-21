#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAX_CHAR 256
#define TABLE_SIZE 7

typedef struct node node;
typedef struct hash_table hash_table;

typedef enum {FALSE, TRUE} bool_;

struct node {
    int num;
    char name[MAX_CHAR];
    node *next;
};

void func(char *a, char *b);
bool_ list_is_empty(node *head);
void insert_at_tail(node **head, node **tail, int num, char *name);
void remove_element(node **head, node **tail, int num);

struct hash_table {
    node* table_list[TABLE_SIZE];
};

int hash_func(int key);
void insert_data(hash_table *table_list_head, hash_table *table_list_tail, int key, char *value);
void remove_data(hash_table *table_list_head, hash_table *table_list_tail, int key);
void search_data(hash_table *table_list_head, int key);
// bool_ is_empty();
void print_hash_table(hash_table *ptr);
void delete_table(hash_table *ptr);

#endif // !HASH_TABLE_H
