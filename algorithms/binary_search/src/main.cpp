#include "binary_search.h"
#include <cstddef>
#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    size_t len = sizeof(arr) / sizeof(int);
    int key = 4;
    int res = BinarySearch(arr, len, key);

    std::cout << "res: " << res << '\n';
}
