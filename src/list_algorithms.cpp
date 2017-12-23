#include "list_algorithms.hpp"

void capture_odd_list_items(node<int> *head, list<int> *odd_lst)
{
    if (head == nullptr) {
        return;
    }

    odd_lst->insert(head->data());

    node<int> *t = (head->_next == nullptr ? nullptr : head->_next->_next);
    capture_odd_list_items(t, odd_lst);
}

void capture_even_list_items(node<int> *head, list<int> *even_lst)
{
    if (head == nullptr) {
        return;
    }

    node<int> *t = (head->_next == nullptr ? nullptr : head->_next->_next);
    capture_even_list_items(t, even_lst);

    even_lst->insert(head->data());
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result_node = nullptr;
    ListNode *result_tail = nullptr;

    size_t carry = 0;
    while (l1 != nullptr && l2 != nullptr) {
        int value;
        int result = l1->val + l2->val + carry;
        if (result > 9) {
            value = result % 10;
            carry = 1;
        } else {
            value = result;
            carry = 0;
        }

        if (result_tail == nullptr) {
            result_node = new ListNode(value);
            result_node->next = nullptr;

            result_tail = result_node;
        } else {
            ListNode *new_node = new ListNode(value);
            new_node->next = nullptr;
            
            result_tail->next = new_node;
            result_tail = new_node;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr) {
        int value;
        int result = l1->val + carry;
        if (result > 9) {
            value = result % 10;
            carry = 1;
        } else {
            value = result;
            carry = 0;
        }

        ListNode *new_node = new ListNode(value);
        new_node->next = nullptr;

        result_tail->next = new_node;
        result_tail = new_node;

        l1 = l1->next;
    }

    while (l2 != nullptr) {
        int value;
        int result = l2->val + carry;
        if (result > 9) {
            value = result % 10;
            carry = 1;
        } else {
            value = result;
            carry = 0;
        }

        ListNode *new_node = new ListNode(value);
        new_node->next = nullptr;

        result_tail->next = new_node;
        result_tail = new_node;

        l2 = l2->next;
    }

    if (carry == 1) {
        ListNode *new_node = new ListNode(carry);
        new_node->next = nullptr;

        result_tail->next = new_node;
        result_tail = new_node;
    }

    return result_node;
}

std::string get_task(std::vector<std::string> &tasks, size_t n)
{
    size_t next_start = 0;
    size_t cycle_length = n - 1;

    while (tasks.size() != 1) {
        size_t index_to_remove = (next_start + cycle_length) % tasks.size();
        next_start = index_to_remove % tasks.size();

        tasks.erase(tasks.begin() + index_to_remove);
    }

    return tasks.front();
}