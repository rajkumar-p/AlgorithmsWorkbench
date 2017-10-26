#ifndef QUICK_SORT_UTILS_HPP
#define QUICK_SORT_UTILS_HPP

#include <vector>
#include <random>

template<typename T, typename F = std::less<T>>
size_t partition(std::vector<T> &v, const int p, const int r, F cmp_fn);

template<typename T, typename F>
size_t partition(std::vector<T> &v, const int p, const int r, F cmp_fn)
{
    if (p >= r) { return 0; }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> range(p, r);
    int rnd_between_p_r = range(gen);

    std::swap(v[rnd_between_p_r], v[r]);

    int less_than_r = p - 1; 
    for (int i = p; i < r; ++i) {
        if (cmp_fn(v[i], v[r])) {
            std::swap(v[less_than_r + 1], v[i]);
            ++less_than_r;
        }
    }

    std::swap(v[less_than_r + 1], v[r]);

    return less_than_r + 1;
}

#endif
