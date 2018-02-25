#include "catch.hpp"
#include "dp_algorithms.hpp"

TEST_CASE("Checking Dynamic Programming Algorithms", "[Dynamic Programming Algorithms]")
{

    SECTION("Weighted Interval Scheduling") {
        std::vector<interval> intervals;
        intervals.push_back(interval("1", 1, 2, 50));
        intervals.push_back(interval("2", 3, 5, 20));
        intervals.push_back(interval("3", 6, 19, 100));
        intervals.push_back(interval("4", 2, 100, 200));

        REQUIRE(weighted_interval_scheduling(intervals) == 250);

        intervals.clear();

        intervals.push_back(interval("1", 0, 6, 3));
        intervals.push_back(interval("2", 1, 4, 5));
        intervals.push_back(interval("3", 3, 5, 5));
        intervals.push_back(interval("4", 3, 8, 8));
        intervals.push_back(interval("5", 4, 7, 3));
        intervals.push_back(interval("6", 5, 9, 7));
        intervals.push_back(interval("7", 6, 10, 3));
        intervals.push_back(interval("8", 8, 11, 4));

        REQUIRE(weighted_interval_scheduling(intervals) == 12);
    }

    SECTION("Maximum Subarray Problem") {
        std::vector<int> numbers = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
        max_subarray_struct max_subarray = get_max_subarray_properties(numbers);

        REQUIRE(max_subarray.sum() == 43);
        REQUIRE(max_subarray.start_index() == 7);
        REQUIRE(max_subarray.end_index() == 10);

        numbers = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        max_subarray = get_max_subarray_properties(numbers);

        REQUIRE(max_subarray.sum() == 6);
        REQUIRE(max_subarray.start_index() == 3);
        REQUIRE(max_subarray.end_index() == 6);
    }

    SECTION("Longest Increasing Subsequence Problem") {
        std::vector<int> numbers = { 3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10 };
        std::vector<int> increasing_subsequence = get_longest_increasing_subsequence(numbers);

        std::vector<int> result = { -1, 2, 3, 7, 9, 10 };
        REQUIRE(increasing_subsequence.size() == 6);
        REQUIRE(increasing_subsequence == result);

        numbers = { 15, 27, 14, 38, 26, 55, 46, 65, 85 };
        increasing_subsequence = get_longest_increasing_subsequence(numbers);

        result = { 15, 27, 38, 46, 65, 85 };
        REQUIRE(increasing_subsequence.size() == 6);
        REQUIRE(increasing_subsequence == result);

        numbers = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
        increasing_subsequence = get_longest_increasing_subsequence(numbers);

        result = { 0, 2, 6, 9, 11, 15 };
        REQUIRE(increasing_subsequence.size() == 6);
        REQUIRE(increasing_subsequence == result);
    }

    SECTION("cut_rod(len_and_prices, n) tests") {
        std::vector<std::pair<size_t, size_t>> len_and_prices;
        std::vector<std::pair<size_t, size_t>> cuts;
        std::vector<std::pair<size_t, size_t>> result_to_check;

        len_and_prices = { {1, 1}, {2, 5},{3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30} };

        result_to_check = { {2, 5}, {2, 5} };
        cuts = cut_rod(len_and_prices, 4);
        for (size_t i = 0; i < result_to_check.size(); ++i) {
            REQUIRE(result_to_check[i].first == cuts[i].first);
            REQUIRE(result_to_check[i].second == cuts[i].second);
        }

        result_to_check = { {6, 17}, {2, 5} };
        cuts = cut_rod(len_and_prices, 8);
        for (size_t i = 0; i < result_to_check.size(); ++i) {
            REQUIRE(result_to_check[i].first == cuts[i].first);
            REQUIRE(result_to_check[i].second == cuts[i].second);
        }

        result_to_check = { {10, 30} };
        cuts = cut_rod(len_and_prices, 10);
        for (size_t i = 0; i < result_to_check.size(); ++i) {
            REQUIRE(result_to_check[i].first == cuts[i].first);
            REQUIRE(result_to_check[i].second == cuts[i].second);
        }
    }

    SECTION("min_coin_change(coins, sum) tests") {
        std::vector<size_t> coins;
        std::vector<size_t> result_to_check;
        size_t sum;

        coins = { 1, 3, 5 };
        sum = 11;
        REQUIRE(min_coin_change(coins, sum) == 3);

        coins = { 2, 3, 6, 7 };
        sum = 13;
        REQUIRE(min_coin_change(coins, sum) == 2);
    }

    SECTION("no_of_coin_changes(coins, sum) tests") {
        std::vector<size_t> coins;
        size_t sum;

        coins = { 1, 2, 3 };
        sum = 4;
        REQUIRE(no_of_coin_changes(coins, sum) == 4);

        coins = { 2, 5, 3, 6 };
        sum = 10;
        REQUIRE(no_of_coin_changes(coins, sum) == 5);
    }

    SECTION("max_value_from_01_knapsack(value_and_weight, max_weight) tests") {
        std::vector<std::pair<size_t, size_t>> value_and_weight;
        size_t max_weight;

        value_and_weight = { {60, 10}, {100, 20}, {120, 30} };
        max_weight = 50;
        REQUIRE(max_value_from_01_knapsack(value_and_weight, max_weight) == 220);

        value_and_weight = { {1, 1}, {4, 3}, {5, 4}, {7, 5} };
        max_weight = 7;
        REQUIRE(max_value_from_01_knapsack(value_and_weight, max_weight) == 9);
    }

    SECTION("lcs(x, y) tests") {
        std::string x;
        std::string y;

        x = "ABCBDAB";
        y = "BDCABA";
        REQUIRE(lcs(x, y) == 4);

        x = "ABCDGH";
        y = "AEDFHR";
        REQUIRE(lcs(x, y) == 3);

        x = "AGGTAB";
        y = "GXTXAYB";
        REQUIRE(lcs(x, y) == 4);
    }

    SECTION("edit_distance(x, y) tests") {
        std::string x;
        std::string y;

        x = "geek";
        y = "gesek";
        REQUIRE(edit_distance(x, y) == 1);

        x = "sunday";
        y = "saturday";
        REQUIRE(edit_distance(x, y) == 3);

        x = "sitting";
        y = "kitten";
        REQUIRE(edit_distance(x, y) == 3);
    }

    SECTION("matrix_chain_mul(dims) tests") {
        std::vector<size_t> dims;

        dims = { 30, 35, 15, 5, 10, 20, 25 };
        REQUIRE(matrix_chain_mul(dims) == 15125);
    }

    SECTION("min_and_max_of_expr(expr) tests") {
        std::tuple<size_t, size_t> min_and_max = min_and_max_of_expr("1+2*3+4*5");

        REQUIRE(std::get<0>(min_and_max) == 27);
        REQUIRE(std::get<1>(min_and_max) == 105);
    }

    SECTION("diff_way_as_sum_of(sums, N) tests") {
        std::vector<size_t> sums = { 1, 3, 4 };
        REQUIRE(diff_way_as_sum_of(sums, 5) == 6);
    }

    SECTION("regex_matching(text_to_match, regex_pattern) tests") {
        REQUIRE(regex_matching("aa", "a") == false);
        REQUIRE(regex_matching("aa", "aa") == true);
        REQUIRE(regex_matching("aaa", "aa") == false);
        REQUIRE(regex_matching("aa", "a*") == true);
        REQUIRE(regex_matching("aa", ".*") == true);
        REQUIRE(regex_matching("ab", ".*") == true);
        REQUIRE(regex_matching("aab", "c*a*b") == true);
    }

    SECTION("wildcard_matching(text_to_match, regex_pattern) tests") {
        REQUIRE(wildcard_matching("aa","a") == false);
        REQUIRE(wildcard_matching("aa","aa") == true);
        REQUIRE(wildcard_matching("aaa","aa") == false);
        REQUIRE(wildcard_matching("aa", "*") == true);
        REQUIRE(wildcard_matching("aa", "a*") == true);
        REQUIRE(wildcard_matching("ab", "?*") == true);
        REQUIRE(wildcard_matching("aab", "c*a*b") == false);
    }

    SECTION("longest_palindromic_subsequence(str)") {
        REQUIRE(longest_palindromic_subsequence("AGBDBA") == 5);
        REQUIRE(longest_palindromic_subsequence("GEEKS FOR GEEKS") == 7);
        REQUIRE(longest_palindromic_subsequence("AABCDEBAZ") == 5);
    }

    SECTION("zig_zag(seq)") {
        REQUIRE(zig_zag({ 1, 7, 4, 9, 2, 5 }) == 6);
        REQUIRE(zig_zag({ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }) == 7);
        REQUIRE(zig_zag({ 44 }) == 1);
        REQUIRE(zig_zag({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }) == 2);
        REQUIRE(zig_zag({ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }) == 8);
        REQUIRE(zig_zag({ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22, 617, 462, 459, 244}) == 36);
    }

    SECTION("longest_palindromic_substring(str)") {
        REQUIRE(longest_palindromic_substring("babad") == "bab");
        REQUIRE(longest_palindromic_substring("cbbd") == "bb");
        REQUIRE(longest_palindromic_substring("forgeeksskeegfor") == "geeksskeeg");
    }

    SECTION("text_justification(words)") {
        std::vector<std::string> words;
        size_t margin;

        words = { "aaa", "bb", "cc", "ddddd" };
        margin = 6;
        REQUIRE(std::get<0>(text_justification(words, margin)) == 11);

        words = { "organisations", "perhaps", "the", "automation", "monitoring",
            "orchestration", "skillsets", "are", "of", "extremely", 
            "then", "I", "components", "state", "expect"
        };
        margin = 19;
        REQUIRE(std::get<0>(text_justification(words, margin)) == 430);
    }

    SECTION("partition_elements_into_k_subsets(elements, k)") {
        std::vector<size_t> elements;

        // elements = { 5, 6, 1, 3, 4, 10 };
        // std::tuple<size_t, std::string> t = partition_elements_into_k_subsets(elements, 3);
        // REQUIRE(std::get<0>(t) == 7);
        // REQUIRE(std::get<1>(t) == "Something");

        elements = { 100, 200, 300, 400, 500, 600, 700, 800, 900 };
        size_t K = 2;

        std::vector<std::vector<size_t>> partitions_results = { {800, 900}, {600, 700}, {100, 200, 300, 400, 500 } };
        std::vector<std::vector<size_t>> partitions = partition_elements_into_k_subsets(elements, K);
        REQUIRE(partitions.size() == K + 1);
        for (size_t i = 0; i < partitions.size(); ++i) {
            REQUIRE(partitions[i] == partitions_results[i]);
        }
    }

    SECTION("partition_elements_into_two_subsets(elements)") {
        std::vector<size_t> elements;

        elements = { 1, 5, 6, 11 };
        REQUIRE(partition_into_two_subsets(elements) == 1);
    }

    SECTION("no_times_pat_as_subseq_of_str(str, patt)") {
        REQUIRE(no_times_pat_as_subseq_of_str("geeksforgeeks", "gks") == 4);
        REQUIRE(no_times_pat_as_subseq_of_str("rabbbit", "rabbit") == 3);
    }

    SECTION("count_distinct_subsequences(str)") {
        REQUIRE(count_distinct_subsequences("gfg") == 7);
        REQUIRE(count_distinct_subsequences("ggg") == 4);
    }

    SECTION("max_subsquare_with_sides_as_1(mat, M, N)") {
        bool mat[5][5] = { { 0, 0, 0, 0, 1}, { 1, 0, 1, 1, 1 }, { 1, 0, 1, 0, 1 }, { 1, 1, 1, 1, 1 }, { 0, 0, 1, 1, 1 } };
        REQUIRE(max_subsquare_with_sides_as_1((bool *) mat, 5, 5) == 3);
    }

    SECTION("sub_rectangular_sum(mat, from_to_q)") {
        int mat[4][4] = { { 2, 0, -3, 4 }, { 6, 3, 2, -1 }, { 5, 4, 7, 3 }, { 2, -6, 8, 1 } };

        std::vector<std::tuple<std::tuple<size_t, size_t>, std::tuple<size_t, size_t>>> from_to_q;
        from_to_q.push_back(std::make_tuple(std::make_tuple(1, 1), std::make_tuple(3, 2)));
        from_to_q.push_back(std::make_tuple(std::make_tuple(0, 2), std::make_tuple(3, 3)));

        std::vector<int> sums = sub_rectangular_sum((int *) mat, 4, 4, from_to_q);

        REQUIRE(sums.size() == 2);
        REQUIRE(sums[0] == 18);
        REQUIRE(sums[1] == 21);
    }

    SECTION("min_jumps_to_reach_end(elements)") {
        std::vector<size_t> jump_indexes;
        std::vector<size_t> jump_test_results;

        jump_indexes = min_jumps_to_reach_end({ 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 });
        jump_test_results = { 0, 1, 3 };
        REQUIRE(jump_indexes.size() == jump_test_results.size());
        for (size_t i = 0; i < jump_test_results.size(); ++i) {
            REQUIRE(jump_indexes[i] == jump_test_results[i]);
        }

        jump_indexes = min_jumps_to_reach_end({ 2, 3, 1, 1, 2, 4, 2, 0, 1, 1 });
        jump_test_results = { 0, 1, 4, 5 };
        REQUIRE(jump_indexes.size() == jump_test_results.size());
        for (size_t i = 0; i < jump_test_results.size(); ++i) {
            REQUIRE(jump_indexes[i] == jump_test_results[i]);
        }
    }

    SECTION("check_interleaving(str1, str2, interleaved_str") {
        REQUIRE(check_interleaving("AAB", "AXY", "AAXABY") == true);
        REQUIRE(check_interleaving("AAB", "AXY", "ABAAXY") == false);
    }

    SECTION("max_sum_non_adj(elements)") {
        REQUIRE(max_sum_non_adj({ 4, 1, 1, 4, 2, 1 }) == 9);
    }

    SECTION("max_sub_square_mat_with_0_1(mat, M, N)") {
        bool mat[5][5] = { { 0, 0, 1, 1, 1 }, { 1, 0, 1, 1, 1 }, { 0, 1, 1, 1, 1 }, { 1, 0, 1, 1, 1 } };
        REQUIRE(max_sub_square_mat_with_0_1((bool *) mat, 4, 5) == 3);
    }

    SECTION("max_size_rectangle_in_mat_with_0_1(mat, M, N)") {
        bool mat[4][6] = { { 1, 0, 0, 1, 1, 1 }, { 1, 0, 1, 1, 0, 1 }, { 0, 1, 1, 1, 1, 1 }, { 0, 0, 1, 1, 1, 1 } };
        REQUIRE(max_size_rectangle_in_mat_with_0_1((bool *) mat, 4, 6) == 8);
    }
}