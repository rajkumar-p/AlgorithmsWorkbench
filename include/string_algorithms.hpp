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

#endif