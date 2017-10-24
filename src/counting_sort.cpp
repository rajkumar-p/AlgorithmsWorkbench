#include "counting_sort.hpp"

std::vector<int> counting_sort(std::vector<int> &v, int range)
{
    std::vector<int> count_vec(range + 1, 0);

    // Count the number of occurences
    for (const int e : v) {
        count_vec[e] += 1;
    }

    // Accumulate the sum
    for (unsigned int i = 1; i < count_vec.size(); ++i) {
        count_vec[i] += count_vec[i - 1];
    }

    // Place the elements in its sorted order
    std::vector<int> sorted_vec(v.size());

    for(int i = v.size() - 1; i >= 0; --i) {
        sorted_vec[count_vec[v[i]] - 1] = v[i];
        count_vec[v[i]] -= 1;
    }

    return sorted_vec;
}