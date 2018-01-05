#include "string_algorithms.hpp"
#include <algorithm>
#include <cctype>
#include <set>
#include <map>

#include <iostream>

std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end(), [](const std::string &s1, const std::string &s2) {
        return s1.length() < s2.length();
    });

    std::string license_plate_stripped = "";
    for(size_t i = 0; i < licensePlate.length(); ++i) {
        if (isalpha(licensePlate[i])) {
            license_plate_stripped += tolower(licensePlate[i]);
        }
    }

    for (const std::string &word : words) {
        std::multiset<char> lp_set;
        for (const char &c : license_plate_stripped) {
            lp_set.insert(c);
        }

        for (const char &c : word) {
            auto it = lp_set.find(c);
            if (it != lp_set.end()) {
                lp_set.erase(it);
            }
        }

        if (lp_set.empty()) {
            return word;
        }
    }

    return "";
}

int strstr(std::string haystack, std::string needle)
{
    if (haystack.length() == 0 || needle.length() == 0) { return -1; }
    if (needle.length() > haystack.length()) { return -1; }

    for (size_t i = 0; i < haystack.length(); ++i) {
        size_t j;
        for (j = 0; j <= (haystack.length() - needle.length()); ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        if (j == needle.length()) {
            return i;
        }
    }

    return -1;
}

std::vector<size_t> kmp(const std::string text, const std::string pattern)
{
    if (pattern.length() == 0) { return {}; }

    size_t n = text.length();
    size_t m = pattern.length();

    std::vector<size_t> result = {};
    std::vector<size_t> prefix_table = compute_prefix_for(pattern);

    size_t i = 0, j = 0;
    while ( i < n) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        }

        if (j == m) {
            result.push_back(i - j);
            j = prefix_table[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j == 0) {
                ++i;
            } else {
                j = prefix_table[j - 1];
            }
        }
    }

    return result;
}

std::vector<size_t> compute_prefix_for(const std::string pattern)
{
    size_t m = pattern.length();
    std::vector<size_t> prefix_table(m, 0);

    size_t i = 1, j = i - 1;
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            prefix_table[i] = j + 1;
            ++i;
            ++j;
        } else {
            if (j == 0) {
                prefix_table[i] = 0;
                ++i;
            } else {
                j = prefix_table[j - 1];
            }
        }
    }

    return prefix_table;
}

std::string reverse_words(std::string &s)
{
    std::reverse(s.begin(), s.end());

    std::vector<std::tuple<int, int>> words_start_end;
    int prev_space = -1;
    int m = s.length();
    for (int i = -1; i < m - 1; ++i) {
        if (isspace(s[i + 1]) ||  i + 1 == m - 1) {
            if (prev_space + 1 != i + 1) {
                words_start_end.push_back(std::make_tuple(prev_space + 1, i));
            }

            prev_space = i + 1;
        }
    }

    for (const std::tuple<int, int> &t : words_start_end) {
        int start = std::get<0>(t);
        int end = std::get<1>(t);
        std::reverse(s.begin() + start, s.begin() + end + 1);
    }

    return s;
}

std::vector<std::string> lengthOfLongestSubstring(const std::string str)
{
    std::vector<std::string> longest_substrings;
    size_t n = str.length();
    size_t ans = 0;

    std::map<char, size_t> mp;
    for (size_t i = 0, j = 0; j < n; ++j) {
        if (mp.find(str[j]) != mp.end()) {
            i = std::max(mp[str[j]], i);
        }

        if (ans <= j - i + 1) {
            longest_substrings.push_back(str.substr(i, j - i + 1));
            ans = j - i + 1;
        }

        mp[str[j]] = j + 1;
    }

    size_t longest_substring_size = longest_substrings.back().length();
    std::vector<std::string> result;
    for (const std::string &s : longest_substrings) {
        if (s.length() == longest_substring_size) {
            result.push_back(s);
        }
    }

    return result;
}

std::vector<std::string> letter_combinations(const std::string &digits)
{
    void letter_mapper(const std::string digits, const std::string prefix, std::vector<std::string> &mappings);

    std::vector<std::string> mappings;
    letter_mapper(digits, "", mappings);

    return mappings;
}

void letter_mapper(const std::string digits, const std::string prefix, std::vector<std::string> &mappings)
{
    std::string get_mappings_for(char c);

    if (digits.empty()) {
        mappings.push_back(prefix);
    } else {
        std::string char_mapping = get_mappings_for(digits[0]);

        for (const char c : char_mapping) {
            letter_mapper(digits.substr(1), prefix + c, mappings);
        }
    }
}

std::string get_mappings_for(char c)
{
    std::map<char, std::string> char_mappings = {
        { '1', "" }, { '2', "abc" }, { '3', "def" },
        { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" },
        { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" },
        { '0', "~"}
    };

    return char_mappings[c];
}

std::vector<std::string> generate_parenthesis(const size_t n)
{
    void all_parenthesis(const std::string p, size_t left, size_t right, std::vector<std::string> &parens);

    std::vector<std::string> parens;
    all_parenthesis("", n, 0, parens);

    return {};
}

void all_parenthesis(const std::string p, size_t left, size_t right, std::vector<std::string> &parens)
{
    if (left == 0 && right == 0) {
        std::cout <<p<<std::endl;
    }

    if (left > 0) {
        all_parenthesis(p + "(", left - 1, right + 1, parens);
    }

    if (right > 0) {
        all_parenthesis(p + ")", left, right - 1, parens);
    }

}