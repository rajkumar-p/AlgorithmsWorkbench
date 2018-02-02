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

    SECTION("lengthOfLongestSubstring(str) tests") {
        std::string s = "abcabcbb";
        std::vector<std::string> result = { "abc", "bca", "cab", "abc" };

        REQUIRE(lengthOfLongestSubstring(s) == result);
    }

    SECTION("reverse_string(str) tests") {
        std::string s = "abcabcbb";
        std::vector<std::string> result = { "abc", "bca", "cab", "abc" };

        REQUIRE(reverse_string("abcabcbb") == "bbcbacba");
        REQUIRE(reverse_string("the sky   is      blue") == "eulb      si   yks eht");
        REQUIRE(reverse_string("      ") == "      ");
        REQUIRE(reverse_string("abcd") == "dcba");
        REQUIRE(reverse_string("hello") == "olleh");
    }

    SECTION("zig_zag_convert(str, row) tests") {
        REQUIRE(zig_zag_convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
        REQUIRE(zig_zag_convert("ABCDEFGHIJKLMNOPQRSTUVWXYZ12345", 7) == "AMYBHNTZCIOU1DJPV2EKQW3FLRX4GS5");
    }

    SECTION("replace_multiple_spaces(str) tests") {
        REQUIRE(replace_multiple_spaces("     the sky   is      blue") == " the sky is blue");
        REQUIRE(replace_multiple_spaces("  Gone  are  the  multiple  spaces  ") == " Gone are the multiple spaces ");
    }

    SECTION("trim_spaces(str) tests") {
        REQUIRE(trim_spaces("    This is a test.   ") == "This is a test.");
        REQUIRE(trim_spaces("This is a test.") == "This is a test.");
    }

    SECTION("longest_substr_with_uniq_chars(str)") {
        REQUIRE(longest_substr_with_uniq_chars("abcabcbb") == 3);
        REQUIRE(longest_substr_with_uniq_chars("bbbbb") == 1);
        REQUIRE(longest_substr_with_uniq_chars("pwwkew") == 3);
    }

    SECTION("is_parentheses_valid(parens)") {
        REQUIRE(is_parentheses_valid("()") == true);
        REQUIRE(is_parentheses_valid("()[]{}") == true);
        REQUIRE(is_parentheses_valid("([{}])") == true);
        REQUIRE(is_parentheses_valid("(]") == false);
        REQUIRE(is_parentheses_valid("([)]") == false);
    }

    SECTION("stoi(digit)") {
        REQUIRE(stoi("22") == 22);
        REQUIRE(stoi("-543") == -543);
        REQUIRE(stoi("   77  ") == 77);
        REQUIRE(stoi("   42424.4322  ") == 42424);
        REQUIRE(stoi("   0.0  ") == 0);
        REQUIRE(stoi("2147483647") == 2147483647);
        REQUIRE(stoi("-2147483648") == -2147483648);
        REQUIRE(stoi("2222222222") == 2147483647);
        REQUIRE(stoi("-2222222222") == -2147483648);
    }

    SECTION("reverse_words_2(str)") {
        REQUIRE(reverse_words_2("           the sky   is        blue    ") == "           eht yks   si        eulb    ");
        REQUIRE(reverse_words_2("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc");
    }

    SECTION("space_replacement(str, len, new_len)") {
        REQUIRE(space_replacement("Mr John Smith         ", 13, 22) == "Mr%20John%20Smith");
    }

    SECTION("length_of_last_word(str)") {
        REQUIRE(length_of_last_word("Hello World") == 5);
        REQUIRE(length_of_last_word("    Hello World      ") == 5);
        REQUIRE(length_of_last_word("~~~~Hello World~~~~~~") == 5);
        REQUIRE(length_of_last_word("") == 0);
        REQUIRE(length_of_last_word("World") == 5);
        REQUIRE(length_of_last_word("    World    ") == 5);
    }
}