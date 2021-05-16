#pragma once

#include <iostream>
#include <stdexcept>
#include <limits>

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