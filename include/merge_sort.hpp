#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

template<typename T, typename F = std::less<T>>
void merge_sort(std::vector<T> &v, int p, int r, F cmp_fn);

template<typename T, typename F = std::less<T>>
void merge(std::vector<T> &v, int p, int q, int r, F cmp_fn);

template<typename T, typename F>
void merge_sort(std::vector<T> &v, int p, int r, F cmp_fn)
{
    if (p < r) {
        int q = ((unsigned int) p + (unsigned int) r) >> 1;
        merge_sort(v, p, q, cmp_fn);
        merge_sort(v, q + 1, r, cmp_fn);

        merge(v, p, q, r, cmp_fn);
    }
}

template<typename T, typename F>
void merge(std::vector<T> &v, int p, int q, int r, F cmp_fn)
{
    if (p > r) {
        return;
    }

    std::vector<T> left(v.begin() + p, v.begin() + q + 1);
    std::vector<T> right(v.begin() + q + 1, v.begin() + r + 1);

    int k = p;
    size_t left_index = 0, right_index = 0;

    while (left_index < left.size() && right_index < right.size()) {
        if (cmp_fn(left[left_index], right[right_index]) == true) {
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

#endif