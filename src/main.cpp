#include <iostream>
#include <vector>
#include "string_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::string text;
    std::string pattern;
    std::vector<size_t> result;

    text = "aaaaabaaaba";
    pattern = "aaaa";
    result = kmp(text, pattern);

    return 0;
}
