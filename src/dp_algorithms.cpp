#include "dp_algorithms.hpp"
#include <algorithm>

size_t weighted_interval_scheduling(std::vector<interval> &intervals)
{
    void fill_p_table(const std::vector<interval> &intervals, std::vector<int> &ptable);
    int get_p_value(const std::vector<int> &p_table, const size_t index);

    std::sort(intervals.begin(), intervals.end(), [](const interval i1, const interval i2) { 
        return i1.end() < i2.end(); 
    });

    std::vector<int> p_table(intervals.size(), -1);
    fill_p_table(intervals, p_table);

    std::vector<size_t> opt_table(intervals.size(), 0);
    opt_table[0] = intervals[0].weight();

    for (size_t i = 1; i < opt_table.size(); ++i) {
        size_t compatible_max_opt_entry_till_now = (get_p_value(p_table, i) == -1 ? 0 : opt_table[get_p_value(p_table, i)]);
        opt_table[i] = std::max(opt_table[i - 1], intervals[i].weight() + compatible_max_opt_entry_till_now);
    }

    return opt_table[intervals.size() - 1];
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

int get_p_value(const std::vector<int> &p_table, const size_t index)
{
    return p_table[index];
}