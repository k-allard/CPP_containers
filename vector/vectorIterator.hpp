//
//  V E C T O R   I T E R A T O R S
//

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "../header.hpp"

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

	template <typename T1>
	class vectorConstIterator
	{
	public:
		typedef const T1				value_type;
		typedef const T1&				reference;
		typedef const T1*				pointer;
		pointer							node;

		vectorConstIterator() : node(nullptr) {}
		vectorConstIterator(pointer p) : node(p) {}
		vectorConstIterator(const vectorConstIterator& rhs): node(rhs.node) {}
		vectorConstIterator & operator=(const vectorConstIterator &src);
		vectorConstIterator & operator=(const vectorIterator<T1> &src);
		~vectorConstIterator() {}

		reference operator*();
		pointer operator->();
		reference operator[](size_t n);
		vectorConstIterator &operator++();
		vectorConstIterator &operator--();
		vectorConstIterator operator++(int);
		vectorConstIterator operator--(int);
		vectorConstIterator &operator+=(int n);
		vectorConstIterator &operator-=(int n);
		vectorConstIterator operator+(int n) const;
		vectorConstIterator operator-(int n) const;
		size_t operator-(vectorConstIterator & rhs) const;
		bool operator==(const vectorConstIterator & second) const;
		bool operator!=(const vectorConstIterator & second) const;

	};

	template<typename T1>
	class vectorRevIterator {
	public:
		typedef T1						value_type;
		typedef T1&						reference;
		typedef T1*						pointer;
		pointer							node;

		vectorRevIterator(): node(nullptr) {}
		vectorRevIterator(pointer p) : node(p) {}
		vectorRevIterator(const vectorRevIterator& rhs): node(rhs.node) {}
		vectorRevIterator& operator=(const vectorRevIterator& rhs);
		~vectorRevIterator() {}

		reference operator*() { return (*(node - 1)); }
		pointer operator->() { return (node); }
		reference operator[](size_t n) { return (*(node + n - 1)); }
		vectorRevIterator &operator++();
		vectorRevIterator &operator--();
		vectorRevIterator operator++(int);
		vectorRevIterator operator--(int);
		vectorRevIterator &operator+=(int n);
		vectorRevIterator &operator-=(int n);
		vectorRevIterator operator+(int n) const;
		vectorRevIterator operator-(int n) const;
		size_t operator-(vectorRevIterator & rhs) const { return (node - rhs.node); }
		bool operator==(const vectorRevIterator & rhs) const { return (node == rhs.node); }
		bool operator!=(const vectorRevIterator & rhs) const { return (node != rhs.node); }
	};

	template<typename T1>
	class vectorConstRevIterator {
	public:
		typedef const T1						value_type;
		typedef const T1&						reference;
		typedef const T1*						pointer;
		pointer									node;

		vectorConstRevIterator(): node(nullptr) {}
		vectorConstRevIterator(pointer p) : node(p) {}
		vectorConstRevIterator(const vectorConstRevIterator& rhs): node(rhs.node) {}
		vectorConstRevIterator& operator=(const vectorConstRevIterator& rhs);
		vectorConstRevIterator& operator=(const ft::vectorRevIterator<T1>& rhs);
		~vectorConstRevIterator() {}

		reference operator*() { return (*(node - 1)); }
		pointer operator->() { return (node); }
		reference operator[](size_t n) { return (*(node + n - 1)); }
		vectorConstRevIterator &operator++();
		vectorConstRevIterator &operator--();
		vectorConstRevIterator operator++(int);
		vectorConstRevIterator operator--(int);
		vectorConstRevIterator &operator+=(int n);
		vectorConstRevIterator &operator-=(int n);
		vectorConstRevIterator operator+(int n) const;
		vectorConstRevIterator operator-(int n) const;
		size_t operator-(vectorConstRevIterator & rhs) const { return (node - rhs.node); }
		bool operator==(const vectorConstRevIterator & rhs) const { return (node == rhs.node); }
		bool operator!=(const vectorConstRevIterator & rhs) const { return (node != rhs.node); }
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

// vectorConstIterator
	// перегрузка оператора присваивания
	template <typename T1>
	vectorConstIterator<T1> &vectorConstIterator<T1>::operator=(const vectorConstIterator &src) {
		node = src.node;
		return (*this);
	}

	// перегрузка оператора присваивания
	template <typename T1>
	vectorConstIterator<T1> &vectorConstIterator<T1>::operator=(const vectorIterator<T1> &src) {
		node = src.node;
		return (*this);
	}

	// dereference iterator returns a reference to the element pointed to by the iterator
	template <typename T1>
	typename vectorConstIterator<T1>::reference vectorConstIterator<T1>::operator*() {
		return (*node);
	}

	// dereference iterator returns a pointer to the element pointed to by the iterator (in order to access one of its members)
	template <typename T1>
	typename vectorConstIterator<T1>::pointer vectorConstIterator<T1>::operator->() {
		return (node);
	}

	// pre-increment - перемещение итератора вперед для обращения к следующему элементу
	template <typename T1>
	vectorConstIterator<T1> &vectorConstIterator<T1>::operator++() {
		node++;
		return (*this);
	}

	// post-increment - returns the value *this had before the call
	template <typename T1>
	vectorConstIterator<T1> vectorConstIterator<T1>::operator++(int)	{
		vectorConstIterator temp = *this;
		node++;
		return (temp);
	}

	// pre-decrement - перемещение итератора назад для обращения к предыдущему элементу
	template <typename T1>
	vectorConstIterator<T1> &vectorConstIterator<T1>::operator--() {
		node--;
		return (*this);
	}

	// post-decrement
	template <typename T1>
	vectorConstIterator<T1>	vectorConstIterator<T1>::operator--(int) {
		vectorConstIterator temp = *this;
		node--;
		return (temp);
	}

	// два итератора равны, если они указывают на один и тот же элемент
	template <typename T1>
	bool vectorConstIterator<T1>::operator==(const vectorConstIterator & second) const {
		return (node == second.node);
	}

	// два итератора не равны, если они указывают на разные элементы
	template <typename T1>
	bool vectorConstIterator<T1>::operator!=(const vectorConstIterator & second) const {
		return (node != second.node);
	}

	// возвращает итератор, который смещен от итератора iter на n позиций вперед
	template <typename T1>
	vectorConstIterator<T1> vectorConstIterator<T1>::operator+(int n) const {
		vectorConstIterator temp = *this;
		temp.node += n;
		return temp;
	}

	// возвращает итератор, который смещен от итератора iter на n позиций назад
	template <typename T1>
	vectorConstIterator<T1>	vectorConstIterator<T1>::operator-(int n) const {
		vectorConstIterator temp = *this;
		temp.node -= n;
		return temp;
	}

	// перемещает итератор на n позиций вперед
	template <typename T1>
	vectorConstIterator<T1> &vectorConstIterator<T1>::operator+=(int n) {
		node += n;
		return (*this);
	}

	// перемещает итератор на n позиций назад
	template <typename T1>
	vectorConstIterator<T1> &vectorConstIterator<T1>::operator-=(int n) {
		node -= n;
		return (*this);
	}

	// dereference iterator with offset accesses the element located n positions away from the element currently pointed to
	template <typename T1>
	typename vectorConstIterator<T1>::reference vectorConstIterator<T1>::operator[](size_t n) {
		return (*(node + n));
	}

	// возвращает количество позиций между итераторами iter1 и iter2
	template <typename T1>
	size_t vectorConstIterator<T1>::operator-(vectorConstIterator & iter2) const {
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

// vectorConstRevIterator
	template <typename T1>
	vectorConstRevIterator<T1> &vectorConstRevIterator<T1>::operator=(const vectorConstRevIterator<T1>& rhs) {
		node = rhs.node;
		return (*this);
	}

	template <typename T1>
		vectorConstRevIterator<T1>& vectorConstRevIterator<T1>::operator=(const vectorRevIterator<T1>& rhs) {
		node = rhs.node;
		return (*this);
	}

	template <typename T1>
	vectorConstRevIterator<T1>& vectorConstRevIterator<T1>::operator++() {
		--node;
		return (*this);
	}

	template <typename T1>
		vectorConstRevIterator<T1> vectorConstRevIterator<T1>::operator++(int) {
			vectorConstRevIterator<T1> tmp(*this);
			operator++();
			return (tmp);
		}

	template <typename T1>
			vectorConstRevIterator<T1>&	vectorConstRevIterator<T1>::operator--() {
				++node;
				return (*this);
			}

	template <typename T1>
			vectorConstRevIterator<T1>	vectorConstRevIterator<T1>::operator--(int) {
				vectorConstRevIterator<T1> tmp(*this);
				operator--();
				return (tmp);
			}

	template <typename T1>
			vectorConstRevIterator<T1>& vectorConstRevIterator<T1>::operator+=(int n) {
				node -= n;
				return (*this);
			}

	template <typename T1>
	vectorConstRevIterator<T1>& vectorConstRevIterator<T1>::operator-=(int n) {
		node += n;
		return (*this);
	}

	template <typename T1>
	vectorConstRevIterator<T1>	vectorConstRevIterator<T1>::operator+(int n) const {
		vectorConstRevIterator<T1> it(*this);
		return (it -= n);
	}

	template <typename T1>
	vectorConstRevIterator<T1>	vectorConstRevIterator<T1>::operator-(int n) const {
		vectorConstRevIterator<T1> it(*this);
		return (it += n);
	}

	template <typename T1>
	bool operator>(vectorConstIterator<T1> &lhs, vectorIterator<T1> &rhs) { return( lhs.node > rhs.node );};

	template <typename T1>
	bool operator<(vectorConstIterator<T1> &lhs, vectorIterator<T1> &rhs) { return( lhs.node < rhs.node );};

	template <typename T1>
	bool operator>=(vectorConstIterator<T1> &lhs, vectorIterator<T1> &rhs) { return( lhs.node >= rhs.node );};

	template <typename T1>
	bool operator<=(vectorConstIterator<T1> &lhs, vectorIterator<T1> &rhs) { return( lhs.node <= rhs.node );};

	template <typename T1>
	bool operator==(vectorConstIterator<T1> &lhs, vectorIterator<T1> &rhs) { return( lhs.node == rhs.node );};

	template <typename T1>
	bool operator!=(vectorConstIterator<T1> &lhs, vectorIterator<T1> &rhs) { return( lhs.node != rhs.node );};

	template <typename T1>
	bool operator>(vectorIterator<T1> &lhs, vectorConstIterator<T1> &rhs) { return( lhs.node > rhs.node );};

	template <typename T1>
	bool operator<(vectorIterator<T1> &lhs, vectorConstIterator<T1> &rhs) { return( lhs.node < rhs.node );};

	template <typename T1>
	bool operator>=(vectorIterator<T1> &lhs, vectorConstIterator<T1> &rhs) { return( lhs.node >= rhs.node );};

	template <typename T1>
	bool operator<=(vectorIterator<T1> &lhs, vectorConstIterator<T1> &rhs) { return( lhs.node <= rhs.node );};

	template <typename T1>
	bool operator==(vectorIterator<T1> &lhs, vectorConstIterator<T1> &rhs) { return( lhs.node == rhs.node );};

	template <typename T1>
	bool operator!=(vectorIterator<T1> &lhs, vectorConstIterator<T1> &rhs) { return( lhs.node != rhs.node );};
}
#endif
