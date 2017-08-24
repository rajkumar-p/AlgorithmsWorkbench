#include <vector>
#include <iostream>

// Sorting interfaces
void insertion_sort(std::vector<int> &);
void selection_sort(std::vector<int> &);

void merge_sort(std::vector<int> &,int , int);
void merge(std::vector<int> &, int , int , int);

template<typename T, typename F = std::less<int>>
void heap_sort(std::vector<T> &, F cmp_fn);
template<typename T, typename F = std::less<int>>
void make_heap(std::vector<T> &, F cmp_fn);
template<typename T, typename F = std::less<int>>
void heapify(std::vector<T> &, int , int , F cmp_fn);
template<typename T, typename F = std::less<int>>
bool is_max_heap(std::vector<T> &, int , F cmp_fn);

int parent_index_of(int );
int left_index_of(int );
int right_index_of(int );

template<typename T, typename F>
void heap_sort(std::vector<T> &v, F cmp_fn)
{
    make_heap(v, cmp_fn);
    int heap_size = v.size() - 1;
    for(int i = heap_size; i > 0; --i) {
        std::swap(v[0], v[i]);
        heapify(v, 0, i - 1, cmp_fn);
    }
}

template<typename T, typename F>
void make_heap(std::vector<T> &v, F cmp_fn)
{
    int last_non_leaf_node = (v.size() >> 1) - 1;
    for(int i = last_non_leaf_node; i >=0; --i) {
        heapify(v, i, v.size() - 1, cmp_fn);
    }
}

template<typename T, typename F>
void heapify(std::vector<T> &v, int index, int heap_size, F cmp_fn)
{
    std::cout <<"index : "<<index<<", heap_size : "<<heap_size<<std::endl;
    int to_replace_index = index;
    int left_index = left_index_of(index);
    int right_index = right_index_of(index);

    if (left_index < heap_size && cmp_fn(v[left_index], v[to_replace_index])) {
        to_replace_index = left_index;
    }

    if (right_index < heap_size && cmp_fn(v[right_index], v[to_replace_index])) {
        to_replace_index = right_index;
    }

    if (to_replace_index != index) {
        std::swap(v[to_replace_index], v[index]);
        heapify(v, to_replace_index, heap_size, cmp_fn);
    }
}

template<typename T, typename F>
bool is_max_heap(std::vector<T> &v, int index, F cmp_fn)
{
    return false;
}