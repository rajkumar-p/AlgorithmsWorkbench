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

class max_subarray_struct {
private:
    int _sum;
    size_t _start_index;
    size_t _end_index;

public:
    max_subarray_struct(int sum, size_t start_index, size_t end_index) : _sum(sum), _start_index(start_index), _end_index(end_index) {}
    int sum() const { return _sum; }
    size_t start_index() const { return _start_index; }
    size_t end_index() const { return _end_index; }
};

max_subarray_struct get_max_subarray_properties(std::vector<int> &numbers);

#endif