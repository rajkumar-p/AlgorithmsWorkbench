#include "catch.hpp"
#include "sorting.hpp"

TEST_CASE("Checking Counting Sort Implementation", "[Counting Sort]")
{
    SECTION("8 Elements") {
        std::vector<int> v = { 2, 5, 3, 0, 2, 3, 0, 3 };
        std::vector<int> sorted_v = counting_sort(v, 5);

        REQUIRE(std::is_sorted(sorted_v.begin(), sorted_v.end()) == true);
    }
}