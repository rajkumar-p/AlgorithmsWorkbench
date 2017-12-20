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

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int to_decimal(int number, int base)
{
    int n = number;
    int sum = 0, power = 0;

    while (n != 0) {
        int rem = n % 10;
        sum += (rem * pow(base, power));

        ++power;
        n = n / 10;
    }

    return sum;
}

int from_decimal(const int number, const int base)
{
    int n = number;
    int sum = 0, power = 0;

    while (n != 0) {
        int rem = n % base;
        sum += (rem * pow(10, power));

        ++power;
        n = n / base;
    }

    return sum;
}