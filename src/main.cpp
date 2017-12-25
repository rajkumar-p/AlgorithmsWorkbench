#include <iostream>
#include <vector>
#include "dp_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::pair<size_t, size_t>> len_and_prices;
    std::vector<std::pair<size_t, size_t>> cuts;
    std::vector<std::pair<size_t, size_t>> result_to_check;

    len_and_prices = { {1, 1}, {2, 5},{3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30} };

    result_to_check = { {2, 5}, {2, 5} };
    cuts = cut_rod(len_and_prices, 8);

    return 0;
}
