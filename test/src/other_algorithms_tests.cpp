#include "catch.hpp"
#include "other_algorithms.hpp"

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
}