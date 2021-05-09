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


    Ring<string> rs;
    rs.push_back("one");
    rs.push_back("two");
    rs.push_back("three");
    rs.push_back("four");
    rs.push_back("five");
    Ring<string>::iterator it = rs.begin();
    ++it; ++it;
    it.insert("six");
    it = rs.begin();
    // Twice around the ring:
    for(int i = 0; i < rs.size() * 2; i++)
    cout << *it++ << endl;
    return 0;
}