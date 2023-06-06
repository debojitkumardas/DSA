#include <stdio.h>

void binary_search(int [], int, int, int);

int main(void) {

    int ar[8];

    for (int i = 0; i < 8; i++)
        ar[i] = i + 1;

    binary_search(ar, 7, 9, 0);

    return 0;
}

void binary_search(int ar[], int n, int x, int start) {

    if (n >= start) {
        int mid = start + (n - start) / 2;

        if (ar[mid] == x) {
            printf("found the element %d at %d\n", ar[mid], mid);
            return;
        }

        if (ar[mid] < x)
            binary_search(ar, n, x, mid + 1);
        else
            binary_search(ar, mid, x, start);
    }

    printf("Element not found\n");
}
