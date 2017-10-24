#include "sorting.hpp"
#include <iostream>

std::vector<int> counting_sort(std::vector<int> &v, int range)
{
    std::vector<int> count_vec(range + 1, 0);

    // Count the elements
    for (auto e : v) {
        count_vec[e] += 1;
    }

    // Accumulate the sum of elements
    for (int i = 1; i < count_vec.size(); ++i) {
        count_vec[i] += count_vec[i - 1];
    }

    std::vector<int> sorted_vec(v.size(), 0);

    // Sort the elements based on its count
    for (int i = v.size() - 1; i >= 0; --i) {
        sorted_vec[count_vec[v[i]] - 1] = v[i];
        count_vec[v[i]] -= 1;
    }

    return sorted_vec;
}

int parent_index_of(int index) { return (index - 1) >> 1; }
int left_index_of(int index) { return (index << 1) + 1; }
int right_index_of(int index) { return (index << 1) + 2; }

// void heap_sort(std::vector<int> &v)
// {

// }

// void max_heapify(std::vector<int> &v, int from_node)
// {

// }

// bool is_max_heap(std::vector<int> &v, int from_node)
// {
//     return false;
// }