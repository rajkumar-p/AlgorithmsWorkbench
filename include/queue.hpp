#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <vector>

template<typename T>
class queue_node {
private:
    T _data;

public:
    queue_node *_next;
    queue_node *_prev;

public:
    explicit queue_node(T data);
    ~queue_node();

    T data();
};

template<typename T>
queue_node<T>::queue_node(T data) : _data(data), _next(nullptr), _prev(nullptr)
{

}

template<typename T>
queue_node<T>::~queue_node()
{
    _next = nullptr;
    _prev = nullptr;
}

template<typename T>
T queue_node<T>::data()
{
    return _data;
}

template<typename T>
class queue {
private:
    size_t _size;

    queue_node<T> *_dummy_node;
    queue_node<T> *_front;
    queue_node<T> *_rear;

public:
    explicit queue();
    ~queue();

    void enqueue(T data);
    void dequeue();
    
    T front();
    bool empty();

    size_t size();

    typename std::vector<T> items();
};

template<typename T>
queue<T>::queue() : _size(0), _dummy_node(new queue_node<T>(T()))
    , _front(_dummy_node), _rear(_dummy_node)
{

}

template<typename T>
queue<T>::~queue()
{
    while(_dummy_node->_prev != nullptr) {
        queue_node<T> *node_to_delete = _dummy_node->_prev;
        _dummy_node->_prev = node_to_delete->_prev;

        delete node_to_delete;
    }

    _front = nullptr;
    _rear = nullptr;
    delete _dummy_node;
}

template<typename T>
bool queue<T>::empty()
{
    return _front == _rear;
}

template<typename T>
void queue<T>::enqueue(T data)
{
    queue_node<T> *node_to_enqueue = new queue_node<T>(data);
    
    node_to_enqueue->_prev = _rear->_prev;
    _rear->_prev = node_to_enqueue;
    node_to_enqueue->_next = _rear;

    if (empty()) {
        _front = node_to_enqueue;
    } else {
        node_to_enqueue->_prev->_next = node_to_enqueue;
    }

    ++_size;
}

template<typename T>
void queue<T>::dequeue()
{
    queue_node<T> *node_to_dequeue = _front;

    _front = _front->_next;
    _front->_prev = node_to_dequeue->_prev;

    delete node_to_dequeue;

    --_size;
}

template<typename T>
T queue<T>::front()
{
    if (empty()) {
        return T();
    }

    return _front->data();
}

template<typename T>
size_t queue<T>::size()
{
    return _size;
}

template<typename T>
typename std::vector<T> queue<T>::items()
{
    std::vector<T> items;
    for (auto iter = _front; iter != _rear; iter = iter->_next) {
        items.push_back(iter->data());
    }

    return items;
}

#endif