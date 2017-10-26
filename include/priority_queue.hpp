#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <iostream>

template<typename T, typename F = std::less<T>>
class priority_queue {
public:
    priority_queue();
    priority_queue(const std::vector<T> &);

    void heapify(const size_t index);
    void reverse_heapify(const size_t index);

    void add(const T );
    void modify(const size_t, T );
    void remove(const size_t );

    T top();
    T extract_top();

    F &get_cmp_fn();

    typename std::vector<T>::const_iterator start_iterator();
    typename std::vector<T>::const_iterator end_iterator();

    size_t size() const;

    typename std::vector<T> elements_copy();
    void print_elements();

    T at(const int ) const;
private:
    size_t parent_index_of(int );
    size_t left_index_of(int );
    size_t right_index_of(int );
private:
    std::vector<T> elements;
    F cmp_fn;
};

bool index_within_range(int index, int heap_size);

template<typename T, typename F>
priority_queue<T, F>::priority_queue() : cmp_fn(F())
{

}

template<typename T, typename F>
priority_queue<T, F>::priority_queue(const std::vector<T> &v)
{
    std::copy(v.begin(), v.end(), std::back_inserter(elements));

    for(int i = std::floor((v.size() - 1) / 2) - 1; i >= 0; --i) {
        heapify(i);
    }
}

template<typename T, typename F>
F &priority_queue<T, F>::get_cmp_fn()
{
    return cmp_fn;
}

template<typename T, typename F>
typename std::vector<T>::const_iterator priority_queue<T, F>::start_iterator()
{
    return elements.begin();
}

template<typename T, typename F>
typename std::vector<T>::const_iterator priority_queue<T, F>::end_iterator()
{
    return elements.end();
}

template<typename T, typename F>
size_t priority_queue<T, F>::size() const
{
    return elements.size();
}

template<typename T, typename F>
typename std::vector<T> priority_queue<T, F>::elements_copy()
{
    std::vector<T> elements_copy;
    std::copy(elements.begin(), elements.end(), std::back_inserter(elements_copy));

    return elements_copy;
}

template<typename T, typename F>
void priority_queue<T, F>::print_elements()
{
    for(auto e : elements) {
        std::cout <<e<<"\t";
    }
    std::cout <<std::endl;
}

template<typename T, typename F>
T priority_queue<T, F>::at(const int index) const
{
    return elements[index];
}

template<typename T, typename F>
size_t priority_queue<T, F>::parent_index_of(int index)
{
    return (index - 1) >> 1;
}

template<typename T, typename F>
size_t priority_queue<T, F>::left_index_of(int index)
{
    return (index << 1) + 1;
}

template<typename T, typename F>
size_t priority_queue<T, F>::right_index_of(int index)
{
    return (index << 1) + 2;
}

template<typename T, typename F>
void priority_queue<T, F>::heapify(const size_t index)
{
    size_t left_index = left_index_of(index);
    size_t right_index = right_index_of(index);

    size_t to_replace_index = index;

    if (left_index < size() && cmp_fn(at(left_index), at(to_replace_index))) {
        to_replace_index = left_index;
    }

    if (right_index < size() && cmp_fn(at(right_index), at(to_replace_index))) {
        to_replace_index = right_index;
    }

    if (to_replace_index != index) {
        std::swap(elements[index], elements[to_replace_index]);
        heapify(to_replace_index);
    }
}

template<typename T, typename F>
void priority_queue<T, F>::reverse_heapify(const size_t index)
{
    if (index < 1) { return; }

    size_t parent_index = parent_index_of(index);

    if (cmp_fn(at(index), at(parent_index))) {
        std::swap(elements[index], elements[parent_index]);
        reverse_heapify(parent_index);
    }

}

template<typename T, typename F>
void priority_queue<T, F>::add(const T new_element)
{
    elements.push_back(new_element);
    reverse_heapify(size() - 1);
}

template<typename T, typename F>
void priority_queue<T, F>::modify(const size_t index, const T new_value)
{
    if (!index_within_range(index, size())) {
        return;
    }

    if (cmp_fn(new_value, at(index))) {
        elements[index] = new_value;
        reverse_heapify(index);
    } else {
        elements[index] = new_value;
        heapify(index);
    }
}

template<typename T, typename F>
void priority_queue<T, F>::remove(size_t index)
{
    if (!index_within_range(index, size())) {
        return;
    }

    T last_value = at(size() - 1);
    elements.pop_back();

    modify(index, last_value);
}

template<typename T, typename F>
T priority_queue<T, F>::top()
{
    return elements[0];
}

template<typename T, typename F>
T priority_queue<T, F>::extract_top()
{
    T tmp = top();
    remove(0);

    return tmp;
}

bool index_within_range(int index, int heap_size)
{
    return (index >=0 && index < heap_size);
}

#endif