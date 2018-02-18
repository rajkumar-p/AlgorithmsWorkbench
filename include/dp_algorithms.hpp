#ifndef DP_ALGORITHMS_HPP
#define DP_ALGORITHMS_HPP

#include <string>
#include <vector>

/**
 * [Weighted Interval Scheduling] *
 * We have n requests labeled 1,..,n; with each request
 * i specifying a start time (start()), and end time
 * (end()). Each interval also has a weight, (weight()).
 * Two intervals are compatible if they do not overlap.
 * The goal is to select subset S ⊆ {1,...,n} of mutually
 * compatible intervals, so as to maximize the sum of the
 * values of the selected intervals, ∑weight(i)
 **/

class interval {
private:
    std::string _id;
    size_t _start;
    size_t _end;

    size_t _weight;

public:
    interval(std::string id, size_t start, size_t end, size_t weight) : _id(id), _start(start), _end(end), _weight(weight) {}
    const std::string id() const { return _id; }
    size_t start() const { return _start; }
    size_t end() const { return _end; }
    size_t weight() const { return _weight; }
};

size_t weighted_interval_scheduling(std::vector<interval> &intervals);

class max_subarray_struct {
private:
    int _sum;
    size_t _start_index;
    size_t _end_index;

public:
    max_subarray_struct(int sum, size_t start_index, size_t end_index) : _sum(sum), _start_index(start_index), _end_index(end_index) {}
    int sum() const { return _sum; }
    size_t start_index() const { return _start_index; }
    size_t end_index() const { return _end_index; }
};

max_subarray_struct get_max_subarray_properties(std::vector<int> &numbers);

std::vector<int> get_longest_increasing_subsequence(std::vector<int> &numbers);

// http://www.radford.edu/~nokie/classes/360/dp-rod-cutting.html
std::vector<std::pair<size_t, size_t>> cut_rod(std::vector<std::pair<size_t, size_t>> &len_and_prices, size_t n);

// https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
size_t min_coin_change(std::vector<size_t> &coins, size_t sum);

// https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
size_t no_of_coin_changes(const std::vector<size_t> &coins, const size_t sum);

// https://www.geeksforgeeks.org/knapsack-problem/
size_t max_value_from_01_knapsack(const std::vector<std::pair<size_t, size_t>> &value_and_weight, const size_t max_weight);

// https://www.geeksforgeeks.org/longest-common-subsequence/
size_t lcs(const std::string x, const std::string y);

// https://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
size_t edit_distance(const std::string x, const std::string y);

// https://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
size_t matrix_chain_mul(const std::vector<size_t> &dims);

// https://www.geeksforgeeks.org/minimum-maximum-values-expression/
std::tuple<size_t, size_t> min_and_max_of_expr(const std::string expr);

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/
size_t diff_way_as_sum_of(std::vector<size_t> &sums, int N);

// https://leetcode.com/problems/regular-expression-matching/description/
bool regex_matching(const std::string &text_to_match, const std::string &regex_pattern);
bool is_match(const std::string &text, const std::string &pattern);

// https://leetcode.com/problems/wildcard-matching/description/
bool wildcard_matching(const std::string &text_to_match, const std::string &wc_pattern);
bool is_match_wc(const std::string &text, const std::string &pattern);

// https://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
size_t longest_palindromic_subsequence(const std::string &str);

// https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
size_t zig_zag(const std::vector<int> &seq);

// https://leetcode.com/problems/longest-palindromic-substring/description/
std::string longest_palindromic_substring(const std::string &str);

// https://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/
std::tuple<size_t, std::vector<std::string>> text_justification(const std::vector<std::string> &words, const size_t margin);

// https://www8.cs.umu.se/kurser/TDBA77/VT06/algorithms/BOOK/BOOK2/NODE45.HTM
std::vector<std::vector<size_t>> partition_elements_into_k_subsets(const std::vector<size_t> &elements, const size_t K);
// std::tuple<size_t, std::string> partition_elements_into_k_subsets(const std::vector<int> &elements, const size_t k);

// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
size_t partition_into_two_subsets(const std::vector<size_t> &elements);

// https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/
size_t no_times_pat_as_subseq_of_str(const std::string &str, const std::string &patt);

// https://www.geeksforgeeks.org/count-distinct-subsequences/
size_t count_distinct_subsequences(const std::string &str);

#endif