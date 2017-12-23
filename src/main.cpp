#include <iostream>
#include <vector>
#include "list_algorithms.hpp"

int main(int argc, char *argv[])
{

    std::vector<std::string> tasks;
    size_t n;

    tasks = { "a","b","c","d","e" };
    n = 3;
    std::cout<<get_task(tasks, n);

    return 0;
}
