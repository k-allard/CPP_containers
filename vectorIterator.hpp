//
//  V E C T O R   I T E R A T O R S
//

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "header.hpp"

namespace ft
{
	template <typename T1>
	class vectorIterator
	{
	public:
		typedef T1						value_type;
		typedef T1&						reference;
		typedef T1*						pointer;
		pointer							node;

		vectorIterator() : node(nullptr) {}
		vectorIterator(pointer p) : node(p) {}
		vectorIterator(const vectorIterator& rhs): node(rhs.node) {}
		vectorIterator & operator=(const vectorIterator &src);
		~vectorIterator() {}

		reference operator*();
		pointer operator->();
		reference operator[](size_t n);
		vectorIterator &operator++();
		vectorIterator &operator--();
		vectorIterator operator++(int);
		vectorIterator operator--(int);
		vectorIterator &operator+=(int n);
		vectorIterator &operator-=(int n);
		vectorIterator operator+(int n) const;
		vectorIterator operator-(int n) const;
		size_t operator-(vectorIterator & rhs) const;
		bool operator==(const vectorIterator & second) const;
		bool operator!=(const vectorIterator & second) const;

	};

	template<typename T>
	class vectorRevIterator {
	public:
		typedef T1						value_type;
		typedef T1&						reference;
		typedef T1*						pointer;
		pointer							node;
		
		vectorRevIterator(): node(nullptr) {}
		vectorIterator(pointer p) : node(p) {}
		vectorRevIterator(const vectorRevIterator& rhs): node(rhs.node) {}
		vectorRevIterator& operator=(const vectorRevIterator& rhs);
		~vectorRevIterator() {}

		reference operator*() { return (*(node - 1)); }
		pointer operator->() { return (node); }
		reference operator[](size_t n) { return (*(node + n - 1)); }
		vectorIterator &operator++();
		vectorIterator &operator--();
		vectorIterator operator++(int);
		vectorIterator operator--(int);
		vectorIterator &operator+=(int n);
		vectorIterator &operator-=(int n);
		vectorIterator operator+(int n) const;
		vectorIterator operator-(int n) const {	return (node - rhs.node); }
		size_t operator-(vectorIterator & rhs) const;
		bool operator==(const vectorIterator & second) const { return (node == rhs.node); }
		bool operator!=(const vectorIterator & second) const { return (node != rhs.node); }

	};



// vectorIterator
	// перегрузка оператора присваивания
	template <typename T1> 
	vectorIterator<T1> &vectorIterator<T1>::operator=(const vectorIterator &src) {
		node = src.node; 
		return (*this); 
	}

	// dereference iterator returns a reference to the element pointed to by the iterator
	template <typename T1> 
	typename vectorIterator<T1>::reference vectorIterator<T1>::operator*() { 
		return (*node);
	}

	// dereference iterator returns a pointer to the element pointed to by the iterator (in order to access one of its members)
	template <typename T1> 
	typename vectorIterator<T1>::pointer vectorIterator<T1>::operator->() { 
		return (node); 
	}

	// pre-increment - перемещение итератора вперед для обращения к следующему элементу
	template <typename T1> 
	vectorIterator<T1> &vectorIterator<T1>::operator++() { 
		node++; 
		return (*this); 
	}

	// post-increment - returns the value *this had before the call
	template <typename T1> 
	vectorIterator<T1> vectorIterator<T1>::operator++(int)	{ 
		vectorIterator temp = *this;
		node++;
		return (temp);
	}

	// pre-decrement - перемещение итератора назад для обращения к предыдущему элементу
	template <typename T1> 
	vectorIterator<T1> &vectorIterator<T1>::operator--() { 
		node--; 
		return (*this); 
	}

	// post-decrement
	template <typename T1> 
	vectorIterator<T1>	vectorIterator<T1>::operator--(int) {
		vectorIterator temp = *this;
		node--;
		return (temp);
	}

	// два итератора равны, если они указывают на один и тот же элемент
	template <typename T1> 
	bool vectorIterator<T1>::operator==(const vectorIterator & second) const { 
		return (node == second.node); 
	}

	// два итератора не равны, если они указывают на разные элементы
	template <typename T1> 
	bool vectorIterator<T1>::operator!=(const vectorIterator & second) const { 
		return (node != second.node); 
	}

	// возвращает итератор, который смещен от итератора iter на n позиций вперед
	template <typename T1> 
	vectorIterator<T1> vectorIterator<T1>::operator+(int n) const {
		vectorIterator temp = *this;
		temp.node += n;
		return temp;
	}

	// возвращает итератор, который смещен от итератора iter на n позиций назад
	template <typename T1> 
	vectorIterator<T1>	vectorIterator<T1>::operator-(int n) const {
		vectorIterator temp = *this;
		temp.node -= n;
		return temp;
	}

	// перемещает итератор на n позиций вперед
	template <typename T1> 
	vectorIterator<T1> &vectorIterator<T1>::operator+=(int n) { 
		node += n; 
		return (*this); 
	}

	// перемещает итератор на n позиций назад
	template <typename T1> 
	vectorIterator<T1> &vectorIterator<T1>::operator-=(int n) { 
		node -= n; 
		return (*this); 
	}

	// dereference iterator with offset accesses the element located n positions away from the element currently pointed to
	template <typename T1> 
	typename vectorIterator<T1>::reference vectorIterator<T1>::operator[](size_t n) { 
		return (*(node + n)); 
	}

	// возвращает количество позиций между итераторами iter1 и iter2
	template <typename T1> 
	size_t vectorIterator<T1>::operator-(vectorIterator & iter2) const { 
		return (node - iter2.node); 
	}

// vectorRevIterator
	template <typename T1>
	vectorRevIterator<T1> &vectorRevIterator<T1>::operator=(const vectorRevIterator<T1>& rhs) {
		node = rhs.node;
		return (*this);
	}

	template <typename T1>
	vectorRevIterator<T1>& vectorRevIterator<T1>::operator++() {
		--node;
		return (*this);
	}

	template <typename T1>
		vectorRevIterator<T1> vectorRevIterator<T1>::operator++(int) {
			vectorRevIterator<T1> tmp(*this);
			operator++();
			return (tmp);
		}

	template <typename T1>
			vectorRevIterator<T1>&	vectorRevIterator<T1>::operator--() {
				++node;
				return (*this);
			}

	template <typename T1>
			vectorRevIterator<T1>	vectorRevIterator<T1>::operator--(int) {
				vectorRevIterator<T1> tmp(*this);
				operator--();
				return (tmp);
			}

	template <typename T1>
			vectorRevIterator<T1>& vectorRevIterator<T1>::operator+=(int n) {
				node -= n;
				return (*this);
			}

	template <typename T1>
			vectorRevIterator<T1>& vectorRevIterator<T1>::operator-=(int n) {
				node += n;
				return (*this);
			}

	template <typename T1>
			vectorRevIterator<T1>	vectorRevIterator<T1>::operator+(int n) const {
				vectorRevIterator<T1> it(*this);
				return (it -= n);
			}



	template <typename T1>
			vectorRevIterator<T1>	vectorRevIterator<T1>::operator-(int n) const {
				vectorRevIterator<T1> it(*this);
				return (it += n);
			}

}
#endif