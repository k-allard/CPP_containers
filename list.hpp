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
    template < class T, class Alloc = std::allocator<T> > 
    class list
    {
    private:


    public:
            typedef T			  value_type;
			typedef Alloc       allocator_type;

        // 
        //  C O N S T R U C T O R S  &  D E S T R U C T O R
        //

        explicit list (const allocator_type& alloc = allocator_type());   // default
        explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());    // fill
        template <class InputIterator>
        list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());    // range
        list (const list& x);   // copy
        ~list();

            
    };
}

#endif
