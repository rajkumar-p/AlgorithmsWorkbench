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

double angle_between_points(std::tuple<int, int> &point1, std::tuple<int, int> &point2)
{
    // Find the vector dot product
    // A.B = |A||B| Cos(Θ)
    int x1 = std::get<0>(point1);
    int y1 = std::get<1>(point1);

    int x2 = std::get<0>(point2);
    int y2 = std::get<1>(point2);

    double dot_product = (x1 * x2) + (y1 * y2);
    double cos_theta =  dot_product == 0 ? 0 : dot_product / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
    double angle_in_radians = acos(cos_theta);
    double angle_in_degrees = angle_in_radians * 180 / 3.14;

    return angle_in_degrees;
}