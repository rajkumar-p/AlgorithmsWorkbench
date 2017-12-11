#ifndef LIST_ALGORITHMS_HPP
#define LIST_ALGORITHMS_HPP

template<typename T>
class node {
private:
    T _data;

public:
    node *_next;

public:
    explicit node(T data) : _data(data), _next(nullptr) {}

    T data() const { return _data; }
};

template<typename T>
class list {
private:
    node<T> *_head;
    node<T> *_tail;

    size_t _size;

public:
    list() : _head(nullptr), _tail(nullptr), _size(0) {}

    node<T> *head() { return _head; }
    node<T> *tail() { return _tail; }
    
    void insert(T data) {
        node<T> *new_node = new node<T>(data);

        if (_head == nullptr) {
            _head = new_node;
            _tail = new_node;
        } else {
            _tail->_next = new_node;
            _tail = new_node;
        }

        ++_size;
    }

    size_t size() { return _size; }

    void for_each_node(std::function<void(const node<T> *n)> fn) {
        node<T> *start = _head;

        while (start != nullptr) {
            fn(start);
            start = start->_next;
        }
    }
};

#endif