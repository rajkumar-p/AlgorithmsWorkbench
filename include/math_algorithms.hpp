#ifndef MATH_ALGORITHMS_HPP
#define MATH_ALGORITHMS_HPP

#include <vector>
#include <cmath>

bool is_prime(int number);
std::vector<bool> all_primes_till(int number);

int gcd(int a, int b);
int lcm(int a, int b);

int to_decimal(int number, int base);
int from_decimal(const int number, const int base);
std::vector<size_t> k_points_closest_to_origin(std::vector<std::tuple<int, int>> &points, size_t k);

double angle_between_points(std::tuple<int, int> &point1, std::tuple<int, int> &point2);

#endif