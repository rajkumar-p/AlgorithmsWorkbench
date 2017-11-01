#ifndef BSTREE_HPP
#define BSTREE_HPP

#include "bstree_node.hpp"
#include <vector>

template<typename T>
class bstree {
private:
    bstree_node<T> *_pseudo_root;

    bstree_node<T> *insert(T key, bstree_node<T> *node, bstree_node<T> *parent);

    void copy_node_data(bstree_node<T> *from, bstree_node<T> *to);

    void remove_node_with_no_children(bstree_node<T> *node_to_remove, bstree_node<T> *node_to_remove_parent);
    void remove_node_with_single_child(bstree_node<T> *node_to_remove, bstree_node<T> *node_to_remove_parent);
    void remove_node_with_both_children(bstree_node<T> *node_to_remove, bstree_node<T> *node_to_remove_parent);

    void delete_entire_tree(bstree_node<T> *root);

public:
    bstree();
    bstree(bstree_node<T> *node);
    bstree(T data);
    ~bstree();

    bstree_node<T> *root();
    bstree_node<T> *pseudo_root();

    bstree_node<T> *insert(T key);
    void insert(std::vector<T> &keys);

    bstree_node<T> *find(T key, bstree_node<T> *node);
    bstree_node<T> *parent_of_key(T key, bstree_node<T> *node, bstree_node<T> *parent);

    void remove(T key);

    bstree_node<T> *max(bstree_node<T> *node);
    bstree_node<T> *min(bstree_node<T> *node);

    bstree_node<T> *parent_of_max(bstree_node<T> *node, bstree_node<T> *parent);
    bstree_node<T> *parent_of_min(bstree_node<T> *node, bstree_node<T> *parent);

    void inorder_walk(bstree_node<T> *node, std::function<void(bstree_node<T> const *current)> fn);  
    void preorder_walk(bstree_node<T> *node, std::function<void(bstree_node<T> const *current)> fn);
    void postorder_walk(bstree_node<T> *node, std::function<void(bstree_node<T> const *current)> fn);
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
void bstree<T>::copy_node_data(bstree_node<T> *from, bstree_node<T> *to)
{
    to->set_data(from->data());
    to->set_count(from->count());
}

template<typename T>
bstree_node<T> *bstree<T>::insert(T key)
{
    bstree_node<T> *new_node = insert(key, root(), pseudo_root());
    return new_node;
}

template<typename T>
bstree_node<T> *bstree<T>::insert(T key, bstree_node<T> *node, bstree_node<T> *parent)
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
        return insert(key, node->_left, node);
    } else {
        return insert(key, node->_right, node);
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
bstree_node<T> *bstree<T>::find(T key, bstree_node<T> *node)
{
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data() == key) {
        return node;
    } else if (node->data() > key) {
        return find(key, node->_left);
    } else {
        return find(key, node->_right);
    }
}

template<typename T>
bstree_node<T> *bstree<T>::parent_of_key(T key, bstree_node<T> *node, bstree_node<T> *parent)
{
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data() == key) {
        return parent;
    } else if (node->data() > key) {
        return parent_of_key(key, node->_left, node);
    } else {
        return parent_of_key(key, node->_right, node);
    }
}

template<typename T>
void bstree<T>::remove(T key)
{
    bstree_node<T> *node_to_remove_parent = parent_of_key(key, root(), pseudo_root());
    bstree_node<T> *node_to_remove = find(key, node_to_remove_parent);

    if (node_to_remove->_left == nullptr && node_to_remove->_right == nullptr) {
        remove_node_with_no_children(node_to_remove, node_to_remove_parent);
    } else if (node_to_remove->_left != nullptr && node_to_remove->_right != nullptr) {
        remove_node_with_both_children(node_to_remove, node_to_remove_parent);
    } else {
        remove_node_with_single_child(node_to_remove, node_to_remove_parent);
    }

}

template<typename T>
void bstree<T>::remove_node_with_no_children(bstree_node<T> *node_to_remove, bstree_node<T> *node_to_remove_parent)
{
    if (node_to_remove_parent->_left == node_to_remove) {
        node_to_remove_parent->_left = nullptr;
    } else {
        node_to_remove_parent->_right = nullptr;
    }

    delete node_to_remove;
}

template<typename T>
void bstree<T>::remove_node_with_both_children(bstree_node<T> *node_to_remove, bstree_node<T> *node_to_remove_parent)
{
    bstree_node<T> *parent_of_max_node = parent_of_max(node_to_remove->_right, node_to_remove);
    bstree_node<T> *max_node = parent_of_max_node->_right;

    parent_of_max_node->_right = max_node->_left;

    max_node->_left = node_to_remove->_left;
    max_node->_right = node_to_remove->_right;

    if (node_to_remove_parent->_left == node_to_remove) {
        node_to_remove_parent->_left = max_node;
    } else {
        node_to_remove_parent->_right = max_node;
    }

    node_to_remove->_left = nullptr;
    node_to_remove->_right = nullptr;

    delete node_to_remove;
}

template<typename T>
void bstree<T>::remove_node_with_single_child(bstree_node<T> *node_to_remove, bstree_node<T> *node_to_remove_parent)
{
    if (node_to_remove_parent->_left == node_to_remove) {
        if (node_to_remove->_left != nullptr) {
            node_to_remove_parent->_left = node_to_remove->_left;
        } else {
            node_to_remove_parent->_left = node_to_remove->_right;
        }
    } else {
        if (node_to_remove->_left != nullptr) {
            node_to_remove_parent->_right = node_to_remove->_left;
        } else {
            node_to_remove_parent->_right = node_to_remove->_right;
        }
    }

    delete node_to_remove;
}

template<typename T>
bstree_node<T> *bstree<T>::max(bstree_node<T> *node)
{
    if (node->_right == nullptr) {
        return node;
    } else {
        return max(node->_right);
    }
}

template<typename T>
bstree_node<T> *bstree<T>::min(bstree_node<T> *node)
{
    if (node->_left == nullptr) {
        return node;
    } else {
        return min(node->_left);
    }
}

template<typename T>
bstree_node<T> *bstree<T>::parent_of_max(bstree_node<T> *node, bstree_node<T> *parent)
{
    if (node->_right == nullptr) {
        return parent;
    } else {
        return parent_of_max(node->_right, node);
    }
}

template<typename T>
bstree_node<T> *bstree<T>::parent_of_min(bstree_node<T> *node, bstree_node<T> *parent)
{
    if (node->_left == nullptr) {
        return parent;
    } else {
        return parent_of_min(node->_left, node);
    }
}

template<typename T>
void bstree<T>::inorder_walk(bstree_node<T> *node, std::function<void(bstree_node<T> const *current)> fn)
{
    if (node == nullptr) {
        return;
    }

    inorder_walk(node->_left, fn);
    fn(node);
    inorder_walk(node->_right, fn);
}

template<typename T>
void bstree<T>::preorder_walk(bstree_node<T> *node, std::function<void(bstree_node<T> const *current)> fn)
{
    if (node == nullptr) {
        return;
    }

    preorder_walk(node->_left, fn);
    preorder_walk(node->_right, fn);
    fn(node);
}

template<typename T>
void bstree<T>::postorder_walk(bstree_node<T> *node, std::function<void(bstree_node<T> const *current)> fn)
{
    if (node == nullptr) {
        return;
    }

    fn(node);
    postorder_walk(node->_left, fn);
    postorder_walk(node->_right, fn);
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