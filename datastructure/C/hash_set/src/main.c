#include "../hdr/hash_set.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    hash_set hash_set_head;
    hash_set hash_set_tail;

    //char ch[2][6] = {"FALSE\0", "TRUE\0"};
    char *ch[2] = {"FALSE", "TRUE"};
    int res;

    for (int i = 0; i < SET_SIZE; ++i) {
        hash_set_head.set_list[i] = NULL;
        hash_set_tail.set_list[i] = NULL;
    }

    insert_data(&hash_set_head, &hash_set_tail, 1);

    insert_data(&hash_set_head, &hash_set_tail, 2);

    res = contains(&hash_set_head, 1);
    printf("%d is in set: %s\n", 1, ch[res]);

    res = contains(&hash_set_head, 3);
    printf("%d is in set: %s\n", 3, ch[res]);

    insert_data(&hash_set_head, &hash_set_tail, 2);

    res = contains(&hash_set_head, 2);
    printf("%d is in set: %s\n", 2, ch[res]);

    remove_data(&hash_set_head, &hash_set_tail, 2);
    print_set(&hash_set_head);

    res = contains(&hash_set_head, 2);
    printf("%d is in set: %s\n", 2, ch[res]);

    delete_set(&hash_set_head);

    return 0;
}
