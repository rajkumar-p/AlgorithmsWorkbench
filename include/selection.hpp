#ifndef SELECTION_HPP
#define SELECTION_HPP

#include <vector>
#include "quick_sort_utils.hpp"

template<typename T>
T selection(std::vector<T> &v, const int low, const int high, unsigned int rank);

template<typename T>
T selection(std::vector<T> &v, const int low, const int high, unsigned int rank)
{
    if (rank < 1 || rank > v.size()) {
        return T();
    }

    if (low == high) {
        return v[low];
    }

    int x = partition(v, 0, v.size() - 1, std::less<int>());
    unsigned int rank_of_x = x - low + 1;

    if (rank_of_x == rank) {
        return v[x];
    } else if (rank_of_x > rank) {
        return selection(v, low, x - 1, rank);
    } else {
        return selection(v, x + 1, high, rank - rank_of_x);
    }
}

#endif