#include "dp_algorithms.hpp"

size_t weighted_interval_scheduling(std::vector<interval> &intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](const interval i1, const interval i2) { 
        return i1.end() < i2.end(); 
    });

    size_t wt_of_selected_intervals = 0;
    return wt_of_selected_intervals;
}