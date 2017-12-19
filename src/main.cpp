#include <iostream>
#include <vector>
#include "dp_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> numbers = { 3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10 };
    std::vector<int> increasing_subsequence = get_longest_increasing_subsequence(numbers);

    for (const int &v : increasing_subsequence) {
        std::cout <<v<<"\t";
    }

    std::cout <<std::endl;

    return 0;
}
