#include "catch.hpp"
#include "aw_tests_constants.hpp"
#include "utils.hpp"
#include "quick_sort.hpp"
#include "binary_search.hpp"
#include "subset_sum_search.hpp"
#include "selection.hpp"

TEST_CASE("Checking Binary Search Implementation", "[Binary Search]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);
        quick_sort(v0, 0, v0.size() - 1, std::less<int>());

        REQUIRE(binary_search(v0, 0, v0.size() - 1, -10) == -1);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);
        quick_sort(v1, 0, v1.size() - 1, std::less<int>());

        REQUIRE(binary_search(v1, 0, v1.size() - 1, 630) == 0);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);
        quick_sort(v5, 0, v5.size() - 1, std::less<int>());

        REQUIRE(binary_search(v5, 0, v5.size() - 1, 999) == -1);
        REQUIRE(binary_search(v5, 0, v5.size() - 1, 3) == 2);
        REQUIRE(binary_search(v5, 0, v5.size() - 1, 1) == 0);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);
        quick_sort(v10, 0, v10.size() - 1, std::less<int>());

        REQUIRE(binary_search(v10, 0, v10.size() - 1, -624) == 1);
        REQUIRE(binary_search(v10, 0, v10.size() - 1, -900) == -1);
        REQUIRE(binary_search(v10, 0, v10.size() - 1, 827) == 8);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);
        quick_sort(v100, 0, v100.size() - 1, std::less<int>());

        REQUIRE(binary_search(v100, 0, v100.size() - 1, 524) == 68);
        REQUIRE(binary_search(v100, 0, v100.size() - 1, 162) == 51);
        REQUIRE(binary_search(v100, 0, v100.size() - 1, -900) == -1);
        REQUIRE(binary_search(v100, 0, v100.size() - 1, -898) == 6);
    }
}

TEST_CASE("Checking Subset Sum Implementation", "[Subset Sum]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);

        REQUIRE(subset_sum_search(v0, 25) == false);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);

        REQUIRE(subset_sum_search(v1, 1260) == false);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);

        REQUIRE(subset_sum_search(v5, 11) == true);
        REQUIRE(subset_sum_search(v5, 16) == false);
        REQUIRE(subset_sum_search(v5, 7) == true);

        v5 = {INT32_MAX, INT32_MIN, INT32_MIN, INT32_MIN, INT32_MAX};

        REQUIRE(subset_sum_search(v5, INT32_MAX + INT32_MAX) == true);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);

        REQUIRE(subset_sum_search(v10, -1067) == true);
        REQUIRE(subset_sum_search(v10, 362) == true);
        REQUIRE(subset_sum_search(v10, 10000) == false);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);

        REQUIRE(subset_sum_search(v100, 925) == true);
        REQUIRE(subset_sum_search(v100, -20) == true);
        REQUIRE(subset_sum_search(v100, 15000) == false);
        REQUIRE(subset_sum_search(v100, 360) == true);
    }
}

TEST_CASE("Selection Implementation", "[Selection]")
{
    std::vector<int> v10 = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    REQUIRE(selection(v10, 0, v10.size() - 1, 5) == 7);
    REQUIRE(selection(v10, 0, v10.size() - 1, 1) == 1);
    REQUIRE(selection(v10, 0, v10.size() - 1, 9) == 14);
    REQUIRE(selection(v10, 0, v10.size() - 1, 10) == 16);
    REQUIRE(selection(v10, 0, v10.size() - 1, 20) == 0);
}