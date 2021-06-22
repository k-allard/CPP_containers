#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../header.hpp"

namespace ft
{
	template <typename T, typename Key>
	class MapIterator
	{
	public:
		typedef T value_type;
		typedef std::pair<Key, T> pair_type;
		typedef pair_type *pointer;
		typedef pair_type &reference;
		typedef TreeNode<Key, T> node_type;
		typedef node_type * node_pointer;
		typedef RBTree<Key, T> tree_type;
		node_pointer _node;

		tree_type _tree;

	public:
		// MapIterator() 					: _node(nullptr) {}
		// MapIterator(node_pointer p) 	: _node(p) {}

		MapIterator & operator=(const MapIterator &src) { _node = src._node; return (*this); }
		reference & operator*() const { return (_node->element); }
		MapIterator & operator++() {
			_node = _tree.successor(_node);
			return (*this);
		}

		MapIterator & operator--() {
			_node = _tree.predecessor(_node);
			return (*this);
		}

		MapIterator operator++(int) {
			MapIterator curr = *this;
			_node = _tree.successor(_node);
			return (curr);
		}

		MapIterator operator--(int) {
			MapIterator curr = *this;
			_node = _tree.predecessor(_node);
			return (curr);
		}

		bool operator==(const MapIterator & second) const
		{ return (_node == second._node); }

		bool operator!=(const MapIterator & second) const
		{ return (_node != second._node); }
	};



} //ft:: end
#endif