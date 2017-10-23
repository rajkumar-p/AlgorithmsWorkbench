#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <vector>

template<typename T, typename F = std::less<T>>
void selection_sort(std::vector<T> &v, F cmp_fn);

template<typename T, typename F>
void selection_sort(std::vector<T> &v, F cmp_fn)
{
    for(size_t i = 0; i < v.size(); ++i) {
        size_t index_to_replace = i;
        for(size_t j = i + 1; j < v.size(); ++j) {
            if (cmp_fn(v[j], v[index_to_replace])) {
                index_to_replace = j;
            }
        }

        std::swap(v[i], v[index_to_replace]);
    }
}

#endif