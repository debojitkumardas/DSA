#include "hash_table.h"

//

int hash_func(int key) {
    return key % TABLE_SIZE;
}

void insert_data(int key, char *value) {
    bool_ is_key_found = FALSE;

    // get hash key from hash function
    int hash_key = hash_func(key);

    // iterate through chaining node (linked list)
    // in the selected cells
}
