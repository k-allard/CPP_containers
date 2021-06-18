#pragma once

#include <iostream>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <sstream>
#include <unistd.h>


#include <vector>
#include "ifInteger.hpp"
#include "vector/vectorIterator.hpp"
#include "vector/vector.hpp"
#include "vector/vectorTester.hpp"

template <typename T>
struct ListNode
{
	T data;
	struct ListNode *prev;
	struct ListNode *next;

	ListNode() : data(T()) {}
	ListNode(const T &value) : data(value) {}
};

// data structure that represents a node in the tree
template <typename Key, typename T>
struct TreeNode {
	std::pair<const Key, T> data; 	// holds the key and value
	TreeNode *parent; 				// pointer to the parent
	TreeNode *left; 				// pointer to left child
	TreeNode *right; 				// pointer to right child
	int color; 					// 1 -> Red, 0 -> Black

	
};

#include "list/listIterator.hpp"
#include "list/list.hpp"
#include "list/listTester.hpp"

#include "map/RBTree.hpp"
#include "map/mapIterator.hpp"
#include "map/map.hpp"
#include "map/mapTester.hpp"