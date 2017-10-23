#include "searching.hpp"
#include "insertion_sort.hpp"

int binary_search(std::vector<int> &v, int key, int min, int max)
{
    if (min > max) {
        return -1;
    }
    
    int q = ((unsigned int) min + (unsigned int) max) >> 1;

    if (v[q] == key) {
        return q;
    } else if (v[q] > key) {
        return binary_search(v, key, min, q - 1);
    } else {
        return binary_search(v, key, q + 1, max);
    }
}

bool subset_sum_search(const std::vector<int> &v, long sum)
{
    std::vector<int> v_copy(v.begin(), v.end());
    insertion_sort(v_copy, std::less<int>());

    for(int i = 0; i < v_copy.size(); ++i) {
        // v[i] + x = sum => x = sum - v[i];
        int x = sum - v_copy[i];
        int found_index = binary_search(v_copy, x, 0, v_copy.size() - 1);

        if (found_index != -1) {
            if (found_index != i) { return true; }
            else {
                int before = i - 1, after = i + 1;
                if (before >= 0 && v_copy[before] == v_copy[i]) { return true; }
                if (after < v_copy.size() && v_copy[after] == v_copy[i]) { return true; }

                return false;
            }
        }
    }

    return false;
}