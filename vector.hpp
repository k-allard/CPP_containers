/*
**  Vector class - dynamically allocated array
**
*/
// #include <vector>

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "header.hpp"
#include <iostream>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        typedef T                                        value_type;               //The first template parameter (T)	
        typedef Allocator                                allocator_type;           //The second template parameter (Alloc)	
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef implementation-defined                   iterator;              //TODO
        typedef implementation-defined                   const_iterator;        //TODO
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef std::reverse_iterator<iterator>          reverse_iterator;
        typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

        vector() noexcept(is_nothrow_default_constructible<allocator_type>::value);
        explicit vector(const allocator_type&);
        explicit vector(size_type n);
        explicit vector(size_type n, const allocator_type&); // C++14
        vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
        template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
        vector(const vector& x);
        vector(vector&& x)
            noexcept(is_nothrow_move_constructible<allocator_type>::value);
        vector(initializer_list<value_type> il);
        vector(initializer_list<value_type> il, const allocator_type& a);
        ~vector();
        vector& operator=(const vector& x);
        vector& operator=(vector&& x)
            noexcept(
                allocator_type::propagate_on_container_move_assignment::value ||
                allocator_type::is_always_equal::value); // C++17
        vector& operator=(initializer_list<value_type> il);
        template <class InputIterator>
            void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const value_type& u);
        void assign(initializer_list<value_type> il);

        allocator_type get_allocator() const noexcept;

        iterator               begin() noexcept;
        const_iterator         begin()   const noexcept;
        iterator               end() noexcept;
        const_iterator         end()     const noexcept;

        reverse_iterator       rbegin() noexcept;
        const_reverse_iterator rbegin()  const noexcept;
        reverse_iterator       rend() noexcept;
        const_reverse_iterator rend()    const noexcept;

        const_iterator         cbegin()  const noexcept;
        const_iterator         cend()    const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend()   const noexcept;

        size_type size() const noexcept;
        size_type max_size() const noexcept;
        size_type capacity() const noexcept;
        bool empty() const noexcept;
        void reserve(size_type n);
        void shrink_to_fit() noexcept;

        reference       operator[](size_type n);
        const_reference operator[](size_type n) const;
        reference       at(size_type n);
        const_reference at(size_type n) const;

        reference       front();
        const_reference front() const;
        reference       back();
        const_reference back() const;

        value_type*       data() noexcept;
        const value_type* data() const noexcept;

        void push_back(const value_type& x);
        void push_back(value_type&& x);
        template <class... Args>
            reference emplace_back(Args&&... args); // reference in C++17
        void pop_back();

        template <class... Args> iterator emplace(const_iterator position, Args&&... args);
        iterator insert(const_iterator position, const value_type& x);
        iterator insert(const_iterator position, value_type&& x);
        iterator insert(const_iterator position, size_type n, const value_type& x);
        template <class InputIterator>
            iterator insert(const_iterator position, InputIterator first, InputIterator last);
        iterator insert(const_iterator position, initializer_list<value_type> il);

        iterator erase(const_iterator position);
        iterator erase(const_iterator first, const_iterator last);

        void clear() noexcept;

        void resize(size_type sz);
        void resize(size_type sz, const value_type& c);

        void swap(vector&)
            noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                    allocator_traits<allocator_type>::is_always_equal::value);  // C++17

        bool __invariants() const;
    };
}

/*
    vector synopsis

namespace std
{

template <class T, class Allocator = allocator<T> >
class vector
{
public:
    typedef T                                        value_type;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    vector()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit vector(const allocator_type&);
    explicit vector(size_type n);
    explicit vector(size_type n, const allocator_type&); // C++14
    vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    vector(const vector& x);
    vector(vector&& x)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    vector(initializer_list<value_type> il);
    vector(initializer_list<value_type> il, const allocator_type& a);
    ~vector();
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    vector& operator=(initializer_list<value_type> il);
    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const value_type& u);
    void assign(initializer_list<value_type> il);

    allocator_type get_allocator() const noexcept;

    iterator               begin() noexcept;
    const_iterator         begin()   const noexcept;
    iterator               end() noexcept;
    const_iterator         end()     const noexcept;

    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin()  const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend()    const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_type n);
    void shrink_to_fit() noexcept;

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;

    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    value_type*       data() noexcept;
    const value_type* data() const noexcept;

    void push_back(const value_type& x);
    void push_back(value_type&& x);
    template <class... Args>
        reference emplace_back(Args&&... args); // reference in C++17
    void pop_back();

    template <class... Args> iterator emplace(const_iterator position, Args&&... args);
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, value_type&& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void clear() noexcept;

    void resize(size_type sz);
    void resize(size_type sz, const value_type& c);

    void swap(vector&)
        noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17

    bool __invariants() const;
};

template <class Allocator = allocator<T> >
class vector<bool, Allocator>
{
public:
    typedef bool                                     value_type;
    typedef Allocator                                allocator_type;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef iterator                                 pointer;
    typedef const_iterator                           const_pointer;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    class reference
    {
    public:
        reference(const reference&) noexcept;
        operator bool() const noexcept;
        reference& operator=(const bool x) noexcept;
        reference& operator=(const reference& x) noexcept;
        iterator operator&() const noexcept;
        void flip() noexcept;
    };

    class const_reference
    {
    public:
        const_reference(const reference&) noexcept;
        operator bool() const noexcept;
        const_iterator operator&() const noexcept;
    };

    vector()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit vector(const allocator_type&);
    explicit vector(size_type n, const allocator_type& a = allocator_type()); // C++14
    vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    vector(const vector& x);
    vector(vector&& x)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    vector(initializer_list<value_type> il);
    vector(initializer_list<value_type> il, const allocator_type& a);
    ~vector();
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    vector& operator=(initializer_list<value_type> il);
    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const value_type& u);
    void assign(initializer_list<value_type> il);

    allocator_type get_allocator() const noexcept;

    iterator               begin() noexcept;
    const_iterator         begin()   const noexcept;
    iterator               end() noexcept;
    const_iterator         end()     const noexcept;

    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin()  const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend()    const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_type n);
    void shrink_to_fit() noexcept;

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;

    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    void push_back(const value_type& x);
    template <class... Args> reference emplace_back(Args&&... args);  // C++14; reference in C++17
    void pop_back();

    template <class... Args> iterator emplace(const_iterator position, Args&&... args);  // C++14
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void clear() noexcept;

    void resize(size_type sz);
    void resize(size_type sz, value_type x);

    void swap(vector&)
        noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17
    void flip() noexcept;

    bool __invariants() const;
};

template <class InputIterator, class Allocator = allocator<typename iterator_traits<InputIterator>::value_type>>
   vector(InputIterator, InputIterator, Allocator = Allocator())
   -> vector<typename iterator_traits<InputIterator>::value_type, Allocator>;

template <class Allocator> struct hash<std::vector<bool, Allocator>>;

template <class T, class Allocator> bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
    noexcept(noexcept(x.swap(y)));

template <class T, class Allocator, class U>
    void erase(vector<T, Allocator>& c, const U& value);       // C++20
template <class T, class Allocator, class Predicate>
    void erase_if(vector<T, Allocator>& c, Predicate pred);    // C++20

}  // std

*/





// template <class T, class A = std::allocator<T> >
// class X {
// public:
//     typedef A allocator_type;
//     typedef typename A::value_type value_type; 
//     typedef typename A::reference reference;
//     typedef typename A::const_reference const_reference;
//     typedef typename A::difference_type difference_type;
//     typedef typename A::size_type size_type;

//     class iterator { 
//     public:
//         typedef typename A::difference_type difference_type;
//         typedef typename A::value_type value_type;
//         typedef typename A::reference reference;
//         typedef typename A::pointer pointer;
//         typedef std::random_access_iterator_tag iterator_category; //or another tag

//         iterator();
//         iterator(const iterator&);
//         ~iterator();

//         iterator& operator=(const iterator&);
//         bool operator==(const iterator&) const;
//         bool operator!=(const iterator&) const;
//         bool operator<(const iterator&) const; //optional
//         bool operator>(const iterator&) const; //optional
//         bool operator<=(const iterator&) const; //optional
//         bool operator>=(const iterator&) const; //optional

//         iterator& operator++();
//         iterator operator++(int); //optional
//         iterator& operator--(); //optional
//         iterator operator--(int); //optional
//         iterator& operator+=(size_type); //optional
//         iterator operator+(size_type) const; //optional
//         friend iterator operator+(size_type, const iterator&); //optional
//         iterator& operator-=(size_type); //optional            
//         iterator operator-(size_type) const; //optional
//         difference_type operator-(iterator) const; //optional

//         reference operator*() const;
//         pointer operator->() const;
//         reference operator[](size_type) const; //optional
//     };
//     class const_iterator {
//     public:
//         typedef typename A::difference_type difference_type;
//         typedef typename A::value_type value_type;
//         typedef typename const A::reference reference;
//         typedef typename const A::pointer pointer;
//         typedef std::random_access_iterator_tag iterator_category; //or another tag

//         const_iterator ();
//         const_iterator (const const_iterator&);
//         const_iterator (const iterator&);
//         ~const_iterator();

//         const_iterator& operator=(const const_iterator&);
//         bool operator==(const const_iterator&) const;
//         bool operator!=(const const_iterator&) const;
//         bool operator<(const const_iterator&) const; //optional
//         bool operator>(const const_iterator&) const; //optional
//         bool operator<=(const const_iterator&) const; //optional
//         bool operator>=(const const_iterator&) const; //optional

//         const_iterator& operator++();
//         const_iterator operator++(int); //optional
//         const_iterator& operator--(); //optional
//         const_iterator operator--(int); //optional
//         const_iterator& operator+=(size_type); //optional
//         const_iterator operator+(size_type) const; //optional
//         friend const_iterator operator+(size_type, const const_iterator&); //optional
//         const_iterator& operator-=(size_type); //optional            
//         const_iterator operator-(size_type) const; //optional
//         difference_type operator-(const_iterator) const; //optional

//         reference operator*() const;
//         pointer operator->() const;
//         reference operator[](size_type) const; //optional
//     };

//     typedef std::reverse_iterator<iterator> reverse_iterator; //optional
//     typedef std::reverse_iterator<const_iterator> const_reverse_iterator; //optional

//     X();
//     X(const X&);
//     ~X();

//     X& operator=(const X&);
//     bool operator==(const X&) const;
//     bool operator!=(const X&) const;
//     bool operator<(const X&) const; //optional
//     bool operator>(const X&) const; //optional
//     bool operator<=(const X&) const; //optional
//     bool operator>=(const X&) const; //optional

//     iterator begin();
//     const_iterator begin() const;
//     const_iterator cbegin() const;
//     iterator end();
//     const_iterator end() const;
//     const_iterator cend() const;
//     reverse_iterator rbegin(); //optional
//     const_reverse_iterator rbegin() const; //optional
//     const_reverse_iterator crbegin() const; //optional
//     reverse_iterator rend(); //optional
//     const_reverse_iterator rend() const; //optional
//     const_reverse_iterator crend() const; //optional

//     reference front(); //optional
//     const_reference front() const; //optional
//     reference back(); //optional
//     const_reference back() const; //optional
//     template<class ...Args>
//     void emplace_front(Args&&...); //optional
//     template<class ...Args>
//     void emplace_back(Args&&...); //optional
//     void push_front(const T&); //optional
//     void push_front(T&&); //optional
//     void push_back(const T&); //optional
//     void push_back(T&&); //optional
//     void pop_front(); //optional
//     void pop_back(); //optional
//     reference operator[](size_type); //optional
//     const_reference operator[](size_type) const; //optional
//     reference at(size_type); //optional
//     const_reference at(size_type) const; //optional

//     template<class ...Args>
//     iterator emplace(const_iterator, Args&&...); //optional
//     iterator insert(const_iterator, const T&); //optional
//     iterator insert(const_iterator, T&&); //optional
//     iterator insert(const_iterator, size_type, T&); //optional
//     template<class iter>
//     iterator insert(const_iterator, iter, iter); //optional
//     iterator insert(const_iterator, std::initializer_list<T>); //optional
//     iterator erase(const_iterator); //optional
//     iterator erase(const_iterator, const_iterator); //optional
//     void clear(); //optional
//     template<class iter>
//     void assign(iter, iter); //optional
//     void assign(std::initializer_list<T>); //optional
//     void assign(size_type, const T&); //optional

//     void swap(X&);
//     size_type size() const;
//     size_type max_size() const;
//     bool empty() const;

//     A get_allocator() const; //optional
// };
// template <class T, class A = std::allocator<T> >
// void swap(X<T,A>&, X<T,A>&); //optional

#endif
