#include <iostream>
#include "queue.hpp"

int main(int argc, char *argv[])
{
    // std::vector<int> v = { 2, 8, 7, 1, 3, 5, 6, 4 };
    // quick_sort(v, 0, v.size() - 1, std::less<int>());

    // for (auto e : v) {
    //     std::cout <<e<<"\t";
    // }
    // std::cout <<std::endl;
    queue<int> q;

    q.enqueue(5);
    q.enqueue(22);
    q.enqueue(7);
    q.enqueue(30);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}