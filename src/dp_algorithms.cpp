#include "dp_algorithms.hpp"
#include <algorithm>
#include <iostream>
#include <stack>
#include <numeric>
#include <limits>

size_t weighted_interval_scheduling(const std::vector<interval> &intervals)
{
    void fill_p_table(const std::vector<interval> &intervals, std::vector<int> &ptable);

    std::vector<interval> intervals_copy(intervals.begin(), intervals.end());
    std::sort(intervals_copy.begin(), intervals_copy.end(), [](const interval &i1, const interval &i2) {
        return i1.end() < i2.end();
    });

    std::vector<int> p_table(intervals.size(), -1);
    fill_p_table(intervals_copy, p_table);
    std::for_each(p_table.begin(), p_table.end(), [](int &i) { i += 1; });

    std::vector<size_t> opt_table(intervals.size() + 1, 0);
    opt_table[1] = std::max(opt_table[0], intervals_copy[0].weight());
    for (size_t i = 2; i < intervals_copy.size() + 1; ++i) {
        opt_table[i] = std::max(opt_table[i - 1], opt_table[p_table[i - 1]] + intervals_copy[i - 1].weight());
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
    int max_global = numbers[0];
    int max_local = numbers[0];

    size_t max_global_start_index = 0, max_global_end_index = 0;
    size_t max_local_start_index = 0, max_local_end_index = 0;

    for (size_t i = 1; i < numbers.size(); ++i) {
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
            incr_index_list.push_back(i);
            
            result_table[i] = incr_index_list[incr_index_list.size() - 2];
        } else if (numbers[i] < incr_values_list.front()) {
            incr_values_list[0] = numbers[i];
            incr_index_list[0] = i;

            result_table[i] = -1;
        } else {
            size_t pos_to_replace = floor_binary_search(incr_values_list, 0, incr_values_list.size() - 1, numbers[i]);
            incr_values_list[pos_to_replace] = numbers[i];
            incr_index_list[pos_to_replace] = i;

            result_table[i] = incr_index_list[pos_to_replace - 1];
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

std::vector<std::tuple<size_t, size_t>> cut_rod(std::map<size_t, size_t> &len_and_prices, size_t n)
{
    std::vector<size_t> opt_table(n + 1, 0);
    std::vector<size_t> sol_table(n + 1, 0);

    for (const std::pair<size_t, size_t> &len_and_price : len_and_prices) {
        size_t i_len = len_and_price.first;
        size_t i_price = len_and_price.second;

        for (size_t j = i_len; j <= n; ++j) {
            if (i_price + opt_table[j - i_len] > opt_table[j]) {
                opt_table[j] = i_price + opt_table[j - i_len];
                sol_table[j] = i_len;
            }
        }
    }

    std::vector<std::tuple<size_t, size_t>> cuts;
    size_t result_index = n;
    while (result_index > 0) {
        cuts.push_back(std::make_tuple(sol_table[result_index], len_and_prices[sol_table[result_index]]));
        result_index -= sol_table[result_index];
    }

    return cuts;
}

size_t min_coin_change(std::vector<size_t> &coins, size_t sum)
{
    std::vector<size_t> opt_table(sum + 1, std::numeric_limits<std::int32_t>::max());

    opt_table[0] = 0;
    for (size_t i = 0; i < coins.size(); ++i) {
        for (size_t j = coins[i]; j <= sum; ++j) {
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
            opt_table[i][j] = std::numeric_limits<std::int32_t>::max();

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

std::tuple<size_t, size_t> min_and_max_of_expr(const std::string expr) {
    std::vector<int> nums;
    std::vector<char> ops;
    std::string tmp = "";
 
    for (size_t i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '+' || expr[i] == '*')
        {
            ops.push_back(expr[i]);
            nums.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else
        {
            tmp += expr[i];
        }
    }
    nums.push_back(atoi(tmp.c_str()));

    size_t N = nums.size();
    size_t min[N][N];
    size_t max[N][N];
 
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; ++j)
        {
            min[i][j] = std::numeric_limits<std::int32_t>::max();
            max[i][j] = 0;
 
            if (i == j)
                min[i][j] = max[i][j] = nums[i];
        }
    }
 
    for (size_t L = 2; L <= N; ++L)
    {
        for (size_t i = 0; i < N - L + 1; ++i)
        {
            size_t j = i + L - 1;
            for (size_t k = i; k < j; ++k)
            {
                size_t minTmp = 0, maxTmp = 0;
 
                if(ops[k] == '+')
                {
                    minTmp = min[i][k] + min[k + 1][j];
                    maxTmp = max[i][k] + max[k + 1][j];
                }

                else if(ops[k] == '*')
                {
                    minTmp = min[i][k] * min[k + 1][j];
                    maxTmp = max[i][k] * max[k + 1][j];
                }
 
                if (minTmp < min[i][j])
                    min[i][j] = minTmp;
                if (maxTmp > max[i][j])
                    max[i][j] = maxTmp;
            }
        }
    }

    return std::make_tuple(min[0][N - 1], max[0][N - 1]);
}

size_t diff_way_as_sum_of(std::vector<size_t> &sums, int N)
{
    std::vector<size_t> opt_table(N + 1, 0);
    opt_table[0] = 1;

    for (int i = 1; i <= N; ++i) {
        int sum  = 0;        
        for (const int &s : sums) {
            sum += (i - s < 0) ? 0 : opt_table[i - s];
        }

        opt_table[i] = sum;
    }

    return opt_table[N];
}

bool regex_matching(const std::string &text_to_match, const std::string &regex_pattern)
{
    size_t M = text_to_match.length();
    size_t N = regex_pattern.length();

    bool match[M + 1][N + 1];

    match[0][0] = true;
    for (size_t i = 1; i < M + 1; ++i) {
        match[i][0] = false;
    }

    for (size_t j = 1; j < N + 1; ++j) {
        if (regex_pattern[j - 1] == '*') {
            match[0][j] = match[0][j - 1] || match[0][j - 2];
        } else if (regex_pattern[j - 1] == '.') {
            match[0][j] = match[0][j - 1];
        } else {
            match[0][j] = false;
        }
    }

    for (size_t i = 1; i < M + 1; ++i) {
        for (size_t j = 1; j < N + 1; ++j) {
            if (text_to_match[i - 1] == regex_pattern[j - 1] || regex_pattern[j - 1] == '.') {
                match[i][j] = match[i - 1][j - 1];
            } else if (regex_pattern[j - 1] == '*') {
                // zero matches
                bool is_match = match[i][j - 1];
                // or more than one match
                if (text_to_match[i - 1] == regex_pattern[j - 2] || regex_pattern[j - 2] == '.') {
                    is_match = is_match || match[i - 1][j];
                }

                match[i][j] = is_match;
            } else {
                match[i][j] = false;
            }
        }
    }

    return match[M][N];
}

bool wildcard_matching(const std::string &text_to_match, const std::string &wc_pattern)
{
    size_t M = text_to_match.length();
    size_t N = wc_pattern.length();

    bool match[M + 1][N + 1];

    match[0][0] = true;
    for (size_t i = 1; i < M + 1; ++i) {
        match[i][0] = false;
    }

    for (size_t j = 1; j < N + 1; ++j) {
        if (wc_pattern[j - 1] == '?' || wc_pattern[j - 1] == '*') {
            match[0][j] = match[0][j - 1];
        } else {
            match[0][j] = false;
        }
    }

    for (size_t i = 1; i < M + 1; ++i) {
        for (size_t j = 1; j < N + 1; ++j) {
            if (text_to_match[i - 1] == wc_pattern[j - 1] || wc_pattern[j - 1] == '?') {
                match[i][j] = match[i - 1][j - 1];
            } else if (wc_pattern[j - 1] == '*') {
                match[i][j] = match[i - 1][j] || match[i][j - 1];
            } else {
                match[i][j] = false;
            }
        }
    }

    return match[M][N];
}

size_t longest_palindromic_subsequence(const std::string &str)
{
    size_t N = str.length();
    size_t pal[N][N];

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            pal[i][j] = 0;
        }
    }

    for (size_t i = 0; i < N; ++i) {
        pal[i][i] = 1;
    }

    for (size_t cycle_len = 2; cycle_len <= N; ++cycle_len) {
        for (size_t i = 0; i <= N - cycle_len; ++i) {
            size_t j = cycle_len + i - 1;
            if (str[i] == str[j]) {
                pal[i][j] = 2 + pal[i + 1][j - 1];
            } else {
                pal[i][j] = std::max(pal[i][j - 1], pal[i + 1][j]);
            }
        }
    }

    return pal[0][N - 1];
}

size_t zig_zag(const std::vector<int> &seq)
{
    size_t zz_table[seq.size()][2];

    zz_table[0][0] = 1;
    zz_table[0][1] = 1;

    size_t max_length = 1;
    for (size_t i = 1; i < seq.size(); ++i) {
        zz_table[i][0] = zz_table[i][1] = 1;
        for (size_t j = 0; j < i; ++j) {
            if (seq[i] > seq[j]) {
                zz_table[i][0] = std::max(zz_table[i][0], zz_table[j][1] + 1);
            }

            if (seq[i] < seq[j]) {
                zz_table[i][1] = std::max(zz_table[i][1], zz_table[j][0] + 1);
            }
        }

        max_length = std::max({ max_length, zz_table[i][0], zz_table[i][1] });
    }

    return max_length;
}

std::string longest_palindromic_substring(const std::string &str) {
    size_t max_substr_start = 0;
    size_t max_substr_length = 1;

    size_t N = str.length();
    bool pal[N][N];

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            pal[i][j] = false;
        }
    }

    for (size_t i = 0; i < N; ++i) {
        pal[i][i] = true;
    }

    for (size_t j = 1; j < N; ++j) {
        if (str[j - 1] == str[j]) {
            pal[j - 1][j] = true;
            
            size_t len_of_current_pal_substr = j - (j - 1) + 1;
            if (len_of_current_pal_substr > max_substr_length) {
                max_substr_start = j - 1;
                max_substr_length = len_of_current_pal_substr;
            }
        }
    }

    for (size_t cycle_len = 3; cycle_len <= N; ++cycle_len) {
        for (size_t i = 0; i <= N - cycle_len; ++i) {
            size_t j = cycle_len + i - 1;
            bool is_str_i_j_a_pal = str[i] == str[j] && pal[i + 1][j - 1];
            pal[i][j] = is_str_i_j_a_pal;
            if (pal[i][j]) {
                size_t len_of_current_pal_substr = j - i + 1;
                if (len_of_current_pal_substr > max_substr_length) {
                    max_substr_start = i;
                    max_substr_length = len_of_current_pal_substr;
                }
            }
        }
    }

    return str.substr(max_substr_start, max_substr_length);
}

std::tuple<size_t, std::vector<std::string>> text_justification(const std::vector<std::string> &words, const size_t margin)
{
    std::vector<size_t> words_len;

    for (const std::string &w : words) {
        words_len.push_back(w.length());
    }

    size_t cost[words.size()][words.size()];

    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i; j < words.size(); ++j) {
            size_t i_to_j_words_len = std::accumulate(words_len.begin() + i, words_len.begin() + j + 1, 0);
            size_t no_words_i_j = j - i + 1;
            // Add spaces between words
            i_to_j_words_len += no_words_i_j - 1;

            int slack = margin - i_to_j_words_len;
            if (slack >= 0) {
                cost[i][j] = slack * slack;
            } else {
                cost[i][j] = std::numeric_limits<std::int32_t>::max();
            }
        }
    }

    std::vector<size_t> opt_table(words.size(), std::numeric_limits<std::int32_t>::max());
    std::vector<int> sol_table(words.size(), -1);

    for (size_t j = 0; j < words.size(); ++j) {
        for (size_t i = 0; i <= j; ++i) {
            size_t prev_opt_value = int(i) - 1 < 0 ? 0 : opt_table[i - 1];
            size_t slack_from_i_to_j = cost[i][j];

            size_t opt_value = prev_opt_value + slack_from_i_to_j;
            if (opt_value < opt_table[j]) {
                opt_table[j] = opt_value;
                sol_table[j] = i;
            }
        }
    }

    std::vector<std::string> words_by_line;

    int to = words.size() - 1;
    while (to >= 0) {
        int from = sol_table[to];
        std::string joined_words = "";
        for (int i = from + 1; i <= to; ++i) {
            joined_words = joined_words + " " + words[i];
        }
        joined_words = words[from] + joined_words;
        words_by_line.push_back(joined_words);

        to = from - 1;
    }

    std::reverse(words_by_line.begin(), words_by_line.end());

    return std::make_tuple(opt_table[words.size() - 1], words_by_line);
}

std::vector<std::vector<size_t>> partition_elements_into_k_subsets(const std::vector<size_t> &elements, const size_t K)
{
    size_t N = elements.size();

    size_t sum[K + 1][N + 1];
    size_t sol[K + 1][N + 1];

    sum[0][0] = 0;
    sol[0][0] = 0;

    for (size_t i = 1; i < K + 1; ++i) {
        sum[i][0] = 0;
        sol[i][0] = 0;
    }

    for (size_t j = 1; j < N + 1; ++j) {
        sum[0][j] = sum[0][j - 1] + elements[j - 1];
        sol[0][j] = 0;
    }

    for (size_t i = 1; i < K + 1; ++i) {
        for (size_t j = 1; j < N + 1; ++j) {
            sum[i][j] = std::numeric_limits<std::int32_t>::max();
        }
    }

    std::vector<size_t> prefix_sum(N + 1, 0);
    for (size_t i = 1; i < N + 1; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + elements[i - 1];
    }

    for (size_t i = 1; i < K + 1; ++i) {
        for (size_t j = 1; j < N + 1; ++j) {
            for (size_t p = 1; p <= j; ++p) {
                size_t sum_from_k_to_j = prefix_sum[j] - prefix_sum[p - 1];
                size_t max_of_partitions = std::max(sum_from_k_to_j, sum[i - 1][p - 1]);

                if (max_of_partitions < sum[i][j]) {
                    sum[i][j] = max_of_partitions;
                    sol[i][j] = p - 1;
                }
            }
        }
    }

    std::vector<std::vector<size_t>> partitions;
    int blocks = K;
    int from_index = sol[blocks][N];
    int to_index = N - 1;
    while (blocks >= 0) {
        std::vector<size_t> v(elements.begin() + from_index, elements.begin() + to_index + 1);
        partitions.push_back(v);

        --blocks;
        to_index = from_index - 1;
        from_index = sol[blocks][from_index];
    }

    return partitions;
}

size_t partition_into_two_subsets(const std::vector<size_t> &elements)
{
    size_t sum = 0;
    for (size_t i = 0; i < elements.size(); ++i) {
        sum += elements[i];
    }

    size_t M = elements.size();
    size_t N = sum;
    bool part[M + 1][N + 1];

    for (size_t i = 0; i < M + 1; ++i) {
        part[i][0] = true;
    }

    for (size_t j = 1; j < N + 1; ++j) {
        part[0][j] = false;
    }

    for (size_t i = 1; i < M + 1; ++i) {
        for (size_t j = 1; j < N + 1; ++j) {
            if (j < elements[i - 1]) {
                part[i][j] = part[i - 1][j];
            } else {
                part[i][j] = part[i - 1][j] || part[i - 1][j - elements[i - 1]];
            }
        }
    }

    size_t diff = std::numeric_limits<std::int32_t>::max();
    for (int j = sum / 2; j >= 0; ++j) {
        if (part[M][j] == true) {
            diff = sum - 2*j;
            break;
        }
    }

    return diff;
}

size_t no_times_pat_as_subseq_of_str(const std::string &str, const std::string &patt)
{
    size_t M = str.length();
    size_t N = patt.length();

    size_t times_table[M + 1][N + 1];

    times_table[0][0] = 1;

    for (size_t i = 1; i < M + 1; ++i) {
        times_table[i][0] = 1;
    }

    for (size_t j = 1; j < N + 1; ++j) {
        times_table[0][j] = 0;
    }

    for (size_t i = 1; i < M + 1; ++i) {
        for (size_t j = 1; j < N + 1; ++j) {
            if (str[i - 1] == patt[j - 1]) {
                times_table[i][j] = times_table[i - 1][j - 1] + times_table[i - 1][j];
            } else {
                times_table[i][j] = times_table[i - 1][j];
            }
        }
    }

    return times_table[M][N];
}

size_t count_distinct_subsequences(const std::string &str)
{
    std::map<char, size_t> last_char_pos;

    size_t N = str.length();

    std::vector<size_t> count_table(N + 1, 0);
    count_table[0] = 1;

    for (size_t i = 1; i < N + 1; ++i) {
        if (last_char_pos.find(str[i - 1]) == last_char_pos.end()) {
            count_table[i] = 2 * count_table[i - 1];
        } else {
            size_t last_pos = last_char_pos[str[i - 1]];
            count_table[i] = 2 * count_table[i - 1] - count_table[last_pos];
        }

        last_char_pos[str[i - 1]] = i - 1;
    }

    return count_table[N];
}

size_t max_subsquare_with_sides_as_1(bool *mat, size_t M, size_t N)
{
    std::tuple<size_t, size_t> prev_table[M][N];

    if (*(mat + 0 * N + 0) == 0) {
        prev_table[0][0] = std::make_tuple<size_t, size_t>(0, 0);
    } else {
        prev_table[0][0] = std::make_tuple<size_t, size_t>(1, 1);
    }

    for (size_t i = 1, j = 0; i < M; ++i) {
        if (*(mat + i * N + j) == 0) {
            prev_table[i][j] = std::make_tuple<size_t, size_t>(0, 0);
        } else {
            size_t i_th_prev_value = std::get<0>(prev_table[i - 1][j]);
            prev_table[i][j] = std::make_tuple<size_t, size_t>(i_th_prev_value + 1, 1);
        }
    }

    for (size_t j = 1, i = 0; j < N; ++j) {
        if (*(mat + i * N + j) == 0) {
            prev_table[i][j] = std::make_tuple<size_t, size_t>(0, 0);
        } else {
            size_t j_th_prev_value = std::get<1>(prev_table[i][j - 1]);
            prev_table[i][j] = std::make_tuple<size_t, size_t>(1, j_th_prev_value + 1);
        }
    }

    for (size_t i = 1; i < M; ++i) {
        for (size_t j = 1; j < N; ++j) {
            if (*(mat + i * N + j) == 0) {
                prev_table[i][j] = std::make_tuple<size_t, size_t>(0, 0);
            } else {
                size_t i_th_prev_value = std::get<0>(prev_table[i - 1][j]);
                size_t j_th_prev_value = std::get<1>(prev_table[i][j - 1]);
                prev_table[i][j] = std::make_tuple<size_t, size_t>(i_th_prev_value + 1, j_th_prev_value + 1);
            }
        }
    }

    size_t max_square_size = 0;
    for (size_t i = M - 1; i > 0; --i) {
        for (size_t j = N - 1; j > 0; --j) {
            std::tuple<size_t, size_t> prev_table_value = prev_table[i][j];
            size_t min_value = std::min(std::get<0>(prev_table_value), std::get<1>(prev_table_value));

            for (size_t check = min_value; check > max_square_size; --check) {
                size_t left_of_top_value = std::get<1>(prev_table[i - check + 1][j]);
                size_t top_of_left_value = std::get<0>(prev_table[i][j - check + 1]);

                if (left_of_top_value >= check && top_of_left_value >= check) {
                    max_square_size = std::max(max_square_size, check);
                }
            }
        }
    }

    return max_square_size;
}

std::vector<int> sub_rectangular_sum(int *mat, size_t M, size_t N, std::vector<std::tuple<std::tuple<size_t, size_t>, std::tuple<size_t, size_t>>> &from_to_q)
{
    int sum_table[M + 1][N + 1];

    for (size_t i = 0; i < M + 1; ++i) {
        sum_table[i][0] = 0;
    }

    for (size_t j = 0; j < N + 1; ++j) {
        sum_table[0][j] = 0;
    }

    // sum_table[1][1] = mat[0][0]
    sum_table[1][1] = *(mat + 0 * N + 0);
    for (size_t i = 2; i < M + 1; ++i) {
        sum_table[i][1] = sum_table[i - 1][1] + *(mat + (i - 1) * N + (1 - 1));
    }

    for (size_t j = 2; j < N + 1; ++j) {
        sum_table[1][j] = sum_table[1][j - 1] + *(mat + (1 - 1) * N + (j - 1));
    }

    for (size_t i = 2; i < M + 1; ++i) {
        for (size_t j = 2; j < N + 1; ++j) {
            sum_table[i][j] = *(mat + (i - 1) * N + (j - 1)) + sum_table[i - 1][j] + sum_table[i][j - 1] - sum_table[i - 1][j - 1];
        }
    }

    std::vector<int> sums;
    for (const std::tuple<std::tuple<size_t, size_t>, std::tuple<size_t, size_t>> &q : from_to_q) {
        size_t from_i = std::get<0>(std::get<0>(q)) + 1;
        size_t from_j = std::get<1>(std::get<0>(q)) + 1;

        size_t to_i = std::get<0>(std::get<1>(q)) + 1;
        size_t to_j = std::get<1>(std::get<1>(q)) + 1;

        int sum = sum_table[to_i][to_j] - sum_table[to_i][from_j - 1] - sum_table[from_i - 1][to_j] + sum_table[from_i - 1][from_j - 1];

        sums.push_back(sum);
    }

    return sums;
}

std::vector<size_t> min_jumps_to_reach_end(const std::vector<int> &elements)
{
    size_t N = elements.size();
    std::vector<size_t> jumps_table(N, 0);
    std::vector<int> sol_table(N, -1);

    jumps_table[0] = 0;
    for (size_t i = 1; i < elements.size(); ++i) {
        jumps_table[i] = std::numeric_limits<std::int32_t>::max();
        for (size_t j = 0; j < i; ++j) {
            bool can_jump = (i - j) <= elements[j];
            if (can_jump && jumps_table[j] + 1 < jumps_table[i]) {
                jumps_table[i] = jumps_table[j] + 1;
                sol_table[i] = j;
            }
        }
    }

    int index = N - 1;
    std::vector<size_t> jump_indexes;
    while (index > 0) {
        jump_indexes.push_back(sol_table[index]);
        index = sol_table[index];
    }

    std::reverse(jump_indexes.begin(), jump_indexes.end());

    return jump_indexes;
}

bool check_interleaving(const std::string &str1, const std::string &str2, const std::string &interleaved_str)
{
    size_t M = str1.length();
    size_t N = str2.length();

    if (interleaved_str.length() < M + N) {
        return false;
    }

    bool inter_table[M + 1][N + 1];
    inter_table[0][0] = true;

    for (size_t i = 1; i < M + 1; ++i) {
        if (str1[i - 1] == interleaved_str[i - 1]) {
            inter_table[i][0] = inter_table[i - 1][0];
        } else {
            inter_table[i][0] = false;
        }
    }

    for (size_t j = 1; j < N + 1; ++j) {
        if (str2[j - 1] == interleaved_str[j - 1]) {
            inter_table[0][j] = inter_table[0][j - 1];
        } else {
            inter_table[0][j] = false;
        }
    }

    for (size_t i = 1; i < M + 1; ++i) {
        for (size_t j = 1; j < N + 1; ++j) {
            if (str1[i - 1] == interleaved_str[i + j - 1]) {
                inter_table[i][j] = inter_table[i - 1][j];
            } else if (str2[j - 1] == interleaved_str[i + j - 1]) {
                inter_table[i][j] = inter_table[i][j - 1];
            } else {
                inter_table[i][j] = false;
            }
        }
    }

    return inter_table[M][N];
}

int max_sum_non_adj(const std::vector<int> &elements)
{
    int max_sum = std::numeric_limits<std::int32_t>::min();
    if (elements.size() == 1) {
        max_sum = elements[0];
    } else if (elements.size() == 2) {
        max_sum = std::max(elements[0], elements[1]);
    } else {
        std::vector<int> opt_table(elements.size() + 1, 0);

        opt_table[1] = elements[0];
        for (size_t i = 2; i < opt_table.size(); ++i) {
            opt_table[i] = std::max(opt_table[i - 1], opt_table[i - 2] + elements[i - 1]);
        }

        max_sum = opt_table[elements.size()];
    }

    return max_sum;
}

size_t max_sub_square_mat_with_0_1(bool *mat, size_t M, size_t N)
{
    size_t sq_table[M + 1][N + 1];

    for (size_t i = 0; i < M + 1; ++i) {
        sq_table[i][0] = false;
    }

    for (size_t j = 0; j < N + 1; ++j) {
        sq_table[0][j] = false;
    }

    for (size_t i = 1; i < M + 1; ++i) {
        for (size_t j = 1; j < N + 1; ++j) {
            if (*(mat + (i - 1) * N + (j - 1)) == 0) {
                sq_table[i][j] = 0;
            } else {
                sq_table[i][j] = std::min({ sq_table[i - 1][j - 1], sq_table[i - 1][j], sq_table[i][j - 1] }) + 1;
            }
        }
    }

    return sq_table[M][N];
}

size_t max_size_rectangle_in_mat_with_0_1(bool *mat, size_t M, size_t N)
{
    size_t get_max_histogram_area_of_array(const std::vector<size_t> &elements);

    size_t max_size_rect = 0;
    std::vector<size_t> sizes(N, 0);

    size_t i = 0;
    for (size_t j = 0; j < N; ++j) {
        sizes[j] = *(mat + i * N + j);
    }

    max_size_rect = std::max(max_size_rect, get_max_histogram_area_of_array(sizes));

    for (size_t i = 1; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (*(mat + i * N + j) == 0) {
                sizes[j] = 0;
            } else {
                sizes[j] += *(mat + i * N + j);
            }
        }

        max_size_rect = std::max(max_size_rect, get_max_histogram_area_of_array(sizes));
    }

    return max_size_rect;
}

size_t get_max_histogram_area_of_array(const std::vector<size_t> &elements)
{
    size_t get_max_histogram_area_of(const std::vector<size_t> &elements);

    size_t max_area = 0;
    size_t elem_index = 0;
    while (1) {
        size_t start_index = elem_index;
        size_t len = 0;
        while (elem_index < elements.size() && elements[elem_index] != 0) {
            ++elem_index;
            ++len;
        }

        std::vector<size_t> nums(elements.begin() + start_index, elements.begin() + start_index + len);
        if (nums.size() == 1) {
            max_area = std::max(max_area, elements[start_index]);
        } else {
            max_area = std::max(max_area, get_max_histogram_area_of(nums));
        }

        while (elem_index < elements.size() && elements[elem_index] == 0) {
            ++elem_index;
        }

        if (elem_index >= elements.size()) {
            break;
        }
    }

    return max_area;
}

size_t get_max_histogram_area_of(const std::vector<size_t> &elements)
{
    std::stack<size_t> stk;

    size_t i = 0;
    size_t max_area = 0;
    while (i < elements.size()) {
        if (stk.empty() || elements[stk.top()] <= elements[i]) {
            stk.push(i);
            ++i;
        } else {
            while (!stk.empty() && elements[stk.top()] > elements[i]) {
                size_t popped_element = stk.top();
                stk.pop();

                size_t area = 0;
                if (stk.empty()) {
                    area = elements[popped_element] * i;
                } else {
                    area = elements[popped_element] * (i - stk.top() - 1);
                }

                max_area = std::max(max_area, area);
            }
        }
    }

    while (!stk.empty()) {
        size_t popped_element = stk.top();
        stk.pop();

        size_t area = 0;
        if (stk.empty()) {
            area = elements[popped_element] * i;
        } else {
            area = elements[popped_element] * (i - stk.top() - 1);
        }

        max_area = std::max(max_area, area);
    }

    return max_area;
}

int bad_neighbors(const std::vector<int> &donations)
{
    int max_donation;
    if (donations.size() == 1) {
        max_donation = donations[0];
    } else if (donations.size() == 2) {
        max_donation = std::max(donations[0], donations[1]);
    } else {
       std::vector<int> opt_table(donations.size(), 0) ;
       int max1 = std::numeric_limits<std::int32_t>::min(), max2 = std::numeric_limits<std::int32_t>::min();
       
       opt_table[1] = donations[0];
       for (size_t i = 2; i < opt_table.size(); ++i) {
           opt_table[i] = std::max(opt_table[i - 1], opt_table[i - 2] + donations[i - 1]);
       }
       max1 = std::max(max1, opt_table[donations.size() - 1]);

       opt_table[1] = donations[1];
       for (size_t i = 2; i < opt_table.size(); ++i) {
           opt_table[i] = std::max(opt_table[i - 1], opt_table[i - 2] + donations[i]);
       }
       max2 = std::max(max2, opt_table[donations.size() - 1]);

       max_donation = std::max(max1, max2);
    }

    return max_donation;
}