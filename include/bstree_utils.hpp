#ifndef BSTREE_UTILS_HPP
#define BSTREE_UTILS_HPP

#include "bstree.hpp"

template<typename T>
void copy_node(bstree_node<T> const *from, bstree_node<T> *to);

template<typename T>
void duplicate_tree(bstree_node<T> const *from, bstree_node<T> *to);

template<typename T>
void copy_node(bstree_node<T> const *from, bstree_node<T> *to)
{
    if (from == nullptr) {
        to = nullptr;
        return;
    }

    to->set_data(from->data());
    to->set_count(from->count());

    to->_left = nullptr;
    to->_right = nullptr;
}

template<typename T>
void duplicate_tree(bstree_node<T> const *from, bstree_node<T> *to)
{
    if (from == nullptr) {
        return;
    }

    copy_node(from, to);

    if (from->_left != nullptr) {
        to->_left = new bstree_node<T>(*from->_left);
    } else {
        to->_left = nullptr;
    }

    if (from->_right != nullptr) {
        to->_right = new bstree_node<T>(*from->_right);
    } else {
        to->_right = nullptr;
    }

    duplicate_tree(from->_left, to->_left);
    duplicate_tree(from->_right, to->_right);
}

#endif