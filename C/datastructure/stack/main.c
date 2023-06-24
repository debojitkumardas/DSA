#include "stack.h"
#include <stdio.h>

int main(void) {

    node *head = NULL;
    int value = 0;
    int choice = 1;

    stack_instructions();
    while (choice == 1) {

        printf("Enter your choice (push/pop): ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                if (!is_empty(head))
                    delete_stack(&head);
                break;
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                push_element(&head, value);
                break;
            case 2:
                pop_element(&head);
                break;
        }
    }

    return 0;
}
