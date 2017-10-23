#include "sorting.hpp"
#include <iostream>

void merge_sort(std::vector<int> &v,int p, int r)
{
    if (p < r) {
        int q = ((unsigned int) p + (unsigned int) r) >> 1;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);

        merge(v, p, q, r);
    }
}

void merge(std::vector<int> &v, int p, int q, int r)
{
    if (p > r) {
        return;
    }

    std::vector<int> left(v.begin() + p, v.begin() + q + 1);
    std::vector<int> right(v.begin() + q + 1, v.begin() + r + 1);

    int k = p;
    int left_index = 0, right_index = 0;

    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] <= right[right_index]) {
            v[k++] = left[left_index++];
        } else {
            v[k++] = right[right_index++];
        }
    }

    while (left_index < left.size()) {
        v[k++] = left[left_index++];
    }
    
    while (right_index < right.size()) {
        v[k++] = right[right_index++];
    }
}

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