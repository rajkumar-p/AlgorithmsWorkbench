#include <iostream>
#include "utils.hpp"
#include "selection.hpp"

int main(int argc, char *argv[])
{
    // std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    // heap_sort(v, v.size(), std::greater<int>());

    std::vector<int> v10 = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    std::cout <<selection(v10, 0, v10.size() - 1, 5);
    std::cout <<std::endl;

    return 0;
}