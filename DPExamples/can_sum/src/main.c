#include <stdio.h>
#include <stdlib.h>

int CanSumMemo(long target, long* ar, int len, int* memo) {
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;
    if (memo[target] == 1)
        return memo[target];

    for (int i = 0; i < len; ++i) {
        if (CanSumMemo(target-ar[i], ar, len, memo) == 1) {
            memo[target] = 1;
            return memo[target];
        }
    }

    memo[target] = 0;

    return memo[target];
}

int main(void) {

    long* ar = NULL;
    int n;
    long target;
    long len;
    char* buf[] = {"No", "Yes"};
    int res;
    int* memo = NULL;

    // *************************************************************************************
    n = 3;
    ar = (long [3]) {2, 3, 5};
    target = 8;
    len = target + 1;
    memo = (int*) malloc(len * sizeof(int));

    for (int i = 0; i < len; ++i)
        memo[i] = 0;
    res = CanSumMemo(target, ar, n, memo);

    for (int i = 0; i < n; ++i)
        printf("%ld ", ar[i]);
    printf("\n");

    printf("Is it possible for the above array to achieve the targe sum of %ld? %s\n", target, buf[res]);

    // *************************************************************************************
    n = 2;
    ar = (long [2]) {7, 14};
    target = 300;
    len = target + 1;
    memo = (int*) malloc(len * sizeof(int));

    for (int i = 0; i < len; ++i)
        memo[i] = 0;
    res = CanSumMemo(target, ar, n, memo);

    for (int i = 0; i < n; ++i)
        printf("%ld ", ar[i]);
    printf("\n");

    printf("Is it possible for the above array to achieve the targe sum of %ld? %s\n", target, buf[res]);

    free(memo);

    return 0;
}
