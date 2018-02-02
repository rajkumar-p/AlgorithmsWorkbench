#ifndef MATH_ALGORITHMS_HPP
#define MATH_ALGORITHMS_HPP

#include <vector>

bool is_prime(int number);
std::vector<bool> all_primes_till(int number);

int gcd(int a, int b);
int lcm(int a, int b);

std::vector<size_t> k_points_closest_to_origin(std::vector<std::tuple<int, int>> &points, size_t k);

#endif