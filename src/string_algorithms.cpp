#include "string_algorithms.hpp"
#include <algorithm>
#include <cctype>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

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

std::string reverse_words(std::string &str)
{
    std::reverse(str.begin(), str.end());
    std::vector<std::tuple<size_t, size_t>> word_bounds;

    size_t str_index = 0;
    while (1) {
        while (isspace(str[str_index]) && str_index < str.length()) {
            ++str_index;
        }

        size_t start_index = str_index;
        size_t len = 0;
        while (!isspace(str[str_index]) && str_index < str.length()) {
            ++str_index;
            ++len;
        }

        if (len > 0) {
            word_bounds.push_back(std::make_tuple(start_index, len));
        }

        if (str_index >= str.length()) { break; }
    }

    for (const std::tuple<size_t, size_t> &t : word_bounds) {
        std::reverse(str.begin() + std::get<0>(t), str.begin() + std::get<0>(t) + std::get<1>(t));
    }

    return str;
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

std::string reverse_string(std::string str)
{
    size_t front_index = 0;
    size_t rear_index = str.length() - 1;

    while (front_index < rear_index) {
        std::swap(str[front_index++], str[rear_index--]);
    }

    return str;
}

std::string zig_zag_convert(std::string str, size_t rows)
{
    std::string result;
    size_t active_index;

    // First row
    active_index = 0;
    while (active_index < str.length()) {
        result += str[active_index];
        active_index += rows - 1 + rows - 2 + 1;
    }

    // Other rows
    for (size_t i = 1; i <= rows - 2; ++i) {
        active_index = i;
        while (active_index < str.length()) {
            result += str[active_index];
            active_index += rows - 2 + 1;
        }
    }

    // last row
    active_index = rows - 1;
    while (active_index < str.length()) {
        result += str[active_index];
        active_index += rows - 1 + rows - 2 + 1;
    }

    return result;
}

size_t longest_substr_with_uniq_chars(std::string str)
{
    size_t max_substr_len = 0;
    std::map<char, size_t> char_indexes;
    
    size_t substr_win_start = 0;
    for (size_t substr_win_end = 0; substr_win_end < str.length(); ++substr_win_end) {
        if (char_indexes.find(str[substr_win_end]) != char_indexes.end()) {
            // size_t char_index = char_indexes[str[substr_win_end]];
            size_t char_index = char_indexes.find(str[substr_win_end])->second;
            substr_win_start = char_index + 1;
        }

        char_indexes[str[substr_win_end]] = substr_win_end;

        size_t substr_win_len = substr_win_end - substr_win_start + 1;
        max_substr_len = std::max(max_substr_len, substr_win_len);
    }

    return max_substr_len;
}

bool is_parentheses_valid(std::string parens)
{
    std::map<char, char> paren_comp;
    paren_comp['('] = ' ';
    paren_comp[')'] = '(';
    paren_comp['{'] = ' ';
    paren_comp['}'] = '{';
    paren_comp['['] = ' ';
    paren_comp[']'] = '[';

    std::stack<char> stk;
    for (size_t i = 0; i < parens.length(); ++i) {
        if (paren_comp[parens[i]] == ' ') {
            stk.push(parens[i]);
        } else {
            while (!stk.empty() && stk.top() != paren_comp[parens[i]]) {
                stk.pop();
            }

            if (stk.empty()) { return false; }
            stk.pop();
        }

    }

    if (stk.empty()) { return true; }

    return false;
}

std::vector<std::string> split_string(std::string str, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(str);

    std::string item;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) {
            result.push_back(item);
        }
    }

    return result;
}

std::string replace_multiple_spaces(std::string str)
{
    std::string result = "";
    size_t str_index = 0;
    while (1) {
        size_t len = 0;
        while (str[str_index] == ' ' && str_index < str.length()) {
            ++str_index;
            ++len;
        }

        if (len > 0) { result += " "; }

        while (str[str_index] != ' ' && str_index < str.length()) {
            result += str[str_index];
            ++str_index;
        }

        if (str_index >= str.length()) {
            break;
        }
    }

    return result;
}

std::string trim_spaces(std::string str)
{
    size_t len = 0;
    int str_len = str.length();
    int str_index = 0;
    while (str[str_index] == ' ' && str_index < str_len) {
        ++str_index;
        ++len;
    }

    if (len > 0) {
        str.erase(0, len);
    }

    len = 0;
    str_index = str.length() - 1;
    while (str[str_index] == ' ' && str_index >= 0) {
        --str_index;
        ++len;
    }

    if (len > 0) {
        str.erase(str_index + 1, len);
    }

    return str;
}

void string_workings(const std::string str)
{
    std::vector<std::tuple<size_t, size_t>> word_bounds;

    size_t str_index = 0;
    while (1) {
        while (isspace(str[str_index]) && str_index < str.length()) {
            ++str_index;
        }

        size_t start_index = str_index;
        size_t length = 0;
        while (!isspace(str[str_index]) && str_index < str.length()) {
            ++str_index;
            ++length;
        }
        
        if (length != 0) {
            word_bounds.push_back(std::make_tuple(start_index, length));
        }

        if (str_index >= str.length()) { break; }
    }

    for (auto t : word_bounds) {
        // std::cout <<"Start Index : "<<std::get<0>(t)<<", Length : "<<std::get<1>(t);
        std::cout <<str.substr(std::get<0>(t), std::get<1>(t));
        std::cout <<std::endl;
        std::cout <<"Start : "<<std::get<0>(t)<<", Len : "<<std::get<1>(t);
        std::cout <<std::endl;
    }
}

int stoi(std::string digits)
{
    bool neg = false;

    int start_index = 0;
    while (digits[start_index] == ' ') {
        ++start_index;
    }

    if (digits[start_index] == '+') { ++start_index; }
    if (digits[start_index] == '-') { neg = true; ++start_index; }

    int end_index = digits.length() - 1;
    while (digits[end_index] == ' ') {
        --end_index;
    }

    for (int i = end_index; i > start_index; --i) {
        if (digits[i] == '.') {
            end_index = i - 1;
            break;
        }
    }

    size_t pow_of_10 = 1;
    long long sum = 0;
    for (int i = end_index; i >= start_index; --i) {
        sum += ((digits[i] - '0') * pow_of_10);
        pow_of_10 *= 10;
    }

    if (neg) { sum = -sum; }
    if (neg && sum < INT32_MIN) { return INT32_MIN; }
    if (!neg && sum > INT32_MAX) { return INT32_MAX; }

    return sum;
}

std::string reverse_words_2(std::string str)
{
    std::vector<std::tuple<size_t, size_t>> word_start_len;

    size_t str_index = 0;
    while (1) {
        while (str[str_index] == ' ' && str_index < str.length()) {
            ++str_index;
        }

        size_t start_index = str_index;
        size_t len = 0;
        while (str[str_index] != ' ' && str_index < str.length()) {
            ++str_index;
            ++len;
        }

        if (len != 0) {
            word_start_len.push_back(std::make_tuple(start_index, len));
        }

        if (str_index >= str.length()) { break; }
    }

    for (const std::tuple<size_t, size_t> &t : word_start_len) {
        size_t word_start = std::get<0>(t);
        size_t word_len = std::get<1>(t);

        std::reverse(str.begin() + word_start, str.begin() + word_start + word_len);
    }

    return str;
}

std::string space_replacement(std::string str, size_t len, size_t new_len)
{
    size_t no_spaces = 0;
    for (size_t i = 0; i < len; ++i) {
        if (str[i] == ' ') { ++no_spaces; }
    }

    size_t new_str_len = std::min(len + 2 * no_spaces, new_len);
    size_t n_pos = new_str_len - 1;
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] != ' ') {
            str[n_pos--] = str[i];
        } else {
            str[n_pos--] = '0';
            str[n_pos--] = '2';
            str[n_pos--] = '%';
        }
    }

    return str.substr(0, new_str_len);
}

size_t length_of_last_word(const std::string &str)
{
    int str_index = str.length() - 1;
    while (str_index >= 0 && !isalpha(str[str_index])) {
        --str_index;
    }

    size_t last_word_len = 0;
    while (str_index >= 0 && isalpha(str[str_index])) {
        --str_index;
        ++last_word_len;
    }

    return last_word_len;
}

std::string longest_common_prefix(const std::vector<std::string> &strs)
{
    size_t min_len_of_all_strings = INT32_MAX;
    for (const std::string &s : strs) {
        min_len_of_all_strings = std::min(min_len_of_all_strings, s.length());
    }

    std::string longest_common_prefix = "";
    for (size_t j = 0; j < min_len_of_all_strings; ++j) {
        for (size_t i = 1; i < strs.size(); ++i) {
            if (strs[i - 1][j] != strs[i][j]) {
                return longest_common_prefix;
            }
        }

        longest_common_prefix.push_back(strs[0][j]);
    }

    return longest_common_prefix;
}