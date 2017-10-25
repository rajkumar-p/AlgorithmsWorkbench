#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>
#include <cmath>

template<typename T, typename F = std::less<T>>
void heap_sort(std::vector<T> &v, unsigned long heap_size, F cmp_fn);

template<typename T, typename F = std::less<T>>
void heapify(std::vector<T> &v, unsigned long start_index, unsigned long heap_size, F cmp_fn);

template<typename T, typename F = std::less<T>>
void make_heap(std::vector<T> &v, unsigned long heap_size, F cmp_fn);

template<typename T, typename F = std::less<T>>
bool is_heap(std::vector<T> &v, unsigned long heap_size, F cmp_fn);

inline unsigned long parent_index_of(unsigned long child_index) { return (child_index - 1) >> 1; }
inline unsigned long left_child_index_of(unsigned long parent_index) { return (parent_index << 1) + 1; }
inline unsigned long right_child_index_of(unsigned long parent_index) { return (parent_index << 1) + 2; }

template<typename T, typename F>
void heap_sort(std::vector<T> &v, unsigned long heap_size, F cmp_fn)
{
    make_heap(v, heap_size, cmp_fn);

    for (unsigned long i = heap_size; i > 0; --i) { 
        std::swap(v[0], v[i - 1]);
        heapify(v, 0, i - 1, cmp_fn);
    }
}

template<typename T, typename F>
void heapify(std::vector<T> &v, unsigned long start_index, unsigned long heap_size, F cmp_fn)
{
    unsigned long index_to_replace = start_index;
    unsigned long left_child_index = left_child_index_of(start_index);
    unsigned long right_child_index = right_child_index_of(start_index);

    if (left_child_index < heap_size && cmp_fn(v[left_child_index], v[index_to_replace])) {
        index_to_replace = left_child_index;
    }

    if (right_child_index < heap_size && cmp_fn(v[right_child_index], v[index_to_replace])) {
        index_to_replace = right_child_index;
    }

    if (start_index != index_to_replace) { 
        std::swap(v[start_index], v[index_to_replace]);
        heapify(v, index_to_replace, heap_size, cmp_fn);
    }
}

template<typename T, typename F>
void make_heap(std::vector<T> &v, unsigned long heap_size, F cmp_fn)
{
    for(int i = std::floor((heap_size - 1) / 2); i >=0; --i) {
        heapify(v, i, heap_size, cmp_fn);
    }
}

template<typename T, typename F>
bool is_heap(std::vector<T> &v, unsigned long heap_size, F cmp_fn)
{
    for(int i = std::floor((heap_size - 1) / 2); i >= 0; --i) {
        unsigned long left_child_index = left_child_index_of(i);
        unsigned long right_child_index = right_child_index_of(i);

        if (left_child_index < heap_size && cmp_fn(v[left_child_index], v[i])) {
            return false;
        }

        if (right_child_index < heap_size && cmp_fn(v[right_child_index], v[i])) {
            return false;
        }
    }

    return true;
}

#endif