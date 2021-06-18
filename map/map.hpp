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
	// 	// INSERT
	// 	std::pair<iterator,bool> insert (const value_type& val)
	// 	{
	// 		_node_pointer tmp = _tree.find_place(val.first, _tree._root);
	// 		if (tmp == NULL)
	// 		{
	// 			_tree.insert_new_node(val);
	// 			return (std::make_pair(iterator(_tree.find_place(val.first, _tree._root)), true));
	// 		}
	// 		return (std::make_pair(iterator(tmp), false));
	// 	}
	// 	iterator insert(iterator position, const value_type &val)
	// 	{
	// 		(void)position;
	// 		_node_pointer tmp = _tree.find_place(val.first, _tree._root);
	// 		if (tmp == NULL)
	// 		{
	// 			_tree.insert_new_node(val);
	// 			return (iterator(_tree.find_place(val.first, _tree._root)));
	// 		}
	// 		return (iterator(tmp));
	// 	}
	// 	template <class InputIterator>
	// 	void insert(InputIterator first, InputIterator last)
	// 	{
	// 		while (first != last)
	// 		{
	// 			insert(*first);
	// 			first++;
	// 		}
	// 	}

	// 	// ERASE
	// 	void erase(iterator position)
	// 	{
	// 		_node_pointer tmp = _tree.find_place((*position).first, _tree._root);
	// 		if (tmp == NULL)
	// 			return;
	// 		_tree.erase(tmp);
	// 		_tree._size--;
	// 	}
	// 	size_type erase(const key_type &k)
	// 	{
	// 		_node_pointer tmp = _tree.find_place(k, _tree._root);
	// 		if (tmp == NULL)
	// 			return 0;
	// 		_tree.erase(tmp);
	// 		_tree._size--;
	// 		return 1;
	// 	}
	// 	void erase(iterator first, iterator last)
	// 	{
	// 		while (first != last)
	// 			erase(first++);
	// 	}

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
	// 		_node_pointer	tmp_root	= _tree._root;
	// 		_node_pointer	tmp_end		= _tree._end;
	// 		_node_pointer	tmp_begin 	= _tree._begin;
	// 		size_type	 	tmp_size	= _tree._size;
	// 		allocator_type	tmp_alloc	= _alloc;
	// 		compare		tmp_k_comp	= _comp;
	// 		value_compare	tmp_v_comp	= _value_comp;

	// 		_tree._root  = x._tree._root;
	// 		_tree._end	 = x._tree._end;
	// 		_tree._begin = x._tree._begin;
	// 		_tree._size	 = x._tree._size;
	// 		_alloc		 = x._alloc;
	// 		_comp		 = x._comp;
	// 		_value_comp  = x._value_comp;

	// 		x._tree._root  = tmp_root;
	// 		x._tree._end   = tmp_end;
	// 		x._tree._begin = tmp_begin;
	// 		x._tree._size  = tmp_size;
	// 		x._allocator 	   = tmp_alloc;
	// 		x._comp		   = tmp_k_comp;
	// 		x._value_comp  = tmp_v_comp;
	// 	}

	// /*
	// ** --------------------------------------------------------------------------------
	// **                                  Operations
	// ** --------------------------------------------------------------------------------
	// */
	// 	iterator find(const key_type &k)
	// 	{
	// 		_node_pointer tmp = _tree.find_place(k, _tree._root);
	// 		return (tmp == NULL ? end() : iterator(tmp));
	// 	}

	// 	const_iterator find(const key_type &k) const
	// 	{
	// 		_node_pointer tmp = _tree.find_place(k, _tree._root);
	// 		return (tmp == NULL ? end() : const_iterator(tmp));
	// 	}

	// 	iterator lower_bound(const key_type &k)
	// 	{
	// 		_node_pointer tmp = _tree.find_lower_bound(k);
	// 		return (tmp == NULL ? end() : iterator(tmp));
	// 	}

	// 	const_iterator lower_bound(const key_type &k) const
	// 	{
	// 		_node_pointer tmp = _tree.find_lower_bound(k);
	// 		return (tmp == NULL ? end() : const_iterator(tmp));
	// 	}

	// 	iterator upper_bound(const key_type &k)
	// 	{
	// 		_node_pointer tmp = _tree.find_lower_bound(k);
	// 		if (tmp)
	// 		{
	// 			_node_pointer equal = _tree.find_place(k, _tree._root);
	// 			if (equal)
	// 				return (++(iterator(equal)));
	// 			return (iterator(tmp));
	// 		}
	// 		return (end());
	// 	}

	// 	const_iterator upper_bound(const key_type &k) const
	// 	{
	// 		_node_pointer tmp = _tree.find_lower_bound(k);
	// 		if (tmp)
	// 		{
	// 			_node_pointer equal = _tree.find_place(k, _tree._root);
	// 			if (equal)
	// 				return (++(const_iterator(equal)));
	// 			return (const_iterator(tmp));
	// 		}
	// 		return (end());
	// 	}

	// 	std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
	// 	{
	// 		return (std::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
	// 	}

	// 	std::pair<iterator, iterator> equal_range(const key_type &k)
	// 	{
	// 		return (std::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
	// 	}

	// 	size_type count(const key_type &k) const
	// 	{
	// 		_node_pointer tmp = _tree.find_lower_bound(k);
	// 		return (tmp == NULL ? 0 : 1);
	// 	}

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