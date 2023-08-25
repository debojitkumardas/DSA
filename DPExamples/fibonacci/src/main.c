#include <stdio.h>
#include <stdlib.h>

long FibMem(long n, long* ar) {
    if (ar[n - 1] != 0)
        return ar[n - 1];
    if (n <= 2)
        return 1;

    ar[n - 1] = FibMem(n - 1, ar) + FibMem(n - 2, ar);

    return ar[n - 1];
}

int main(void) {

    int n = 0;
    long *ar = NULL;
    long res = 0;

    n = 50;
    ar = (long*) malloc(n * sizeof(long));
    for (int i = 0; i < n; ++i)
        ar[i] = 0;
    res = FibMem(n, ar);

    printf("%dth Fibonacci number: %ld\n", n, res);

    free(ar);

    return 0;
}
