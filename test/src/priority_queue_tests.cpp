#include "catch.hpp"
#include "priority_queue.hpp"

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

    std::string get_name() const { return name; }
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

TEST_CASE("Priority Queue Tests", "[Priority Queue Tests - Max PQ and Min PQ]")
{
    SECTION("[extract_top() test] - Max Priority Queue - Built-In Data Types") {
        std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

        priority_queue<int, std::greater<int>> max_pq(v);
        REQUIRE(max_pq.extract_top() == 16);
        REQUIRE(max_pq.size() == v.size() - 1);
        REQUIRE(max_pq.top() == 14);
    }

    SECTION("[extract_top() test] - Max Priority Queue - Custom Data Types") {
        std::vector<name_and_value> nv_v = { 
            {"Marina", 4}, {"Robyn", 1},
            {"Kasey", 3}, {"Christop", 2},
            {"Mandy", 16}, {"Clemens", 9},
            {"Angie", 10}, {"Evert", 14},
            {"Natasha", 8}, {"Dena", 7}
        };

        priority_queue<name_and_value, std::greater<name_and_value>> nv_max_pq(nv_v);
        name_and_value nv = nv_max_pq.extract_top();
        REQUIRE(nv.get_name() == "Mandy");
        REQUIRE(nv.get_value() == 16);

        REQUIRE(nv_max_pq.size() == nv_v.size() - 1);

        nv = nv_max_pq.top();
        REQUIRE(nv.get_name() == "Evert");
        REQUIRE(nv.get_value() == 14);

        REQUIRE(nv_max_pq.size() == nv_v.size() - 1);
    }

    SECTION("Max Priority Queue - Built-In Data Types") {
        std::vector<int> v = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

        priority_queue<int, std::greater<int>> max_pq(v);
        v = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
        REQUIRE(max_pq.elements_copy() == v);
        REQUIRE(max_pq.top() == 16);

        max_pq.modify(-2, 19);
        max_pq.modify(max_pq.size(), 19);
        max_pq.modify(3, 19);
        max_pq.modify(max_pq.size() - 1, 6);

        v = {19, 16, 10, 14, 7, 9, 3, 2, 4, 6};
        REQUIRE(max_pq.elements_copy() == v);
        REQUIRE(max_pq.top() == 19);

        max_pq.add(20);
        max_pq.add(5);
        max_pq.add(25);
        max_pq.add(22);
        max_pq.add(15);

        v = {25, 19, 22, 14, 16, 10, 20, 2, 4, 6, 7, 5, 9, 3, 15};
        REQUIRE(max_pq.elements_copy() == v);
        REQUIRE(max_pq.top() == 25);

        max_pq.remove(max_pq.size());
        max_pq.remove(-2);
        max_pq.remove(max_pq.size() - 1);
        max_pq.remove(0);

        v = {22, 19, 20, 14, 16, 10, 3, 2, 4, 6, 7, 5, 9};
        REQUIRE(max_pq.elements_copy() == v);
        REQUIRE(max_pq.top() == 22);
    }

    SECTION("Max Priority Queue - Custom Data Types") {
        std::vector<name_and_value> nv_v = { 
            {"Marina", 4}, {"Robyn", 1},
            {"Kasey", 3}, {"Christop", 2},
            {"Mandy", 16}, {"Clemens", 9},
            {"Angie", 10}, {"Evert", 14},
            {"Natasha", 8}, {"Dena", 7}
        };

        priority_queue<name_and_value, std::greater<name_and_value>> nv_max_pq(nv_v);

        nv_v = {{"Mandy", 16}, {"Evert", 14}, {"Angie", 10}, {"Natasha", 8}, {"Dena", 7}, {"Clemens", 9}, {"Kasey", 3}, {"Christop", 2}, {"Marina", 4}, {"Robyn", 1}};
        REQUIRE(nv_max_pq.size() == nv_v.size());
        for(int i = 0; i < nv_max_pq.size(); ++i) {
            REQUIRE(nv_max_pq.at(i).get_name() == nv_v[i].get_name());
            REQUIRE(nv_max_pq.at(i).get_value() == nv_v[i].get_value());
        }

        nv_max_pq.modify(-2, {"Akeem", 19});
        nv_max_pq.modify(nv_max_pq.size(), {"Akeem", 19});
        nv_max_pq.modify(3, {"Akeem", 19});
        nv_max_pq.modify(nv_max_pq.size() - 1, {"Laron", 6});

        nv_v = {{"Akeem", 19}, {"Mandy", 16}, {"Angie", 10}, {"Evert", 14}, {"Dena", 7}, {"Clemens", 9}, {"Kasey", 3}, {"Christop", 2}, {"Marina", 4}, {"Laron", 6}};
        REQUIRE(nv_max_pq.size() == nv_v.size());
        for(int i = 0; i < nv_max_pq.size(); ++i) {
            REQUIRE(nv_max_pq.at(i).get_name() == nv_v[i].get_name());
            REQUIRE(nv_max_pq.at(i).get_value() == nv_v[i].get_value());
        }

        nv_max_pq.add({"Cecil", 20});
        nv_max_pq.add({"Asa", 5});
        nv_max_pq.add({"Cierra", 25});
        nv_max_pq.add({"Benedict", 22});
        nv_max_pq.add({"Sylvester", 15});

        nv_v = {{"Cierra", 25}, {"Akeem", 19}, {"Benedict", 22}, {"Evert", 14}, {"Mandy", 16}, {"Angie", 10}, {"Cecil", 20}, {"Christop", 2}, {"Marina", 4}, {"Laron", 6}, {"Dena", 7}, {"Asa", 5}, {"Clemens", 9}, {"Kasey", 3}, {"Sylvester", 15}};
        REQUIRE(nv_max_pq.size() == nv_v.size());
        for(int i = 0; i < nv_max_pq.size(); ++i) {
            REQUIRE(nv_max_pq.at(i).get_name() == nv_v[i].get_name());
            REQUIRE(nv_max_pq.at(i).get_value() == nv_v[i].get_value());
        }

        nv_max_pq.remove(nv_max_pq.size());
        nv_max_pq.remove(-2);
        nv_max_pq.remove(nv_max_pq.size() - 1);
        nv_max_pq.remove(0);

        nv_v = {{"Benedict", 22}, {"Akeem", 19}, {"Cecil", 20}, {"Evert", 14}, {"Mandy", 16}, {"Angie", 10}, {"Kasey", 3}, {"Christop", 2}, {"Marina", 4}, {"Laron", 6}, {"Dena", 7}, {"Asa", 5}, {"Clemens", 9}};
        REQUIRE(nv_max_pq.size() == nv_v.size());
        for(int i = 0; i < nv_max_pq.size(); ++i) {
            REQUIRE(nv_max_pq.at(i).get_name() == nv_v[i].get_name());
            REQUIRE(nv_max_pq.at(i).get_value() == nv_v[i].get_value());
        }
    }

    SECTION("Min Priority Queue - Built-In Data Types") {
        std::vector<double> v = { -121.67, 102.75, 153.91, -165.78, -97.64, -92.50, 149.84, 49.42, 58.75, -51.81 };

        priority_queue<double, std::less<double>> min_pq(v);

        v = { -165.78, -121.67, -92.5, 49.42, -97.64, 153.91, 149.84, 102.75, 58.75, -51.81 };
        REQUIRE(min_pq.elements_copy() == v);
        REQUIRE(min_pq.top() == -165.78);

        min_pq.modify(-2, -200.58);
        min_pq.modify(min_pq.size(), -200.58);
        min_pq.modify(7, -200.58);
        min_pq.modify(2, 170.85);

        v = { -200.58, -165.78, 149.84, -121.67, -97.64, 153.91, 170.85, 49.42, 58.75, -51.81 };
        REQUIRE(min_pq.elements_copy() == v);
        REQUIRE(min_pq.top() == -200.58);

        min_pq.add(75.67);
        min_pq.add(200.99);
        min_pq.add(-10.89);

        v = { -200.58, -165.78, -10.89, -121.67, -97.64, 149.84, 170.85, 49.42, 58.75, -51.81, 75.67, 200.99, 153.91 };
        REQUIRE(min_pq.elements_copy() == v);
        REQUIRE(min_pq.top() == -200.58);

        min_pq.remove(-2);
        min_pq.remove(min_pq.size());
        min_pq.remove(min_pq.size() - 1);
        min_pq.remove(1);
        min_pq.remove(0);

        v = { -121.67, -97.64, -10.89, 49.42, -51.81, 149.84, 170.85, 200.99, 58.75, 75.67 };
        REQUIRE(min_pq.elements_copy() == v);
        REQUIRE(min_pq.top() == -121.67);
    }
}