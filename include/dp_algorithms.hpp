#ifndef DP_ALGORITHMS_HPP
#define DP_ALGORITHMS_HPP

#include <string>
#include <vector>

/**
 * [Weighted Interval Scheduling] *
 * We have n requests labeled 1,..,n; with each request
 * i specifying a start time (start()), and end time
 * (end()). Each interval also has a weight, (weight()).
 * Two intervals are compatible if they do not overlap.
 * The goal is to select subset S ⊆ {1,...,n} of mutually
 * compatible intervals, so as to maximize the sum of the
 * values of the selected intervals, ∑weight(i)
 **/

class interval {
private:
    std::string _id;
    size_t _start;
    size_t _end;

    size_t _weight;

public:
    interval(std::string id, size_t start, size_t end, size_t weight) : _id(id), _start(start), _end(end), _weight(weight) {}
    const std::string id() const { return _id; }
    size_t start() const { return _start; }
    size_t end() const { return _end; }
    size_t weight() const { return _weight; }
};

size_t weighted_interval_scheduling(std::vector<interval> &intervals);

#endif