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
}