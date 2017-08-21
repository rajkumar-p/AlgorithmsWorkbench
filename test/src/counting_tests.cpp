#include "catch.hpp"
#include "aw_tests_constants.hpp"
#include "utils.hpp"
#include "counting.hpp"

TEST_CASE("Checking Couting Inversions Implementation", "[Counting Inversions]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);

        REQUIRE(count_inversions(v0, 0, v0.size() - 1) == 0);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);

        REQUIRE(count_inversions(v1, 0, v1.size() - 1) == 0);
    }

    SECTION("5 Elements") {
        std::vector<int> v5 = {2, 3, 8, 6, 1};

        REQUIRE(count_inversions(v5, 0, v5.size() - 1) == 5);
    }

    SECTION("10 Elements") {
        std::vector<int> v10 = {827, -558, 265, -384, -805, 94, -443, -624, 94, 986};

        REQUIRE(count_inversions(v10, 0, v10.size() - 1) == 22);
    }
}