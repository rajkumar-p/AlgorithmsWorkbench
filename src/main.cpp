#include <iostream>
#include <vector>
#include "math_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<bool> primes = all_primes_till(50);

    for(size_t i = 0; i < primes.size(); ++i) {
        if (primes[i] == true) {
            std::cout <<i<<"\t";
        }
    }

    std::cout <<std::endl;

    return 0;
}