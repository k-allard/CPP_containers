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