#include <stdio.h>
#include <stdlib.h>

long GridTravMem(long row, long col, long** ar) {
    if (ar[row - 1][col - 1] != -1)
        return ar[row - 1][col - 1];
    if (row == 1 || col == 1)
        return 1;

    if (row == col) {
        ar[row - 1][col - 1] = 2 * GridTravMem(row - 1, col, ar);
    }
    else
        ar[row - 1][col - 1] = GridTravMem(row - 1, col, ar) + GridTravMem(row, col - 1, ar);

    return ar[row - 1][col - 1];
}

int main(void) {

    long row = 0;
    long col = 0;
    long **ar = NULL;
    long res = 0;

    row = 3;
    col = 3;

    ar = (long**) malloc(row * sizeof(long*));
    for (int i = 0; i < row; ++i) {
        ar[i] = (long*) malloc(col * sizeof(long));
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j)
            ar[i][j] = -1;
    }

    res = GridTravMem(row, col, ar);

    printf("For a grid of %ld x %ld the possible ways to travel is: %ld\n", row, col, res);

    for (int i = 0; i < row; ++i)
        free(ar[i]);
    free(ar);

    return 0;
}
