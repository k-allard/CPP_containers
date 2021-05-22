#pragma once

#include <iostream>
#include <stdexcept>
#include <limits>
#include <sstream>

#include <vector>
#include "vectorIterator.hpp"
#include "vector.hpp"
#include "vectorTester.hpp"

// A DLL 
template <typename T>
struct node
{
	T data;
	struct node *prev;
	struct node *next;

	node() : data(T()) {}
	node(const T &value) : data(value) {}
};