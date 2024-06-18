#include "linear_search.h"
#include <cstddef>
#include <iostream>

int main() {
    char arr[] = {'a', 'd', '1', '4', '5'};
    size_t len = sizeof(arr) / sizeof(char);
    char key = '9';
    char res = ' ';

    std::cout << "len: " << len << '\n';
    res = LinearSearch(arr, len, key);

    std::cout << "res: " << res << '\n';

    return 0;
}
