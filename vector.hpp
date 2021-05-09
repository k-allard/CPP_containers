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
    public:
        typedef T                                        value_type;               
        typedef Allocator                                allocator_type;      
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

		typedef vectorIterator<T>		            	iterator;
		typedef constVectorIterator<T>		            const_iterator;
		typedef revVectorIterator<T>	            	reverse_iterator;
		typedef constRevVectorIterator<T>           	const_reverse_iterator;

        // 
        //  C O N S T R U C T O R S  &  D E S T R U C T O R
        //

        vector() noexcept(is_nothrow_default_constructible<allocator_type>::value);
        explicit vector(const allocator_type&);
        explicit vector(size_type n);
        vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
        template <class InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
        vector(const vector& x);
        vector(vector&& x)   noexcept(is_nothrow_move_constructible<allocator_type>::value);
        vector(initializer_list<value_type> il);
        vector(initializer_list<value_type> il, const allocator_type& a);
        vector& operator=(const vector& x);
        vector& operator=(initializer_list<value_type> il);
        ~vector();


        // 
        //  A S S I G N A T I O N
        //

        template <class InputIterator> void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const value_type& u);
        void assign(initializer_list<value_type> il);

        // 
        //  I T E R A T O R S
        //

        iterator               begin() noexcept;
        const_iterator         begin()   const noexcept;
        iterator               end() noexcept;
        const_iterator         end()     const noexcept;
        reverse_iterator       rbegin() noexcept;
        const_reverse_iterator rbegin()  const noexcept;
        reverse_iterator       rend() noexcept;
        const_reverse_iterator rend()    const noexcept;
        const_iterator         cbegin()  const noexcept;
        const_iterator         cend()    const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend()   const noexcept;

        // 
        //  S I Z E
        // 

        size_type size() const noexcept;
        size_type max_size() const noexcept;
        size_type capacity() const noexcept;
        bool empty() const noexcept;
        void reserve(size_type n);
        void shrink_to_fit() noexcept;

        // 
        //  E L E M E N T   A C C E S S
        //

        reference       operator[](size_type n);
        const_reference operator[](size_type n) const;
        reference       at(size_type n);
        const_reference at(size_type n) const;
        reference       front();
        const_reference front() const;
        reference       back();
        const_reference back() const;

        //
        //  M O D I F I C A T I O N

        void push_back(const value_type& x);
        void push_back(value_type&& x);
        void pop_back();
        iterator insert(const_iterator position, const value_type& x);
        iterator insert(const_iterator position, value_type&& x);
        iterator insert(const_iterator position, size_type n, const value_type& x);
        template <class InputIterator> iterator insert(const_iterator position, InputIterator first, InputIterator last);
        iterator insert(const_iterator position, initializer_list<value_type> il);
        iterator erase(const_iterator position);
        iterator erase(const_iterator first, const_iterator last);
        void clear() noexcept;
        void resize(size_type sz);
        void resize(size_type sz, const value_type& c);

    };
}

#endif
