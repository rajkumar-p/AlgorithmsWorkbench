#include "catch.hpp"
#include "queue.hpp"
#include <vector>

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

        q.dequeue();

        REQUIRE(q.front() == 22);
        REQUIRE(q.size() == 3);

        q.dequeue();
        q.dequeue();
        q.dequeue();

        REQUIRE(q.front() == int());
        REQUIRE(q.size() == 0);
    }

    SECTION("Queue items() tests") {
        std::vector<int> v = { 5, 22, 7, 30, 3, 65 };
        queue<int> q;

        for (auto e : v) {
            q.enqueue(e);
        }

        std::vector<int> v_items = q.items();
        REQUIRE(v == v_items);
        REQUIRE(v.size() == v_items.size());
        REQUIRE(v_items.size() == 6);

        q.dequeue();
        v.erase(v.begin());

        q.dequeue();
        v.erase(v.begin());

        v_items = q.items();
        REQUIRE(v == v_items);
        REQUIRE(v.size() == v_items.size());
        REQUIRE(v_items.size() == 4);
    }
}