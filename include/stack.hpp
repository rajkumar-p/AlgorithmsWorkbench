template<typename T>
class stack {
private:
    T *elements;
    const size_t size;
    size_t length;

public:
    explicit stack(size_t size);
    ~stack();

    stack(const stack &other);
    stack<T> &operator=(const stack &other);

    stack(stack &&other);
    stack<T> &operator=(stack &&other);

    void push(T element);
    T top() const;
    void pop();

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
    std::copy(other.elements, other.elements + other.length, elements);
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
    if (length == size - 1) {
        // Throw exception
    } else {
        elements[++length] = element;
    } 
}

template<typename T>
T stack<T>::top() const
{
    if (length == 0) { 
        // Throw exception
    }

    return elements[length];
}

template<typename T>
void stack<T>::pop()
{
    if (length == 0) { return; }

    --length;
    delete elements[length + 1];
}