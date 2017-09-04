#include <vector>
#include <iostream>

template<typename T, typename F = std::less<T>>
class priority_queue {
public:
    priority_queue();
    priority_queue(const std::vector<T> &);

    void heapify(int );
    void reverse_heapify(int );

    void add(T );
    void modify(int, T );
    void remove(int );

    T top();
    T extract_top();

    F &get_cmp_fn();

    typename std::vector<T>::const_iterator start_iterator();
    typename std::vector<T>::const_iterator end_iterator();

    size_t size() const;

    typename std::vector<T> elements_copy();
    void print_elements();

    T at(int ) const;
private:
    int parent_index_of(int );
    int left_index_of(int );
    int right_index_of(int );
private:
    std::vector<T> elements;
    F cmp_fn;
};

bool index_within_range(int , int );

template<typename T, typename F>
priority_queue<T, F>::priority_queue() : cmp_fn(F())
{

}

template<typename T, typename F>
priority_queue<T, F>::priority_queue(const std::vector<T> &v)
{
    std::copy(v.begin(), v.end(), std::back_inserter(elements));

    int last_non_leaf_index = size() >> 1;
    for(int i = last_non_leaf_index - 1; i >= 0; --i) {
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
T priority_queue<T, F>::at(int index) const
{
    return elements[index];
}

template<typename T, typename F>
int priority_queue<T, F>::parent_index_of(int index)
{
    int parent_index = (index - 1) >> 1;
    return parent_index;
}

template<typename T, typename F>
int priority_queue<T, F>::left_index_of(int index)
{
    int left_index = (index << 1) + 1; 
    return left_index;
}

template<typename T, typename F>
int priority_queue<T, F>::right_index_of(int index)
{
    int right_index = (index << 1) + 2;
    return right_index;
}

template<typename T, typename F>
void priority_queue<T, F>::heapify(int index)
{
    int left_index = left_index_of(index);
    int right_index = right_index_of(index);

    int to_replace_index = index;

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
void priority_queue<T, F>::reverse_heapify(int index)
{
    if (index < 1) { return; }

    int parent_index = parent_index_of(index);

    if (cmp_fn(at(index), at(parent_index))) {
        std::swap(elements[index], elements[parent_index]);
        reverse_heapify(parent_index);
    }

}

template<typename T, typename F>
void priority_queue<T, F>::add(T new_element)
{
    elements.push_back(new_element);
    reverse_heapify(size() - 1);
}

template<typename T, typename F>
void priority_queue<T, F>::modify(int index, T new_value)
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
void priority_queue<T, F>::remove(int index)
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

bool index_within_range(int index, int size)
{
    return (index >=0 && index < size);
}