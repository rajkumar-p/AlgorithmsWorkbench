#include "other_algorithms.hpp"
#include <stack>
#include <vector>
#include <tuple>

std::vector<size_t> get_next_high_for_each(std::vector<size_t> &temps)
{
    std::stack<std::tuple<size_t, size_t>> stk;
    std::vector<size_t> result(temps.size(), 0);

    for (int i = temps.size() - 1; i >= 0; --i) {
        while (!stk.empty() && std::get<1>(stk.top()) < temps[i]) {
            stk.pop();
        }

        if (stk.empty()) {
            result[i] = 0;
        } else {
            result[i] = std::get<0>(stk.top()) - i;
        }

        stk.push(std::make_tuple(i, temps[i]));
    }

    return result;
}

double median_of_two_sorted_arrays(std::vector<int> &a1, std::vector<int> &a2)
{
    size_t N = a1.size() + a2.size();
    size_t median_pos = (N - 1) / 2;

    int median_a1_index = get_median(a1, a2, 0, a1.size() - 1, median_pos);
    if (median_a1_index != -1) {
        if (N % 2 != 0) { return a1[median_a1_index]; }

        int next_median = get_equal_or_next_high_in_sorted_array(a2, 0, a2.size() - 1, a1[median_a1_index]);
        next_median = std::min(next_median, median_a1_index + 1 == a1.size() ? next_median : a1[median_a1_index + 1]);
        return (a1[median_a1_index] + next_median) / 2.0;
    }

    int median_a2_index = get_median(a2, a1, 0, a2.size() - 1, median_pos);
    if (median_a2_index != -1) {
        if (N % 2 != 0) { return a2[median_a2_index]; }

        int next_median = get_equal_or_next_high_in_sorted_array(a1, 0, a1.size() - 1, a2[median_a2_index]);
        next_median = std::min(next_median, median_a2_index + 1 == a2.size() ? next_median : a2[median_a2_index + 1]);
        return (a2[median_a2_index] + next_median) / 2.0;
    }
    
    return 0.0;
}

int get_median(std::vector<int> &from_array, std::vector<int> &check_array, int low, int high, size_t median_pos)
{
    if (low <= high) {
        int mid = low + (high - low) / 2;
        int rank_of_mid = mid + 1;
        size_t no_elements_left_of_mid = rank_of_mid - 1;
        int to_check_index_in_check_array = median_pos - no_elements_left_of_mid;

        int mid_value = from_array[mid];
        int left_value_to_check = to_check_index_in_check_array - 1 < 0 ? from_array[mid] : check_array[to_check_index_in_check_array - 1];
        int right_value_to_check = to_check_index_in_check_array >= check_array.size() ? std::max(mid_value, left_value_to_check) : check_array[to_check_index_in_check_array];

        if (mid_value >= left_value_to_check && mid_value <= right_value_to_check) {
            return mid;
        } else if (mid_value < left_value_to_check) {
            return get_median(from_array, check_array, mid + 1, high, median_pos);
        } else if (mid_value > left_value_to_check) {
            return get_median(from_array, check_array, low, mid - 1, median_pos);
        }
    }

    return -1;
}

int get_equal_or_next_high_in_sorted_array(std::vector<int> &arr, int low, int high, int val)
{
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val) {
            return arr[mid];
        } else if (arr[mid] < val) {
            return get_equal_or_next_high_in_sorted_array(arr, mid + 1, high, val);
        } else {
            return get_equal_or_next_high_in_sorted_array(arr, low, mid - 1, val);
        }
    }

    return arr[low];
}