#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAX_CHAR 256
#define TABLE_SIZE 26

typedef struct node node;
typedef struct hash_table hash_table;

typedef enum {FALSE, TRUE} bool_;

struct node {
    int num;
    char name[MAX_CHAR];
    node *next;
};

struct hash_table {
    node* table_list[TABLE_SIZE];
};

int hash_func(int key);
int contains_elem(hash_table *head, char *name);
void insert_elem(hash_table *head, char *name);
void print_table(hash_table *head);
void delete_table(hash_table *head);

#endif // !HASH_TABLE_H
