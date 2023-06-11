#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertion_sort(int ar[], int n, char c);

int main(void) {

    int ar[10];
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        ar[i] = 1 + rand() % 20;

    printf("Unsorted array.\n");
    for (int i = 0; i < 10; i++)
        printf("%d\n", ar[i]);

    insertion_sort(ar, 10, 'D');

    return 0;
}

void insertion_sort(int ar[], int n, char c) {

    int temp;

    if (c == 'A') {
        // sorting the array in ascending order
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n-i; j++) {
                if (ar[j] > ar[j+1]) {
                    temp = ar[j];
                    ar[j] = ar[j+1];
                    ar[j+1] = temp;
                }
            }
        }

        printf("Sorting in ascending order.\n");
    }

    if (c == 'D') {
        // sorting the array in descending order
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n-i; j++) {
                if (ar[j] < ar[j+1]) {
                    temp = ar[j];
                    ar[j] = ar[j+1];
                    ar[j+1] = temp;
                }
            }
        }

        printf("Sorting in descending order.\n");
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", ar[i]);
}
