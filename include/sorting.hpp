#include <vector>
#include <random>

// Sorting interfaces
void selection_sort(std::vector<int> &);

void merge_sort(std::vector<int> &,int , int);
void merge(std::vector<int> &, int , int , int);

std::vector<int> counting_sort(std::vector<int> &, int );

template<typename T, typename F = std::less<int>>
void heap_sort(std::vector<T> &, F cmp_fn);
template<typename T, typename F = std::less<int>>
void make_heap(std::vector<T> &, F cmp_fn);
template<typename T, typename F = std::less<int>>
void heapify(std::vector<T> &, int , int , F cmp_fn);
template<typename T, typename F = std::less<int>>
bool is_heap(std::vector<T> &, int , F cmp_fn);

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
        heapify(v, 0, i, cmp_fn);
    }
}

template<typename T, typename F>
void make_heap(std::vector<T> &v, F cmp_fn)
{
    int last_non_leaf_node = (v.size() >> 1) - 1;
    for(int i = last_non_leaf_node; i >=0; --i) {
        heapify(v, i, v.size(), cmp_fn);
    }
}

template<typename T, typename F>
void heapify(std::vector<T> &v, int index, int heap_size, F cmp_fn)
{
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
bool is_heap(std::vector<T> &v, int index, F cmp_fn)
{
    int limit = (v.size() >> 1) - 1;
    if (index > limit) {
        return true;
    } else {
        int left_index = left_index_of(index);
        int right_index = right_index_of(index);

        int winner_index = index;
        if (right_index < v.size() && cmp_fn(winner_index, right_index)) {
            winner_index = right_index;
        }
        if (left_index < v.size() && cmp_fn(winner_index, left_index)) {
            winner_index = left_index;
        }

        if (winner_index != index) {
            return false;
        } else {
            return is_heap(v, left_index, cmp_fn) && is_heap(v, right_index, cmp_fn);
        }
    }
}

template<typename T, typename F>
void quick_sort(std::vector<T> &, int , int , F );
// template<typename T, typename F>
// int partition(std::vector<T> &, int , int , F );

template<typename T, typename F>
void quick_sort(std::vector<T> &v, int p, int r, F cmp_fn)
{
    if (p < r) {
        int q = partition(v, p, r, cmp_fn);
        quick_sort(v, p, q, cmp_fn);
        quick_sort(v, q + 1, r, cmp_fn);
    }
}

// template<typename T, typename F = std::less<T>>
// int partition(std::vector<T> &v, int p, int r, F cmp_fn)
// {
//     if (!(p < r)) {
//         return 0;
//     }

//     int i = p - 1;

//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> range(p, r);
//     int rnd_p_r = range(gen);

//     std::swap(v[rnd_p_r], v[r]);

//     for(int j = p; j < r; ++j) {
//         if (cmp_fn(v[j], v[r])) {
//             std::swap(v[i + 1], v[j]);
//             ++i;
//         }
//     }

//     std::swap(v[i + 1], v[r]);

//     return i + 1;
// }