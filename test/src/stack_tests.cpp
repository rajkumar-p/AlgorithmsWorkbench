#include "catch.hpp"
#include "stack.hpp"

TEST_CASE("Stack Tests", "[Stack Tests - Implementation]")
{
    SECTION("Basic stack tests") {
        stack<int> s(2);
        REQUIRE(s.get_size() == 2);
        REQUIRE(s.get_length() == 0);

        s.push(5);
        REQUIRE(s.get_size() == 2);
        REQUIRE(s.get_length() == 1);
        REQUIRE(s.top() == 5);

        s.push(2);
        REQUIRE(s.get_size() == 2);
        REQUIRE(s.get_length() == 2);
        REQUIRE(s.top() == 2);

        s.push(22);
        REQUIRE(s.get_size() == 4);
        REQUIRE(s.get_length() == 3);
        REQUIRE(s.top() == 22);

        s.pop();
        REQUIRE(s.get_size() == 4);
        REQUIRE(s.get_length() == 2);
        REQUIRE(s.top() == 2);

        s.pop();
        REQUIRE(s.get_size() == 4);
        REQUIRE(s.get_length() == 1);
        REQUIRE(s.top() == 5);

        s.pop();
        REQUIRE(s.get_size() == 4);
        REQUIRE(s.get_length() == 0);
        REQUIRE(s.top() == int());
    }

    SECTION("Stack copy ctor and copy assignment tests") {
        stack<double> s(4);

        // std::vector<double> v = { -121.67, 102.75, 153.91, -165.78, -97.64, -92.50, 149.84, 49.42, 58.75, -51.81 };
        s.push(-121.67);
        s.push(102.75);
        s.push(-51.81);
        s.push(-97.64);

        stack<double> another_s(s);

        REQUIRE(another_s.get_size() == s.get_size());
        REQUIRE(s.get_size() == 4);
        REQUIRE(another_s.get_length() == s.get_length());
        REQUIRE(s.get_length() == 4);
        REQUIRE(another_s.top() == s.top());
        REQUIRE(s.top() == -97.64);

        s.push(153.91);
        REQUIRE(s.get_size() == 8);
        REQUIRE(s.get_length() == 5);
        REQUIRE(s.top() == 153.91);

        another_s = s;
        REQUIRE(another_s.get_size() == s.get_size());
        REQUIRE(s.get_size() == 8);
        REQUIRE(another_s.get_length() == s.get_length());
        REQUIRE(s.get_length() == 5);
        REQUIRE(another_s.top() == s.top());
        REQUIRE(s.top() == 153.91);

        another_s.push(-165.78);
        REQUIRE(another_s.get_size() == 8);
        REQUIRE(another_s.get_length() == 6);
        REQUIRE(another_s.top() == -165.78);
    }
}