#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <vector>

template<typename T>
int binary_search(std::vector<T> &v, int low, int high, T key);

template<typename T>
int binary_search(std::vector<T> &v, int low, int high, T key)
{
    if (low > high) { return -1; }

    unsigned long mid = ((unsigned long) low + (unsigned long) high) >> 1;

    if (v[mid] == key) {
        return mid;
    } else if (v[mid] > key) {
        return binary_search(v, low, mid - 1, key);
    } else {
        return binary_search(v, mid + 1, high, key);
    }
}

#endif
