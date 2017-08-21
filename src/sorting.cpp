#include "sorting.hpp"

void insertion_sort(std::vector<int> &v)
{
    for(int i = 1; i < v.size(); ++i) {
        int key = v[i];
        int j = i - 1;

        while(j >= 0 && v[j] > key) {
            if (v[j] > key) {
                v[j+1] = v[j];
            }
            --j;
        }

        v[j+1] = key;
    }
}

void selection_sort(std::vector<int> &v)
{
    for(int i = 0; i < v.size(); ++i) {
        for(int j = i + 1; j < v.size(); ++j) {
            int min_index = i;
            if (v[j] < v[min_index]) {
                min_index = j;
            }

            v[i] = v[min_index];
        }
    }
}

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

void heap_sort(std::vector<int> &v)
{

}

void max_heapify(std::vector<int> &v, int from_node)
{

}

bool is_max_heap(std::vector<int> &v, int from_node)
{
    return false;
}