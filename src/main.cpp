#include <iostream>
#include "utils.hpp"
#include "heap_sort.hpp"

int main(int argc, char *argv[])
{
    // std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    // heap_sort(v, v.size(), std::greater<int>());

    std::string input_file_name = "/Users/raj/Projects/Cpp/AlgorithmsWorkbench/test/res/10_input.in";
    std::vector<int> v10;

    put_into_vector(v10, input_file_name);

    heap_sort(v10, v10.size(), std::greater<int>());

    for (const int e : v10) {
        std::cout <<e<<"\t";
    }

    std::cout <<std::endl;
    
    std::cout <<std::is_sorted(v10.begin(), v10.end(), std::greater<int>());

    return 0;
}