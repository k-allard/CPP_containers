//
//  V E C T O R   I T E R A T O R S COPY OF VECTOR ITERATOR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
//

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

#include "../header.hpp"

namespace ft
{
	template <typename T1>
	class listIterator
	{
	public:
		typedef T1						value_type;
		typedef T1&						reference;
		typedef T1*						pointer;
		pointer							node;

		listIterator() : node(nullptr) {}
		listIterator(pointer p) : node(p) {}
		listIterator(const listIterator& rhs): node(rhs.node) {}
		listIterator & operator=(const listIterator &src);
		~listIterator() {}

		reference operator*();
		pointer operator->();
		reference operator[](size_t n);
		listIterator &operator++();
		listIterator &operator--();
		listIterator operator++(int);
		listIterator operator--(int);
		listIterator &operator+=(int n);
		listIterator &operator-=(int n);
		listIterator operator+(int n) const;
		listIterator operator-(int n) const;
		size_t operator-(listIterator & rhs) const;
		bool operator==(const listIterator & second) const;
		bool operator!=(const listIterator & second) const;

	};

	template <typename T1>
	class listConstIterator
	{
	public:
		typedef const T1				value_type;
		typedef const T1&				reference;
		typedef const T1*				pointer;
		pointer							node;

		listConstIterator() : node(nullptr) {}
		listConstIterator(pointer p) : node(p) {}
		listConstIterator(const listConstIterator& rhs): node(rhs.node) {}
		listConstIterator & operator=(const listConstIterator &src);
		listConstIterator & operator=(const listIterator<T1> &src);
		~listConstIterator() {}

		reference operator*();
		pointer operator->();
		reference operator[](size_t n);
		listConstIterator &operator++();
		listConstIterator &operator--();
		listConstIterator operator++(int);
		listConstIterator operator--(int);
		listConstIterator &operator+=(int n);
		listConstIterator &operator-=(int n);
		listConstIterator operator+(int n) const;
		listConstIterator operator-(int n) const;
		size_t operator-(listConstIterator & rhs) const;
		bool operator==(const listConstIterator & second) const;
		bool operator!=(const listConstIterator & second) const;

	};

	template<typename T1>
	class listRevIterator {
	public:
		typedef T1						value_type;
		typedef T1&						reference;
		typedef T1*						pointer;
		pointer							node;
		
		listRevIterator(): node(nullptr) {}
		listRevIterator(pointer p) : node(p) {}
		listRevIterator(const listRevIterator& rhs): node(rhs.node) {}
		listRevIterator& operator=(const listRevIterator& rhs);
		~listRevIterator() {}

		reference operator*() { return (*(node - 1)); }
		pointer operator->() { return (node); }
		reference operator[](size_t n) { return (*(node + n - 1)); }
		listRevIterator &operator++();
		listRevIterator &operator--();
		listRevIterator operator++(int);
		listRevIterator operator--(int);
		listRevIterator &operator+=(int n);
		listRevIterator &operator-=(int n);
		listRevIterator operator+(int n) const;
		listRevIterator operator-(int n) const;
		size_t operator-(listRevIterator & rhs) const { return (node - rhs.node); }
		bool operator==(const listRevIterator & rhs) const { return (node == rhs.node); }
		bool operator!=(const listRevIterator & rhs) const { return (node != rhs.node); }
	};

	template<typename T1>
	class listConstRevIterator {
	public:
		typedef const T1						value_type;
		typedef const T1&						reference;
		typedef const T1*						pointer;
		pointer									node;
		
		listConstRevIterator(): node(nullptr) {}
		listConstRevIterator(pointer p) : node(p) {}
		listConstRevIterator(const listConstRevIterator& rhs): node(rhs.node) {}
		listConstRevIterator& operator=(const listConstRevIterator& rhs);
		listConstRevIterator& operator=(const ft::listRevIterator<T1>& rhs);
		~listConstRevIterator() {}

		reference operator*() { return (*(node - 1)); }
		pointer operator->() { return (node); }
		reference operator[](size_t n) { return (*(node + n - 1)); }
		listConstRevIterator &operator++();
		listConstRevIterator &operator--();
		listConstRevIterator operator++(int);
		listConstRevIterator operator--(int);
		listConstRevIterator &operator+=(int n);
		listConstRevIterator &operator-=(int n);
		listConstRevIterator operator+(int n) const;
		listConstRevIterator operator-(int n) const;
		size_t operator-(listConstRevIterator & rhs) const { return (node - rhs.node); }
		bool operator==(const listConstRevIterator & rhs) const { return (node == rhs.node); }
		bool operator!=(const listConstRevIterator & rhs) const { return (node != rhs.node); }
	};


// listIterator
	// перегрузка оператора присваивания
	template <typename T1> 
	listIterator<T1> &listIterator<T1>::operator=(const listIterator &src) {
		node = src.node; 
		return (*this); 
	}

	// dereference iterator returns a reference to the element pointed to by the iterator
	template <typename T1> 
	typename listIterator<T1>::reference listIterator<T1>::operator*() { 
		return (*node);
	}

	// dereference iterator returns a pointer to the element pointed to by the iterator (in order to access one of its members)
	template <typename T1> 
	typename listIterator<T1>::pointer listIterator<T1>::operator->() { 
		return (node); 
	}

	// pre-increment - перемещение итератора вперед для обращения к следующему элементу
	template <typename T1> 
	listIterator<T1> &listIterator<T1>::operator++() { 
		node++; 
		return (*this); 
	}

	// post-increment - returns the value *this had before the call
	template <typename T1> 
	listIterator<T1> listIterator<T1>::operator++(int)	{ 
		listIterator temp = *this;
		node++;
		return (temp);
	}

	// pre-decrement - перемещение итератора назад для обращения к предыдущему элементу
	template <typename T1> 
	listIterator<T1> &listIterator<T1>::operator--() { 
		node--; 
		return (*this); 
	}

	// post-decrement
	template <typename T1> 
	listIterator<T1>	listIterator<T1>::operator--(int) {
		listIterator temp = *this;
		node--;
		return (temp);
	}

	// два итератора равны, если они указывают на один и тот же элемент
	template <typename T1> 
	bool listIterator<T1>::operator==(const listIterator & second) const { 
		return (node == second.node); 
	}

	// два итератора не равны, если они указывают на разные элементы
	template <typename T1> 
	bool listIterator<T1>::operator!=(const listIterator & second) const { 
		return (node != second.node); 
	}

	// возвращает итератор, который смещен от итератора iter на n позиций вперед
	template <typename T1> 
	listIterator<T1> listIterator<T1>::operator+(int n) const {
		listIterator temp = *this;
		temp.node += n;
		return temp;
	}

	// возвращает итератор, который смещен от итератора iter на n позиций назад
	template <typename T1> 
	listIterator<T1>	listIterator<T1>::operator-(int n) const {
		listIterator temp = *this;
		temp.node -= n;
		return temp;
	}

	// перемещает итератор на n позиций вперед
	template <typename T1> 
	listIterator<T1> &listIterator<T1>::operator+=(int n) { 
		node += n; 
		return (*this); 
	}

	// перемещает итератор на n позиций назад
	template <typename T1> 
	listIterator<T1> &listIterator<T1>::operator-=(int n) { 
		node -= n; 
		return (*this); 
	}

	// dereference iterator with offset accesses the element located n positions away from the element currently pointed to
	template <typename T1> 
	typename listIterator<T1>::reference listIterator<T1>::operator[](size_t n) { 
		return (*(node + n)); 
	}

	// возвращает количество позиций между итераторами iter1 и iter2
	template <typename T1> 
	size_t listIterator<T1>::operator-(listIterator & iter2) const { 
		return (node - iter2.node); 
	}

// listConstIterator
	// перегрузка оператора присваивания
	template <typename T1> 
	listConstIterator<T1> &listConstIterator<T1>::operator=(const listConstIterator &src) {
		node = src.node; 
		return (*this); 
	}

	// dereference iterator returns a reference to the element pointed to by the iterator
	template <typename T1> 
	typename listConstIterator<T1>::reference listConstIterator<T1>::operator*() { 
		return (*node);
	}

	// dereference iterator returns a pointer to the element pointed to by the iterator (in order to access one of its members)
	template <typename T1> 
	typename listConstIterator<T1>::pointer listConstIterator<T1>::operator->() { 
		return (node); 
	}

	// pre-increment - перемещение итератора вперед для обращения к следующему элементу
	template <typename T1> 
	listConstIterator<T1> &listConstIterator<T1>::operator++() { 
		node++; 
		return (*this); 
	}

	// post-increment - returns the value *this had before the call
	template <typename T1> 
	listConstIterator<T1> listConstIterator<T1>::operator++(int)	{ 
		listConstIterator temp = *this;
		node++;
		return (temp);
	}

	// pre-decrement - перемещение итератора назад для обращения к предыдущему элементу
	template <typename T1> 
	listConstIterator<T1> &listConstIterator<T1>::operator--() { 
		node--; 
		return (*this); 
	}

	// post-decrement
	template <typename T1> 
	listConstIterator<T1>	listConstIterator<T1>::operator--(int) {
		listConstIterator temp = *this;
		node--;
		return (temp);
	}

	// два итератора равны, если они указывают на один и тот же элемент
	template <typename T1> 
	bool listConstIterator<T1>::operator==(const listConstIterator & second) const { 
		return (node == second.node); 
	}

	// два итератора не равны, если они указывают на разные элементы
	template <typename T1> 
	bool listConstIterator<T1>::operator!=(const listConstIterator & second) const { 
		return (node != second.node); 
	}

	// возвращает итератор, который смещен от итератора iter на n позиций вперед
	template <typename T1> 
	listConstIterator<T1> listConstIterator<T1>::operator+(int n) const {
		listConstIterator temp = *this;
		temp.node += n;
		return temp;
	}

	// возвращает итератор, который смещен от итератора iter на n позиций назад
	template <typename T1> 
	listConstIterator<T1>	listConstIterator<T1>::operator-(int n) const {
		listConstIterator temp = *this;
		temp.node -= n;
		return temp;
	}

	// перемещает итератор на n позиций вперед
	template <typename T1> 
	listConstIterator<T1> &listConstIterator<T1>::operator+=(int n) { 
		node += n; 
		return (*this); 
	}

	// перемещает итератор на n позиций назад
	template <typename T1> 
	listConstIterator<T1> &listConstIterator<T1>::operator-=(int n) { 
		node -= n; 
		return (*this); 
	}

	// dereference iterator with offset accesses the element located n positions away from the element currently pointed to
	template <typename T1> 
	typename listConstIterator<T1>::reference listConstIterator<T1>::operator[](size_t n) { 
		return (*(node + n)); 
	}

	// возвращает количество позиций между итераторами iter1 и iter2
	template <typename T1> 
	size_t listConstIterator<T1>::operator-(listConstIterator & iter2) const { 
		return (node - iter2.node); 
	}

// listRevIterator
	template <typename T1>
	listRevIterator<T1> &listRevIterator<T1>::operator=(const listRevIterator<T1>& rhs) {
		node = rhs.node;
		return (*this);
	}

	template <typename T1>
	listRevIterator<T1>& listRevIterator<T1>::operator++() {
		--node;
		return (*this);
	}

	template <typename T1>
		listRevIterator<T1> listRevIterator<T1>::operator++(int) {
			listRevIterator<T1> tmp(*this);
			operator++();
			return (tmp);
		}

	template <typename T1>
			listRevIterator<T1>&	listRevIterator<T1>::operator--() {
				++node;
				return (*this);
			}

	template <typename T1>
			listRevIterator<T1>	listRevIterator<T1>::operator--(int) {
				listRevIterator<T1> tmp(*this);
				operator--();
				return (tmp);
			}

	template <typename T1>
			listRevIterator<T1>& listRevIterator<T1>::operator+=(int n) {
				node -= n;
				return (*this);
			}

	template <typename T1>
			listRevIterator<T1>& listRevIterator<T1>::operator-=(int n) {
				node += n;
				return (*this);
			}

	template <typename T1>
			listRevIterator<T1>	listRevIterator<T1>::operator+(int n) const {
				listRevIterator<T1> it(*this);
				return (it -= n);
			}

	template <typename T1>
			listRevIterator<T1>	listRevIterator<T1>::operator-(int n) const {
				listRevIterator<T1> it(*this);
				return (it += n);
			}

// listConstRevIterator
	template <typename T1>
	listConstRevIterator<T1> &listConstRevIterator<T1>::operator=(const listConstRevIterator<T1>& rhs) {
		node = rhs.node;
		return (*this);
	}

	template <typename T1>
		listConstRevIterator<T1>& listConstRevIterator<T1>::operator=(const listRevIterator<T1>& rhs) {
		node = rhs.node;
		return (*this);
	}

	template <typename T1>
	listConstRevIterator<T1>& listConstRevIterator<T1>::operator++() {
		--node;
		return (*this);
	}

	template <typename T1>
		listConstRevIterator<T1> listConstRevIterator<T1>::operator++(int) {
			listConstRevIterator<T1> tmp(*this);
			operator++();
			return (tmp);
		}

	template <typename T1>
			listConstRevIterator<T1>&	listConstRevIterator<T1>::operator--() {
				++node;
				return (*this);
			}

	template <typename T1>
			listConstRevIterator<T1>	listConstRevIterator<T1>::operator--(int) {
				listConstRevIterator<T1> tmp(*this);
				operator--();
				return (tmp);
			}

	template <typename T1>
			listConstRevIterator<T1>& listConstRevIterator<T1>::operator+=(int n) {
				node -= n;
				return (*this);
			}

	template <typename T1>
			listConstRevIterator<T1>& listConstRevIterator<T1>::operator-=(int n) {
				node += n;
				return (*this);
			}

	template <typename T1>
			listConstRevIterator<T1>	listConstRevIterator<T1>::operator+(int n) const {
				listConstRevIterator<T1> it(*this);
				return (it -= n);
			}

	template <typename T1>
			listConstRevIterator<T1>	listConstRevIterator<T1>::operator-(int n) const {
				listConstRevIterator<T1> it(*this);
				return (it += n);
			}

}
#endif