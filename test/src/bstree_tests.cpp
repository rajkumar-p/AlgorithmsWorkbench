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

        delete b1;
    }

    SECTION("Insert into a BSTree") {
        bstree<int> *b1 = new bstree<int>();

        REQUIRE(b1->insert(22)->data() == 22);
        REQUIRE(b1->insert(16)->data() == 16);

        bstree_node<int> *same_node = b1->insert(22);
        REQUIRE(same_node->data() == 22);
        REQUIRE(same_node->count() == 2);

        delete b1;
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

        delete bst;
    }

    SECTION("BSTree find()") {
        std::vector<int> nums = {5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22, 20};

        bstree<int> *bst = new bstree<int>(15);
        bst->insert(nums);

        bstree_node<int> *node1 = bst->find(15, bst->root());

        REQUIRE(node1->data() == 15);
        REQUIRE(node1->count() == 1);
        REQUIRE(node1->_left->data() == 5);
        REQUIRE(node1->_right->data() == 16);

        bstree_node<int> *node2 = bst->find(20, bst->root());

        REQUIRE(node2->data() == 20);
        REQUIRE(node2->count() == 2);
        REQUIRE(node2->_left->data() == 18);
        REQUIRE(node2->_right->data() == 23);

        bstree_node<int> *node3 = bst->find(7, bst->root());

        REQUIRE(node3->data() == 7);
        REQUIRE(node3->count() == 1);
        REQUIRE(node3->_left == nullptr);
        REQUIRE(node3->_right == nullptr);

        bstree_node<int> *node4 = bst->find(40, bst->root());

        REQUIRE(node4 == nullptr);

        bstree_node<int> *node5 = bst->parent_of_key(12, bst->root(), bst->pseudo_root());

        REQUIRE(node5->data() == 5);
        REQUIRE(node5->count() == 1);
        REQUIRE(node5->_right->data() == 12);

        bstree_node<int> *node6 = bst->parent_of_key(16, bst->root(), bst->pseudo_root());

        REQUIRE(node6->data() == 15);
        REQUIRE(node6->count() == 1);
        REQUIRE(node6->_right->data() == 16);

        bstree_node<int> *node7 = bst->parent_of_key(40, bst->root(), bst->pseudo_root());

        REQUIRE(node7 == nullptr);

        delete bst;
    }

    SECTION("Min and Max") {
        std::vector<int> nums = {5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22, 20};

        bstree<int> *bst = new bstree<int>(15);
        bst->insert(nums);

        bstree_node<int> *node1 = bst->find(15, bst->root());
        bstree_node<int> *node2 = bst->max(node1);
        bstree_node<int> *node3 = bst->min(node1);

        REQUIRE(node2->data() == 23);
        REQUIRE(node3->data() == 3);

        bstree_node<int> *node4 = bst->find(12, bst->root());
        bstree_node<int> *node5 = bst->max(node4);
        bstree_node<int> *node6 = bst->min(node4);

        REQUIRE(node5->data() == 13);
        REQUIRE(node6->data() == 6);

        bstree_node<int> *node7 = bst->find(22, bst->root());
        bstree_node<int> *node8 = bst->max(node7);
        bstree_node<int> *node9 = bst->min(node7);

        REQUIRE(node8->data() == 22);
        REQUIRE(node9->data() == 22);

        bstree_node<int> *node13 = bst->parent_of_key(12, bst->root(), bst->pseudo_root());
        bstree_node<int> *node14 = bst->parent_of_max(node13->_right, node13);
        bstree_node<int> *node15 = bst->parent_of_min(node13->_right, node13);

        REQUIRE(node13->data() == 5);
        REQUIRE(node13->_right->data() == 12);
        REQUIRE(node14->data() == 12);
        REQUIRE(node14->_right->data() == 13);
        REQUIRE(node15->data() == 10);
        REQUIRE(node15->_left->data() == 6);

        bstree_node<int> *node16 = bst->parent_of_key(22, bst->root(), bst->pseudo_root());
        bstree_node<int> *node17 = bst->parent_of_max(node16->_right, node16);
        bstree_node<int> *node18 = bst->parent_of_min(node16->_right, node16);

        REQUIRE(node16->data() == 21);
        REQUIRE(node16->_right->data() == 22);
        REQUIRE(node17->data() == 21);
        REQUIRE(node17->_right->data() == 22);
        REQUIRE(node18->data() == 21);

        delete bst;
    }

    SECTION("BSTree remove()") {
        std::vector<int> nums = {5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22, 20};

        bstree<int> *bst = new bstree<int>(15);
        bst->insert(nums);

        bst->remove(55);

        std::vector<int> walk_output_vec;
        bst->inorder_walk(bst->root(), [&walk_output_vec](bstree_node<int> const *current) {
            walk_output_vec.push_back(current->data());
        });

        std::vector<int> expected_vec = { 3, 5, 6, 7, 10, 12, 13, 15, 16, 18, 20, 21, 22, 23 };
        REQUIRE(walk_output_vec == expected_vec);

        walk_output_vec.clear();

        bst->remove(7);

        bst->inorder_walk(bst->root(), [&walk_output_vec](bstree_node<int> const *current) {
            walk_output_vec.push_back(current->data());
        });

        expected_vec = { 3, 5, 6, 10, 12, 13, 15, 16, 18, 20, 21, 22, 23 };
        REQUIRE(walk_output_vec == expected_vec);

        walk_output_vec.clear();

        bst->remove(22);

        bst->inorder_walk(bst->root(), [&walk_output_vec](bstree_node<int> const *current) {
            walk_output_vec.push_back(current->data());
        });
        
        expected_vec = { 3, 5, 6, 10, 12, 13, 15, 16, 18, 20, 21, 23 };
        REQUIRE(walk_output_vec == expected_vec);

        walk_output_vec.clear();

        bst->remove(20);

        bst->inorder_walk(bst->root(), [&walk_output_vec](bstree_node<int> const *current) {
            walk_output_vec.push_back(current->data());
        });
        
        expected_vec = { 3, 5, 6, 10, 12, 13, 15, 16, 18, 21, 23 };
        REQUIRE(walk_output_vec == expected_vec);

        delete bst;
    }
}