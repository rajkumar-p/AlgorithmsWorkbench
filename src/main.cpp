#include <iostream>
#include "utils.hpp"
#include "searching.hpp"
#include "sorting.hpp"

int main(int argc, char *argv[])
{
    // std::vector<int> v = { 2, 8, 7, 1, 3, 5, 6, 4 };
    // quick_sort(v, 0, v.size() - 1, std::less<int>());

    // for (auto e : v) {
    //     std::cout <<e<<"\t";
    // }
    // std::cout <<std::endl;

    std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    std::cout <<select(v, 0, v.size() - 1, 10)<<std::endl;

    return 0;
}