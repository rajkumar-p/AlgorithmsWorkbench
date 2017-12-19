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

std::vector<int> get_longest_increasing_subsequence(std::vector<int> &numbers)
{
    size_t floor_binary_search(std::vector<int> &numbers, int low, int high, int key);

    std::vector<int> incr_values_list;
    std::vector<int> incr_index_list;
    std::vector<int> result_table(numbers.size(), -1);

    incr_values_list.push_back(numbers[0]);
    incr_index_list.push_back(0);

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] > incr_values_list.back()) {
            incr_values_list.push_back(numbers[i]);

            result_table[i] = incr_index_list.back();
            incr_index_list.push_back(i);
        } else {
            size_t pos_to_replace = floor_binary_search(incr_values_list, 0, incr_values_list.size() - 1, numbers[i]);
            incr_values_list[pos_to_replace] = numbers[i];
            incr_index_list[pos_to_replace] = i;

            if (pos_to_replace == 0) {
                result_table[i] = -1;
            } else {
                result_table[i] = incr_index_list[pos_to_replace - 1];
            }
        }
    }

    std::vector<int> ln_incr_subsq;
    ln_incr_subsq.push_back(incr_values_list.back());

    int to_follow_index = result_table.back();
    while(to_follow_index != -1) {
        ln_incr_subsq.push_back(numbers[to_follow_index]);
        to_follow_index = result_table[to_follow_index];
    }

    std::reverse(ln_incr_subsq.begin(), ln_incr_subsq.end());
    return ln_incr_subsq;
}

size_t floor_binary_search(std::vector<int> &numbers, int low, int high, int key)
{
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (key == numbers[mid]) {
            return mid;
        } else if (key < numbers[mid]) {
            return floor_binary_search(numbers, low, mid - 1, key);
        } else {
            return floor_binary_search(numbers, mid + 1, high, key);
        }
    }

    return low;
}