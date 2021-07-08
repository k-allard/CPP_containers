// a sorted associative container 
// contains key-value pairs with unique keys
// implemented as a red-black tree
// keys are sorted by using the comparison function Compare

#ifndef MAP_HPP
# define MAP_HPP

#include "../header.hpp"
#include <iostream>
#include <map>

namespace ft
{
    template <class Key,
          class T,
		  class Compare =  std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key,T> > >
    class map
    {
        typedef Key key_type;
		typedef T value_type;
		typedef std::pair<const key_type, value_type> pair_type;
		typedef Allocator allocator_type;
		typedef Compare compare;
		typedef value_type & reference;
		typedef const value_type & const_reference;
		typedef value_type * pointer;
		typedef const value_type * const_pointer;
		typedef RBTree<Key, T, compare> tree_type;
		typedef MapIterator<T, Key>	iterator;

        typedef TreeNode<Key, T>		_node;
		typedef _node *					_node_pointer;
		allocator_type					_allocator;
		compare				    		_compare;
		tree_type						_tree;
    public:
    /*
	** --------------------------------------------------------------------------------
	**                               Constructors & other
	** --------------------------------------------------------------------------------
	*/
		explicit
		map(const compare &comp = compare(), const allocator_type &allocator = allocator_type()) : _allocator(allocator), _compare(comp) {}//, _value_comp(comp) {}
		
        // template <class InputIterator>
		// map(InputIterator first, InputIterator last, const compare &comp = compare(), const allocator_type &allocator = allocator_type())
		// {
		// 	_allocator = allocator;
		// 	_compare = comp;
		// 	insert(first, last);
		// }

		// map(const map &x)
		// {
		// 	_allocator = x._allocator;
		// 	_compare = x._compare;
		// 	insert(x.begin(), x.end());
		// }

		~map()
		{
			clear();
			delete _tree.maximum(_tree.getRoot());
		}

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
	// 	bool					empty() const		{return (_tree._size == 0);}
	// 	size_type				size() const		{return (_tree._size);}
	// 	size_type				max_size() const
	// 	{
	// 		return (std::numeric_limits<size_type>::max() / (sizeof(TreeNode<Key, T>)));
	// 	}

	// /*
	// ** --------------------------------------------------------------------------------
	// **                                Iterators
	// ** --------------------------------------------------------------------------------
	// */
		iterator				begin() 			{return (iterator(_tree.minimum(_tree.getRoot())));}
	// 	const_iterator			begin() const 		{return (const_iterator(_tree._begin));}
		iterator				end() 				{return (iterator(_tree.maximum(_tree.getRoot())));}
	// 	const_iterator			end() const 		{return (const_iterator(_tree._end));}
	// 	reverse_iterator		rbegin() 			{return (reverse_iterator(_tree._end->parent ? _tree._end->parent : _tree._end));}
	// 	const_reverse_iterator	rbegin() const 		{return (const_reverse_iterator(_tree._end->parent ? _tree._end->parent : _tree._end));}
	// 	reverse_iterator		rend() 				{return (reverse_iterator(_tree._end));}
	// 	const_reverse_iterator	rend()const  		{return (const_reverse_iterator(_tree._end));}

	// /*
	// ** --------------------------------------------------------------------------------
	// **                               Element access
	// ** --------------------------------------------------------------------------------
	// */
	// 	mapped_type &			 operator[](const key_type &k)
	// 	{
	// 		_node_pointer curr = _tree.find_place(k, _tree._root);
	// 		if (!curr)
	// 		{
	// 			insert(std::make_pair(k, mapped_type()));
	// 			curr = _tree.find_place(k, _tree._root);
	// 		}
	// 		return (curr->element.second);
	// 	}

	// /*
	// ** --------------------------------------------------------------------------------
	// **                                  Modifiers
	// ** --------------------------------------------------------------------------------
	// */
	// 	std::pair<iterator,bool> insert (const value_type& val)
	// 	{

	// }

	// 	// ERASE
	

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
		compare key_comp() const
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