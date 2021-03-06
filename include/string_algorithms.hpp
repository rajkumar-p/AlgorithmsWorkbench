#ifndef STRING_ALGORITHMS_HPP
#define STRING_ALGORITHMS_HPP

#include <vector>
#include <string>

// https://leetcode.com/problems/shortest-completing-word/description/
std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string> &words);

// https://leetcode.com/problems/implement-strstr/description/
int strstr(std::string haystack, std::string needle);

// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
std::vector<size_t> kmp(const std::string text, const std::string pattern);
std::vector<size_t> compute_prefix_for(const std::string pattern);

// https://leetcode.com/problems/reverse-words-in-a-string/description/
std::string reverse_words(std::string &str);

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
std::vector<std::string> lengthOfLongestSubstring(const std::string s);

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
std::vector<std::string> letter_combinations(const std::string &digits);

// https://leetcode.com/problems/generate-parentheses/description/
std::vector<std::string> generate_parenthesis(const size_t n);

// https://leetcode.com/problems/reverse-string/description/
std::string reverse_string(std::string str);

// https://leetcode.com/problems/zigzag-conversion/description/
std::string zig_zag_convert(std::string str, size_t rows);

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
size_t longest_substr_with_uniq_chars(std::string str);

// https://leetcode.com/problems/valid-parentheses/description/
bool is_parentheses_valid(std::string parens);

// https://leetcode.com/problems/string-to-integer-atoi/description/
int stoi(std::string digits);

// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
std::string reverse_words_2(std::string str);

// https://algorithm.yuanbin.me/zh-hans/string/space_replacement.html
std::string space_replacement(std::string str, size_t len, size_t new_len);

// https://algorithm.yuanbin.me/zh-hans/string/length_of_last_word.html
size_t length_of_last_word(const std::string &str);

// https://leetcode.com/problems/longest-common-prefix/description/
std::string longest_common_prefix(const std::vector<std::string> &strs);

// https://leetcode.com/problems/minimum-window-substring/description/
std::string min_window_substring(const std::string &str, const std::string &substr);

// https://leetcode.com/problems/group-anagrams/
std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string> &strs);

// https://leetcode.com/problems/decode-ways/description/
size_t get_num_decodings(const std::string &str);

std::vector<std::string> split_string(std::string str, char delim);
std::string replace_multiple_spaces(std::string str);
std::string trim_spaces(std::string str);

void string_workings(std::string str);

#endif