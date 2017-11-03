#ifndef BSTREE_NODE_HPP
#define BSTREE_NODE_HPP

template<typename T>
class bstree_node {
private:
    T _data;
    size_t _count;

public:
    bstree_node *_left;
    bstree_node *_right;

    bstree_node(T data);
    ~bstree_node();

    bstree_node(const bstree_node<T> &other);
    bstree_node<T> &operator=(const bstree_node<T> &other);

    T data() const;
    size_t count() const;

    void set_data(T new_data);
    void set_count(size_t new_count);

    void increment_count();
    void decrement_count();
};

template<typename T>
bstree_node<T>::bstree_node(T data) : _data(data), _count(1)
{
    _left = nullptr;
    _right = nullptr;
}

template<typename T>
bstree_node<T>::~bstree_node()
{
    _left = nullptr;
    _right = nullptr;
}

template<typename T>
bstree_node<T>::bstree_node(const bstree_node<T> &other) : _data(other.data()), _count(other.count())
{

}

template<typename T>
bstree_node<T> &bstree_node<T>::operator=(const bstree_node<T> &other)
{
    if (this != &other) {
        _data = other.data();
        _count = other.count();
    }

    return *this;
}

template<typename T>
inline T bstree_node<T>::data() const
{
    return _data;
}

template<typename T>
inline size_t bstree_node<T>::count() const
{
    return _count;
}

template<typename T>
inline void bstree_node<T>::set_data(T new_data)
{
    _data = new_data;
}

template<typename T>
inline void bstree_node<T>::set_count(size_t count)
{
    _count = count;
}

template<typename T>
inline void bstree_node<T>::increment_count()
{
    ++_count;
}

template<typename T>
inline void bstree_node<T>::decrement_count()
{
    --_count;
}

#endif