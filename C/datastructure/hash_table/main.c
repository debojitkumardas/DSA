#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    hash_table new_table_head;
    hash_table new_table_tail;

    for (int i = 0; i < TABLE_SIZE; ++i) {
        new_table_head.table_list[i] = NULL;
        new_table_tail.table_list[i] = NULL;
    }

    insert_data(&new_table_head, &new_table_tail, 434, "Dylan");
    insert_data(&new_table_head, &new_table_tail, 806, "Adam");
    insert_data(&new_table_head, &new_table_tail, 722, "Brynn");
    insert_data(&new_table_head, &new_table_tail, 548, "Cameron");
    insert_data(&new_table_head, &new_table_tail, 391, "Dominic");
    insert_data(&new_table_head, &new_table_tail, 895, "Vanessa");

    search_data(&new_table_head, 722);
    search_data(&new_table_head, 723);

    printf("Hash table before removal.\n");
    print_hash_table(&new_table_head);

    remove_data(&new_table_head, &new_table_tail, 548);

    printf("Hash table after removal.\n");
    print_hash_table(&new_table_head);

    delete_table(&new_table_head);

    return 0;
}
