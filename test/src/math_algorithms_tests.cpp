#include "catch.hpp"
#include "math_algorithms.hpp"

TEST_CASE("Checking Math Algorithms Implementation", "[Math Algorithms]")
{
    SECTION("is_prime() tests") {
        REQUIRE(is_prime(2) == true);
        REQUIRE(is_prime(3) == true);
        REQUIRE(is_prime(17) == true);

        REQUIRE(is_prime(-1) == false);
        REQUIRE(is_prime(1) == false);
        REQUIRE(is_prime(4) == false);
        REQUIRE(is_prime(6) == false);
        REQUIRE(is_prime(9) == false);
        REQUIRE(is_prime(15) == false);
    }

    SECTION("all_primes_till() tests") {
        std::vector<bool> primes = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 };
        REQUIRE(all_primes_till(20) == primes);

        primes = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 };
        REQUIRE(all_primes_till(50) == primes);
    }

    SECTION("gcd() and lcm() tests") {
        REQUIRE(gcd(2336, 1314) == 146);
        REQUIRE(lcm(2336, 1314) == 21024);

        REQUIRE(gcd(9, 6) == 3);
        REQUIRE(lcm(9, 6) == 18);
    }

    SECTION("to_decimal() tests") {
        REQUIRE(to_decimal(1011, 2) == 11);
        REQUIRE(to_decimal(0000, 2) == 0);
        REQUIRE(to_decimal(1111, 2) == 15);

        REQUIRE(to_decimal(22, 7) == 16);
        REQUIRE(to_decimal(34, 7) == 25);
        REQUIRE(to_decimal(123, 7) == 66);
    }

    SECTION("from_decimal() tests") {
        REQUIRE(from_decimal(11, 2) == 1011);
        REQUIRE(from_decimal(0, 2) == 0);
        REQUIRE(from_decimal(15, 2) == 1111);

        REQUIRE(from_decimal(16, 7) == 22);
        REQUIRE(from_decimal(25, 7) == 34);
        REQUIRE(from_decimal(66, 7) == 123);
    }

    SECTION("k_points_closest_to_origin(points, k)") {
        std::vector<std::tuple<int, int>> points;

        points.push_back(std::make_tuple(-2, 4));
        points.push_back(std::make_tuple(0, -2));
        points.push_back(std::make_tuple(-1, 0));
        points.push_back(std::make_tuple(3, 5));
        points.push_back(std::make_tuple(-2, -3));
        points.push_back(std::make_tuple(3, 2));

        size_t k = 3;
        std::vector<size_t> test_result = { 2, 1, 4 };
        std::vector<size_t> closest_points = k_points_closest_to_origin(points, k);
        REQUIRE(closest_points.size() == k);
        REQUIRE(closest_points == test_result);
    }

    SECTION("angle_between_two_points(point1, point2)") {
        std::tuple<int, int> point1;
        std::tuple<int, int> point2;

        point1 = std::make_tuple(5, 0);
        point2 = std::make_tuple(0, 5);

        // REQUIRE(angle_between_points(point1, point2) == 90.0456493067);

        point1 = std::make_tuple(5, 0);
        point2 = std::make_tuple(1, 5);

        // REQUIRE(angle_between_points(point1, point2) == 78.72);

        point1 = std::make_tuple(5, 0);
        point2 = std::make_tuple(1, -5);

        // REQUIRE(angle_between_points(point1, point2) == 78.72);
    }
}