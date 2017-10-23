#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>

template<typename T, typename F = std::less<T>>
void insertion_sort(std::vector<T> &v, F cmp_fn);

template<typename T, typename F>
void insertion_sort(std::vector<T> &v, F cmp_fn)
{
    for(size_t i = 1; i < v.size(); ++i) {
        T current = v[i];
        int j = i - 1;

        while(cmp_fn(current, v[j]) && j >= 0) {
            v[j + 1] = v[j];
            --j;
        }

        v[j + 1] = current;
    }
}

#endif