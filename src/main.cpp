#include <iostream>
#include "utils.hpp"
#include "sorting.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> v = { 2, 8, 7, 1, 3, 5, 6, 4 };
    partition(v, 0, v.size() - 1, std::less<int>());

    for (auto e : v) {
        std::cout <<e<<"\t";
    }
    std::cout <<std::endl;

    return 0;
}