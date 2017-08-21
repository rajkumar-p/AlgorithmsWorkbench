#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <string>

void put_into_vector(std::vector<int> &v, std::string from_file)
{
    std::ifstream in_file(from_file);
    int n;
    in_file >> n;

    for(int i = 0; i < n; ++i) {
        int element;
        in_file >> element;

        v.push_back(element);
    }

    in_file.close();
}