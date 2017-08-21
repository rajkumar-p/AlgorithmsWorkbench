#include "catch.hpp"
#include "aw_tests_constants.hpp"
#include "utils.hpp"
#include "sorting.hpp"

TEST_CASE("Checking Insertion Sort Implementation", "[Insertion Sort]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);
        insertion_sort(v0);

        REQUIRE(std::is_sorted(v0.begin(), v0.end()) == true);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);
        insertion_sort(v1);

        REQUIRE(std::is_sorted(v1.begin(), v1.end()) == true);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);
        insertion_sort(v5);

        REQUIRE(std::is_sorted(v5.begin(), v5.end()) == true);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);
        insertion_sort(v10);

        REQUIRE(std::is_sorted(v10.begin(), v10.end()) == true);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);
        insertion_sort(v100);

        REQUIRE(std::is_sorted(v100.begin(), v100.end()) == true);
    }
}