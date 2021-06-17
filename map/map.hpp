// sorted associative container that contains key-value pairs with unique keys

#ifndef MAP_HPP
# define MAP_HPP

#include "../header.hpp"
#include <iostream>
#include <map>

namespace ft
{
    template <class Key,
          class T,
		  class Compare =  std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key,T> > >
    class map
    {

    };
}


#endif