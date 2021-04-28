#include "vector.hpp"
#include "list.hpp"

int main()
{
    ft::vector<int, std::allocator<int> >::display();
    ft::List<int>::display();
    return 0;
}