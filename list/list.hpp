//
//  L I S T
//  doubly-linked list
//
#include <list>
#ifndef LIST_HPP
# define LIST_HPP

#include "../header.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class list
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

		typedef listIterator<T>								iterator;
		typedef listConstIterator<T>						const_iterator;
		typedef listRevIterator<T>							reverse_iterator;
		typedef listConstRevIterator<T>						const_reverse_iterator;

	private:
		allocator_type						_allocator;
		size_type							_size;
		typedef node<T>						_node;
		typedef _node *						_node_pointer;
		_node_pointer						_end;

	public:

		//
		//  C O N S T R U C T O R S  &  D E S T R U C T O R
		//

		explicit list (const allocator_type& alloc = allocator_type());   // default
		explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());    // fill
		 template <class InputIterator> list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());    // range
		list (const list& x);   // copy
		~list();

		//
		//  A S S I G N A T I O N
		//

		list& operator=(const list& x);
		template <class InputIterator> void assign (InputIterator first, InputIterator last);    // range
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

		bool empty() const { return (_size == 0); }
		size_type size() const { return (_size); }
		size_type max_size() const ;


		//
		//  E L E M E N T   A C C E S S
		//

		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		//
		//  M O D I F I C A T I O N
		//

		void push_front (const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val); // single element
		void insert (iterator position, size_type n, const value_type& val); // fill
		template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); // range
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (list& x);
		void resize (size_type n, value_type val = value_type());
		void clear();

		//
		// O P E R A T I O N S
		//

		void splice (iterator position, list& x); //   entire list
		void splice (iterator position, list& x, iterator i); // single element
		void splice (iterator position, list& x, iterator first, iterator last); // element range
		void remove (const value_type& val);
		template <class Predicate> void remove_if (Predicate pred);
  		void unique();
		template <class BinaryPredicate> void unique (BinaryPredicate binary_pred);
		void merge (list& x);
		template <class Compare> void merge (list& x, Compare comp);
		void sort();
		template <class Compare> void sort (Compare comp);
		void reverse();

	private:

		void defaultListBuild(const allocator_type& alloc);
		void _assign(size_type count, const T &value, ft::is_int);
		template <typename InputIterator> void _assign(InputIterator first, InputIterator last, ft::not_int);
		void _insert(iterator position, int n, T val, ft::is_int);
		template <typename InputIterator> void _insert(iterator position, InputIterator first, InputIterator last, ft::not_int);
	};

	//
	//  C O N S T R U C T O R S  &  D E S T R U C T O R
	//

	template <typename T, typename Allocator>
	void list<T, Allocator>::defaultListBuild(const allocator_type& alloc) {
		_allocator = alloc;
		_size = 0;
		_end = new node<value_type>();
		_end->next = _end;
		_end->prev = _end;
	}

	template <typename T, typename Allocator>
	list<T, Allocator>::list (const allocator_type& alloc) { // default constructor
		defaultListBuild(alloc);
	}

	template <typename T, typename Allocator>
	list<T, Allocator>::list (size_type n, const value_type& val, const allocator_type& alloc) { 	// fill constructor
		defaultListBuild(alloc);
		for (int i = 0; i < n; i++)
			push_back(val);
	}

	 template <typename T, typename Allocator>
	 template <class InputIterator>
	 list<T, Allocator>::list (InputIterator first, InputIterator last, const allocator_type& alloc) {    // range constructor
	 	defaultListBuild(alloc);
	 	insert(begin(), first, last);
	 }

	template <typename T, typename Allocator>
	list<T, Allocator>::list (const list& x) { 	// copy constructor
		defaultListBuild(x._allocator);
		_node_pointer temp = x._end->next;
		while (temp != x._end) {
			push_back(temp->data);
			temp = temp->next;
		}
	}

	template <typename T, typename Allocator>
	list<T, Allocator>::~list() {
		clear();
		// if (_size != 0)
			delete _end;
	}

	//
	//  A S S I G N A T I O N
	//

	template <typename T, typename Allocator>
	class list<T, Allocator>::list& list<T, Allocator>::operator=(const list& x) {
		if (this != &x) {
			clear();
			_node_pointer temp = x._end->next;
			while (temp != x._end) {
				push_back(temp->data);
				temp = temp->next;
			}
		}
		return (*this);
	}

// assign - range

	template <typename T, typename Allocator>
	void list<T, Allocator>::_assign(size_type count, const T &value, ft::is_int) {
		while (_size < count)
			push_back(value);
	}

	template <typename T, typename Allocator>
	template <typename InputIt> 
	void list<T, Allocator>::_assign(InputIt first, InputIt last, ft::not_int) {
		while (first != last) {
			push_back(*first);
			first++;
		}
	}

	template <typename T, typename Allocator>
	template <class InputIterator> 
	void list<T, Allocator>::assign(InputIterator first, InputIterator last) {   
		typedef typename ft::is_integer<InputIterator>::type res;
		clear();
		_assign(first, last, res());
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::assign (size_type count, const value_type& value) {   // fill
		clear();
		while (_size < count)
			push_back(value);
	}

	//
	//  I T E R A T O R S
	//

	template <typename T, typename Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::begin() {
		return (iterator(_end->next));
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::const_iterator list<T, Allocator>::begin() const {
		return (const_iterator(_end->next));
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::end() {
		return (iterator(_end));
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::const_iterator list<T, Allocator>::end() const {
		return (const_iterator(_end));
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rbegin() {
		return (reverse_iterator(_end->prev));
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::rbegin() const {
		return (const_reverse_iterator(_end->prev));
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rend() {
		return (reverse_iterator(_end));
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::rend() const {
		return (const_reverse_iterator(_end));
	}

	//
	//  C A P A C I T Y
	//

	template <class T, class Allocator>
	typename list<T, Allocator>::size_type list<T, Allocator>::max_size() const {
		return (std::numeric_limits<size_type>::max() / sizeof(_node));
	}
	//
	//  E L E M E N T   A C C E S S
	//

	template <class T, class Allocator>
	typename list<T, Allocator>::reference list<T, Allocator>::front() {
		return (_end->next->data);
	}
	template <class T, class Allocator>
	typename list<T, Allocator>::const_reference list<T, Allocator>::front() const {
		return (_end->next->data);
	}
	template <class T, class Allocator>
	typename list<T, Allocator>::reference list<T, Allocator>::back() {
		return (_end->prev->data);
	}
	template <class T, class Allocator>
	typename list<T, Allocator>::const_reference list<T, Allocator>::back() const {
		return (_end->prev->data);
	}

	//
	//  M O D I F I C A T I O N
	//

	template <typename T, typename Allocator>
	void list<T, Allocator>::push_front (const value_type& val) {
		insert(begin(), val);
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::pop_front() {
		erase(begin());
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::push_back (const value_type& val) {
		_node_pointer newNode 	= new node<value_type>(val);
		newNode->next 			= _end;
		newNode->prev 			= _end->prev;
		_end->prev->next 		= newNode;
		_end->prev 				= newNode;
		_size++;
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::pop_back() {
		_node_pointer toDel = _end->prev;
		_end->prev = toDel->prev;
		toDel->prev->next = _end;
		delete toDel;
		_size--;
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::_insert(iterator position, int n, T val, ft::is_int) {
		while (n--)
			position = insert(position, val);
	}



	template <typename T, typename Allocator>
	template <typename InputIterator>
	void list<T, Allocator>::_insert(iterator position, InputIterator first, InputIterator last, ft::not_int) {
		while (first != last) {
			position = insert(position, *(first++));
			position++;
		}
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::insert (iterator position, const value_type& val) {		// single element
		_node_pointer temp = new _node(val);
		temp->next = position._node;
		temp->prev = position._node->prev;
		temp->prev->next = temp;
		temp->next->prev = temp;
		_size++;
		return (iterator(temp));
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::insert (iterator position, size_type n, const value_type& val) {							// fill
		while (n--)
			position = insert(position, val);
	}

	template <typename T, typename Allocator>
	template <class InputIterator>
	void list<T, Allocator>::insert (iterator position, InputIterator first, InputIterator last) {						// range
		typedef typename is_integer<InputIterator>::type res;
		_insert(position, first, last, res());
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::erase (iterator position) {
		iterator ret_temp = position;
		ret_temp++;
		_node_pointer temp = position._node;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		_size--;
		return(ret_temp);
	}

	template <typename T, typename Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::erase (iterator first, iterator last) {
		iterator temp = first;
		while (temp != last && temp != end())
			temp = erase(temp);
		return (temp);
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::swap (list& x) {
		list<T, Allocator> temp = *this;
		*this = x;
		x = temp;
		temp.clear();
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::resize (size_type n, value_type val) {
		while (n < _size)
			pop_back();
		while (n > _size)
			push_back(val);
	 }

	template <typename T, typename Allocator>
	void list<T, Allocator>::clear() {
		while (_size)
			pop_back();
	}

	//
	// O P E R A T I O N S
	//

	// splice() functions
	//  - transfer elements of list x into the container
	//  - do not involve the construction or destruction of any element

	template <typename T, typename Allocator>
	void list<T, Allocator>::splice (iterator position, list& x) { 					//   entire list
		_node_pointer first_moved_node = x.begin()._node;	//1ая перемещаемая нода
		_node_pointer last_moved_node = (--x.end())._node;	//последняя перемещаемая нода
		_node_pointer next = position._node;				// эта нода будет следующей за ними
		_node_pointer prev = (--position)._node;			// эта будет перед ними
		int node_count = x._size;

		// удаляем ноды из листа-листочника x
		x.end()._node->next = x.end()._node;
		x.end()._node->prev = x.end()._node;
		x._size = 0;

		// добавляем ноды в текущий лист
		prev->next = first_moved_node;
		next->prev = last_moved_node;
		first_moved_node->prev = prev;
		last_moved_node->next = next;
		_size += node_count;
	}

	template <typename T, typename Allocator>					//   куда			     из какого листа     откуда
	void list<T, Allocator>::splice (   iterator position,   list& x,			 iterator i) { 		// single element
		_node_pointer moved_node = i._node;				// перемещаемая нода
		_node_pointer next = position._node;			// эта нода будет следующей за ней
		_node_pointer prev= (--position)._node;			// эта будет перед ней

		// удаляем ноду из листа-листочника x
		moved_node->prev->next = moved_node->next;
		moved_node->next->prev = moved_node->prev;
		x._size--;

		// добавляем ноду в текущий лист
		prev->next = moved_node;
		moved_node->prev = prev;
		next->prev = moved_node;
		moved_node->next = next;
		_size++;
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::splice (iterator position, list& x, iterator first, iterator last) { 	// element range
		size_type node_count = 0;

		_node_pointer first_moved_node = first._node;	// 1ая перемещаемая нода
		_node_pointer last_moved_node = (--last)._node;	// последняя перемещаемая нода
		_node_pointer next = position._node;			// эта нода будет следующей за ними
		_node_pointer prev= (--position)._node;			// эта будет перед ними

		while (first++ != last)
			node_count++;
		node_count++;

		// удаляем ноды из листа-листочника x
		first_moved_node->prev->next = last_moved_node->next;
		last_moved_node->next->prev = first_moved_node->prev;
		x._size -= node_count;

		// добавляем ноды в текущий лист
		prev->next = first_moved_node;
		first_moved_node->prev = prev;
		next->prev = last_moved_node;
		last_moved_node->next = next;
		_size += node_count;
	}

	template <typename T, typename Allocator>
	void list<T, Allocator>::remove (const value_type& val) {
		ft::list<int>::iterator it = begin();
		while (it != end()) {
			if (*it == val) {
				ft::list<int>::iterator itt = it;
				++it;
				erase(itt);
			}
			else
				++it;
		}
	}

	 template <typename T, typename Allocator>
	 template <class Predicate>
	 void list<T, Allocator>::remove_if (Predicate pred) {

	 }

	template <typename T, typename Allocator>
	void list<T, Allocator>::unique() {

	}


	template <typename T, typename Allocator>
	template <class BinaryPredicate>
	 void list<T, Allocator>::unique (BinaryPredicate binary_pred) {

	 }

	template <typename T, typename Allocator>
	void list<T, Allocator>::merge (list& x) {

	}

	template <typename T, typename Allocator>
	template <class Compare>
	 void list<T, Allocator>::merge (list& x, Compare comp) {

	 }

	template <typename T, typename Allocator>
	void list<T, Allocator>::sort() {

	}

	template <typename T, typename Allocator>
	template <class Compare>
	 void list<T, Allocator>::sort (Compare comp) {

	 }

	template <typename T, typename Allocator>
	void list<T, Allocator>::reverse() {

	}

	//
	//  N O N - M E M B E R S
	//

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y);

	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
}

#endif
