#include <iostream>
#include <vector>
#include "other_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<size_t> temps = { 73, 74, 75, 71, 69, 72, 76, 73 };

    std::vector<size_t> result = get_next_high_for_each(temps);

    std::cout <<std::endl;

    return 0;
}
