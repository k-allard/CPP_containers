#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstring>
#include "../iterators/iteratorVector.hpp"

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
	class vector {

		/*
		** Typedefs
		*/
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::IteratorVector<T>						iterator;
			typedef ft::ReverseIteratorVector<T>				reverse_iterator;
			typedef ft::ConstIteratorVector<T>					const_iterator;
			typedef ft::ConstReverseIteratorVector<T>			const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

		/*
		** Class members
		*/
		private:
			T						*_array;
			size_type				_size;
			size_type				_capacity;
			allocator_type			_alloc;
			const static size_type	_scaleFactor = 2;
			const static size_type	_initCapacity = 10;

			void fill_initialize(size_type n, const value_type& val) {
				_array = _alloc.allocate(_initCapacity);
				_capacity = _initCapacity;
				_size = 0;
				resize(n, val);
			}

			template<typename Integer>
			void initialize_dispatch(Integer n, Integer val, true_type) {
				fill_initialize(static_cast<size_type>(n), val);
			}

			template<typename InputIterator>
			void initialize_dispatch(InputIterator first, InputIterator last, false_type) {
				difference_type size = ft::distance(first, last);
				_size = size;
				_capacity = size;
				if (size > 0) {
					_array = _alloc.allocate(_size);
					for (difference_type i = 0; i < size; i++)
						_alloc.construct(_array + i, *first++);
				}
				else
					_array = NULL;
			}


			void fill_assign(size_type n, const value_type& val) {
				clear();
				while (n--)
					push_back(val);
			}

			template<typename Integer>
			void assign_dispatch(Integer n, Integer val, true_type) {
				fill_assign(static_cast<size_type>(n), val);
			}

			template<typename InputIterator>
			void assign_dispatch(InputIterator first, InputIterator last, false_type) {
				clear();
				while (first != last)
					push_back(*first++);
			}

			void fill_insert(iterator position, size_type n, const value_type& val) {
				while (n--)
					insert(position, val);
			}

			template<typename Integer>
			void insert_dispatch(iterator position, Integer n, Integer val, true_type) {
				fill_insert(position, static_cast<size_type>(n), val);
			}

			template<typename InputIterator>
			void insert_dispatch(iterator position, InputIterator first, InputIterator last, false_type) {
				while (first != last) {
					position = insert(position, *first++);
					position++;
				}
			}

		public:

			/*
			** Constructors and destructor
			*/
			explicit vector (const allocator_type& alloc = allocator_type()):_alloc(alloc) {
				_array = _alloc.allocate(_initCapacity);
				_capacity = _initCapacity;
				_size = 0;
			}

			explicit vector (size_type n, const value_type& val = value_type(),
						 	const allocator_type& alloc = allocator_type()):_alloc(alloc) {
				fill_initialize(n, val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()):_alloc(alloc) {
				typedef typename ft::is_integer<InputIterator>::type Integral;
				initialize_dispatch(first, last, Integral());
			}

			vector (const vector& x) {
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._capacity;
				if (x._capacity > 0) {
					_array = _alloc.allocate(_capacity);
					for (size_type i = 0; i < x._size; i++)
						_alloc.construct(_array + i, x._array[i]);
				}
				else
					_array = NULL;
			}

			~vector() {
				clear();
				if (_capacity > 0)
					_alloc.deallocate(_array, _capacity);
			}

			vector& operator=(const vector& x) {
				if (this != &x) {
					clear();
					reserve(x._capacity);
					_alloc = x._alloc;
					_size = x._size;
					_capacity = x._capacity;
					for (size_type i = 0; i < x._size; i++)
						_alloc.construct(_array + i, x._array[i]);
				}
				return (*this);
			}

			/*
			** Iterators
			*/

			iterator 			begin() {
				return (iterator(&_array[0]));
			}

			const_iterator		begin() const {
				return (const_iterator(&_array[0]));
			}

			iterator 			end() {
				return (iterator(&_array[_size]));
			}

			const_iterator		end() const {
				return (const_iterator(&_array[_size]));
			}

			reverse_iterator 	rbegin() {
				return (reverse_iterator(&_array[_size]));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(&_array[_size]));
			}

			reverse_iterator 	rend() {
				return (reverse_iterator(&_array[0]));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(&_array[0]));
			}

			/*
			** Capacity
			*/
			size_type 			size() const {
				return (_size);
			}

			size_type			max_size() const {
				return (_alloc.max_size());
			}

			void 				resize(size_type n, value_type val = value_type()) {
				reserve(n);

				for (size_type i = _size; i < n; i++)
					_alloc.construct(_array + i, val);

				_size = n;
			}

			size_type			capacity() const {
				return (_capacity);
			}

			bool				empty() const {
				return (_size == 0);
			}

			void				reserve(size_type n) {
				if (n > _capacity) {
					T* array = _alloc.allocate(n);

					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(array + i, _array[i]);
						_alloc.destroy(_array + i);
					}

					_alloc.deallocate(_array, _capacity);
					_capacity = n;
					_array = array;
				}
			}

			/*
			** Element access
			*/
			reference 			operator[](size_type n) {
				return (_array[n]);
			}

			const_reference		operator[](size_type n) const {
				return (_array[n]);
			}

			reference			at(size_type n) {
				if (n >= _size)
					throw std::out_of_range("Out of range");
				return (_array[n]);
			}

			const_reference		at(size_type n) const {
				if (n >= _size)
					throw std::out_of_range("Out of range");
				return (_array[n]);
			}

			reference			front() {
				return (_array[0]);
			}

			const_reference		front() const {
				return (_array[0]);
			}

			reference			back() {
				return (_array[_size - 1]);
			}

			const_reference		back() const {
				return (_array[_size - 1]);
			}

			/*
			** Modifiers
			*/

			template <class InputIterator>
			void				assign(InputIterator first, InputIterator last) {
				typedef typename ft::is_integer<InputIterator>::type Integral;
				assign_dispatch(first, last, Integral());
			}

			void				assign(size_type n, const value_type& val) {
				fill_assign(n, val);
			}

			void				push_back(const value_type& val) {
				if (_size >= _capacity)
					reserve(_size * _scaleFactor);
				_alloc.construct(_array + _size++, val);
			}

			void				pop_back() {
				if (!empty())
					_alloc.destroy(_array + --_size);
			}

			iterator			insert(iterator position, const value_type& val) {
				iterator end = this->end();
				if (_size >= _capacity)
					reserve(_size * _scaleFactor);
				size_type i = _size++;
				while (position++ != end) {
					_array[i] = _array[i - 1];
					i--;
				}
				_array[i] = val;
				return (iterator(_array + i));
			}

			void				insert(iterator position, size_type n, const value_type& val) {
				fill_insert(position, n, val);
			}

			template <class InputIterator>
			void				insert(iterator position, InputIterator first, InputIterator last) {
				typedef typename ft::is_integer<InputIterator>::type Integral;
				insert_dispatch(position, first, last, Integral());
			}

			iterator			erase(iterator position) {
				difference_type dist = position - this->begin(), size = this->size();

				_alloc.destroy(_array + dist);
				for (difference_type i = dist; i < size - 1; i++)
					_array[i] = _array[i + 1];
				_size--;
				return (iterator(_array + dist));
			}

			iterator			erase(iterator first, iterator last) {
				difference_type begin = first - this->begin(), len = last - first;

				_size -= len;
				for (difference_type i = begin; i < len; i++)
					_alloc.destroy(_array + i);
				for (size_type i = begin; i < _size; i++)
					_array[i] = _array[i + len];
				return (iterator(_array + begin));
			}

			void				swap (vector& x) {
				ft::swap(_array, x._array);
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
				ft::swap(_alloc, x._alloc);
			}

			void				clear() {
				while (_size)
					_alloc.destroy(_array + --_size);
			}
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (typename vector<T,Alloc>::size_type i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}

}

#endif
