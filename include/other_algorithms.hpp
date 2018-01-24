#ifndef OTHER_ALGORITHMS_HPP
#define OTHER_ALGORITHMS_HPP

#include <vector>

std::vector<size_t> get_next_high_for_each(std::vector<size_t> &temps);

// http://www.drdobbs.com/parallel/finding-the-median-of-two-sorted-arrays/240169222?pgno=2
double median_of_two_sorted_arrays(std::vector<int> &a1, std::vector<int> &a2);
int get_median(std::vector<int> &from_array, std::vector<int> &check_array, int low, int high, size_t median_pos);
int get_equal_or_next_high_in_sorted_array(std::vector<int> &arr, int low, int high, int val);

#endif