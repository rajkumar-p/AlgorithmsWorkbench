#ifndef SUBSET_SUM_SEARCH_HPP
#define SUBSET_SUM_SEARCH_HPP

#include <vector>
#include <map>
#include "quick_sort.hpp"
#include "binary_search.hpp"

bool subset_sum_search(const std::vector<int> &v, long sum);

bool subset_sum_search(const std::vector<int> &v, long sum)
{
    std::map<int, bool> numbers_seen;
    for (size_t i = 0; i < v.size(); ++i) {
        int to_find = sum - v[i];
        if (numbers_seen.find(to_find) != numbers_seen.end()) {
            return true;
        }

        numbers_seen.emplace(v[i], true);
    }

    return false;
}

#endif