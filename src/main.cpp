#include <iostream>
#include <vector>
#include "dp_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> numbers = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    max_subarray_struct max_subarray = get_max_subarray_properties(numbers);

    std::cout <<"Sum : "<<max_subarray.sum()<<", Start_index : "<<max_subarray.start_index()<<", End_index : "<<max_subarray.end_index()<<std::endl;

    return 0;
}