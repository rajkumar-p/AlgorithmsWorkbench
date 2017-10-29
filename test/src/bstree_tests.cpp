#include "catch.hpp"
#include "bstree.hpp"

TEST_CASE("Checking Bstree Implementation", "[BSTree]")
{
    SECTION("BSTree Creation") {
        bstree<int> *b1 = new bstree<int>();
        
        bstree_node<std::string> *b2_node = new bstree_node<std::string>("Alice");
        bstree<std::string> *b2 = new bstree<std::string>(b2_node);

        bstree<int> *b3 = new bstree<int>(22);

        REQUIRE(b1->pseudo_root()->data() == int());
        REQUIRE(b2->pseudo_root()->data() == std::string());
        REQUIRE(b3->pseudo_root()->data() == int());

        REQUIRE(b1->root() == nullptr);
        REQUIRE(b2->root()->data() == "Alice");
        REQUIRE(b3->root()->data() == 22);
    }

    SECTION("Insert into a BSTree") {
        bstree<int> *b1 = new bstree<int>();

        REQUIRE(b1->insert(22)->data() == 22);
        REQUIRE(b1->insert(16)->data() == 16);

        bstree_node<int> *same_node = b1->insert(22);
        REQUIRE(same_node->data() == 22);
        REQUIRE(same_node->count() == 2);
    }
}