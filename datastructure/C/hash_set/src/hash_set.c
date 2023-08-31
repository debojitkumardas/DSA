#include "../hdr/hash_set.h"
#include <stdlib.h>
#include <stdio.h>

bool_ is_empty(node *head) {
    if (head == NULL)
        return TRUE;
    else
        return FALSE;
}
void insert_node_at_tail(node **head, node **tail, int num) {
    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->num = num;
        new_node->next = NULL;

        if (is_empty(*head))
            *head = new_node;
        else
            (*tail)->next = new_node;
        *tail = new_node;
    }
}

void remove_node(node **head, node **tail, int num) {
    if (!is_empty(*head)) {

        node *temp = NULL;
        node *h_ptr = NULL;

        if ((*head)->num == num) {
            temp = *head;
            *head = (*head)->next;
            free(temp);
            return;
        }
        else {
            temp = *head;
            while (temp != NULL) {
                h_ptr = temp->next;

                if (h_ptr->num == num) {
                    // if it's at tail
                    if (h_ptr->next == NULL) {
                        *tail = temp;
                        temp->next = NULL;
                        free(h_ptr);
                        break;
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
    return key % SET_SIZE;
}

bool_ contains(hash_set *hash_set_head, int key) {
    int hash_val = hash_func(key);

    node *temp = hash_set_head->set_list[hash_val];
    while (temp != NULL) {
        if (temp->num == key)
            return TRUE;

        temp = temp->next;
    }

    return FALSE;
}

void insert_data(hash_set *hash_set_head, hash_set *hash_set_tail, int key) {
    if (!contains(hash_set_head, key)) {
        int hash_val = hash_func(key);
        insert_node_at_tail(&(hash_set_head->set_list[hash_val]), &(hash_set_tail->set_list[hash_val]), key);
    }
    else
        print_set(hash_set_head);
}

void remove_data(hash_set *hash_set_head, hash_set *hash_set_tail, int key) {
    int hash_val = hash_func(key);

    remove_node(&(hash_set_head->set_list[hash_val]), &(hash_set_tail->set_list[hash_val]), key);
}

void print_set(hash_set *hash_set_head) {
    printf("[");
    for (int i = 0; i < SET_SIZE; ++i) {
        node *temp = hash_set_head->set_list[i];
        while (temp != NULL) {
            printf("%d, ", temp->num);
            temp = temp->next;
        }
    }
    printf("]\n");
}

void delete_set(hash_set *hash_set_head) {
    for (int i = 0; i < SET_SIZE; ++i) {
        node *temp = hash_set_head->set_list[i];
        while (temp != NULL) {
            node *h_ptr = temp;
            temp = temp->next;
            free(h_ptr);
        }
    }
}
