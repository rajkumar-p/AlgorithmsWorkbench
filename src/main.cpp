#include <iostream>
#include <vector>
#include <cmath>
#include "other_algorithms.hpp"

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


    std::vector<size_t> heights;
    heights = { 9, 5, 2, 1, 3, 5, 4, 7, 2, 6 };

    size_t area = trapping_rain_water_in_histogram(heights);
    return 0;
}
