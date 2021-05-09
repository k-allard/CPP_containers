//: C07:Ring.cpp
// Making a "ring" data structure from the STL.
#include <iostream>
#include <iterator>
#include <list>
#include <string>
using namespace std;
 
template<class T> class Ring {
	list<T> lst;
public:
	// Declaration necessary so the following
	// 'friend' statement sees this 'iterator'
	// instead of std::iterator:
	class iterator;
	friend class iterator;
	class iterator : public std::iterator<
	std::bidirectional_iterator_tag,T,ptrdiff_t>{
	typename list<T>::iterator it;
	list<T>* r;
public:
	iterator(list<T>& lst,
	const typename list<T>::iterator& i)
	: it(i), r(&lst) {}
	bool operator==(const iterator& x) const {
	return it == x.it;
	}
	bool operator!=(const iterator& x) const {
	return !(*this == x);
	}
	typename list<T>::reference operator*() const {
	return *it;
	}
	iterator& operator++() {
		++it;
		if(it == r->end())
		it = r->begin();
		return *this;
	}
	iterator operator++(int) {
		iterator tmp = *this;
		++*this;
		return tmp;
	}
	iterator& operator--() {
		if(it == r->begin())
		it = r->end();
		--it;
		return *this;
	}
	iterator operator--(int) {
	iterator tmp = *this;
	--*this;
	return tmp;
	}
	iterator insert(const T& x) {
	return iterator(*r, r->insert(it, x));
	}
	iterator erase() {
	return iterator(*r, r->erase(it));
	}
	};
	void push_back(const T& x) { lst.push_back(x); }
	iterator begin() { return iterator(lst, lst.begin()); }
	int size() { return lst.size(); }
};
 
