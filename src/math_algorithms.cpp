#include "math_algorithms.hpp"
#include <cmath>
#include <queue>

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

std::vector<size_t> k_points_closest_to_origin(std::vector<std::tuple<int, int>> &points, size_t k)
{
    struct points_compare {
        bool operator()(const std::tuple<double, size_t> &t1, const std::tuple<double, size_t> &t2) {
            return std::get<0>(t1) > std::get<0>(t2);
        }
    };

    std::priority_queue<std::tuple<double, size_t>, std::vector<std::tuple<double, size_t>>, points_compare> pq;

    for (size_t i = 0; i < points.size(); ++i) {
        int x = std::get<0>(points[i]);
        int y = std::get<1>(points[i]);
        double st_line_dist = sqrt(x * x + y * y);

        pq.push(std::make_tuple(st_line_dist, i));
    }

    std::vector<size_t> closest_points_indexes;
    for (size_t i = 0; i < k; ++i) {
        std::tuple<double, size_t> top_tuple = pq.top();
        closest_points_indexes.push_back(std::get<1>(top_tuple));

        pq.pop();
    }

    return closest_points_indexes;
}