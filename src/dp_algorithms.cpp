#include "dp_algorithms.hpp"
#include <algorithm>

size_t weighted_interval_scheduling(std::vector<interval> &intervals)
{
    void fill_p_table(const std::vector<interval> &intervals, std::vector<int> &ptable);

    std::sort(intervals.begin(), intervals.end(), [](const interval i1, const interval i2) { 
        return i1.end() < i2.end(); 
    });

    std::vector<int> p_table(intervals.size(), -1);
    fill_p_table(intervals, p_table);
    std::for_each(p_table.begin(), p_table.end(), [](int &i) { i += 1; });

    std::vector<size_t> opt_table(intervals.size() + 1, 0);
    for (size_t i = 1; i < opt_table.size(); ++i) {
        opt_table[i] = std::max(opt_table[i - 1], intervals[i - 1].weight() + opt_table[p_table[i - 1]]);
    }

    return opt_table[opt_table.size() - 1];
}

void fill_p_table(const std::vector<interval> &intervals, std::vector<int> &p_table)
{
    int ceil_binary_search(const std::vector<interval> &intervals, int low, int high, size_t key);

    for (size_t i = 1; i < p_table.size(); ++i) {
        p_table[i] = ceil_binary_search(intervals, 0, i, intervals[i].start());
    }
}

int ceil_binary_search(const std::vector<interval> &intervals, int low, int high, size_t key)
{
    if (low <= high) {
        int mid = ((unsigned int) low + (unsigned int) high) >> 1;
        if (key == intervals[mid].end()) {
            return mid;
        } else if (key < intervals[mid].end()) {
            return ceil_binary_search(intervals, low, mid - 1, key);
        } else {
            return ceil_binary_search(intervals, mid + 1, high, key);
        }
    }

    return high;
}

max_subarray_struct get_max_subarray_properties(std::vector<int> &numbers)
{
    int max_global = -1;
    int max_local = -1;

    size_t max_global_start_index = 0, max_global_end_index = 0;
    size_t max_local_start_index = 0, max_local_end_index = 0;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (max_local + numbers[i] > numbers[i]) {
            ++max_local_end_index;
            max_local = max_local + numbers[i];
        } else {
            max_local_start_index = max_local_end_index = i;
            max_local = numbers[i];
        }

        if (max_local > max_global) {
            max_global_start_index = max_local_start_index;
            max_global_end_index = max_local_end_index;
            max_global = max_local;
        }
    }

    return max_subarray_struct(max_global, max_global_start_index, max_global_end_index);
}