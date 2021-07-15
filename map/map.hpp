// a sorted associative container
// contains key-value pairs with unique keys
// implemented as a red-black tree
// keys are sorted by using the comparison function Compare

#ifndef MAP_HPP
# define MAP_HPP

#include "../header.hpp"
#include "pair.hpp"

#include <iostream>
#include <map>

namespace ft
{
    template <class Key,
          class T,
		  class Compare =  std::less<Key>,
          class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
    {
		/*
		** member types
		*/
        typedef Key 					key_type;
		typedef T 						mapped_type;
		typedef ft::pair<const Key, T>	value_type;
	public:
		typedef Compare					key_compare;
	private:
		// Nested function class to compare elements
		class value_compare : public binary_function<value_type, value_type, bool>
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool 		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const {
					return comp(x.first, y.first);
				}
		};
		typedef Alloc 					allocator_type;
		typedef value_type & 			reference;
		typedef const value_type & 		const_reference;
		typedef value_type * 			pointer;
		typedef const value_type * 		const_pointer;
		typedef RBTree<Key, value_type, Compare, allocator_type>	tree_type;
        typedef TreeNode<Key, value_type>		_node;
		typedef _node *					_node_pointer;

		allocator_type					_allocator;
		key_compare				    	_compare;
		tree_type						_tree;
		value_compare					_value_comp;
    public:
        typedef MapIterator<Key, value_type, Compare, Alloc>		iterator;
		typedef ConstMapIterator<Key, value_type, Compare, Alloc>	const_iterator;
		typedef RevMapIterator<Key, value_type, Compare, Alloc> 	reverse_iterator;
		typedef ConstRevMapIterator<Key, value_type, Compare, Alloc> 	const_reverse_iterator;
	//
	//  C O N S T R U C T O R S  &  D E S T R U C T O R
	//
		explicit
		map(const key_compare &comp = key_compare(), const allocator_type &allocator = allocator_type()) :
			_allocator(allocator),
			_compare(comp),
			_value_comp(comp) { }

        template <class InputIterator>
  		map (InputIterator first, InputIterator last,
       			const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type()) : _allocator(alloc), _compare(comp), _value_comp (comp)
		{
//			_allocator = alloc;
//			_compare = comp;
//			_value_comp = comp;
			insert(first, last);
		}

		 map(const map &x) : _value_comp(x._value_comp)
		 {
		 	_allocator = x._allocator;
		 	_compare = x._compare;
		 	insert(x.begin(), x.end());
		 }

		~map()
		{
			clear();
			//delete _tree.maximum(_tree.getRoot());
		}

		map &operator=(const map &x)
		{
			clear();
			insert(x.begin(), x.end());
			return (*this);
		}

//capacity
	 	bool				empty() const		{return (_tree.size() == 0);}
	 	size_t				size() const		{return (_tree.size());}
	 	size_t				max_size() const
	 	{
	 		return (std::numeric_limits<size_t>::max() / (sizeof(TreeNode<Key, T>)));
	 	}

//iterators
		iterator				begin() 			{return (iterator(_tree.minimum(_tree.getRoot()), &_tree));}
	 	const_iterator			begin() const 		{return (const_iterator(_tree.minimum(_tree.getRoot()), &_tree));}
		iterator				end() 				{return (++iterator(_tree.maximum(_tree.getRoot()), &_tree));}
	 	const_iterator			end() const 		{return (++const_iterator(_tree.maximum(_tree.getRoot()), &_tree));}
	 	reverse_iterator		rbegin() 			{return (reverse_iterator(_tree.maximum(_tree.getRoot()), &_tree));}
	 	const_reverse_iterator	rbegin() const 		{return (const_reverse_iterator(_tree.maximum(_tree.getRoot()), &_tree));}
	 	reverse_iterator		rend() 				{return (++reverse_iterator(_tree.minimum(_tree.getRoot()), &_tree)); }
	 	const_reverse_iterator	rend()const  		{return (++const_reverse_iterator(_tree.minimum(_tree.getRoot()), &_tree));}

		void printTree() {
			_tree.prettyPrint();
		}


		// **       Element access
		// если ключа нет - то function inserts a new element with that key and returns a reference to its mapped value
		// если ключ есть - то function returns a reference to its mapped value
		mapped_type &			 operator[](const key_type &k)
	 	{
//			std::cout << "operator[] : Looking for a [" << k << "] key" << std::endl;
			_node_pointer node = _tree.searchTree(k);
			if (node == nullptr) {
//				std::cout << "operator[] : Key [" << k << "] not found" << std::endl;
				ft::pair<const Key, T> val(k, T());
				_tree.insert(k, val);
				node = _tree.searchTree(k);
//				std::cout << "operator[] : Inserted new node with key [" << node->data << "] and value [" << node->dataValue.second << "]" << std::endl;
				if (node) {
//					std::cout << "operator[] : Returning value" << std::endl;
					return (node->dataValue.second);
				}
				else {
					std::cout << "Something went wrong with map::insert()" << std::endl;
					exit (6);
				}
			}
			else {
//				std::cout << "operator[] : Key [" << k << "] found" << std::endl;
//				std::cout << "operator[] : Returning its value [" << node->dataValue.second << "]" << std::endl;
				return (node->dataValue.second);
			}
	 	}

//modifiers

	// insert single element (1)
	ft::pair<iterator,bool> insert (const value_type& val) {
			// returns a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or
			// 		to the element with an equivalent key in the map.
			// The pair::second element in the pair is set to true if a new element was inserted or
			// 		false if an equivalent key already existed.
		_node_pointer node = _tree.searchTree(val.first);
		if (!node) {
			_tree.insert(val.first, val);
			return (ft::make_pair(iterator(_tree.searchTree(val.first), &_tree), true));
		}
		else {
			return (ft::make_pair(iterator(node, &_tree), false));
		}
	}

	// insert with hint (2)
	iterator insert (iterator position, const value_type& val) {
		(void)position;
		_node_pointer node = _tree.searchTree(val.first);
		if (!node) {
			_tree.insert(val.first, val);
			return (iterator(_tree.searchTree(val.first), &_tree));
		}
		else {
			return (iterator(node, &_tree));
		}
	}

	// insert range (3)
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		while (first != last) {
			insert(*first);
			first++;
		}
	}

	 void erase (iterator position) {
	 	_node_pointer tmp = _tree.searchTree((*position).first);
	 	if (tmp == nullptr)
	 			return ;
	 	_tree.deleteNode((*position).first);
	 }

	 size_t erase(const key_type &k)
	 	{
	 		_node_pointer tmp = _tree.searchTree(k);
	 		if (tmp == nullptr)
	 			return 0;
	 		_tree.deleteNode(k);
	 		return 1;
	 	}

		void erase (iterator first, iterator last) {
			while (first != last)
				erase(first++);
		}

		void clear()
		{
			  iterator it = begin();
			  while (it != end()) {
                  erase(it++);
              }
		}

	 	void swap (map& x) {
			map<Key, T> temp = *this;
			*this = x;
			x = temp;
			temp.clear();
	 	}


	//                            Operations
		iterator find (const key_type& k) {
			_node_pointer node = _tree.searchTree(k);
			if (!node)
				return (end());
			else
				return (iterator(node, &_tree));
		}

		const_iterator find (const key_type& k) const {
			_node_pointer node = _tree.searchTree(k);
			if (!node)
				return (end());
			else
				return (const_iterator(node, &_tree));
		}

		size_t count (const key_type& k) const {
			_node_pointer node = _tree.searchTree(k);
			if (!node)
				return (0);
			else
				return (1);
		}

		// the first element in the container whose key is equivalent or goes after.
		// returning an iterator to the first element for which key_comp(element_key,k) would return false
		iterator lower_bound (const key_type& k) {
			iterator tmp = iterator(_tree.minimum(_tree.getRoot()), &_tree);
			iterator last = end();

			while (tmp != last) {
				if (k == tmp._node->dataValue.first)
					return tmp;
				if (_compare(k, tmp._node->dataValue.first))
					return tmp;
				tmp++;
			}
			return (last);
		}

		const_iterator lower_bound (const key_type& k) const {
			const_iterator tmp = iterator(_tree.minimum(_tree.getRoot()), &_tree);
			const_iterator last = end();

			while (tmp != last) {
				if (k == tmp._node->dataValue.first)
					return tmp;
				if (_compare(k, tmp._node->dataValue.first))
					return tmp;
				tmp++;
			}
			return (last);
		}

		iterator upper_bound (const key_type& k) {
			iterator tmp = iterator(_tree.minimum(_tree.getRoot()), &_tree);
			iterator last = end();

			while (tmp != last) {
				if (k == tmp._node->dataValue.first)
					return (++tmp);
				if (_compare(k, tmp._node->dataValue.first))
					return tmp;
				tmp++;
			}
			return (last);
		}

		// returning an iterator to the first element for which key_comp(k,element_key) would return true
		const_iterator upper_bound (const key_type& k) const {
			const_iterator tmp = iterator(_tree.minimum(_tree.getRoot()), &_tree);
			const_iterator last = end();

			while (tmp != last) {
				if (k == tmp._node->dataValue.first)
					return (++tmp);
				if (_compare(k, tmp._node->dataValue.first))
					return tmp;
				tmp++;
			}
			return (last);
		}

		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		ft::pair<iterator,iterator>             equal_range (const key_type& k) {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}

		//observers
		key_compare key_comp() const {
			return (_compare);
		}

		 value_compare value_comp() const {
		 	return (_value_comp);
		 }
	};

	//
	//  N O N - M E M B E R S
	//

	template <class Key, class T>
	void swap (ft::map<Key, T>& x, ft::map<Key, T>& y) { x.swap(y); }
}

#endif
