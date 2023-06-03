#include <stdio.h>

void linear_search(int [], int, int);

int main() {

    int ar[10], x = 2;

    for (int i = 0; i < 10; i++)
        ar[i] = i;

    linear_search(ar, 10, x);
}

void linear_search(int ar[], int n, int x) {

    for (int i = 0; i < n; i++) {
        if (x == ar[i]) {
            printf("Found the element!!\n");
            return;
        }
    }

    printf("Couldn't find the element!!\n");
}
