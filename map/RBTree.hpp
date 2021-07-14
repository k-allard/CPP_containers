#ifndef RBTREE_HPP
# define RBTREE_HPP

// Red Black Tree implementation in C++
// Tutorial URL: https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/

#include <iostream>
#include "../header.hpp"
using namespace std;



namespace ft
{
	template < typename Key,
				typename T,
				typename Compare = std::less<Key>,
				typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class RBTree {
	public:
		typedef TreeNode<Key,T> *NodePtr;
		typedef Key key_type;
		typedef T value_type;
		typedef ft::pair<const key_type, value_type> pair;

	private:
		Compare	compare;
        Alloc alloc;
		NodePtr root;
		NodePtr TNULL;

		void initializeNULLNode(NodePtr node, NodePtr parent);
		void preOrderHelper(NodePtr node);
		void inOrderHelper(NodePtr node);
		void postOrderHelper(NodePtr node);
		NodePtr searchTreeHelper(NodePtr node, key_type key) const;
		void fixDelete(NodePtr x);
		void rbTransplant(NodePtr u, NodePtr v);
		void deleteNodeHelper(NodePtr node, key_type key);
		void fixInsert(NodePtr k);
		void printHelper(NodePtr root, string indent, bool last) const;
        std::size_t _size;

	public:
		RBTree();
        ~RBTree();
        size_t size() const { return _size ; }
		void preorder();
		void inorder();
		void postorder();
		NodePtr searchTree(key_type key) const;
		NodePtr minimum(NodePtr node) const;
		NodePtr maximum(NodePtr node) const;
		NodePtr successor(NodePtr x) const;
		NodePtr predecessor(NodePtr x) const;
		void leftRotate(NodePtr x);
		void rightRotate(NodePtr x);
		void insert(key_type key, value_type value);
        void insert(key_type key);
        void insert(NodePtr x);
//        void size() const;
		NodePtr getRoot() const;
		void deleteNode(key_type key);
		void prettyPrint() const;
		int isNull(NodePtr x) const { return (x == TNULL); };

	};

	// initializes the nodes with appropirate values
	// all the pointers are set to point to the null pointer
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::initializeNULLNode(NodePtr node, NodePtr parent) {
		node->data = 0;
		node->parent = parent;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 0;
	}

	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::preOrderHelper(NodePtr node) {
		if (node != TNULL) {
			cout<<node->data<<" ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		}
	}

	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::inOrderHelper(NodePtr node) {
		if (node != TNULL) {
			inOrderHelper(node->left);
			cout<<node->data<<" ";
			inOrderHelper(node->right);
		}
	}

	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::postOrderHelper(NodePtr node) {
		if (node != TNULL) {
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			cout<<node->data<<" ";
		}
	}

	template <typename Key, typename Type, typename Compare, typename Alloc>
	typename RBTree<Key, Type, Compare, Alloc>::NodePtr RBTree<Key, Type, Compare, Alloc>::searchTreeHelper(NodePtr node, key_type key) const {
		if (node == TNULL) {
			return nullptr;
		}
		if (key == node->data) {
			return node;
		}
		if (key < node->data) {
			return searchTreeHelper(node->left, key);
		}
		return searchTreeHelper(node->right, key);
	}

	// fix the rb tree modified by the delete operation
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::fixDelete(NodePtr x) {
		NodePtr s;
		while (x != root && x->color == 0) {
			if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == 1) {
					// case 3.1
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0) {
					// case 3.2
					s->color = 1;
					x = x->parent;
				} else {
					if (s->right->color == 0) {
						// case 3.3
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}

					// case 3.4
					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			} else {
				s = x->parent->left;
				if (s->color == 1) {
					// case 3.1
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0) {
					// case 3.2
					s->color = 1;
					x = x->parent;
				} else {
					if (s->left->color == 0) {
						// case 3.3
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					// case 3.4
					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}


	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::rbTransplant(NodePtr u, NodePtr v){
		if (u->parent == TNULL) {
			root = v;
		} else if (u == u->parent->left){
			u->parent->left = v;
		} else {
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::deleteNodeHelper(NodePtr node, key_type key) {
		// find the node containing key
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL){
			if (node->data == key) {
				z = node;
			}

			if (node->data <= key) {
				node = node->right;
			} else {
				node = node->left;
			}
		}

		if (z == TNULL) {
			cout<<"Couldn't find key in the tree"<<endl;
			return;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL) {
			x = z->right;
			rbTransplant(z, z->right);
		} else if (z->right == TNULL) {
			x = z->left;
			rbTransplant(z, z->left);
		} else {
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			} else {
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0){
			fixDelete(x);
		}
		_size--;
	}

	// fix the red-black tree
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::fixInsert(NodePtr k){
		NodePtr u;
		while (k->parent->color == 1) {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left; // uncle
				if (u->color == 1) {
					// case 3.1
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				} else {
					if (k == k->parent->left) {
						// case 3.2.2
						k = k->parent;
						rightRotate(k);
					}
					// case 3.2.1
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			} else {
				u = k->parent->parent->right; // uncle

				if (u->color == 1) {
					// mirror case 3.1
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				} else {
					if (k == k->parent->right) {
						// mirror case 3.2.2
						k = k->parent;
						leftRotate(k);
					}
					// mirror case 3.2.1
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root->color = 0;
	}

	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::printHelper(NodePtr root, string indent, bool last) const {
		// print the tree structure on the screen
		if (root != TNULL) {
		cout<<indent;
		if (last) {
			cout<<"R----";
			indent += "     ";
		} else {
			cout<<"L----";
			indent += "|    ";
		}

		string sColor = root->color?"RED":"BLACK";
		cout << "[" << root->data << "]:[" << root->dataValue.second << "]("<<sColor<<")" <<  endl;
		printHelper(root->left, indent, false);
		printHelper(root->right, indent, true);
		}
		// cout<<root->left->data<<endl;
	}

	template <typename Key, typename Type, typename Compare, typename Alloc>
	RBTree<Key, Type, Compare, Alloc>::RBTree() {
        _size = 0;
		TNULL = new TreeNode<Key, Type>;
		TNULL->color = 0;
		TNULL->left = TNULL;
		TNULL->right = TNULL;
		TNULL->parent = TNULL;
		root = TNULL;
	}

    template <typename Key, typename Type, typename Compare, typename Alloc>
    RBTree<Key, Type, Compare, Alloc>::~RBTree() {
        delete TNULL;

    }

	// Pre-Order traversal
	// Node->Left Subtree->Right Subtree
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::preorder() {
		preOrderHelper(this->root);
	}

	// In-Order traversal
	// Left Subtree -> Node -> Right Subtree
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::inorder() {
		inOrderHelper(this->root);
	}

	// Post-Order traversal
	// Left Subtree -> Right Subtree -> Node
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::postorder() {
		postOrderHelper(this->root);
	}

	// search the tree for the key k
	// and return the corresponding node
	template <typename Key, typename Type, typename Compare, typename Alloc>
	typename RBTree<Key, Type, Compare, Alloc>::NodePtr RBTree<Key, Type, Compare, Alloc>::searchTree(key_type key) const {
		return searchTreeHelper(this->root, key);
	}

	// find the node with the minimum key
	template <typename Key, typename Type, typename Compare, typename Alloc>
	typename RBTree<Key, Type, Compare, Alloc>::NodePtr  RBTree<Key, Type, Compare, Alloc>::minimum(NodePtr node) const {
		while (node->left != TNULL) {
			node = node->left;
		}
		return node;
	}

	// find the node with the maximum key
	template <typename Key, typename Type, typename Compare, typename Alloc>
	typename RBTree<Key, Type, Compare, Alloc>::NodePtr  RBTree<Key, Type, Compare, Alloc>::maximum(NodePtr node) const {
		while (node->right != TNULL) {
			node = node->right;
		}
		return node;
	}

	// find the successor of a given node
	template <typename Key, typename Type, typename Compare, typename Alloc>
	typename RBTree<Key, Type, Compare, Alloc>::NodePtr  RBTree<Key, Type, Compare, Alloc>::successor(NodePtr x) const {
		// if the right subtree is not null,
		// the successor is the leftmost node in the
		// right subtree
		if (x->right != TNULL) {
			return minimum(x->right);
		}

		// else it is the lowest ancestor of x whose
		// left child is also an ancestor of x.
		NodePtr y = x->parent;
		while (y != TNULL && x == y->right) {
			x = y;
			y = y->parent;
		}
		return y;
	}

	// find the predecessor of a given node
	template <typename Key, typename Type, typename Compare, typename Alloc>
	typename RBTree<Key, Type, Compare, Alloc>::NodePtr RBTree<Key, Type, Compare, Alloc>::predecessor(NodePtr x) const {
		// if the left subtree is not null,
		// the predecessor is the rightmost node in the
		// left subtree
		if (x->left != TNULL) {
			return maximum(x->left);
		}

		NodePtr y = x->parent;
		while (y != TNULL && x == y->left) {
			x = y;
			y = y->parent;
		}

		return y;
	}

	// rotate left at node x
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::leftRotate(NodePtr x) {
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != TNULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == TNULL) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	// rotate right at node x
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::rightRotate(NodePtr x) {
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != TNULL) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == TNULL) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

    // insert the key to the tree in its appropriate position
    // and fix the tree
    template <typename Key, typename Type, typename Compare, typename Alloc>
    void RBTree<Key, Type, Compare, Alloc>::insert(NodePtr node) {
        // Ordinary Binary Search Insertion


        NodePtr y = TNULL;
        NodePtr x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        // y is parent of x
        node->parent = y;
        if (y == TNULL) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }
		_size++;
        // if new node is a root node, simply return
        if (node->parent == TNULL){
            node->color = 0;
            return;
        }

        // if the grandparent is null, simply return
        if (node->parent->parent == TNULL) {
            return;
        }

        // Fix the tree
        fixInsert(node);
    }

    // insert the key to the tree in its appropriate position
    // and fix the tree
    template <typename Key, typename Type, typename Compare, typename Alloc>
    void RBTree<Key, Type, Compare, Alloc>::insert(key_type key) {
        // Ordinary Binary Search Insertion

        //TreeNode<Key, Type> tree_node = { key, value, TNULL, TNULL, TNULL, 1};
        //NodePtr node = &tree_node;
        NodePtr node = new TreeNode<Key, Type>();
        node->data = key;
        NodePtr ptr = alloc.allocate(1);
        node->dataValue = *ptr;

        node->parent = TNULL;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1; // new node must be red
        insert(node);
    }

	// insert the key to the tree in its appropriate position
	// and fix the tree
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::insert(key_type key, value_type value) {
		// Ordinary Binary Search Insertion

		//TreeNode<Key, Type> tree_node = { key, value, TNULL, TNULL, TNULL, 1};
		//NodePtr node = &tree_node;
		NodePtr node = new TreeNode<Key, Type>(key, value, TNULL);
//		node->data = key;
//		node->dataValue = value;
//		node->parent = TNULL;
//		node->left = TNULL;
//		node->right = TNULL;
//		node->color = 1; // new node must be red
        insert(node);
	}

	template <typename Key, typename Type, typename Compare, typename Alloc>
	typename RBTree<Key, Type, Compare, Alloc>::NodePtr RBTree<Key, Type, Compare, Alloc>::getRoot() const {
		return this->root;
	}

	// delete the node from the tree
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::deleteNode(key_type key) {
		deleteNodeHelper(this->root, key);
	}

	// print the tree structure on the screen
	template <typename Key, typename Type, typename Compare, typename Alloc>
	void RBTree<Key, Type, Compare, Alloc>::prettyPrint() const {
		if (root) {
			printHelper(this->root, "", true);
		}
	}
}

#endif
