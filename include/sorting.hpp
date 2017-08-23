#include <vector>

// Sorting interfaces
void insertion_sort(std::vector<int> &);
void selection_sort(std::vector<int> &);

void merge_sort(std::vector<int> &,int , int);
void merge(std::vector<int> &, int , int , int);

template<typename T>
void heap_sort(std::vector<T> &);
template<typename T, typename F = std::less<T>>
void heapify(std::vector<T> &, int );
template<typename T, typename F = std::less<T>>
bool is_max_heap(std::vector<T> &, int );

int parent_index_of(int );
int left_index_of(int );
int right_index_of(int );

template<typename T, typename F>
void heap_sort(std::vector<T> &v)
{
    int last_non_leaf_node = ((v.size() - 1) << 1) - 1;
    for(int i = last_non_leaf_node; i >=0; --i) {
        heapify<T, F>(index);
    }
}

template<typename T, typename F>
void heapify(std::vector<T> &v, int index)
{
    F cmp_fn = F();
    int index_to_replace = index;
    int left_index = left_index_of(index);
    int right_index = right_index_of(index);

    if (left_index < v.size() && cmp_fn(v[index_to_replace], v[left_index])) {
        index_to_replace = left_index;
    }

    if (right_index < v.size() && cmp_fn(v[index_to_replace], v[right_index])) {
        index_to_replace = right_index;
    }

    if (index_to_replace != index) {
        std::swap(v[index_to_replace], v[index]);
        heapify<T, F>(v, index_to_replace);
    }
}

template<typename T, typename F>
bool is_max_heap(std::vector<T> &v, int index)
{
    return false;
}