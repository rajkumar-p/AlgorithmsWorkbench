#include "catch.hpp"
#include "list_algorithms.hpp"
#include <vector>

TEST_CASE("Checking List Implementation", "[List]") {
    SECTION("List Insert") {
        list<int> *lst = new list<int>();
        std::vector<int> v = { 22, 23, 24, 25, 26, 27, 28, 29 };

        lst->insert(v[0]);
        lst->insert(v[1]);
        lst->insert(v[2]);
        lst->insert(v[3]);
        lst->insert(v[4]);
        lst->insert(v[5]);
        lst->insert(v[6]);
        lst->insert(v[7]);

        REQUIRE(lst->size() == 8);

        size_t index = 0;
        lst->for_each_node([&v, &index](const node<int> *n) {
            REQUIRE(n->data() == v[index++]);
        });
    }
}