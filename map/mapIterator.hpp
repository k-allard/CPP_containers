#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../header.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare, typename Alloc>
	class MapIterator
	{
	public:
		typedef T value_type;
		typedef T pair_type;
		typedef pair_type *pointer;
		typedef pair_type &reference;
		typedef TreeNode<Key, T> node_type;
		typedef node_type * node_pointer;
        typedef RBTree<Key, T, Compare, Alloc> tree_type;
        typedef tree_type * tree_pointer;
		node_pointer _node;

        tree_pointer _tree;

	public:
		MapIterator() 					: _node(nullptr), _tree(nullptr) {}
		MapIterator(node_pointer p, tree_pointer t) 	: _node(p), _tree(t) {}

		MapIterator & operator=(const MapIterator &src) { _node = src._node; return (*this); }

		reference & operator*() const {
		    return (_node->dataValue);
		}

		MapIterator & operator++() {
			_node = _tree->successor(_node);
			return (*this);
		}

		MapIterator & operator--() {
			_node = _tree->predecessor(_node);
			return (*this);
		}

		MapIterator operator++(int) {
			MapIterator curr = *this;
			_node = _tree->successor(_node);
			return (curr);
		}

		MapIterator operator--(int) {
			MapIterator curr = *this;
			_node = _tree->predecessor(_node);
			return (curr);
		}

		bool operator==(const MapIterator & second) const
		{ return (_node == second._node); }

		bool operator!=(const MapIterator & second) const
		{ return (_node != second._node); }

	};


    template <typename Key, typename T, typename Compare, typename Alloc>
    class ConstMapIterator
    {
    public:
        typedef T value_type;
        typedef T pair_type;
        typedef pair_type *pointer;
        typedef pair_type &reference;
        typedef TreeNode<Key, T> node_type;
        typedef node_type * node_pointer;
        typedef const RBTree<Key, T, Compare, Alloc> tree_type;
        typedef tree_type * tree_pointer;
        node_pointer _node;

        tree_pointer _tree;

    public:
        ConstMapIterator() 					: _node(nullptr), _tree(nullptr) {}
        ConstMapIterator(node_pointer p, tree_pointer const t) 	: _node(p), _tree(t) {}

        ConstMapIterator & operator=(const ConstMapIterator &src) { _node = src._node; return (*this); }
        reference & operator*() const { return (_node->dataValue); }
        ConstMapIterator & operator++() {
            _node = _tree->successor(_node);
            return (*this);
        }

        ConstMapIterator & operator--() {
            _node = _tree->predecessor(_node);
            return (*this);
        }

        ConstMapIterator operator++(int) {
            ConstMapIterator curr = *this;
            _node = _tree->successor(_node);
            return (curr);
        }

        ConstMapIterator operator--(int) {
            ConstMapIterator curr = *this;
            _node = _tree->predecessor(_node);
            return (curr);
        }

        bool operator==(const ConstMapIterator & second) const
        { return (_node == second._node); }

        bool operator!=(const ConstMapIterator & second) const
        { return (_node != second._node); }
    };
} //ft:: end
#endif
