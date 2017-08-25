#include "catch.hpp"
#include "aw_tests_constants.hpp"
#include "utils.hpp"
#include "sorting.hpp"

TEST_CASE("Checking Max Heapify Implementation", "[Max Heapify]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);
        heapify(v0, 0, v0.size(), std::greater<int>());

        REQUIRE(is_heap(v0, 0, std::greater<int>()) == true);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);
        heapify(v1, 0, v1.size(), std::greater<int>());

        REQUIRE(is_heap(v1, 0, std::greater<int>()) == true);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);
        heapify(v5, 0, v5.size(), std::greater<int>());

        REQUIRE(is_heap(v5, 0, std::greater<int>()) == true);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);
        heapify(v10, 0, v10.size(), std::greater<int>());

        REQUIRE(is_heap(v10, 0, std::greater<int>()) == true);
    }
}

TEST_CASE("Checking Heap Sort Implementation", "[Heap Sort]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);
        heap_sort(v0, std::greater<int>());

        REQUIRE(std::is_sorted(v0.begin(), v0.end()) == true);

        heap_sort(v0, std::less<int>());

        REQUIRE(std::is_sorted(v0.begin(), v0.end(), std::greater<int>()) == true);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);
        heap_sort(v1, std::greater<int>());

        REQUIRE(std::is_sorted(v1.begin(), v1.end()) == true);

        heap_sort(v1, std::less<int>());

        REQUIRE(std::is_sorted(v1.begin(), v1.end(), std::greater<int>()) == true);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);
        heap_sort(v5, std::greater<int>());

        REQUIRE(std::is_sorted(v5.begin(), v5.end()) == true);

        heap_sort(v5, std::less<int>());

        REQUIRE(std::is_sorted(v5.begin(), v5.end(), std::greater<int>()) == true);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);
        heap_sort(v10, std::greater<int>());

        REQUIRE(std::is_sorted(v10.begin(), v10.end()) == true);

        heap_sort(v10, std::less<int>());

        REQUIRE(std::is_sorted(v10.begin(), v10.end(), std::greater<int>()) == true);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);
        heap_sort(v100, std::greater<int>());

        REQUIRE(std::is_sorted(v100.begin(), v100.end()) == true);

        heap_sort(v100, std::less<int>());

        REQUIRE(std::is_sorted(v100.begin(), v100.end(), std::greater<int>()) == true);
    }
}