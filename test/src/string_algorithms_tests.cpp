#include "catch.hpp"
#include "string_algorithms.hpp"

TEST_CASE("Checking String Algorithms Implementation", "[String Algorithms]")
{
    SECTION("shortestCompletingWord() tests") {
        std::vector<std::string> words = { "step", "steps", "stripe", "stepple" };
        std::string license_plate = "1s3 PSt";

        REQUIRE(shortestCompletingWord(license_plate, words) == "steps");    

        words = { "looks", "pest", "stew", "show" };
        license_plate = "1s3 456";

        REQUIRE(shortestCompletingWord(license_plate, words) == "pest");
    }

    SECTION("strstr() tests") {
        std::string haystack = "hello";
        std::string needle = "ll";
        REQUIRE(strstr(haystack, needle) == 2);

        haystack = "aaaaa";
        needle = "bba";
        REQUIRE(strstr(haystack, needle) == -1);
    }

    SECTION("kmp(text, pattern) Prefix Table Construction tests") {
        std::string pattern;
        std::vector<size_t> result;

        pattern = "abcaby";
        result = { 0, 0, 0, 1, 2, 0 };
        REQUIRE(compute_prefix_for(pattern) == result);

        pattern = "aaaa";
        result = { 0, 1, 2, 3 };
        REQUIRE(compute_prefix_for(pattern) == result);

        pattern = "abcdabca";
        result = { 0, 0, 0, 0, 1, 2, 3, 1 };
        REQUIRE(compute_prefix_for(pattern) == result);
    }

    SECTION("kmp(text, pattern) tests") {
        std::string text;
        std::string pattern;
        std::vector<size_t> result;

        text = "abxabcabcaby";
        pattern = "abcaby";
        result = { 6 };
        REQUIRE(kmp(text, pattern) == result);

        text = "aaaaabaaaba";
        pattern = "aaaa";
        result = { 0, 1 };
        REQUIRE(kmp(text, pattern) == result);

        text = "bacbababaabcbab";
        pattern = "ababaca";
        result = {};
        REQUIRE(kmp(text, pattern) == result);
    }

    SECTION("reverse_words(str) tests") {
        std::string s = "the sky is blue";
        REQUIRE(reverse_words(s) == "blue is sky the");
    }
}