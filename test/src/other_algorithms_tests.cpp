#include "catch.hpp"
#include "other_algorithms.hpp"
#include <map>

TEST_CASE("Checking Other Algorithms", "[Other Algorithms]")
{
    SECTION("get_next_high_for_each()") {
        std::vector<size_t> temps = { 73, 74, 75, 71, 69, 72, 76, 73 };
        std::vector<size_t> next_highs = get_next_high_for_each(temps);
        std::vector<size_t> results = { 1, 1, 4, 2, 1, 1, 0, 0 };

        REQUIRE(next_highs == results);
    }

    SECTION("median_of_two_sorted_arrays(a1, a2)") {
        std::vector<int> a1;
        std::vector<int> a2;

        a1 = { 1, 2, 3, 4, 7 };
        a2 = { 0, 5, 6, 9 };
        REQUIRE(median_of_two_sorted_arrays(a1, a2) == 4.0);

        a1 = { 1, 2 };
        a2 = { 3, 4 };
        REQUIRE(median_of_two_sorted_arrays(a1, a2) == 2.5);

        a1 = { 15, 17, 18, 25, 70 };
        a2 = { 1, 2, 3, 4, 5 };
        REQUIRE(median_of_two_sorted_arrays(a1, a2) == 10.0);

        a1 = { 4, 5, 18, 25, 70 };
        a2 = { 1, 2, 3, 15, 17 };
        REQUIRE(median_of_two_sorted_arrays(a1, a2) == 10.0);

        a1 = { 4, 5, 18, 25, 70 };
        a2 = { 17 };
        REQUIRE(median_of_two_sorted_arrays(a1, a2) == 17.5);
    }

    SECTION("find_peak(nums)") {
        std::vector<int> nums;
        std::map<size_t, bool> peaks;

        nums = { 1, 2, 6, 5, 3, 7, 4 };
        peaks = { std::make_pair(2, true), std::make_pair(5, true) };
        REQUIRE(peaks.find(find_peak(nums)) != peaks.end());

        nums = { 1, 3, 4, 3, 5, 1, 3 };
        peaks = { std::make_pair(2, true), std::make_pair(4, true), std::make_pair(6, true) };
        REQUIRE(peaks.find(find_peak(nums)) != peaks.end());
    }

    SECTION("find_peak_2d(nums)") {
        // int a[4][3] = { { 10, 20, 26 }, { 17, 19, 14 }, { 7, 16, 32 }, {21, 15, 14 } };
        // std::map<std::tuple<int, int>, bool> peaks;

        // peaks.emplace(std::make_tuple(0, 2), true);
        // peaks.emplace(std::make_tuple(2, 2), true);

        // std::tuple<int, int> peak_2d = find_peak_2d((int *)a, 0, 3, 0, 2);

        // REQUIRE(peaks.find(peak_2d) != peaks.end());
    }

    SECTION("max_area_of_histogram(heights)") {
        std::vector<size_t> heights;

        heights = { 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2 };
        REQUIRE(max_area_of_histogram(heights) == 16);

        heights = { 9, 5, 2, 1, 3, 5, 4, 7, 2, 6 };
        REQUIRE(max_area_of_histogram(heights) == 12);

        heights = { 2, 1, 2, 3, 1 };
        REQUIRE(max_area_of_histogram(heights) == 5);
    }

    SECTION("trapping_rain_water_in_histogram(heights)") {
        std::vector<size_t> heights;

        heights = { 3, 0, 0, 2, 0, 4 };
        REQUIRE(trapping_rain_water_in_histogram(heights) == 10);

        heights = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        REQUIRE(trapping_rain_water_in_histogram(heights) == 6);

        heights = { 9, 5, 2, 1, 3, 5, 4, 7, 2, 6 };
        REQUIRE(trapping_rain_water_in_histogram(heights) == 26);
    }

    SECTION("sliding_window_max_of_size_k(elements, k)") {
        std::vector<int> result_vector;

        result_vector = { 3, 3, 4, 5, 5, 5, 6 };
        REQUIRE(sliding_window_max_of_size_k({ 1, 2, 3, 1, 4, 5, 2, 3, 6 }, 3) == result_vector);

        result_vector = { 10, 10, 10, 15, 15, 90, 90 };
        REQUIRE(sliding_window_max_of_size_k({ 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 }, 4) == result_vector);

        result_vector = { 3, 3, 5, 5, 6, 7 };
        REQUIRE(sliding_window_max_of_size_k({ 1, 3, -1, -3, 5, 3, 6, 7 }, 3) == result_vector);
    }
}