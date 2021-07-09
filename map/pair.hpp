// std::pair implementation

#ifndef PAIR_HPP
# define PAIR_HPP

#include "../header.hpp"
#include <iostream>

namespace ft
{
	// A template for heterogeneous pairs of values
    template <class T1, class T2>
    struct pair {
            typedef T1 first_type;
            typedef T2 second_type;
            
			T1 first;
            T2 second;

            pair() : first(), second() { } // Default constructor. Initializes first and  second  using their default constructors.
           	pair (const T1& x, const T2& y) : first(x), second(y) { } // Creates a pair of types T1 and T2, making  the  necessary conversions in x and y.
            template <class V, class U> 
			pair(const ft::pair <V, U>& p) : first(p.first), second(p.second) { } // Copies first and second from the  corresponding  elements of p.
            ~pair();
     };

// N O N - M E M B E R   O P E R A T O R S
     template <class T1, class T2>
     bool operator== (const ft::pair<T1, T2>& x,
                      const ft::pair< T1, T2>& y) {
		return (x.first == y.first && x.second == y.second);
	}

     template <class T1, class T2>
     bool operator!= (const ft::pair<T1, T2>& x,
                      const ft::pair< T1, T2>& y) {
		return (!(x == y));
	}

     template <class T1, class T2>
     bool operator< (const ft::pair<T1, T2>& x,
                     const ft::pair< T1, T2>& y) {
		return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
	} 

     template <class T1, class T2>
     bool operator> (const ft::pair<T1, T2>& x,
                     const ft::pair< T1, T2>& y) {
		return (y < x); 
	}

     template <class T1, class T2>
     bool operator<= (const ft::pair<T1, T2>& x,
                     const ft::pair< T1, T2>& y) {
		return (!(y < x));
	}

     template <class T1, class T2>
     bool operator>= (const ft::pair<T1, T2>& x,
                     const ft::pair< T1, T2>& y) {
		return (!(x < y));
	}


// N O N - M E M B E R   F U N C T I O N
     
	 //creates a pair by deducing  and  returning the types of x and y.
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {
		return ( ft::pair<T1,T2>(x,y) );
	}
}


#endif
