//
//  V E C T O R
//  dynamically allocated array
//

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../header.hpp"

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        typedef T											value_type;
        typedef Allocator									allocator_type;
        typedef typename allocator_type::reference			reference;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
        typedef typename allocator_type::const_reference	const_reference;
        typedef typename allocator_type::pointer			pointer;
        typedef typename allocator_type::const_pointer		const_pointer;

		typedef vectorIterator<T>							iterator;
		typedef vectorConstIterator<T>						const_iterator;
		typedef vectorRevIterator<T>						reverse_iterator;
		typedef vectorConstRevIterator<T>					const_reverse_iterator;

	private:
		allocator_type						_allocator;
		pointer								_ptr;
		size_type							_size;
		size_type							_capacity;
		const static size_type 				_growthRate = 2;

	public:

        //
        //  C O N S T R U C T O R S  &  D E S T R U C T O R
        //

        explicit vector (const allocator_type& alloc = allocator_type());   // default
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());    // fill
        template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());    // range
        vector (const vector& x);   // copy
        ~vector();


        //
        //  A S S I G N A T I O N
        //

        vector& operator=(const vector& x);
        template <class InputIterator> void assign(InputIterator first, InputIterator last);    // range
        void assign (size_type n, const value_type& val);   // fill

        //
        //  I T E R A T O R S
        //

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        //
        //  C A P A C I T Y
        //

        size_type size() const;
        size_type max_size() const;
        size_type capacity() const;
        bool empty() const;
        void reserve (size_type n);
        void resize (size_type n, value_type val = value_type());

        //
        //  E L E M E N T   A C C E S S
        //

        reference operator[] (size_type n);
        const_reference operator[] (size_type n) const;
        reference at (size_type n);
		const_reference at (size_type n) const;
        reference       front();
        const_reference front() const;
        reference       back();
        const_reference back() const;

        //
        //  M O D I F I C A T I O N
        //

        void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);	// single element
    	void insert (iterator position, size_type n, const value_type& val);	// fill
		template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);	// range
        iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
        void clear();
		void swap (vector& x);

private:
		void _assign(size_type count, const T &value, ft::is_int);
		template <typename InputIt> void _assign(InputIt first, InputIt last, ft::not_int);
		void _insert(iterator pos, size_type count, const T &value, ft::is_int);
	 	template <typename InputIt> void _insert(iterator pos, InputIt first, InputIt last, ft::not_int);
    };

	//
	//  C O N S T R U C T O R S  &  D E S T R U C T O R
	//

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector (const allocator_type& alloc) {
		_allocator = alloc;
		_ptr = nullptr;
		_capacity = 0;
		_size = 0;
	}

  	// fill
	// Создаёт вектор с n объектами. Если val объявлена, то каждый из этих объектов будет инициализирован её значением; 
	// в противном случае объекты получат значение конструктора по умолчанию типа T.	
	template <typename T, typename Allocator>
	vector<T, Allocator>::vector (size_type n, const value_type& val, const allocator_type& alloc) {  
		_allocator = alloc;
		_capacity 	= 0;
		_ptr		= nullptr;
		_size 		= n;
		reserve(n);
		for (size_type i = 0; i < n; i++)
			_allocator.construct(_ptr + i, val);
	}

	// 		range
	// Constructs a container with as many elements as the range [first,last), 
	// 		with each element constructed from its corresponding element in that range, in the same order.
	template <typename T, typename Alloc>
	template <typename InputIterator>
	vector<T, Alloc>::vector (InputIterator first, InputIterator last, const allocator_type& alloc) {    
		_allocator = alloc;
		_capacity 	= 0;
		_ptr		= nullptr;
		_size 		= 0;
		assign(first, last);
	}

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector (const vector& x) {
		_allocator = x._allocator;
		_size = x._size;
		_capacity = x._capacity;
		if (x._capacity > 0) {
			_ptr = _allocator.allocate(_capacity);
		for (size_type i = 0; i < x._size; i++)
			_allocator.construct(_ptr + i, x._ptr[i]);
		}
		else
			_ptr = nullptr;
	}  

	template <typename T, typename Allocator>
	vector<T, Allocator>::~vector() { 
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(_ptr + i);			// destructs an object in allocated storage
		if (_capacity > 0)
			_allocator.deallocate(_ptr, _capacity);	// deallocates storage
	}

	//
	//  A S S I G N A T I O N
	//

	template <typename T, typename Allocator>
	vector<T, Allocator> & vector<T, Allocator>::operator=(const vector& rhs) {
		if (this != &rhs) {
			while (_size)
				_allocator.destroy(_ptr + --_size);
			reserve(rhs._capacity);
			_allocator = rhs._allocator;
			_size = rhs._size;
			_capacity = rhs._capacity;
			for (size_type i = 0; i < rhs._size; i++)
				_allocator.construct(_ptr + i, rhs._ptr[i]);
		}
		return (*this);
	}

 // assign - fill 
	template <typename T, typename Alloc>
	void vector<T, Alloc>::assign (size_type n, const value_type& val) {
		clear();
		reserve(n);
		while (_size < n)
			push_back(val);
	}

// assign - range

	template <typename T, typename Alloc>
	void vector<T, Alloc>::_assign(size_type count, const T &value, ft::is_int) {
		clear();
		reserve(count);
		while (_size < count)
			push_back(value);
	}

	template <typename T, typename Alloc>
	template <typename InputIt> 
	void vector<T, Alloc>::_assign(InputIt first, InputIt last, ft::not_int) {
		clear();
		while (first != last) {
			push_back(*first);
			first++;
		}
	}

	template <typename T, typename Alloc>
	template <class InputIterator> 
	void vector<T, Alloc>::assign(InputIterator first, InputIterator last) {
		typedef typename ft::is_integer<InputIterator>::type res;
		_assign(first, last, res());
	}

	//
	//  I T E R A T O R S
	//

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() {
		return (iterator(&_ptr[0]));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const {
		return (const_iterator(&_ptr[0]));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::end() {
		return (iterator(&_ptr[_size]));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const {
		return (const_iterator(&_ptr[_size]));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin() {
		return (reverse_iterator(&_ptr[_size]));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const {
		return (const_reverse_iterator(&_ptr[_size]));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend() {
		return (reverse_iterator(&_ptr[0]));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const {
		return (const_reverse_iterator(&_ptr[0]));
	}

	//
	//  C A P A C I T Y
	//

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const {
		return (_size);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const {
		return (std::numeric_limits<size_type>::max() / sizeof(value_type));
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const {
		return (_capacity);
	}

	template <class T, class Allocator>
	bool vector<T, Allocator>::empty() const {
		return (_size == 0);
	}

	template <class T, class Allocator>
	void vector<T, Allocator>::reserve (size_type n) {
		if (n > _capacity) {
			T* temp = _allocator.allocate(n);
			if (_ptr) {
				for (size_type i = 0; i < _size; i++) {
					_allocator.construct(temp + i, _ptr[i]);
					_allocator.destroy(_ptr + i);
				}
			}
			_allocator.deallocate(_ptr, _capacity);
			_capacity = n;
			_ptr = temp;
		}
	}

	template <class T, class Allocator>
	void vector<T, Allocator>::resize (size_type n, value_type val) {
		while (_size < n)
			push_back(val);
		while (_size > n)
			pop_back();
	}

	//
	//  E L E M E N T   A C C E S S
	//

	template <class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::operator[] (size_type n) {
		return (_ptr[n]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[] (size_type n) const {
		return (_ptr[n]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::at (size_type n) {
		if (n >= _size)
			throw std::out_of_range("vector");
		return (_ptr[n]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::at (size_type n) const {
		if (n >= _size)
			throw std::out_of_range("vector");
		return (_ptr[n]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::front() {
		return (_ptr[0]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const {
		return (_ptr[0]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::back() {
		return (_ptr[_size - 1]);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const {
		return (_ptr[_size - 1]);
	}

	//
	//  M O D I F I C A T I O N
	//

	template <typename T, typename Allocator>
	void vector<T, Allocator>::push_back(const value_type &value) {
	if (_capacity == _size)
			reserve(_capacity + 1);
		new(&_ptr[_size]) value_type(value);
		_size++;
	}

	template <typename T, typename Allocator>
	void vector<T, Allocator>::pop_back() {
		if (!empty())
			_allocator.destroy(_ptr + --_size);
	}


// single element
// - inserts value before pos
template <typename T, typename Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, const T &value) {
		size_t i = 0;
		for (iterator it = begin(); it != pos; it++)
			i++;
		insert(pos, 1, value);
		return (iterator(&(_ptr[i])));
	}

// fill
// - inserts count copies of the value before pos
template <typename T, typename Alloc>
	void vector<T, Alloc>::insert(iterator position, size_type n, const T &val)
	{
		size_t i = 0;
		iterator it = begin();
		reserve(_size + n);
		while (it++ != position)
			i++;
		for (size_t j = _size - 1; j != i - 1; j--) {
			if (j + n < _size)
				_ptr[j + n] = _ptr[j];
			else
				new(&_ptr[j + n]) value_type(_ptr[j]);
		}

		for (size_t j = 0; j < n; j++) {
			if (i < _size)
				_ptr[i++] = val;
			else
				new(&_ptr[i++]) value_type(val);
		}
		_size += n;
	}

// range
// - has the same effect as overload (3) if InputIt is an integral type.
	template <typename T, typename Alloc>
	template <typename InputIt>
	void vector<T, Alloc>::insert(iterator pos, InputIt first, InputIt last) {
		typedef typename ft::is_integer<InputIt>::type res;
		_insert(pos, first, last, res());
	}

	template <typename T, typename Alloc>
	void vector<T, Alloc>::_insert(iterator pos, size_type count, const T &value, ft::is_int)
	{
		size_t i = 0;
		iterator it = begin();
		reserve(_size + count);
		while (it++ != pos)
			i++;
		for (size_t j = _size - 1; j != i - 1; j--) {
			if (j + count < _size)
				_ptr[j + count] = _ptr[j];
			else
				new(&_ptr[j + count]) value_type(_ptr[j]);
		}
		for (size_t j = 0; j < count; j++) {
			if (i < _size)
				_ptr[i++] = value;
			else
				new(&_ptr[i++]) value_type(value);
		}
		_size += count;
	}

	template <typename T, typename Alloc>
	template <typename InputIt>
	void vector<T, Alloc>::_insert(iterator pos, InputIt first, InputIt last, ft::not_int)
	{
		size_t i = 0;
		size_t count = 0;
		iterator it = begin();
		InputIt tmp = first;
		while (it++ != pos)
			i++;
		while (tmp++ != last)
			count++;
		reserve(_size + count);
		for (size_t j = _size - 1; j != i - 1; j--) {
			if (j + count < _size)
				_ptr[j + count] = _ptr[j];
			else
				new(&_ptr[j + count]) value_type(_ptr[j]);
		}
		for (size_t j = 0; j < count; j++) {
			if (i < _size)
				_ptr[i++] = *first++;
			else
				new(&_ptr[i++]) value_type(*first++);
		}
		_size += count;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase (iterator position) {
		size_t i	= 0;
		iterator it = begin();
		while (it++ != position)
			i++;
		for (size_t j = i; j != _size - 1; j++)
			_ptr[j] = _ptr[j + 1];
		pop_back();
		return (--it);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase (iterator first, iterator last) {
		size_t count_first = 0;
		size_t count = 0;
		iterator it = begin();

		while (it++ != first)
			count_first++;
		while (first++ != last)
			count++;
		if (count) {
			for (size_t j = count_first; j + count < _size; j++)
				_ptr[j] = _ptr[j + count];
		}
		while (count--)
			pop_back();
		if (_size == 0)
			return (begin());
		return (--it);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::swap (vector& x){
		std::swap(_allocator, x._allocator);
		std::swap(_ptr, x._ptr);
		std::swap(_size, x._size);
		std::swap(_capacity, x._capacity);
	}
	
	template <class T, class Alloc>
	void vector<T, Alloc>::clear () {
	while (_size)
		_allocator.destroy(_ptr + --_size);
	}

	//
	//  N O N - M E M B E R S
	//

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (typename vector<T,Alloc>::size_type i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (true);
		for (typename vector<T,Alloc>::size_type i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		for (typename vector<T,Alloc>::size_type i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (false);
			else if (lhs[i] < rhs[i])
				return (true);
		}
		if (lhs.size() < rhs.size())
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}
}

#endif


// 	template <typename _T, typename Alloc>
// 	bool operator<(const vector<_T, Alloc> &lhs, const vector<_T, Alloc> &rhs)
// 	{
// 		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
// 		{
// 			if (lhs[i] > rhs[i])
// 				return false;
// 			else if (lhs[i] < rhs[i])
// 				return true;
// 		}
// 		if (lhs.size() < rhs.size())
// 			return true;
// 		return false;
// 	}

// 	template <typename _T, typename Alloc>
// 	bool operator>(const vector<_T, Alloc> &lhs, const vector<_T, Alloc> &rhs)
// 	{
// 		return (rhs < lhs);
// 	}

// 	template <typename _T, typename Alloc>
// 	bool operator<=(const vector<_T, Alloc> &lhs, const vector<_T, Alloc> &rhs)
// 	{
// 		return (!(rhs < lhs));
// 	}

// 	template <typename _T, typename Alloc>
// 	bool operator>=(const vector<_T, Alloc> &lhs, const vector<_T, Alloc> &rhs)
// 	{
// 		return (!(lhs < rhs));
// 	}