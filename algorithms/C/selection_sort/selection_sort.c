#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int ar[], int n, char order);

int main(void) {

    int ar[10];
    char order = 'D';

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        ar[i] = (rand() % 20) + 2;
        printf("%d\n", ar[i]);
    }

    selection_sort(ar, 10, order);

    for (int i = 0; i < 10; i++)
        printf("%d\n", ar[i]);

    return 0;
}

void selection_sort(int ar[], int n, char order) {

    int index = 0, temp = 0;

    if (order == 'A') {
        // sort in ascending order
        printf("Sorting the array in ascending order.\n");
        for (int i = 0; i < n; i++) {
            index = i;
            for (int j = i + 1; j < n; j++) {
                if (ar[index] > ar[j])
                    index = j;
            }

            if (index != i) {
                temp = ar[i];
                ar[i] = ar[index];
                ar[index] = temp;
            }
        }
    }

    if (order == 'D') {
        // sort in descending order
        printf("Sorting the array in descending order.\n");
        for (int i = 0; i < n; i++) {
            index = i;
            for (int j = i + 1; j < n; j++) {
                if (ar[index] < ar[j])
                    index = j;
            }

            if (index != i) {
                temp = ar[i];
                ar[i] = ar[index];
                ar[index] = temp;
            }
        }
    }
}
