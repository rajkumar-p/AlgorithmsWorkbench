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

        delete lst;
    }
    SECTION("List Odd Even Seperation") {
        list<int> *lst = new list<int>();
        std::vector<int> v = { 21, 22, 23, 24, 25, 26, 27, 28, 29 };

        lst->insert(v[0]);
        lst->insert(v[1]);
        lst->insert(v[2]);
        lst->insert(v[3]);
        lst->insert(v[4]);
        lst->insert(v[5]);
        lst->insert(v[6]);
        lst->insert(v[7]);
        lst->insert(v[8]);

        list<int> *odd_lst = new list<int>();
        list<int> *even_lst = new list<int>();

        if (lst->_head != nullptr) {
            capture_odd_list_items(lst->_head, odd_lst);
            capture_even_list_items(lst->_head->_next, even_lst);
        }

        std::vector<int> odd = { 21, 23, 25, 27, 29 };
        std::vector<int> even = { 22, 24, 26, 28 };

        size_t odd_index = 0;
        odd_lst->for_each_node([&odd, &odd_index](const node<int> *n) {
            REQUIRE(n->data() == odd[odd_index++]);
        });

        size_t even_index = even.size() - 1;
        even_lst->for_each_node([&even, &even_index](const node<int> *n) {
            REQUIRE(n->data() == even[even_index--]);
        });

        delete lst;
        delete odd_lst;
        delete even_lst;
    }
}