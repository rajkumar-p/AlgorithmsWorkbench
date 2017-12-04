#include <iostream>
#include "dp_algorithms.hpp"

int main(int argc, char *argv[])
{
    std::vector<interval> intervals;

    // intervals.push_back(interval("1", 0, 6, 3));
    // intervals.push_back(interval("2", 1, 4, 5));
    // intervals.push_back(interval("3", 3, 5, 5));
    // intervals.push_back(interval("4", 3, 8, 8));
    // intervals.push_back(interval("5", 4, 7, 3));
    // intervals.push_back(interval("6", 5, 9, 7));
    // intervals.push_back(interval("7", 6, 10, 3));
    // intervals.push_back(interval("8", 8, 11, 4));

    intervals.push_back(interval("1", 1, 2, 50));
    intervals.push_back(interval("2", 3, 5, 20));
    intervals.push_back(interval("3", 6, 19, 100));
    intervals.push_back(interval("4", 2, 100, 200));

    size_t max_weight = weighted_interval_scheduling(intervals);

    std::cout <<"Maximum weight of non-overlapping intervals - "<<max_weight<<std::endl;
    // for (const interval &i : intervals) {
    //     std::cout <<"Id : "<<i.id()<<", Start : "<<i.start()<<", End : "<<i.end()<<", Weight : "<<i.weight()<<std::endl;
    // }

    return 0;
}