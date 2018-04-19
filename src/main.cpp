#include <iostream>
#include <vector>
#include <queue>
#include "dp_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::map<size_t, size_t> len_and_prices;
    // std::vector<std::tuple<size_t, size_t>> len_and_prices;
    std::vector<std::tuple<size_t, size_t>> cuts;

    len_and_prices = { {1, 1}, {2, 5},{3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30} };

    cuts = cut_rod(len_and_prices, 8);
    for (size_t i = 0; i < cuts.size(); ++i) {
        std::cout <<std::get<0>(cuts[i])<<", "<<std::get<1>(cuts[i])<<std::endl;
        // REQUIRE(std::get<0>(result_to_check[i]) == std::get<0>(cuts[i]));
        // REQUIRE(std::get<1>(result_to_check[i]) == std::get<1>(cuts[i]));
    }

    return 0;
}