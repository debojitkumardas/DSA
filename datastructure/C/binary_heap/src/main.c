#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* ar) {

}

int main(void) {
    int *ar = NULL;
    int n = 6;

    ar = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        ar[i] = i;
    }

    return 0;
}
