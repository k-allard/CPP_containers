#include "vector.hpp"
#include "ring.hpp"

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++) {
        vec.push_back(i);
    }
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i);
    }

    ft::vector<int> vecMy;
    for (int i = 1; i <= 5; i++) {
        vecMy.push_back(i);
    }
    for (int i = 0; i < vecMy.size(); i++) {
        std::cout << vecMy.at(i);
    }
}