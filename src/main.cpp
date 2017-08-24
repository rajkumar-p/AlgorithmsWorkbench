#include <iostream>
#include "sorting.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    heap_sort(v, std::greater<int>());

    for (auto e : v) {
        std::cout <<e<<"\t";
    }
    std::cout <<std::endl;

    return 0;
}