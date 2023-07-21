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
        new_node->next = NULL;

        if (list_is_empty(*head))
            *head = new_node;
        else
            (*tail)->next = new_node;
        *tail = new_node;
    }
}

void remove_element(node **head, node **tail, int num) {
    if (!list_is_empty(*head)) {
        node *temp = *head;
        node *h_ptr = NULL;
        // if element if at head
        if (temp->num == num) {
            *head = temp->next;
            free(temp);
        }
        else {
            while (temp != NULL) {
                h_ptr = temp->next;
                if (h_ptr->num == num) {
                    // if element is at tail
                    if (h_ptr->next == NULL) {
                        temp->next = NULL;
                        *tail = temp;
                        free(h_ptr);
                    }
                    else {
                        temp->next = h_ptr->next;
                        free(h_ptr);
                        break;
                    }
                }
                temp = temp->next;
            }
        }
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

void remove_data(hash_table *table_list_head, hash_table *table_list_tail, int key) {
    int hash_key = hash_func(key);

    remove_element(&(table_list_head->table_list[hash_key]), &(table_list_tail->table_list[hash_key]), key);
}

void search_data(hash_table *table_list_head, int key) {
    int hash_key = hash_func(key);
    bool_ is_found = FALSE;

    node *temp = table_list_head->table_list[hash_key];
    while (temp != NULL) {
        if (temp->num == key) {
            is_found = TRUE;
            printf("Found key: %d, value is: %s\n", temp->num, temp->name);
        }
        temp = temp->next;
    }

    if (!is_found)
        printf("Key not found.\n");
}

void print_hash_table(hash_table *ptr) {

    for (int i = 0; i < TABLE_SIZE; ++i) {
        node *temp = ptr->table_list[i];
        while (temp != NULL) {
            printf("[%d, %s] - ", temp->num, temp->name);
            temp = temp->next;
        }
        printf("\\0\n");
    }
}

void delete_table(hash_table *ptr) {

    for (int i = 0; i < TABLE_SIZE; ++i) {
        node **temp = &(ptr->table_list[i]);
        while (*temp != NULL) {
            node *h_ptr = *temp;
            *temp = (*temp)->next;
            free(h_ptr);
        }
    }
}
