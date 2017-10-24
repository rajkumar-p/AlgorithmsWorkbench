#include "sorting.hpp"
#include <iostream>

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