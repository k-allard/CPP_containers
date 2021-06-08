#ifndef MULTISET_HPP
#define MULTISET_HPP

#include "iteratorSet.hpp"

namespace ft {

	template 	< 	class T,							// set::key_type/value_type
					class Compare = std::less<T>,		// set::key_compare/value_compare
					class Alloc = std::allocator<T>		// set::allocator_type
				>
	class multiset {

		/*
		** Typedefs
		*/
	public:
		typedef T											key_type;
		typedef T											value_type;
		typedef Compare										key_compare;
		typedef Compare										value_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef IteratorSet<false,T>						iterator;
		typedef ReverseIteratorSet<T>						reverse_iterator;
		typedef IteratorSet<true,T>							const_iterator;
		typedef ConstReverseIteratorSet<T>					const_reverse_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;

		/*
		** Class members
		*/
	private:
		SetNode<T>*		_root;
		SetNode<T>*		_begin;
		SetNode<T>*		_end;
		key_compare		_comp;
		allocator_type	_alloc;
		size_type		_size;

		SetNode<T>*	treeMinimum(SetNode<T>* ptr) {
			SetNode<T>* leftMost = ptr;

			while (leftMost && leftMost->_left)
				leftMost = leftMost->_left;

			return (leftMost);
		}

		SetNode<T>*	treeMaximum(SetNode<T>* ptr) {
			SetNode<T>* rightMost = ptr;

			while (rightMost && rightMost->_right)
				rightMost = rightMost->_right;

			return (rightMost);
		}

		void	refresh_iterators() {
			SetNode<T>* leftMost = this->treeMinimum(_root), *rightMost = this->treeMaximum(_root);

			_begin = leftMost;
			if (rightMost != _end) {
				rightMost->_right = _end;
				_end->_parent = rightMost;
			}
		}

		void	transplant(SetNode<T> *first, SetNode<T> *second) {
			if (!first->_parent)
				_root = second;
			else if (first == first->_parent->_left)
				first->_parent->_left = second;
			else
				first->_parent->_right = second;
			if (second)
				second->_parent = first->_parent;
		}

	public:
		/*
		** Constructors
		*/
		explicit multiset(const key_compare& comp = key_compare(),
					 const allocator_type& alloc = allocator_type()) {
			_root = NULL;
			_begin = _end = new SetNode<T>;
			_begin->_left = _begin->_right = _begin->_parent = _end->_left = _end->_right = _end->_parent = NULL;
			_begin->_data = _end->_data = NULL;
			_comp = comp;
			_alloc = alloc;
			_size = 0;
		}

		template <class InputIterator>
		multiset(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) {
			_root = NULL;
			_begin = _end = new SetNode<T>;
			_begin->_left = _begin->_right = _begin->_parent = _end->_left = _end->_right = _end->_parent = NULL;
			_comp = comp;
			_alloc = alloc;
			_size = 0;
			while (first != last)
				insert(*first++);
		}

		multiset(const multiset& x) {
			_root = NULL;
			_begin = _end = new SetNode<T>;
			_begin->_left = _begin->_right = _begin->_parent = _end->_left = _end->_right = _end->_parent = NULL;
			_comp = x._comp;
			_alloc = x._alloc;
			_size = 0;

			if (x.size()) {
				const_iterator first = x.begin(), last = x.end();
				while (first != last)
					insert(*first++);
			}
		}

		~multiset() {
			clear();
			delete _end;
		}

		multiset& operator=(const multiset& x) {
			if (this != &x) {
				clear();
				delete _end;

				_root = NULL;
				_begin = _end = new SetNode<T>;
				_begin->_left = _begin->_right = _begin->_parent = _end->_left = _end->_right = _end->_parent = NULL;
				_comp = x._comp;
				_alloc = x._alloc;
				_size = 0;

				if (x.size()) {
					const_iterator first = x.begin(), last = x.end();
					while (first != last)
						insert(*first++);
				}
			}
			return (*this);
		}

		/*
		** Iterators
		*/
		iterator				begin() {
			return (iterator(_begin));
		}

		const_iterator			begin() const {
			return (const_iterator(_begin));
		}

		iterator				end() {
			return (iterator(_end));
		}

		const_iterator 			end() const {
			return (const_iterator(_end));
		}

		reverse_iterator		rbegin() {
			return (reverse_iterator(_end));
		}

		const_reverse_iterator	rbegin() const {
			return (const_reverse_iterator(_end));
		}

		reverse_iterator 		rend() {
			return (reverse_iterator(_begin));
		}

		const_reverse_iterator	rend() const {
			return (const_reverse_iterator(_end));
		}

		/*
		** Capacity
		*/
		bool		empty() const {
			return (_size == 0);
		}

		size_type	size() const {
			return (_size);
		}

		size_type	max_size() const {
			return (_alloc.max_size());
		}

		/*
		** Modifiers
		*/
		iterator					insert (const value_type& val) {
			SetNode<T> *x = _root;
			SetNode<T> *y = NULL;

			while (x && x != _end) {
				y = x;
				if (_comp(val, *(x->_data)))
					x = x->_left;
				else
					x = x->_right;
			}
			SetNode<T> *z = new SetNode<T>;
			z->_data = _alloc.allocate(1);
			_alloc.construct(z->_data, val);
			z->_parent = y;
			z->_left = z->_right = NULL;
			if (!y) {
				z->_right = _end;
				_root = _begin = _end->_parent = z;
			}
			else if (_comp(*(z->_data), *(y->_data)))
				y->_left = z;
			else
				y->_right = z;
			_size++;
			refresh_iterators();
			return (iterator(z));
		}

		iterator					insert (iterator position, const value_type& val) {
			SetNode<T> *x = position.getPtr();
			SetNode<T> *y = NULL;

			while (x->_parent) {
				x = x->_parent;
				y = x;
				if (_comp(*(x->_data), val))
					break ;
			}

			while (x && x != _end) {
				y = x;
				if (_comp(val, *(x->_data)))
					x = x->_left;
				else
					x = x->_right;
			}
			SetNode<T> *z = new SetNode<T>;
			z->_data = _alloc.allocate(1);
			_alloc.construct(z->_data, val);
			z->_parent = y;
			z->_left = z->_right = NULL;
			if (!y) {
				z->_right = _end;
				_root = _begin = _end->_parent = z;
			}
			else if (_comp(*(z->_data), *(y->_data)))
				y->_left = _begin = z;
			else
				y->_right = z;
			_size++;
			refresh_iterators();
			return (iterator(z));
		}

		template <class InputIterator>
		void						insert (InputIterator first, InputIterator last) {
			while (first != last)
				insert(*first++);
		}

		void						erase (iterator position) {
			SetNode<T>* ptr = position.getPtr(), *y;

			if (!ptr->_left)
				transplant(ptr, ptr->_right);
			else if (!ptr->_right || ptr->_right == _end)
				transplant(ptr, ptr->_left);
			else {
				y = treeMinimum(ptr->_right);
				if (y->_parent != ptr) {
					transplant(y, y->_right);
					y->_right = ptr->_right;
					y->_right->_parent = y;
				}
				transplant(ptr, y);
				y->_left = ptr->_left;
				y->_left->_parent = y;
			}
			_alloc.destroy(ptr->_data);
			_alloc.deallocate(ptr->_data, 1);
			delete ptr;
			_size--;
			refresh_iterators();
		}

		size_type					erase (const value_type& k) {
			size_type count = 0;
			iterator del;
			while ((del = find(k)) != this->end()) {
				erase(del);
				count++;
			}
			return (count);
		}

		void						erase (iterator first, iterator last) {
			iterator tmp;

			while (first != last) {
				tmp = first++;
				erase(tmp);
			}
		}

		void						swap (multiset& x) {
			ft::swap(_root, x._root);
			ft::swap(_begin, x._begin);
			ft::swap(_end, x._end);
			ft::swap(_comp, x._comp);
			ft::swap(_alloc, x._alloc);
			ft::swap(_size, x._size);
		}

		void						clear() {
			while (!empty())
				erase(this->begin());
		}

		/*
		** Observers
		*/
		key_compare		key_comp() const {
			return (_comp);
		}

		value_compare	value_comp() const {
			return (_comp);
		}

		/*
		** Operations
		*/
		iterator		find (const value_type& val) const {
			const_iterator first = this->begin(), last = this->end();

			while (first != last) {
				if (!_comp(*first, val) && !_comp(val, *first))
					return (first);
				first++;
			}
			return (last);
		}

		size_type		count (const value_type& val) const {
			return (this->find(val) != this->end());
		}

		iterator		lower_bound (const value_type& val) const {
			iterator first = this->begin(), last = this->end();

			while (first != last) {
				if (!(_comp(*first, val)))
					return (first);
				first++;
			}
			return (last);
		}

		iterator		upper_bound (const value_type& val) const {
			iterator first = this->begin(), last = this->end();

			while (first != last) {
				if (_comp(val, *first))
					return (first);
				first++;
			}
			return (last);
		}

		std::pair<iterator,iterator>	equal_range (const value_type& val) const {
			return (std::make_pair(this->lower_bound(val), this->upper_bound(val)));
		}


	};

	/*
	** Non-member function overloads
	*/
	template <class T, class Compare, class Alloc>
	bool operator==(const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename multiset<T,Compare,Alloc>::const_iterator firstLhs = lhs.begin(), firstRhs = rhs.begin();
		for (typename multiset<T,Compare,Alloc>::size_type i = 0; i < lhs.size(); i++)
			if (*firstLhs++ != *firstRhs++)
				return (false);
		return (true);
	}

	template <class T, class Compare, class Alloc>
	bool operator!=(const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator<(const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Compare, class Alloc>
	bool operator<=(const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator>(const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator>=(const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Compare, class Alloc>
	void swap(multiset<T,Compare,Alloc>& x, multiset<T,Compare,Alloc>& y) {
		x.swap(y);
	}

}

#endif
