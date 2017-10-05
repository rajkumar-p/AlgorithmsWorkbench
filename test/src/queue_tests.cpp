#include "catch.hpp"
#include "queue.hpp"

TEST_CASE("Queue Tests", "[Queue Tests - Implementation]")
{
    SECTION("Basic queue tests") {
        queue<int> q;

        REQUIRE(q.size() == 0);
        REQUIRE(q.empty() == true);

        q.enqueue(5);
        REQUIRE(q.front() == 5);
        REQUIRE(q.size() == 1);
        
        q.enqueue(22);
        q.enqueue(7);
        q.enqueue(30);

        REQUIRE(q.front() == 5);
        REQUIRE(q.size() == 4);
    }
}