#include <stdio.h>

void binary_search(int [], int, int, int);

int main(void) {

    int ar[8];

    for (int i = 0; i < 8; i++)
        ar[i] = i + 1;

    binary_search(ar, 0, 0, 7);

    return 0;
}

void binary_search(int ar[], int x, int s, int e) {

    if (e >= s) {
        int mid = s + (e - s) / 2;

        if (ar[mid] == x) {
            printf("Found the element %d at position %d\n", ar[mid], mid);
            return;
        }

        if (ar[mid] > x)
            binary_search(ar, x, s, mid-1);
        else
            binary_search(ar, x, mid+1, e);
    }

    else
        printf("Couldn't find the element!!\n");
}
