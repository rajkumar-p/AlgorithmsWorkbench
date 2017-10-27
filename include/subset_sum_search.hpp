#ifndef SUBSET_SUM_SEARCH_HPP
#define SUBSET_SUM_SEARCH_HPP

#include <vector>
#include "quick_sort.hpp"
#include "binary_search.hpp"

bool subset_sum_search(const std::vector<int> &v, long sum);

bool subset_sum_search(const std::vector<int> &v, long sum)
{
    std::vector<int> v_copy(v.begin(), v.end());
    quick_sort(v_copy, 0, v_copy.size() - 1, std::less<int>());

    for(int i = 0; i < v_copy.size(); ++i) {
        // v[i] + x = sum => x = sum - v[i];
        int x = sum - v_copy[i];
        int found_index = binary_search(v_copy, 0, v_copy.size() - 1, x);

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

#endif