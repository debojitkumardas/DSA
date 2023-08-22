#include "linked_list.h"
#include <stdio.h>

int main(void) {

    node *head = NULL;
    node *tail = NULL;
    int value = 0;
    int choice = 1;
    char ch = ' ';

    instructions();
    while (choice != 0) {

        printf("Enter the choice (insert/remove/exit): ");
        scanf("%d", &choice);

        if (choice != 0) {
            printf("Enter choice (head/tail): ");
            scanf(" %c", &ch);
        }

        switch (choice) {
            case 0:
                if (!is_empty(head))
                    delete_list_on_exiting(&head);
                break;
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                insert_element(&head, &tail, value, ch);
                break;
            case 2:
                remove_element(&head, &tail, ch);
                break;
            default:
                printf("Please enter a valid choice.\n");
                break;
        }

        print_list(head);
    }

    return 0;
}
