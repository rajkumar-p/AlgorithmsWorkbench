#include <iostream>
#include "counting_sort.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> v = { 2, 5, 3, 0, 2, 3, 0, 3 };
    std::vector<int> sorted_v = counting_sort(v, 5);

    for (const int e : sorted_v) {
        std::cout <<e<<"\t";
    }

    std::cout <<std::endl;

    return 0;
}