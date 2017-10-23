#include "catch.hpp"
#include "aw_tests_constants.hpp"
#include "utils.hpp"
#include "insertion_sort.hpp"

TEST_CASE("Checking Insertion Sort Implementation", "[Insertion Sort]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);

        auto cmp_fn_less = std::less<int>();
        auto cmp_fn_greater = std::greater<int>();

        insertion_sort(v0, cmp_fn_less);
        REQUIRE(std::is_sorted(v0.begin(), v0.end(), cmp_fn_less) == true);

        insertion_sort(v0, cmp_fn_greater);
        REQUIRE(std::is_sorted(v0.begin(), v0.end(), cmp_fn_greater) == true);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);

        auto cmp_fn_less = std::less<int>();
        auto cmp_fn_greater = std::greater<int>();
        
        insertion_sort(v1, cmp_fn_less);
        REQUIRE(std::is_sorted(v1.begin(), v1.end(), cmp_fn_less) == true);

        insertion_sort(v1, cmp_fn_greater);
        REQUIRE(std::is_sorted(v1.begin(), v1.end(), cmp_fn_greater) == true);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);

        auto cmp_fn_less = std::less<int>();
        auto cmp_fn_greater = std::greater<int>();

        insertion_sort(v5, cmp_fn_less);
        REQUIRE(std::is_sorted(v5.begin(), v5.end(), cmp_fn_less) == true);

        insertion_sort(v5, cmp_fn_greater);
        REQUIRE(std::is_sorted(v5.begin(), v5.end(), cmp_fn_greater) == true);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);

        auto cmp_fn_less = std::less<int>();
        auto cmp_fn_greater = std::greater<int>();

        insertion_sort(v10, cmp_fn_less);
        REQUIRE(std::is_sorted(v10.begin(), v10.end(), cmp_fn_less) == true);

        insertion_sort(v10, cmp_fn_greater);
        REQUIRE(std::is_sorted(v10.begin(), v10.end(), cmp_fn_greater) == true);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);

        auto cmp_fn_less = std::less<int>();
        auto cmp_fn_greater = std::greater<int>();

        insertion_sort(v100, cmp_fn_less);
        REQUIRE(std::is_sorted(v100.begin(), v100.end(), cmp_fn_less) == true);

        insertion_sort(v100, cmp_fn_greater);
        REQUIRE(std::is_sorted(v100.begin(), v100.end(), cmp_fn_greater) == true);
    }
}