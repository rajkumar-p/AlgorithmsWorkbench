#include <vector>

template<typename T>
class stack {
private:
    std::vector<T> elements;
    const size_t size;
    size_t count;

public:
    stack(size_t size);

    void push(T element);
    T top() const;
    void pop();

    size_t size() const { return 0; }
    size_t count() const { return 0; }
};