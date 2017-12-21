#include "string_algorithms.hpp"
#include <cctype>
#include <set>

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