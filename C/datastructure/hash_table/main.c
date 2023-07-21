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

    #if NR
    int choice = 1;
    int key;
    char value[MAX_CHAR];

    while (choice) {

        printf("Enter key: ");
        scanf("%d", &key);
        getchar();
        printf("Enter value: ");
        scanf("%s", value);
        getchar();

        insert_data(&new_table_head, &new_table_tail, key, value);

        printf("Enter choice: ");
        scanf("%d", &choice);
    }
    #endif

    print_hash_table(&new_table_head);

    return 0;
}
