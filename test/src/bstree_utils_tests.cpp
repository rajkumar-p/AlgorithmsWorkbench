#include "catch.hpp"
#include "bstree_utils.hpp"

TEST_CASE("Checking Bstree Utils Implementation", "[BSTree Utils]")
{
    SECTION("BSTree Copy Node") {
        bstree_node<int> *n1 = new bstree_node<int>(22);
        bstree_node<int> *n2 = new bstree_node<int>(90);

        copy_node(n1, n2);

        REQUIRE(n1->data() == n2->data());
        REQUIRE(n1->count() == n2->count());
        REQUIRE(n2->_left == nullptr);
        REQUIRE(n2->_right == nullptr);

        delete n1;
        delete n2;

        bstree_node<std::string> *n3 = new bstree_node<std::string>("Hello");
        bstree_node<std::string> *n4 = new bstree_node<std::string>("World");

        copy_node(n3, n4);

        REQUIRE(n3->data() == n4->data());
        REQUIRE(n3->count() == n4->count());
        REQUIRE(n4->_left == nullptr);
        REQUIRE(n4->_right == nullptr);

        delete n3;
        delete n4;
    }

    SECTION("BSTree Duplicate") {
        std::vector<int> nums = {5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22, 20};

        bstree<int> *bst = new bstree<int>(15);
        bst->insert(nums);

        bstree<int> *bst_dup = new bstree<int>(new bstree_node<int>(*bst->root()));
        duplicate_tree(bst->root(), bst_dup->root());

        std::vector<int> bst_inorder_vec, bst_dup_inorder_vec; 

        bst->inorder_walk(bst->root(), [&bst_inorder_vec](bstree_node<int> const *current) {
            bst_inorder_vec.push_back(current->data());
        });

        bst_dup->inorder_walk(bst_dup->root(), [&bst_dup_inorder_vec](bstree_node<int> const *current) {
            bst_dup_inorder_vec.push_back(current->data());
        });

        REQUIRE(bst_inorder_vec == bst_dup_inorder_vec);
    }
}