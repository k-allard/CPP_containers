//
//  V E C T O R
//  dynamically allocated array
//

#include <vector>

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "header.hpp"
#include <iostream>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
	private: 
		Allocator							_allocator;
		Allocator::pointer					_ptr;
		Allocator::size_type				_size;
		Allocator::size_type				_capacity;

    public:
        typedef T											value_type;               
        typedef Allocator									allocator_type;      
        typedef typename allocator_type::reference			reference;
        typedef typename allocator_type::size_type			size_type;
        typedef typename allocator_type::difference_type	difference_type;
        typedef typename allocator_type::const_reference	const_reference;
        typedef typename allocator_type::pointer			pointer;
        typedef typename allocator_type::const_pointer		const_pointer;

		typedef vectorIterator<T>							iterator;
		typedef constVectorIterator<T>						const_iterator;
		typedef revVectorIterator<T>						reverse_iterator;
		typedef constRevVectorIterator<T>					const_reverse_iterator;

        // 
        //  C O N S T R U C T O R S  &  D E S T R U C T O R
        //

        explicit vector (const allocator_type& alloc = allocator_type());   // default
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());    // fill
        template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());    // range
        vector (const vector& x);   // copy
        ~vector();


        // 
        //  A S S I G N A T I O N
        //

        vector& operator=(const vector& x);
        template <class InputIterator> void assign(InputIterator first, InputIterator last);    // range
        void assign (size_type n, const value_type& val);   // fill

        // 
        //  I T E R A T O R S
        //

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // 
        //  C A P A C I T Y
        // 

        size_type size() const;
        size_type max_size() const;
        size_type capacity() const;
        bool empty() const;
        void reserve (size_type n);
        void resize (size_type n, value_type val = value_type());

        // 
        //  E L E M E N T   A C C E S S
        //

        reference operator[] (size_type n);
        const_reference operator[] (size_type n) const;
        reference at (size_type n);
		const_reference at (size_type n) const;
        reference       front();
        const_reference front() const;
        reference       back();
        const_reference back() const;

        //
        //  M O D I F I C A T I O N
        //

        void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);	// single element
    	void insert (iterator position, size_type n, const value_type& val);	// fill
		template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);	// range
        iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
        void clear();
		void swap (vector& x);

    };

	// 
	//  N O N - M E M B E R S
	//

	template <class T, class Alloc> 
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
}

#endif
