#ifndef STACK_HPP
#define STACK_HPP

template<typename T>
class stack {
private:
    size_t size;
    size_t length;

    T *elements;

public:
    explicit stack(size_t size);
    ~stack();

    stack(const stack &other);
    stack(stack &&other);

    stack<T> &operator=(const stack &other);
    stack<T> &operator=(stack &&other);

    void push(T element);
    T top() const;
    void pop();

    bool empty() const { return length == 0; }
    bool full() const { return length == size; }

    size_t get_size() const { return size; }
    size_t get_length() const { return length; }

    void reset_size() { this->size = 0; }
    void reset_length() { this->length = 0; }
};

template<typename T>
stack<T>::stack(size_t size) : size(size), length(0), elements(new T[size])
{

}

template<typename T>
stack<T>::~stack()
{
    if (elements != nullptr) {
        delete[] elements;
    }
}

template<typename T>
stack<T>::stack(const stack &other) : size(other.size), length(other.length), elements(new T[size])
{
    std::copy(other.elements, other.elements + other.size, elements);
}

template<typename T>
stack<T>::stack(stack &&other) : elements(nullptr), size(0), length(0)
{
    elements = other.elements;
    size = other.get_size();
    length = other.get_length();

    other.elements = nullptr;
    other.reset_size();
    other.reset_length();
}

template<typename T>
stack<T> &stack<T>::operator=(const stack &other)
{
    if (this != &other) {
        delete[] elements;

        size = other.get_size();
        length = other.get_length();
        elements = new T[size];

        std::copy(other.elements, other.elements + other.length, elements);
    }

    return *this;
}

template<typename T>
stack<T> &stack<T>::operator=(stack &&other)
{
    if (this != &other) {
        delete[] elements;

        elements = other.elements;
        size = other.get_size();
        length = other.get_length();

        other.elements = nullptr;
        other.reset_size();
        other.reset_length();
    }

    return *this;
}

template<typename T>
void stack<T>::push(T element)
{
    if (this->full()) {
        size_t new_size = size * 2;
        T *new_elements = new T[new_size];
        std::copy(elements, elements + size, new_elements);

        delete[] elements;

        elements = new_elements;
        size = new_size;
        elements[length++] = element;
    } else {
        elements[length++] = element;
    }
}

template<typename T>
T stack<T>::top() const
{
    if (this->empty()) { 
        return T();
    }

    return elements[length - 1];
}

template<typename T>
void stack<T>::pop()
{
    if (this->empty()) { return; }
    --length;
}

#endif