#include "catch.hpp"
#include "aw_tests_constants.hpp"
#include "utils.hpp"

TEST_CASE("Elements are correctly inserted into a vector", "[put_into_vector test]")
{
    SECTION("0 Elements") {
        std::string input_file_name = input_files_directory + "0_input.in";
        std::vector<int> v_actual = {};
        std::vector<int> v0;

        put_into_vector(v0, input_file_name);

        REQUIRE(v_actual == v0);
    }

    SECTION("1 Elements") {
        std::string input_file_name = input_files_directory + "1_input.in";
        std::vector<int> v_actual = {630};
        std::vector<int> v1;

        put_into_vector(v1, input_file_name);

        REQUIRE(v_actual == v1);
    }

    SECTION("5 Elements") {
        std::string input_file_name = input_files_directory + "5_custom.in";
        std::vector<int> v_actual = {2, 3, 8, 6, 1};
        std::vector<int> v5;

        put_into_vector(v5, input_file_name);

        REQUIRE(v_actual == v5);
    }

    SECTION("10 Elements") {
        std::string input_file_name = input_files_directory + "10_input.in";
        std::vector<int> v_actual = {827, -558, 265, -384, -805, 94, -443, -624, 94, 986};
        std::vector<int> v10;

        put_into_vector(v10, input_file_name);

        REQUIRE(v_actual == v10);
    }
}