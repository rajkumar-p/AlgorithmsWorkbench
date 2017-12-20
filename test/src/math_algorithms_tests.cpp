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
}