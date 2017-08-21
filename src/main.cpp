#include <iostream>
#include <typeinfo>
#include <initializer_list>
#include "priority_queue.hpp"

// template<typename T>
// struct name_and_value_comparator {
//     bool operator() (const T &nv1, const T &nv2) const {
//         return nv1.get_value() > nv2.get_value();
//     }
// };

class name_and_value {
private:
    std::string name;
    int value;
public:
    name_and_value() : name(""), value(0) {}
    name_and_value(std::string name, int value) : name(name), value(value) {}
    name_and_value(std::initializer_list<name_and_value> il);

    name_and_value(const name_and_value &other) : name(other.name), value(other.value) {}
    name_and_value &operator=(const name_and_value &other)
    {
        if (this != &other) {
            name = other.name;
            value = other.value;
        }

        return *this;
    }

    name_and_value(name_and_value &&other) : name(other.name), value(other.value)
    {
        other.name = "";
        other.value = 0;
    }
    name_and_value &operator=(name_and_value &&other)
    {
        if (this != &other) {
            name = other.name;
            value = other.value;

            other.name = "";
            other.value = 0;
        }

        return *this;
    }

    int get_value() const { return value; }

    friend bool operator<(const name_and_value &nv1, const name_and_value &nv2)
    {
        return nv1.get_value() < nv2.get_value();
    }

    friend bool operator>(const name_and_value &nv1, const name_and_value &nv2)
    {
        return nv1.get_value() > nv2.get_value();
    }

    friend std::ostream &operator<<(std::ostream &os, const name_and_value &nv)
    {
        os <<"Name : "<<nv.name<<", Value : "<<nv.value; 
        return os;
    }
};

int main(int argc, char *argv[])
{
    std::vector<name_and_value> nv_v = { 
        {"Marina", 4}, {"Robyn", 1},
        {"Kasey", 3}, {"Christop", 2},
        {"Mandy", 16}, {"Clemens", 9},
        {"Angie", 10}, {"Evert", 14},
        {"Natasha", 8}, {"Dena", 7}
    };

    priority_queue<name_and_value, std::greater<name_and_value>> nv_max_pq(nv_v);
    nv_max_pq.print_elements();

    return 0;
}

void test_max_pq_with_int()
{
    std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    priority_queue<int, std::greater<int>> max_pq(v);
    max_pq.print_elements();

    max_pq.modify(-2, 19);
    max_pq.modify(max_pq.size(), 19);
    max_pq.modify(3, 19);
    max_pq.modify(max_pq.size() - 1, 6);

    max_pq.print_elements();

    max_pq.add(20);
    max_pq.add(5);
    max_pq.add(25);
    max_pq.add(22);
    max_pq.add(15);

    max_pq.print_elements();

    max_pq.remove(max_pq.size());
    max_pq.remove(-2);
    max_pq.remove(max_pq.size() - 1);
    max_pq.remove(0);

    max_pq.print_elements();
}