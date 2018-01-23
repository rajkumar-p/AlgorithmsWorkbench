#include <iostream>
#include <vector>
#include <cmath>
#include "string_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::string> words = {
        "organisations", "perhaps", "the", "automation", "monitoring",
        "orchestration", "skillsets", "are", "of", "extremely", 
        "then", "I", "components", "state", "expect"
    };

    std::vector<size_t> words_lengths;
    for (const std::string &word : words) {
        words_lengths.push_back(word.length());
    }

    for (size_t i = 0; i < words.size(); ++i) {
        std::cout <<words[i]<<" : "<<words_lengths[i]<<std::endl;
    }

    std::cout <<std::endl<<std::endl;
    std::cout <<reverse_words_2("           the sky   is        blue    ");
    std::cout <<std::endl;

    return 0;
}
