#ifndef DP_ALGORITHMS_HPP
#define DP_ALGORITHMS_HPP

#include <string>
#include <vector>
#include <map>

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

size_t weighted_interval_scheduling(const std::vector<interval> &intervals);

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
std::vector<std::tuple<size_t, size_t>> cut_rod(std::map<size_t, size_t> &len_and_prices, size_t n);

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

// https://www.youtube.com/watch?v=vi_1eHCsR9A&index=42&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
size_t max_subsquare_with_sides_as_1(bool *mat, size_t M, size_t N);

// https://www.youtube.com/watch?v=PwDqpOMwg6U&t=0s&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=40
std::vector<int> sub_rectangular_sum(int *mat, size_t M, size_t N, std::vector<std::tuple<std::tuple<size_t, size_t>, std::tuple<size_t, size_t>>> &from_to_q);

// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
std::vector<size_t> min_jumps_to_reach_end(const std::vector<int> &elements);

// https://www.youtube.com/watch?v=ih2OZ9-M3OM&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=32&t=0s
bool check_interleaving(const std::string &str1, const std::string &str2, const std::string &interleaved_str);

// https://www.youtube.com/watch?v=UtGtF6nc35g&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=34&t=0s
int max_sum_non_adj(const std::vector<int> &elements);

// https://www.youtube.com/watch?v=_Lf1looyJMU&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=29&t=0s
size_t max_sub_square_mat_with_0_1(bool *mat, size_t M, size_t N);

// https://www.youtube.com/watch?v=g8bSdXCG-lA&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=17&t=0s
size_t max_size_rectangle_in_mat_with_0_1(bool *mat, size_t M, size_t N);

// https://community.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009
int bad_neighbors(const std::vector<int> &donations);

#endif