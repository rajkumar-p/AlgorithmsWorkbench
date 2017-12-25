#include <iostream>
#include <vector>
#include "dp_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<size_t> coins;
    size_t sum;

    coins = { 1, 3, 5 };
    sum = 11;

    min_coin_change(coins, sum);
    return 0;
}
