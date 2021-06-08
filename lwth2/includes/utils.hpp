#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

	template <typename T>
	bool isPositive(const T& val) {
		return (val > 0);
	}

	template <typename T>
	bool isGreater(const T& val1, const T& val2) {
		return (val1 > val2);
	}

	template <class T>
	struct small: std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {
			return (y<x);
		}
	};

	template <class T>
	struct greater: std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {
			return (x<y);
		}
	};

	struct true_type {};
	struct false_type {};

	template<typename Tp>
	struct is_integer
	{
		typedef false_type type;
	};

	template<>
	struct is_integer<bool>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<char>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<signed char>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned char>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<wchar_t>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<short>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned short>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<int>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned int>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<long>
	{
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned long>
	{
		typedef true_type type;
	};

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								 InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template <typename T>
	T min(T a, T b) {
		return (a > b ? b : a);
	}

	template <typename T>
	void swap(T &a, T &b) {
		T c;
		c = a;
		a = b;
		b = c;
	}

	template<typename T>
	typename T::difference_type distance(T first, T last) {
		return (last.getPtr() - first.getPtr());
	}

}

#endif

