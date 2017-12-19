#include "other_algorithms.hpp"
#include <stack>
#include <vector>
#include <tuple>

std::vector<size_t> get_next_high_for_each(std::vector<size_t> &temps)
{
    std::stack<std::tuple<size_t, size_t>> stk;
    std::vector<size_t> result(temps.size(), 0);

    for (int i = temps.size() - 1; i >= 0; --i) {
        while (!stk.empty() && std::get<1>(stk.top()) < temps[i]) {
            stk.pop();
        }

        if (stk.empty()) {
            result[i] = 0;
        } else {
            result[i] = std::get<0>(stk.top()) - i;
        }

        stk.push(std::make_tuple(i, temps[i]));
    }

    return result;
}