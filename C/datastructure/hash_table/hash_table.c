#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

void func(char *a, char *b) {

    int i = 0;
    while (i < MAX_CHAR && *b != '\0') {
        a[i] = *b;
        i++;
        b++;
    }
}

bool_ list_is_empty(node *head) {
    if (head == NULL)
        return TRUE;
    else
        return FALSE;
}

void insert_at_tail(node **head, node **tail, int num, char *name) {
    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->num = num;

        func(new_node->name, name);

        if (list_is_empty(*head))
            *head = new_node;
        else
            (*tail)->next = new_node;
        *tail = new_node;
    }
}

int hash_func(int key) {
    return key % TABLE_SIZE;
}

void insert_data(hash_table *table_list_head, hash_table *table_list_tail, int key, char *value) {
    bool_ is_key_found = FALSE;

    // get hash key from hash function
    int hash_key = hash_func(key);

    // iterate through chaining node (linked list)
    // in the selected cells
    node *temp = table_list_head->table_list[hash_key];
    while (temp != NULL) {
        // if the key is found; update the key
        if (temp->num == key) {
            is_key_found = TRUE;
            func(temp->name, value);
        }
        temp = temp->next;
    }

    if (!is_key_found)
        insert_at_tail(&(table_list_head->table_list[hash_key]), &(table_list_tail->table_list[hash_key]), key, value);
}

void print_hash_table(hash_table *ptr) {

    for (int i = 0; i < TABLE_SIZE; ++i) {
        node *temp = ptr->table_list[i];
        while (temp != NULL) {
            printf("key: %d \t value: %s\n", temp->num, temp->name);
            temp = temp->next;
        }
    }
}
