#ifndef COUNTING_HPP
#define COUNTING_HPP

#include <vector>

// int count_inversions(std::vector<int> &, int , int );

template<typename T, typename F = std::less<T>>
unsigned int count_inversions(std::vector<T> &v, int p, int r, F cmp_fn = F());

template<typename T, typename F = std::less<T>>
void count_inversions(std::vector<T> &v, unsigned int &no_of_inversions, int p, int r, F cmp_fn = F());

template<typename T, typename F = std::less<T>>
int count_inversions_for_subarrays(std::vector<T> &v, int p, int q, int r, F cmp_fn = F());

template<typename T, typename F>
unsigned int count_inversions(std::vector<T> &v, int p, int r, F cmp_fn)
{
    unsigned int no_of_inversions = 0;
    count_inversions(v, no_of_inversions, p, r, std::less<T>());

    return no_of_inversions;
}

template<typename T, typename F>
void count_inversions(std::vector<T> &v, unsigned int &no_of_inversions, int p, int r, F cmp_fn)
{
    if (p < r) {
        int q = ((unsigned int) p + (unsigned int) r) >> 1;
        count_inversions(v, no_of_inversions, p, q);
        count_inversions(v, no_of_inversions, q + 1, r);

        no_of_inversions += count_inversions_for_subarrays(v, p, q, r);
    }
}

template<typename T, typename F>
int count_inversions_for_subarrays(std::vector<T> &v, int p, int q, int r, F cmp_fn)
{
    std::vector<T> left(v.begin() + p, v.begin() + q + 1);
    std::vector<T> right(v.begin() + q + 1, v.begin() + r + 1);

    int left_index = 0, right_index = 0;
    int inversion_count = 0;
    int k = p;

    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] > right[right_index]) {
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