//
//  L I S T   I T E R A T O R S
//

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

#include "../header.hpp"

namespace ft
{
	template <typename T1>
	class listIterator
	{
	public:
		typedef T1						value_type;
		typedef T1&						reference;
		typedef T1*						ptr;
		typedef node<T1>*				node_ptr;
		node_ptr						_node;

		listIterator() : _node(nullptr) {}
		listIterator(node_ptr p) : _node(p) {}
		listIterator(const listIterator& rhs) : _node(rhs._node) {}
		listIterator & operator=(const listIterator &src) { _node = src._node; return (*this); }
		~listIterator() {}

		reference & operator*() const { return (_node->data); }
		ptr operator->() { return (_node->data);}
		listIterator &operator++() { _node = _node->next; return (*this); }
		listIterator &operator--() { _node = _node->prev; return (*this); }
		listIterator operator++(int);
		listIterator operator--(int);
		bool operator==(const listIterator & second) const { return (_node == second._node); }
		bool operator!=(const listIterator & second) const { return (_node != second._node); }

	};

	template <typename T1>
	class listConstIterator
	{
	public:
		typedef const T1				value_type;
		typedef const T1&				reference;
		typedef const T1*				ptr;
		typedef node<T1>*				node_ptr;
		node_ptr						_node;

		listConstIterator() : _node(nullptr) {}
		listConstIterator(node_ptr p) : _node(p) {}
		listConstIterator(const listConstIterator& rhs) : _node(rhs._node) {}
		listConstIterator & operator=(const listConstIterator &src) { _node = src._node; return (*this); }
		~listConstIterator() {}

		reference operator*() const { return (_node->data); }
		ptr operator->() {return (&_node->data);}
		listConstIterator &operator++() { _node = _node->next; return (*this); }
		listConstIterator &operator--() { _node = _node->prev; return (*this); }
		listConstIterator operator++(int);
		listConstIterator operator--(int);
		bool operator==(const listConstIterator & second) const { return (_node == second._node); }
		bool operator!=(const listConstIterator & second) const { return (_node != second._node); }
	};

	template<typename T1>
	class listRevIterator {
		public:
		typedef T1						value_type;
		typedef T1&						reference;
		typedef T1*						ptr;
		typedef node<T1>*				node_ptr;
		node_ptr						_node;

		listRevIterator() : _node(nullptr) {}
		listRevIterator(node_ptr p) : _node(p) {}
		listRevIterator(const listRevIterator& rhs) : _node(rhs._node) {}
		listRevIterator & operator=(const listRevIterator &src) { _node = src._node; return (*this); }
		~listRevIterator() {}

		reference & operator*() const { return (_node->data); }
		ptr operator->() {return (_node->data); }
		listRevIterator &operator++() { _node = _node->prev; return (*this); }
		listRevIterator &operator--() { _node = _node->next; return (*this); }
		listRevIterator operator++(int);
		listRevIterator operator--(int);
		bool operator==(const listRevIterator & second) const { return (_node == second._node); }
		bool operator!=(const listRevIterator & second) const { return (_node != second._node); }
	};

	template<typename T1>
	class listConstRevIterator {
	public:
		typedef const T1						value_type;
		typedef const T1&						reference;
		typedef const T1*						ptr;
		typedef const node<T1>*					node_ptr;
		node_ptr								_node;

		listConstRevIterator() : _node(nullptr) {}
		listConstRevIterator(node_ptr p) : _node(p) {}
		listConstRevIterator(const listConstRevIterator& rhs) : _node(rhs._node) {}
		listConstRevIterator & operator=(const listConstRevIterator &src) { _node = src._node; return (*this); }
		~listConstRevIterator() {}

		reference operator*() const { return (*_node->data); }
		ptr operator->() {return (_node->data); }
		listConstRevIterator &operator++() { _node = _node->prev; return (*this); }
		listConstRevIterator &operator--() { _node = _node->next; return (*this); }
		listConstRevIterator operator++(int);
		listConstRevIterator operator--(int);
		bool operator==(const listConstRevIterator & second) const { return (_node == second._node); }
		bool operator!=(const listConstRevIterator & second) const { return (_node != second._node); }
	};


// listIterator
	// post-increment - returns the value *this had before the call
	template <typename T1>
	listIterator<T1> listIterator<T1>::operator++(int) {
		listIterator temp = *this;
		_node = _node->next;
		return (temp);
	}

	// post-decrement
	template <typename T1>
	listIterator<T1> listIterator<T1>::operator--(int) {
		listIterator temp = *this;
		_node = _node->prev;
		return (temp);
	}


// listConstIterator
	// post-increment - returns the value *this had before the call
	template <typename T1>
	listConstIterator<T1> listConstIterator<T1>::operator++(int)	{
		listConstIterator temp = *this;
		_node = _node->next;
		return (temp);
	}

	// post-decrement
	template <typename T1>
	listConstIterator<T1> listConstIterator<T1>::operator--(int) {
		listConstIterator temp = *this;
		_node = _node->prev;
		return (temp);
	}

// listRevIterator
	template <typename T1>
	listRevIterator<T1> listRevIterator<T1>::operator++(int) {
		listRevIterator temp = *this;
		_node = _node->prev;
		return (temp);
	}

	template <typename T1>
	listRevIterator<T1>	listRevIterator<T1>::operator--(int) {
		listRevIterator<T1> temp = *this;
		_node = _node->next;
		return (temp);
	}

// listConstRevIterator

	template <typename T1>
	listConstRevIterator<T1> listConstRevIterator<T1>::operator++(int) {
		listConstRevIterator temp = *this;
		_node = _node->prev;
		return (temp);
	}

	template <typename T1>
	listConstRevIterator<T1>	listConstRevIterator<T1>::operator--(int) {
		listConstRevIterator<T1> temp = *this;
		_node = _node->next;
		return (temp);
	}
}
#endif
