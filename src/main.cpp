#include <iostream>
#include <vector>
#include "list_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> elements = { 5, 4, 3, 2, 1 };

    ListNode *root = insert_data(elements);
    for_each_node(root, [](const ListNode *node) {
        std::cout <<node->val<<"\t";
    });
    std::cout <<std::endl;

    ListNode *rev_root = reverse_list(root);
    for_each_node(rev_root, [](const ListNode *node) {
        std::cout <<node->val<<"\t";
    });
    std::cout <<std::endl;

    delete_list(rev_root);

    return 0;
}
