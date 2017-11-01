#include <iostream>
#include "utils.hpp"
#include "bstree.hpp"

int main(int argc, char *argv[])
{
    // std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    // heap_sort(v, v.size(), std::greater<int>());

    // std::vector<int> v10 = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    // std::cout <<selection(v10, 0, v10.size() - 1, 5);
    // std::cout <<std::endl;

    std::vector<int> nums = {5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 21, 7, 22, 20};

    bstree<int> *bst = new bstree<int>(15);
    bst->insert(nums);

    bst->remove(7);
    bst->remove(22);
    bst->remove(20);

    std::vector<int> sorted_vec;
    bst->inorder_walk(bst->root(), [&sorted_vec](bstree_node<int> const *current) {
        // sorted_vec.push_back(current->data());
        std::cout <<current->data()<<", ";
    });

    std::cout <<std::endl;

    return 0;
}