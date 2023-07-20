#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAX_CHAR 256
#define TABLE_SIZE 10

typedef struct node node;
typedef struct hash_table hash_table;

typedef enum {FALSE, TRUE} bool_;

struct node {
    int num;
    char name[MAX_CHAR];
    node *next;
};

void insert_at_tail(node **head, node **tail, int num, char *name);

struct hash_table {
    node table_list[TABLE_SIZE];
};

int hash_func(int key);
void insert_data(int key, char *value);
char* search_data(int key);
void remove_data(int key);
bool_ is_empty();

#endif // !HASH_TABLE_H
