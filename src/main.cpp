#include <iostream>
#include "merge_sort.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> v = { 6, 3, 5, 6, 7, 1, 1, 9, 3, 2 };

    merge_sort(v, 0, v.size() - 1, std::less<int>());
    return 0;
}