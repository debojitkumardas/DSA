#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    node *head = NULL;
    node *tail = NULL;
    int value = 0;
    int choice = 1;

    instructions();
    while (choice != 0) {

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                if (!is_empty(head))
                    delete_queue(&head, &tail);
                break;
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                enqueue(&head, &tail, value);
                break;
            case 2:
                dequeue(&head, &tail);
                break;
            default:
                printf("Enter a valid choice.\n");
                break;
        }

        print_queue(head);
    }

    delete_queue(&head, &tail);

    return 0;
}
