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
}