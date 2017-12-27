#include "dp_algorithms.hpp"
#include <algorithm>

size_t weighted_interval_scheduling(std::vector<interval> &intervals)
{
    void fill_p_table(const std::vector<interval> &intervals, std::vector<int> &ptable);

    std::sort(intervals.begin(), intervals.end(), [](const interval &i1, const interval &i2) { 
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

std::vector<std::pair<size_t, size_t>> cut_rod(std::vector<std::pair<size_t, size_t>> &len_and_prices, size_t n)
{
    std::vector<size_t> opt_table(n + 1, 0);
    std::vector<size_t> sol_table(n + 1, 0);

    for (size_t i = 0; i < len_and_prices.size(); ++i) {
        size_t i_len = len_and_prices[i].first;
        size_t i_price = len_and_prices[i].second;

        for (size_t j = i_len; j <= n; ++j) {
            if (opt_table[j] < i_price + opt_table[j - i_len]) {
                opt_table[j] = i_price + opt_table[j - i_len];
                sol_table[j] = i;
            }
        }
    }

    std::vector<std::pair<size_t, size_t>> cuts;
    size_t result_index = n;
    while (result_index > 0) {
        cuts.push_back(len_and_prices[sol_table[result_index]]);
        result_index -= len_and_prices[sol_table[result_index]].first;
    }

    return cuts;
}

size_t min_coin_change(std::vector<size_t> &coins, size_t sum)
{
    std::vector<size_t> opt_table(sum + 1, INT32_MAX);

    opt_table[0] = 0;
    for (size_t i = 0; i < coins.size(); ++i) {
        for (size_t j = i; j <= sum; ++j) {
            if (opt_table[j] > 1 + opt_table[j - coins[i]]) {
                opt_table[j] = 1 + opt_table[j - coins[i]];
            }
        }
    }

    return opt_table[sum];
}

size_t no_of_coin_changes(const std::vector<size_t> &coins, const size_t sum)
{
    std::vector<size_t> n_table(sum + 1, 0);

    n_table[0] = 1;
    for (size_t i = 0; i < coins.size(); ++i) {
        for (size_t j = coins[i]; j <= sum; ++j) {
            n_table[j] += n_table[j - coins[i]];
        }
    }

    return n_table[sum];
}

size_t max_value_from_01_knapsack(const std::vector<std::pair<size_t, size_t>> &value_and_weight, const size_t max_weight)
{
    size_t opt_table[value_and_weight.size() + 1][max_weight + 1];

    for (size_t i = 0; i <= max_weight; ++i) {
        opt_table[0][i] = 0;
    }

    for (size_t i = 0; i <= value_and_weight.size(); ++i) {
        opt_table[i][0] = 0;
    }

    for (size_t i = 1; i <= value_and_weight.size(); ++i) {
        size_t i_value = value_and_weight[i - 1].first;
        size_t i_weight = value_and_weight[i - 1].second;

        for (size_t j = 1; j <= max_weight; ++j) {
            if (j < i_weight) {
                opt_table[i][j] = opt_table[i - 1][j];
            } else {
                opt_table[i][j] = std::max(opt_table[i - 1][j], i_value + opt_table[i - 1][j - i_weight]);
            }
        }
    }

    return opt_table[value_and_weight.size()][max_weight];
}

size_t lcs(const std::string x, const std::string y)
{
    size_t lcs_table[x.length() + 1][y.length() + 1];

    for (size_t i = 0; i < x.length() + 1; ++i) {
        lcs_table[i][0] = 0;
    }

    for (size_t j = 0; j < y.length() + 1; ++j) {
        lcs_table[0][j] = 0;
    }

    for (size_t i = 1; i < x.length() + 1; ++i) {
        for (size_t j = 1; j < y.length() + 1; ++j) {
            if (x[i - 1] == y[j - 1]) {
                lcs_table[i][j] = 1 + lcs_table[i - 1][j - 1];
            } else {
                lcs_table[i][j] = std::max(lcs_table[i][j - 1], lcs_table[i - 1][j]);
            }
        }
    }

    return lcs_table[x.length()][y.length()];
}

size_t edit_distance(const std::string x, const std::string y)
{
    size_t ed_table[x.length() + 1][y.length() + 1];

    for (size_t i = 0; i < x.length() + 1; ++i) {
        ed_table[i][0] = i;
    }

    for (size_t j = 0; j < y.length() + 1; ++j) {
        ed_table[0][j] = j;
    }

    for (size_t i = 1; i < x.length() + 1; ++i) {
        for (size_t j = 1; j < y.length() + 1; ++j) {
            if (x[i - 1] == y[j - 1]) {
                ed_table[i][j] = ed_table[i - 1][j - 1];
            } else {
                ed_table[i][j] = 1 + std::min({ ed_table[i][j - 1], ed_table[i - 1][j], ed_table[i - 1][j - 1] });
            }
        }
    }

    return ed_table[x.length()][y.length()];
}

size_t matrix_chain_mul(const std::vector<size_t> &dims)
{
    size_t N = dims.size();

    size_t opt_table[N][N];
    size_t sol_table[N][N];

    for (size_t i = 1; i < N; ++i) {
        for (size_t j = 1; j < N; ++j) {
            opt_table[i][j] = 0;
            sol_table[i][j] = 0;
        }
    }

    for (size_t i = 0; i < N; ++i) {
        opt_table[i][i] = 0;
    }

    for (size_t chain_len = 2; chain_len < N; ++chain_len) {
        for (size_t i = 1; i < N - chain_len + 1; i++) {
            size_t j = i + chain_len - 1;
            opt_table[i][j] = INT32_MAX;

            for (size_t k = i; k <= j - 1; ++k) {
                size_t val = opt_table[i][k] + opt_table[k+1][j] + dims[i - 1] * dims[k] * dims[j];
                if (val < opt_table[i][j]) {
                    opt_table[i][j] = val;
                    sol_table[i][j] = k;
                }
            }
        }
    }

    return opt_table[1][N - 1];
}
