#ifndef BSTREE_HPP
#define BSTREE_HPP

#include "bstree_node.hpp"
#include <vector>

template<typename T>
class bstree {
private:
    bstree_node<T> *_pseudo_root;

    void delete_entire_tree(bstree_node<T> *root);
    bstree_node<T> *insert(bstree_node<T> *node, bstree_node<T> *parent, T key);

public:
    bstree();
    bstree(bstree_node<T> *node);
    bstree(T data);
    ~bstree();

    bstree_node<T> *root();
    bstree_node<T> *pseudo_root();

    bstree_node<T> *insert(T key);
    void insert(std::vector<T> &keys);
};

template<typename T>
bstree<T>::bstree() : _pseudo_root(new bstree_node<T>(T()))
{
    _pseudo_root->_left = nullptr;
    _pseudo_root->_right = nullptr;
}

template<typename T>
bstree<T>::bstree(bstree_node<T> *root) : _pseudo_root(new bstree_node<T>(T()))
{
    root->_left = nullptr;
    root->_right = nullptr;

    if (root->data() > _pseudo_root->data()) {
        _pseudo_root->_right = root;
        _pseudo_root->_left = nullptr;
    } else {
        _pseudo_root->_left = root;
        _pseudo_root->_right = nullptr;
    }
}

template<typename T>
bstree<T>::bstree(T key) : bstree(new bstree_node<T>(key))
{

}

template<typename T>
bstree<T>::~bstree()
{
    delete_entire_tree(root());
    delete pseudo_root();
}

template<typename T>
void bstree<T>::delete_entire_tree(bstree_node<T> *node)
{
    if (node == nullptr) {
        return;
    }

    delete_entire_tree(node->_left);
    delete_entire_tree(node->_right);

    delete node;
}

template<typename T>
bstree_node<T> *bstree<T>::insert(T key)
{
    bstree_node<T> *new_node = insert(root(), pseudo_root(), key);
    return new_node;
}

template<typename T>
bstree_node<T> *bstree<T>::insert(bstree_node<T> *node, bstree_node<T> *parent, T key)
{
    if (node == nullptr) {
        bstree_node<T> *new_node = new bstree_node<T>(key);
        new_node->_left = nullptr;
        new_node->_right = nullptr;

        if (parent->data() > key) {
            parent->_left = new_node;
        } else {
            parent->_right = new_node;
        }

        return new_node;
    }

    if (node->data() == key) {
        node->increment_count();
        return node;
    } else if (node->data() > key) {
        return insert(node->_left, node, key);
    } else {
        return insert(node->_right, node, key);
    }
}

template<typename T>
void bstree<T>::insert(std::vector<T> &keys)
{
    for (const T key : keys) {
        insert(key);
    }
}

template<typename T>
bstree_node<T> *bstree<T>::pseudo_root()
{
    return _pseudo_root;
}

template<typename T>
bstree_node<T> *bstree<T>::root()
{
    if (_pseudo_root->_left == nullptr && _pseudo_root->_right == nullptr) {
        return nullptr;
    } else if (_pseudo_root->_left == nullptr) {
        return _pseudo_root->_right;
    } else {
        return _pseudo_root->_left;
    }
}

#endif