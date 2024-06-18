#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <cstddef>

template <typename T>
T BinarySearch(T* arr, size_t len, T key, char sort = 'a') {
    size_t left_index = 0;
    size_t right_index = len - 1;
    size_t mid = left_index + (right_index - left_index + 1) / 2;

    if (sort == 'a') {
        while (left_index < right_index && right_index > 0) {
            if (arr[mid] == key) {
                return arr[mid];
            } else if (arr[mid] > key) {
                right_index = mid - 1;
            } else {
                left_index = mid + 1;
            }
            mid = left_index + (right_index - left_index) / 2;
        }
    } else {
        while (left_index < right_index && right_index > 0) {
            if (arr[mid] == key) {
                return arr[mid];
            } else if (arr[mid] < key) {
                right_index = mid - 1;
            } else {
                left_index = mid + 1;
            }
            mid = left_index + (right_index - left_index) / 2;
        }
    }

    return {};
}

#endif // !BINARY_SEARCH_H
