#include <iostream>
#include "utils.hpp"
#include "sorting.hpp"

int main(int argc, char *argv[])
{
    std::string input_file_name = "/Users/raj/Projects/Cpp/AlgorithmsWorkbench/test/res/5_custom.in";
    std::vector<int> v5;

    put_into_vector(v5, input_file_name);

    int p;
    std::vector<int>::iterator iter;

    p = partition(v5, 0, v5.size() - 1, std::greater<int>());
    iter = std::min_element(v5.begin(), v5.begin() + p + 1, std::greater<int>());

    std::cout <<*iter<<std::endl;

    // std::vector<int> v = { 2, 8, 7, 1, 3, 5, 6, 4 };
    // quick_sort(v, 0, v.size() - 1, std::less<int>());

    // for (auto e : v) {
    //     std::cout <<e<<"\t";
    // }
    // std::cout <<std::endl;

    return 0;
}