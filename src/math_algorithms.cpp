#include "math_algorithms.hpp"
#include <cmath>

bool is_prime(int number)
{
    if (number <= 1) { return false; }
    if (number == 2) { return true; }
    if (number % 2 == 0) { return false; }

    int sq_rt = sqrt(double(number));

    for (int i = 3; i <= sq_rt; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

std::vector<bool> all_primes_till(int number)
{
    std::vector<bool> primes(number + 1, true);
    primes[0] = false;    
    primes[1] = false;

    int sq_rt = sqrt(double(number));
    for (int i = 2; i <= sq_rt; ++i) {
        if (is_prime(i)) {
            for (int j = i*i; j <= number; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;
}