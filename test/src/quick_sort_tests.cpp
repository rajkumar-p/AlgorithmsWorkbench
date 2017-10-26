#include "catch.hpp"
#include "aw_tests_constants.hpp"
#include "utils.hpp"
#include "quick_sort.hpp"
#include "quick_sort_utils.hpp"

TEST_CASE("Checking Partition Implementation", "[Partition Method]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);

        int p;
        std::vector<int>::const_iterator *iter;
        
        p = partition(v0, 0, v0.size() - 1, std::less<int>());

        REQUIRE(std::max_element(v0.begin(), v0.begin() + p + 1, std::less<int>()) == v0.end());
        REQUIRE(std::min_element(v0.begin() + p, v0.end(), std::greater<int>()) == v0.end());

        p = partition(v0, 0, v0.size() - 1, std::greater<int>());
        REQUIRE(std::min_element(v0.begin(), v0.begin() + p + 1, std::less<int>()) == v0.end());
        REQUIRE(std::max_element(v0.begin() + p, v0.end(), std::greater<int>()) == v0.end());
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);

        int p;
        std::vector<int>::iterator iter;

        p = partition(v1, 0, v1.size() - 1, std::less<int>());

        iter = std::max_element(v1.begin(), v1.begin() + p + 1);
        REQUIRE(*iter == v1[0]);
        iter = std::min_element(v1.begin() + p, v1.end());
        REQUIRE(*iter == v1[0]);

        p = partition(v1, 0, v1.size() - 1, std::greater<int>());

        iter = std::min_element(v1.begin(), v1.begin() + p + 1);
        REQUIRE(*iter == v1[0]);
        iter = std::max_element(v1.begin() + p, v1.end());
        REQUIRE(*iter == v1[0]);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);

        int p;
        std::vector<int>::iterator iter;

        p = partition(v5, 0, v5.size() - 1, std::less<int>());

        iter = std::max_element(v5.begin(), v5.begin() + p + 1);
        REQUIRE(*iter == v5[p]);
        iter = std::min_element(v5.begin() + p, v5.end());
        REQUIRE(*iter == v5[p]);

        p = partition(v5, 0, v5.size() - 1, std::greater<int>());

        iter = std::min_element(v5.begin(), v5.begin() + p + 1);
        REQUIRE(*iter == v5[p]);
        iter = std::max_element(v5.begin() + p, v5.end());
        REQUIRE(*iter == v5[p]);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);

        int p;
        std::vector<int>::iterator iter;

        p = partition(v10, 0, v10.size() - 1, std::less<int>());

        iter = std::max_element(v10.begin(), v10.begin() + p + 1);
        REQUIRE(*iter == v10[p]);
        iter = std::min_element(v10.begin() + p, v10.end());
        REQUIRE(*iter == v10[p]);

        p = partition(v10, 0, v10.size() - 1, std::greater<int>());

        iter = std::min_element(v10.begin(), v10.begin() + p + 1);
        REQUIRE(*iter == v10[p]);
        iter = std::max_element(v10.begin() + p, v10.end());
        REQUIRE(*iter == v10[p]);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);

        int p;
        std::vector<int>::iterator iter;

        p = partition(v100, 0, v100.size() - 1, std::less<int>());

        iter = std::max_element(v100.begin(), v100.begin() + p + 1);
        REQUIRE(*iter == v100[p]);
        iter = std::min_element(v100.begin() + p, v100.end());
        REQUIRE(*iter == v100[p]);

        p = partition(v100, 0, v100.size() - 1, std::greater<int>());

        iter = std::min_element(v100.begin(), v100.begin() + p + 1);
        REQUIRE(*iter == v100[p]);
        iter = std::max_element(v100.begin() + p, v100.end());
        REQUIRE(*iter == v100[p]);
    }
}

TEST_CASE("Checking Quick Sort Implementation", "[Quick Sort]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);

        quick_sort(v0, 0, v0.size(), std::less<int>());
        REQUIRE(std::is_sorted(v0.begin(), v0.end()) == true);

        quick_sort(v0, 0, v0.size(), std::greater<int>());
        REQUIRE(std::is_sorted(v0.begin(), v0.end(), std::greater<int>()) == true);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);
        quick_sort(v1, 0, v1.size(), std::less<int>());
        REQUIRE(std::is_sorted(v1.begin(), v1.end()) == true);

        quick_sort(v1, 0, v1.size(), std::greater<int>());
        REQUIRE(std::is_sorted(v1.begin(), v1.end(), std::greater<int>()) == true);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);
        quick_sort(v5, 0, v5.size(), std::less<int>());
        REQUIRE(std::is_sorted(v5.begin(), v5.end()) == true);

        quick_sort(v5, 0, v5.size(), std::greater<int>());
        REQUIRE(std::is_sorted(v5.begin(), v5.end(), std::greater<int>()) == true);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);
        quick_sort(v10, 0, v10.size(), std::less<int>());
        REQUIRE(std::is_sorted(v10.begin(), v10.end()) == true);

        quick_sort(v10, 0, v10.size(), std::greater<int>());
        REQUIRE(std::is_sorted(v10.begin(), v10.end(), std::greater<int>()) == true);
    }

    SECTION("100 Elements") {
        std::string input_file_name = input_files_directory + "100_input.in";
        std::vector<int> v100;

        put_into_vector(v100, input_file_name);
        quick_sort(v100, 0, v100.size(), std::less<int>());
        REQUIRE(std::is_sorted(v100.begin(), v100.end()) == true);

        quick_sort(v100, 0, v100.size(), std::greater<int>());
        REQUIRE(std::is_sorted(v100.begin(), v100.end(), std::greater<int>()) == true);
    }
}