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