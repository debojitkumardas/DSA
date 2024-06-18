#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <cstddef>

template <typename T>
T LinearSearch(T* arr, size_t len, T key) {
    for (size_t i = 0; i < len; ++i) {
        if (arr[i] == key) {
            return arr[i];
        }
    }

    return {};
}

#endif // !LINEAR_SEARCH_H
