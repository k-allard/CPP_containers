#pragma once

#include <iostream>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <sstream>
#include <unistd.h>


#include <vector>


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
    Key data;
	T dataValue; 	// holds the key and value
	TreeNode *parent; 				// pointer to the parent
	TreeNode *left; 				// pointer to left child
	TreeNode *right; 				// pointer to right child
	int color; 					// 1 -> Red, 0 -> Black

	
};

// const                         /* this is a const object...     */
// class nullptr_t
// {
// public:
//     template<class T>          /* convertible to any type       */
//     operator T*() const        /* of null non-member            */
//     { return 0; }           /* pointer...                    */

//     template<class C, class T> /* or any type of null           */
//     operator T C::*() const /* member pointer...             */
//     { return 0; }

// private:
//     void operator&() const;    /* Can't take address of nullptr */

// } nullptr = {};               /* and whose name is nullptr     */

#include "ifInteger.hpp"
#include "vector/vectorIterator.hpp"
#include "vector/vector.hpp"
#include "vector/vectorTester.hpp"

#include "list/listIterator.hpp"
#include "list/list.hpp"
#include "list/listTester.hpp"

#include "map/RBTree.hpp"
#include "map/mapIterator.hpp"
#include "map/map.hpp"
#include "map/mapTester.hpp"
