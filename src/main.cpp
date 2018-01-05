#include <iostream>
#include <vector>
#include "bstree.hpp"

int main(int argc, char *argv[])
{
    // std::vector<int> nums = { 5, 16 };
    std::vector<int> nums = { 5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22 };

    bstree<int> *bst = new bstree<int>(15);
    bst->insert(nums);

    bst->inorder_walk(bst->root(), [](bstree_node<int> const *node) {
        std::cout <<node->data()<<"\t";
    });

    std::cout <<std::endl;

    bstree_node<int> *new_root = bst->invert_btree(bst->root());
    bst->inorder_walk(new_root, [](bstree_node<int> const *node) {
        std::cout <<node->data()<<"\t";
    });

    std::cout <<std::endl;
    return 0;
}
