#include <iostream>
#include <vector>
#include "list_algorithms.hpp"

int main(int argc, char *argv[])
{
    list<int> *lst = new list<int>();
    std::vector<int> v = { 21, 22, 23, 24, 25, 26, 27, 28, 29 };

    lst->insert(v[0]);
    lst->insert(v[1]);
    lst->insert(v[2]);
    lst->insert(v[3]);
    lst->insert(v[4]);
    lst->insert(v[5]);
    lst->insert(v[6]);
    lst->insert(v[7]);
    lst->insert(v[8]);

    list<int> *odd_lst = new list<int>();
    list<int> *even_lst = new list<int>();

    if (lst->_head != nullptr) {
        capture_odd_list_items(lst->_head, odd_lst);
        capture_even_list_items(lst->_head->_next, even_lst);
    }

    std::cout <<"Printing odd list : "<<std::endl;
    odd_lst->for_each_node([](const node<int> *n) {
        std::cout <<n->data()<<"\t";
    });

    std::cout <<std::endl;
    std::cout <<"Printing even list : "<<std::endl;
    even_lst->for_each_node([](const node<int> *n) {
        std::cout <<n->data()<<"\t";
    });

    std::cout <<std::endl;

    delete lst;
    delete odd_lst;
    delete even_lst;

    return 0;
}