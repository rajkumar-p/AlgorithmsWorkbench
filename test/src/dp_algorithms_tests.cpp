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

        len_and_prices = { {0, 0}, {1, 1}, {2, 5},{3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30} };

        result_to_check = { {2, 5}, {2, 5} };
        cuts = cut_rod(len_and_prices, 4);
        for (size_t i = 0; i < result_to_check.size(); ++i) {
            REQUIRE(result_to_check[i].first == cuts[i].first);
            REQUIRE(result_to_check[i].second == cuts[i].second);
        }

        result_to_check = { {2, 5}, {6, 17} };
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
}