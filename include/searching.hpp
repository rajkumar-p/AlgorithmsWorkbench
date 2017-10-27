#ifndef SEARCHING_HPP
#define SEARCHING_HPP

#include <vector>
#include "quick_sort_utils.hpp"

template<typename T>
T select(std::vector<T> &v, int p, int r, int rank);

template<typename T>
T select(std::vector<T> &v, int p, int r, int rank)
{
    if (rank > v.size()) { return T(); }
    if (p == r) { return v[p]; }

    int q = partition(v, p, r, std::less<T>());

    // Get the rank of the index
    int rank_of_q = q - p + 1;

    if (rank_of_q == rank) {
        return v[q];
    } else if (rank_of_q > rank) {
        return select(v, p, q - 1, rank);
    } else {
        return select(v, q + 1, r, rank - rank_of_q);
    }

}

#endif