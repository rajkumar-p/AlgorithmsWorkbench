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
}