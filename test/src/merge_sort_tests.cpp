#include "catch.hpp"
#include "aw_tests_constants.hpp"
#include "utils.hpp"
#include "sorting.hpp"

TEST_CASE("Merging two parts of a vector", "[Merge elements in vector]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);

        int p = 0, q = 0, r = v0.size() - 1;
        merge(v0, p, q, r);

        REQUIRE(std::is_sorted(v0.begin() + p, v0.begin() + r + 1) == true);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);

        int p = 0, q = 0, r = v1.size() - 1;
        merge(v1, p, q, r);

        REQUIRE(std::is_sorted(v1.begin() + p, v1.begin() + r + 1) == true);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);

        int p = 0, q = 2, r = v5.size() - 1;
        std::sort(v5.begin() + p, v5.begin() + q + 1, std::less<int>());
        std::sort(v5.begin() + q + 1, v5.begin() + r + 1, std::less<int>());

        merge(v5, p, q, r);

        REQUIRE(std::is_sorted(v5.begin() + p, v5.begin() + r + 1) == true);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);

        int p = 3, q = 5, r = v10.size() - 1;
        std::sort(v10.begin() + p, v10.begin() + q + 1, std::less<int>());
        std::sort(v10.begin() + q + 1, v10.begin() + r + 1, std::less<int>());

        merge(v10, p, q, r);

        REQUIRE(std::is_sorted(v10.begin() + p, v10.begin() + r + 1) == true);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);

        int p = 24, q = 49, r = v100.size() - 1;
        std::sort(v100.begin() + p, v100.begin() + q + 1, std::less<int>());
        std::sort(v100.begin() + q + 1, v100.begin() + r + 1, std::less<int>());

        merge(v100, p, q, r);

        REQUIRE(std::is_sorted(v100.begin() + p, v100.begin() + r + 1) == true);
    }
}

TEST_CASE("Checking Merge Sort Implementation", "[Merge Sort]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);
        merge_sort(v0, 0, v0.size() - 1);

        REQUIRE(std::is_sorted(v0.begin(), v0.end()) == true);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);
        merge_sort(v1, 0, v1.size() - 1);

        REQUIRE(std::is_sorted(v1.begin(), v1.end()) == true);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);
        merge_sort(v5, 0, v5.size() - 1);

        REQUIRE(std::is_sorted(v5.begin(), v5.end()) == true);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);
        merge_sort(v10, 0, v10.size() - 1);

        REQUIRE(std::is_sorted(v10.begin(), v10.end()) == true);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);
        merge_sort(v100, 0, v100.size() - 1);

        REQUIRE(std::is_sorted(v100.begin(), v100.end()) == true);
    }
}