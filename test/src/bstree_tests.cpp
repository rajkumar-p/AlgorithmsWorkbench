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

        //TODO: Test insert of vector elements
    }

    SECTION("BSTree tree traversal") {
        std::vector<int> nums = {5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22, 20};

        bstree<int> *bst = new bstree<int>(15);
        bst->insert(nums);

        std::vector<int> walk_output_vec;
        bst->inorder_walk(bst->root(), [&walk_output_vec](bstree_node<int> const *current) {
            walk_output_vec.push_back(current->data());
        });

        REQUIRE(std::is_sorted(walk_output_vec.begin(), walk_output_vec.end()) == true);
        walk_output_vec.clear();

        std::vector<int> preorder_vec = { 3, 7, 6, 10, 13, 12, 5, 18, 22, 21, 23, 20, 16, 15 };
        bst->preorder_walk(bst->root(), [&walk_output_vec](bstree_node<int> const *current) {
            walk_output_vec.push_back(current->data());
        });

        REQUIRE(walk_output_vec == preorder_vec);
        walk_output_vec.clear();

        std::vector<int> postorder_vec = { 15, 5, 3, 12, 10, 6, 7, 13, 16, 20, 18, 23, 21, 22 };
        bst->postorder_walk(bst->root(), [&walk_output_vec](bstree_node<int> const *current) {
            walk_output_vec.push_back(current->data());
        });

        REQUIRE(walk_output_vec == postorder_vec);
        walk_output_vec.clear();
    }

    SECTION("BSTree find()") {
        std::vector<int> nums = {5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22, 20};

        bstree<int> *bst = new bstree<int>(15);
        bst->insert(nums);

        bstree_node<int> *node1 = bst->find(bst->root(), 15);

        REQUIRE(node1->data() == 15);
        REQUIRE(node1->count() == 1);
        REQUIRE(node1->_left->data() == 5);
        REQUIRE(node1->_right->data() == 16);

        bstree_node<int> *node2 = bst->find(bst->root(), 20);

        REQUIRE(node2->data() == 20);
        REQUIRE(node2->count() == 2);
        REQUIRE(node2->_left->data() == 18);
        REQUIRE(node2->_right->data() == 23);

        bstree_node<int> *node3 = bst->find(bst->root(), 7);

        REQUIRE(node3->data() == 7);
        REQUIRE(node3->count() == 1);
        REQUIRE(node3->_left == nullptr);
        REQUIRE(node3->_right == nullptr);
    }
}