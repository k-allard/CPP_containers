
#pragma once
#include "../header.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack {
	public:
		typedef T							value_type;
		typedef size_t						size_type;
		typedef Container					container_type;

		container_type						_container;

		// Constructs a stack container adaptor object.
		// A container adaptor keeps internally a container object as data. This container object is a copy of the ctnr argument passed to the constructor, if any, otherwise it is an empty container.
		explicit stack(const container_type & cntr = container_type()) : _container(cntr) {}
		~stack() {};

		bool				empty()	const					{ return (_container.empty()); }
		void				pop()							{ _container.pop_back(); }
		void				push(const value_type &value)	{ _container.push_back(value); }
		size_type			size()	const					{ return (_container.size()); }
		value_type &		top()							{ return (_container.back()); }
		const value_type &	top() const						{ return (_container.back()); }
	};

	template <typename T, typename Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container == rhs._container);
	}

	template <typename T, typename Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container != rhs._container);
	}

	template <typename T, typename Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container < rhs._container);
	}

	template <typename T, typename Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container > rhs._container);
	}

	template <typename T, typename Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container <= rhs._container);
	}

	template <typename T, typename Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container >= rhs._container);
	}
}
