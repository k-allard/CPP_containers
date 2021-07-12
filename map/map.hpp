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
		typedef Compare					key_compare;
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
				bool operator() (const value_type& x, const value_type& y) const
				{
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
        typedef MapIterator<Key, value_type>		iterator;
        typedef MapIterator<Key, value_type>		const_iterator;
	//
	//  C O N S T R U C T O R S  &  D E S T R U C T O R
	//
		explicit
		map(const key_compare &comp = key_compare(), const allocator_type &allocator = allocator_type()) : _allocator(allocator), _compare(comp), _value_comp(comp) { }

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

//		~map()
//		{
//			clear();
//			//delete _tree.maximum(_tree.getRoot());
//		}

		map &operator=(const map &x)
		{
			clear();
			insert(x.begin(), x.end());
			return (*this);
		}

	// 	/*
	// ** --------------------------------------------------------------------------------
	// **                                  Capacity
	// ** --------------------------------------------------------------------------------
	// */
	 	bool				empty() const		{return (_tree.size() == 0);}
	 	size_t				size() const		{return (_tree.size());}
	 	size_t				max_size() const
	 	{
	 		return (std::numeric_limits<size_t>::max() / (sizeof(TreeNode<Key, T>)));
	 	}

	// /*
	// ** --------------------------------------------------------------------------------
	// **                                Iterators
	// ** --------------------------------------------------------------------------------
	// */
		iterator				begin() 			{return (iterator(_tree.minimum(_tree.getRoot())));}
	 	const_iterator			begin() const 		{return (const_iterator(_tree.minimum(_tree.getRoot())));}
		iterator				end() 				{return (iterator(_tree.maximum(_tree.getRoot())));}
	 	const_iterator			end() const 		{return (const_iterator(_tree.maximum(_tree.getRoot())));}
	// 	reverse_iterator		rbegin() 			{return (reverse_iterator(_tree._end->parent ? _tree._end->parent : _tree._end));}
	// 	const_reverse_iterator	rbegin() const 		{return (const_reverse_iterator(_tree._end->parent ? _tree._end->parent : _tree._end));}
	// 	reverse_iterator		rend() 				{return (reverse_iterator(_tree._end));}
	// 	const_reverse_iterator	rend()const  		{return (const_reverse_iterator(_tree._end));}

	// **       Element access

	// если ключа нет - то function inserts a new element with that key and returns a reference to its mapped value
		// если ключ есть - то function returns a reference to its mapped value
		mapped_type &			 operator[](const key_type &k)
	 	{
			_node_pointer node = _tree.searchTree(k);
			if (!node) {
				_tree.insert(k, nullptr);
				node = _tree.searchTree(k);
				if (node)
					return (node->dataValue.second);
				else {
					std::cout << "Something went wrong with insert()" << std::endl;
					exit (6);
				}
			}
			else {
				return (node->dataValue.second);
			}
	// 		_node_pointer curr = _tree.find_place(k, _tree._root);
	// 		if (!curr)
	// 		{
	// 			insert(ft::make_pair(k, mapped_type()));
	// 			curr = _tree.find_place(k, _tree._root);
	// 		}
	// 		return (curr->element.second);
	 	}

	// /*
	// **                                  Modifiers
	// */

	// insert single element (1)
	ft::pair<iterator,bool> insert (const value_type& val) {
			// returns a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or
			// 		to the element with an equivalent key in the map.
			// The pair::second element in the pair is set to true if a new element was inserted or
			// 		false if an equivalent key already existed.
		_node_pointer node = _tree.searchTree(val.first);
		if (!node) {
			_tree.insert(val.first, val);
			return (ft::make_pair(iterator(_tree.searchTree(val.first)), true));
		}
		else {
			return (ft::make_pair(iterator(node), false));
		}
	}

	// insert with hint (2)
	iterator insert (iterator position, const value_type& val) {

	}

	// insert range (3)
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		while (first != last)
		{
			insert(*first);
			first++;
		}
	}

	// ERASE


		// CLEAR
		void clear()
		{
			// iterator it = begin();
			// while (it != end())
			// 	erase(it++);
		}

	// 	// SWAP
	// 	void swap (map& x)
	// 	{

	// 	}

	// /*
	// ** --------------------------------------------------------------------------------
	// **                                  Operations
	// ** --------------------------------------------------------------------------------
	// */
	// 	iterator find(const key_type &k)


	/*
	** --------------------------------------------------------------------------------
	**                                  Observers
	** --------------------------------------------------------------------------------
	*/
		key_compare key_comp() const
		{
			return (_compare);
		}

		// value_compare value_comp() const
		// {
		// 	return _value_comp;
		// }
	};
}


#endif
