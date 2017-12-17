#include <iostream>
#include <vector>
#include "math_algorithms.hpp"

int main(int argc, char *argv[])
{
    int a = 9, b = 6;
    std::cout <<"gcd("<<a<<", "<<b<<")"<<gcd(a, b)<<std::endl;
    std::cout <<"lcm("<<a<<", "<<b<<")"<<lcm(a, b)<<std::endl;

    return 0;
}