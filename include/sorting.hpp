#include <vector>
#include <random>

// Sorting interfaces
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