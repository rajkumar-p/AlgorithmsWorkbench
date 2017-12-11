#include <iostream>
#include <vector>
#include "list_algorithms.hpp"

int main(int argc, char *argv[])
{
    list<int> *lst = new list<int>();
    std::vector<int> v = { 22, 23, 24, 25, 26, 27, 28, 29 };

    lst->insert(v[0]);
    lst->insert(v[1]);
    lst->insert(v[2]);
    lst->insert(v[3]);
    lst->insert(v[4]);
    lst->insert(v[5]);
    lst->insert(v[6]);
    lst->insert(v[7]);

    size_t index = 0;
    std::cout <<v.size()<<std::endl;
    lst->for_each_node([&v, &index](const node<int> *n) {
        std::cout <<n->data()<<std::endl;        
    });

    return 0;
}