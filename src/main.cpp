#include <iostream>
#include <vector>
#include <cmath>
#include "dp_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::string> words = {
        "organisations", "perhaps", "the", "automation", "monitoring",
        "orchestration", "skillsets", "are", "of", "extremely", 
        "then", "I", "components", "state", "expect"
    };

    // std::vector<size_t> words_lengths;
    // for (const std::string &word : words) {
    //     words_lengths.push_back(word.length());
    // }

    // for (size_t i = 0; i < words.size(); ++i) {
    //     std::cout <<words[i]<<" : "<<words_lengths[i]<<std::endl;
    // }

    // words = { "aaa", "bb", "cc", "ddddd" };
    auto t = text_justification(words, 19);

    return 0;
}
