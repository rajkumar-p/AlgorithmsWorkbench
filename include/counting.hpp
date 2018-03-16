#ifndef COUNTING_HPP
#define COUNTING_HPP

#include <vector>

// int count_inversions(std::vector<int> &, int , int );

template<typename T, typename F = std::greater<T>>
unsigned int count_inversions(std::vector<T> &v, long p, long r, F cmp_fn = F());

template<typename T, typename F = std::greater<T>>
void count_inversions(std::vector<T> &v, size_t &no_of_inversions, long p, long r, F cmp_fn = F());

template<typename T, typename F = std::greater<T>>
size_t count_inversions_for_subarrays(std::vector<T> &v, long p, long q, long r, F cmp_fn = F());

template<typename T, typename F>
unsigned int count_inversions(std::vector<T> &v, long p, long r, F cmp_fn)
{
    size_t no_of_inversions = 0;
    count_inversions(v, no_of_inversions, p, r, cmp_fn);

    return no_of_inversions;
}

template<typename T, typename F>
void count_inversions(std::vector<T> &v, size_t &no_of_inversions, long p, long r, F cmp_fn)
{
    if (p < r) {
        long q = p + (r - p) / 2;
        count_inversions(v, no_of_inversions, p, q);
        count_inversions(v, no_of_inversions, q + 1, r);

        no_of_inversions += count_inversions_for_subarrays(v, p, q, r, cmp_fn);
    }
}

template<typename T, typename F>
size_t count_inversions_for_subarrays(std::vector<T> &v, long p, long q, long r, F cmp_fn)
{
    std::vector<T> left(v.begin() + p, v.begin() + q + 1);
    std::vector<T> right(v.begin() + q + 1, v.begin() + r + 1);

    size_t left_index = 0, right_index = 0;
    size_t inversion_count = 0;
    size_t k = p;

    while (left_index < left.size() && right_index < right.size()) {
        if (cmp_fn(left[left_index], right[right_index])) {
            inversion_count += left.size() - left_index;
            v[k++] = right[right_index++];
        } else {
            v[k++] = left[left_index++];
        }
    }

    while(left_index < left.size()) {
        v[k++] = left[left_index++];
    }

    while(right_index < right.size()) {
        v[k++] = right[right_index++];
    }

    return inversion_count;
}

#endif