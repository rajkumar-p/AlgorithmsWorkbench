#include "other_algorithms.hpp"
#include <stack>
#include <vector>
#include <tuple>
#include <map>

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

std::tuple<int, int> find_peak_2d(int *arr, int begin_rows, int end_rows, int begin_cols, int end_cols)
{
    if (begin_rows <= end_rows && begin_cols <= end_cols) {
        int row_to_check = begin_rows + (end_rows - begin_rows) / 2;
        int col_to_check = begin_cols + (end_cols - begin_cols) / 2;

        std::tuple<int, int> max_row_col;
        int max_in_row_and_col = INT32_MIN;
        for (int j = begin_cols; j <= end_cols; ++j) {
            int arr_value = *(arr + row_to_check * (end_cols + 1) + j);
            if (arr_value > max_in_row_and_col) {
                max_in_row_and_col = arr_value;
                max_row_col = std::make_tuple(row_to_check, j);
            }
        }

        for (int i = begin_rows; i <= end_rows; ++i) {
            int arr_value = *(arr + i * (end_cols + 1) + col_to_check);
            if (arr_value > max_in_row_and_col) {
                max_in_row_and_col = arr_value;
                max_row_col = std::make_tuple(i, col_to_check);
            }
        }

        int max_i = std::get<0>(max_row_col);
        int max_j = std::get<1>(max_row_col);
        int i_j_elem = *(arr + max_i * (end_cols + 1) + max_j);

        std::map<int, std::tuple<int, int>> indexes;
        int top_to_max = max_i - 1 < 0 ? INT32_MIN : *(arr + (max_i - 1) * (end_cols + 1) + max_j);
        indexes.emplace(top_to_max, std::make_tuple(max_i - 1, max_j));

        int bottom_to_max = max_i + 1 > end_rows ? INT32_MIN : *(arr + (max_i + 1) * (end_cols + 1) + max_j);
        indexes.emplace(bottom_to_max, std::make_tuple(max_i + 1, max_j));

        int left_to_max = max_j - 1 < 0 ? INT32_MIN : *(arr + max_i * (end_cols + 1) + max_j - 1);
        indexes.emplace(left_to_max, std::make_tuple(max_i, max_j - 1));

        int right_to_max = max_j + 1 > end_cols ? INT32_MIN : *(arr + max_i * (end_cols + 1) + max_j + 1);
        indexes.emplace(right_to_max, std::make_tuple(max_i, max_j + 1));

        int max_elem = std::max({ i_j_elem, top_to_max, bottom_to_max, left_to_max, right_to_max });
        if (max_elem == i_j_elem) {
            return std::make_tuple(max_i, max_j);
        } 

        int max_neig_i = std::get<0>(indexes.find(max_elem)->second);
        int max_neig_j = std::get<1>(indexes.find(max_elem)->second);
        std::tuple<int, int> next_row_to_check_begin_end = max_neig_i < row_to_check ? std::make_tuple(begin_rows, row_to_check - 1) : std::make_tuple(row_to_check + 1, end_rows);
        std::tuple<int, int> next_col_to_check_begin_end = max_neig_j < col_to_check ? std::make_tuple(begin_cols, col_to_check - 1) : std::make_tuple(col_to_check + 1, end_cols);

        return find_peak_2d(arr, std::get<0>(next_row_to_check_begin_end), std::get<1>(next_row_to_check_begin_end), std::get<0>(next_col_to_check_begin_end), std::get<1>(next_col_to_check_begin_end));
    }

    return std::make_tuple(0, 0);
}

size_t find_peak(std::vector<int> &numbers)
{
    int low = 0, high = numbers.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        int mid_element = numbers[mid];
        int left_element = mid - 1 < 0 ? mid_element - 1 : numbers[mid - 1];
        int right_element = mid + 1 == numbers.size() ? mid_element + 1 : numbers[mid + 1];

        if (left_element <= mid_element && mid_element >= right_element) {
            return mid;
        } else if (mid_element < left_element) {
            high = mid - 1;
        } else if (mid_element < right_element) {
            low = mid + 1;
        }
    }

    return 0;
}

size_t max_area_of_histogram(std::vector<size_t> &heights)
{
    std::stack<size_t> stk;
    size_t max_area = 0;

    size_t i = 0;
    while (i < heights.size()) {
        if (stk.empty() || heights[i] >= heights[stk.top()]) {
            stk.push(i);
            ++i;
            continue;
        }

        size_t pop_elem = stk.top();
        stk.pop();

        size_t area = 0;
        if (stk.empty()) {
            area = heights[pop_elem] * i;
        } else {
            area = heights[pop_elem] * (i - stk.top() - 1);
        }

        max_area = std::max(area, max_area);
    }

    while (!stk.empty()) {
        size_t pop_elem = stk.top();
        stk.pop();

        size_t area = 0;
        if (stk.empty()) {
            area = heights[pop_elem] * i;
        } else {
            area = heights[pop_elem] * (i - stk.top() - 1);
        }

        max_area = std::max(area, max_area);
    }

    return max_area;
}

size_t trapping_rain_water_in_histogram(std::vector<size_t> &heights)
{
    size_t left_max = 0, right_max = 0;
    size_t max_sum = 0;

    size_t left = 0, right = heights.size() - 1;

    while (left < right) {
        if (heights[left] <= heights[right]) {
            if (heights[left] < left_max) {
                max_sum = max_sum + (left_max - heights[left]);
            }

            left_max = std::max(heights[left], left_max);
            ++left;
        } else {
            if (heights[right] < right_max) {
                max_sum = max_sum + (right_max - heights[right]);
            }

            right_max = std::max(heights[right], right_max);
            --right;
        }
    }

    return max_sum;
}

std::vector<int> sliding_window_max_of_size_k(const std::vector<int> &elements, size_t k)
{
    std::deque<size_t> indexes;

    for (size_t i = 0; i < k; ++i) {
        while (!indexes.empty() && elements[indexes.front()] <= elements[i]) {
            indexes.pop_front();
        }

        indexes.push_back(i);
    }

    std::vector<int> results;
    results.push_back(elements[indexes.front()]);

    for (size_t i = k; i < elements.size(); ++i) {
        while (!indexes.empty() && indexes.front() < i - k + 1) {
            indexes.pop_front();
        }

        while (!indexes.empty() && elements[indexes.front()] <= elements[i]) {
            indexes.pop_front();
        }

        indexes.push_back(i);
        results.push_back(elements[indexes.front()]);
    }

    return results;
}