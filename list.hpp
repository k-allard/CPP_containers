/*
**  List class
**
*/

#ifndef LIST_HPP
# define LIST_HPP

#include "header.hpp"
#include <iostream>

// A DLL node
class	Node {
	public:
		int		data;
		Node*   next;
		Node*	prev;
};

namespace ft
{
    // template < class T, class Alloc = allocator<T> > class list;
    class List
    {
        public:
            typedef T			  value_type;
			typedef Alloc       allocator_type;
            static void display()
            {
                std::cout << "ft::List is displaying\n";
            }

        private:
            
    };
}

#endif
