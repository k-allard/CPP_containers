//
//  L I S T
//  doubly-linked list
//
#include <list>
#ifndef LIST_HPP
# define LIST_HPP

#include "../header.hpp"

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
	template < class T, class Allocator = std::allocator<T> > 
	class list
	{
	public:
        typedef T											value_type;
        typedef Allocator									allocator_type;
        typedef typename allocator_type::reference			reference;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
        typedef typename allocator_type::const_reference	const_reference;
        typedef typename allocator_type::pointer			pointer;
        typedef typename allocator_type::const_pointer		const_pointer;

		typedef listIterator<T>								iterator;
		typedef listConstIterator<T>						const_iterator;
		typedef listRevIterator<T>							reverse_iterator;
		typedef listConstRevIterator<T>						const_reverse_iterator;

	private:
		allocator_type						_allocator;
		size_type							_size;
		typedef node<T>						_node;
		typedef _node *						_node_pointer;
		_node_pointer						_end;
		
	public:

		// 
		//  C O N S T R U C T O R S  &  D E S T R U C T O R
		//

		list (const allocator_type& alloc = allocator_type());   // default
		list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());    // fill
		template <class InputIterator> list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());    // range
		list (const list& x);   // copy
		~list();

		// 
		//  A S S I G N A T I O N
		//

		list& operator=(const list& x);
		template <class InputIterator> void assign (InputIterator first, InputIterator last);    // range
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

		bool empty() const;
		size_type size() const;
		size_type max_size() const;

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

		void push_front (const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val); // single element
		void insert (iterator position, size_type n, const value_type& val); // fill
		template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); // range	
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (list& x);
		void resize (size_type n, value_type val = value_type());
		void clear();

		//
		// O P E R A T I O N S
		//

		void splice (iterator position, list& x); //   entire list
		void splice (iterator position, list& x, iterator i); // single element
		void splice (iterator position, list& x, iterator first, iterator last); // element range
		void remove (const value_type& val);
		template <class Predicate> void remove_if (Predicate pred);
  		void unique();
		template <class BinaryPredicate> void unique (BinaryPredicate binary_pred);
		void merge (list& x);
		template <class Compare> void merge (list& x, Compare comp);
		void sort();
		template <class Compare> void sort (Compare comp);
		void reverse();

	private:

		void defaultListBuild(const allocator_type& alloc);
	};

	// 
	//  C O N S T R U C T O R S  &  D E S T R U C T O R
	//

	template <typename T, typename Allocator>
	void list<T, Allocator>::defaultListBuild(const allocator_type& alloc) {
		_allocator = alloc;
		_size = 0;
		_end = new node<value_type>();
		_end->next = _end;
		_end->prev = _end;
	}

	template <typename T, typename Allocator>
	list<T, Allocator>::list (const allocator_type& alloc) { // default constructor
		defaultListBuild(alloc);
	}

	template <typename T, typename Allocator>
	list<T, Allocator>::list (size_type n, const value_type& val, const allocator_type& alloc) { 	// fill constructor
		defaultListBuild(alloc);
		for (int i = 0; i < n; i++)
			push_back(val);
	}

	// template <class InputIterator>
	// template <typename T, typename Allocator>
	// list<T, Allocator>::list (InputIterator first, InputIterator last, const allocator_type& alloc) {    // range constructor

	// }

	template <typename T, typename Allocator>
	list<T, Allocator>::list (const list& x) { 	// copy constructor

	}

	template <typename T, typename Allocator>
	list<T, Allocator>::~list() {
		clear();
		// if (_size != 0)
			delete _end;
	}

	// 
	//  A S S I G N A T I O N
	//

	// list& operator=(const list& x);
	// template <class InputIterator> void assign (InputIterator first, InputIterator last);    // range
	// void assign (size_type n, const value_type& val);   // fill

	// 
	//  I T E R A T O R S
	//

	// iterator begin();
	// const_iterator begin() const;
	// iterator end();
	// const_iterator end() const;
	// reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator rend();
	// const_reverse_iterator rend() const;

	// 
	//  C A P A C I T Y
	// 

	// bool empty() const;
	// size_type size() const;
	// size_type max_size() const;

	// 
	//  E L E M E N T   A C C E S S
	//

	// reference front();
	// const_reference front() const;
	// reference back();
	// const_reference back() const;

	//
	//  M O D I F I C A T I O N
	//

	// void push_front (const value_type& val);
	// void pop_front();

	template <typename T, typename Allocator>
	void list<T, Allocator>::push_back (const value_type& val) {
		_node_pointer newNode 	= new node<value_type>(val);
		newNode->next 			= _end;
		newNode->prev 			= _end->prev;
		_end->prev->next 		= newNode;
		_end->prev 				= newNode;
		_size++;
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::pop_back() {
		_node_pointer toDel = _end->prev;
		_end->prev = toDel->prev;
		toDel->prev->next = _end;
		delete toDel;
		_size--;
	}

	// iterator insert (iterator position, const value_type& val); // single element
	// void insert (iterator position, size_type n, const value_type& val); // fill
	// template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); // range	
	// iterator erase (iterator position);
	// iterator erase (iterator first, iterator last);
	// void swap (list& x);
	// void resize (size_type n, value_type val = value_type());
	
	template <typename T, typename Allocator>
	void list<T, Allocator>::clear() {
		while (_size)
			pop_back();
	}

	//
	// O P E R A T I O N S
	//

	// void splice (iterator position, list& x); //   entire list
	// void splice (iterator position, list& x, iterator i); // single element
	// void splice (iterator position, list& x, iterator first, iterator last); // element range
	// void remove (const value_type& val);
	// template <class Predicate> void remove_if (Predicate pred);
	// void unique();
	// template <class BinaryPredicate> void unique (BinaryPredicate binary_pred);
	// void merge (list& x);
	// template <class Compare> void merge (list& x, Compare comp);
	// void sort();
	// template <class Compare> void sort (Compare comp);
	// void reverse();

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
