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

		// 
		//  A S S I G N A T I O N
		//

		list& operator= (const list& x);
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);    // range
		void assign (size_type n, const value_type& val);   // fill

		// 
		//  I T E R A T O R S
		//

		reference back();
		const_reference back() const;
		iterator begin();
		const_iterator begin() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// 
		//  C A P A C I T Y
		// 

		size_type size() const;
		size_type max_size() const;
		bool empty() const;
		void resize (size_type n, value_type val = value_type());

		// 
		//  E L E M E N T   A C C E S S
		//

		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		//
		//  M O D I F I C A T I O N
		//

		void push_back (const value_type& val);
		void pop_back();
		void push_front (const value_type& val);
		void pop_front();
		iterator insert (iterator position, const value_type& val); // single element
		void insert (iterator position, size_type n, const value_type& val); // fill
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last); // range	
		void merge (list& x);
		template <class Compare>
		void merge (list& x, Compare comp);

		bool empty() const;
		void reverse();
		void sort();
		template <class Compare>
		void sort (Compare comp);
		void splice (iterator position, list& x); //   entire list
		void splice (iterator position, list& x, iterator i); // single element
		void splice (iterator position, list& x, iterator first, iterator last); // element range
		void swap (list& x);
		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void clear();
		void swap (list& x);

	};
	
	// 
	//  N O N - M E M B E R S
	//

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y);

	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
}

#endif
