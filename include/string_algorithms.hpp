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
std::string reverse_words(std::string &s);

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
std::vector<std::string> lengthOfLongestSubstring(const std::string s);

#endif