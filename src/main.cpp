#include <iostream>
#include <vector>
#include "list_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> numbers;
    ListNode *l1 = nullptr;
    ListNode *l1_tail = nullptr;

    numbers = { 2, 4, 3, 9, 9, 9 };
    for (const int &n : numbers) {
        if (l1_tail == nullptr) {
            l1 = new ListNode(n);
            l1->next = nullptr;

            l1_tail = l1;
        } else {
            ListNode *new_node = new ListNode(n);
            new_node->next = nullptr;

            l1_tail->next = new_node;
            l1_tail = new_node;
        }
    }

    ListNode *l2 = nullptr;
    ListNode *l2_tail = nullptr;

    numbers = { 5, 6, 7 };
    for (const int &n : numbers) {
        if (l2_tail == nullptr) {
            l2 = new ListNode(n);
            l2->next = nullptr;

            l2_tail = l2;
        } else {
            ListNode *new_node = new ListNode(n);
            new_node->next = nullptr;

            l2_tail->next = new_node;
            l2_tail = new_node;
        }
    }

    std::cout <<"L1 Data : "<<std::endl;
    ListNode *l1_copy = l1;
    while (l1_copy != nullptr) {
        std::cout <<l1_copy->val<<"\t";
        l1_copy = l1_copy->next;
    }
    std::cout <<std::endl;

    std::cout <<"L2 Data : "<<std::endl;
    ListNode *l2_copy = l2;
    while (l2_copy != nullptr) {
        std::cout <<l2_copy->val<<"\t";
        l2_copy = l2_copy->next;
    }
    std::cout <<std::endl;

    ListNode *result = addTwoNumbers(l1, l2);
    std::vector<int> result_to_compare = { 7, 0, 1, 0, 0, 0, 1 };

    std::cout <<"Result Data : "<<std::endl;
    ListNode *result_copy = result;
    while (result_copy != nullptr) {
        std::cout <<result_copy->val<<"\t";
        result_copy = result_copy->next;
    }
    std::cout <<std::endl;

    while (l1 != nullptr) {
        ListNode *to_delete = l1;
        l1 = l1->next;

        delete to_delete;
    }

    while (l2 != nullptr) {
        ListNode *to_delete = l2;
        l2 = l2->next;

        delete to_delete;
    }

    while (result != nullptr) {
        ListNode *to_delete = result;
        result = result->next;

        delete to_delete;
    }

    return 0;
}
