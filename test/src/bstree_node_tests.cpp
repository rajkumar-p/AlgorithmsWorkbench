#include "catch.hpp"
#include "bstree_node.hpp"

TEST_CASE("Checking Bstree Node Implementation", "[BSTreeNode]")
{
    SECTION("Basic btree tests") {
        bstree_node<std::string> *node = new bstree_node<std::string>("Alice");

        REQUIRE(node->data() == "Alice");
        REQUIRE(node->count() == 1);
        REQUIRE(node->_left == nullptr);
        REQUIRE(node->_right == nullptr);

        node->increment_count();
        node->increment_count();

        REQUIRE(node->data() == "Alice");
        REQUIRE(node->count() == 3);
        REQUIRE(node->_left == nullptr);
        REQUIRE(node->_right == nullptr);

        node->set_data("Bob");
        node->set_count(1);

        REQUIRE(node->data() == "Bob");
        REQUIRE(node->count() == 1);
        REQUIRE(node->_left == nullptr);
        REQUIRE(node->_right == nullptr);

        delete node;
    }
}