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

	public:
		vectorIterator() : node(nullptr) {}
		vectorIterator(pointer p) : node(p) {}
		vectorIterator & operator=(const vectorIterator &src);
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
		size_t operator-(vectorIterator & other) const;
		bool operator==(const vectorIterator & second) const;
		bool operator!=(const vectorIterator & second) const;

	};

	// перегрузка оператора присваиванияа
	template <typename T1> 
	vectorIterator<T1> &vectorIterator<T1>::operator=(const vectorIterator &src) {
		this.node = src.node; 
		return (*this); 
	}

	// dereference iterator returns a reference to the element pointed to by the iterator
	template <typename T1> 
	vectorIterator<T1>::reference vectorIterator<T1>::operator*() { 
		return (*this.node);
	}

	// dereference iterator returns a pointer to the element pointed to by the iterator (in order to access one of its members)
	template <typename T1> 
	vectorIterator<T1>::pointer vectorIterator<T1>::operator->() { 
		return (this.node); 
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
	vectorIterator<T1>::reference vectorIterator<T1>::operator[](size_t n) { 
		return (*(this.node + n)); 
	}

	// возвращает количество позиций между итераторами iter1 и iter2
	template <typename T1> 
	size_t vectorIterator<T1>::operator-(vectorIterator & iter2) const { 
		return (this.node - iter2.node); 
	}
	

}
#endif