#include <iostream>
#include "utils.hpp"
#include "sorting.hpp"

int main(int argc, char *argv[])
{
    // std::string input_file_name = "/Users/raj/Projects/Cpp/AlgorithmsWorkbench/test/res/5_custom.in";
    // std::vector<int> v10;

    // put_into_vector(v10, input_file_name);
    // heap_sort(v10, std::greater<int>());

    std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    make_heap(v, std::greater<int>());

    bool res = is_heap(v, 0, std::greater<int>());

    // for (auto e : v) {
    //     std::cout <<e<<"\t";
    // }
    // std::cout <<std::endl;

    return 0;
}