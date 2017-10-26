#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include <random>
#include "quick_sort_utils.hpp"

template<typename T, typename F>
void quick_sort(std::vector<T> &v, const int p, const int r, F cmp_fn);

// template<typename T, typename F>
// size_t partition(std::vector<T> &v, int p, int r, F cmp_fn);

template<typename T, typename F>
void quick_sort(std::vector<T> &v, const int p, const int r, F cmp_fn)
{
    if (p < r) {
        size_t q = partition(v, p, r, cmp_fn);
        quick_sort(v, p, q - 1, cmp_fn);
        quick_sort(v, q + 1, r, cmp_fn);
    }
}

#endif