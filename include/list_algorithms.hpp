#ifndef LIST_ALGORITHMS_HPP
#define LIST_ALGORITHMS_HPP

#include <functional>
#include <vector>
#include <string>

template<typename T>
class node {
private:
    T _data;

public:
    node *_next;

public:
    explicit node(T data) : _data(data), _next(nullptr) {}
    ~node() { _next = nullptr; }

    T data() const { return _data; }
};

template<typename T>
class list {
public:
    node<T> *_head;
    node<T> *_tail;

private:
    unsigned int _size;

public:
    list() : _head(nullptr), _tail(nullptr), _size(0) {}
    list(node<T> *head) : _head(head), _tail(nullptr), _size(0) {
        node<T> *start = _head;
        while (start != nullptr) {
            start = start->_next;
            ++_size;
        }
    }
    ~list() {
        node<T> *n = nullptr;

        while (_head != nullptr) {
            n = _head;
            _head = _head->_next;

            delete n;
        }

        _head = _tail = nullptr;
    }

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

    unsigned int size() { return _size; }

    void for_each_node(std::function<void(const node<T> *n)> fn) {
        node<T> *start = _head;

        while (start != nullptr) {
            fn(start);
            start = start->_next;
        }
    }
};

void capture_odd_list_items(node<int> *head, list<int> *odd_lst);
void capture_even_list_items(node<int> *head, list<int> *even_lst);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insert_data(std::vector<int> &elements);
void delete_list(ListNode *node);
void for_each_node(ListNode *node, std::function<void(const ListNode *node)> fn);

// https://leetcode.com/problems/add-two-numbers/description/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

// https://algorithm.yuanbin.me/zh-hans/linked_list/remove_duplicates_from_sorted_list_ii.html
ListNode *remove_dups_from_sorted_list(ListNode *root);

// https://community.topcoder.com/stat?c=problem_statement&pm=1585&rd=6535
std::string get_task(std::vector<std::string> &tasks, size_t n);

// https://algorithm.yuanbin.me/zh-hans/linked_list/reverse_linked_list.html
ListNode *reverse_list(ListNode *root);

#endif