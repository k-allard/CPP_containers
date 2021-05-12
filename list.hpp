/*
**  List class - doubly-linked list
**
*/
// #include <list>

#ifndef LIST_HPP
# define LIST_HPP

#include "header.hpp"
#include <iostream>

// A DLL node
template <typename T>
struct node
{
    T data;
	struct node *prev;
	struct node *next;

	node() : data(T()) {}
	node(const T &value) : data(value) {}
};

namespace ft
{
    template < class T, class Alloc = allocator<T> > class list;
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
