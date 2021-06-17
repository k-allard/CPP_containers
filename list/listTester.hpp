#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
#include "../header.hpp"
#include <cmath>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define NC "\033[0m"

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value < 10); }

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second) {
	return ( int(first) == int(second) );
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }


class ListTester {
public:
	ListTester() {
		std::cout << " - - - - - - - - - - - - - - - - - - - -";
		std::cout << "\n" << " - - - - - - - - L I S T - - - - - - - - " << "\n";
		std::cout << " - - - - - - - - - - - - - - - - - - - -\n";
	}
	void testConstructors();
	void testAssignations();
	void testCapacity();
	void testElementAccess();
	void testIterators();
	void testModifiers() ;
	void testOperations();
	void testSwap();
	void testRelationalOperators();

private:
	std::stringstream stdString;
	std::stringstream ftString;
	static void passed();
	template <class T> int compareStdFtLists(std::list<T> &std_list, ft::list<T> &ft_list);
	template <class T> void printStdFtLists(std::list<T> &std_list, ft::list<T> &ft_list);
	template <class T> void printStdlist(std::list<T> &std_list);
	template <class T> void printFtlist(ft::list<T> &ft_list);

	// a predicate implemented as a class:
	struct is_odd {
		bool operator() (const int& value) { return (value % 2) == 1; }
	};

	// a binary predicate implemented as a class:
	struct is_near {
		bool operator() (double first, double second)
		{ return (fabs(first-second) < 5.0); }
	};
};

void ListTester::testConstructors() {
	std::list<int> first;
	std::list<int> second (4,100);
	 std::list<int> third (second.begin(),second.end());
	std::list<int> fourth (second);

	ft::list<int> ft_first;
	ft::list<int> ft_second(4, 100);
	 ft::list<int> ft_third (ft_second.begin(),ft_second.end());
	ft::list<int> ft_fourth (ft_second);

	std::cout << "Default constructor - ";
	if (!compareStdFtLists(first, ft_first))
		passed();
	std::cout << "Fill constructor -    ";
	if (!compareStdFtLists(second, ft_second))
		passed();
	 std::cout << "Range constructor -   ";
	 if (!compareStdFtLists(third, ft_third))
	 	passed();
	std::cout << "Copy constructor -    ";
	if (!compareStdFtLists(fourth, ft_fourth))
		passed();
}

void ListTester::testAssignations() {
	std::list<int> first(3,0);
	std::list<int> second(5,0);
	std::list<int> third;

	ft::list<int> ft_first(3,0);
	ft::list<int> ft_second(5,0);
	ft::list<int> ft_third;

	first = second;
	ft_first = ft_second;

	std::cout << "operator= -           ";
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "Fill assignation -    ";
	first.assign(2, 99);
	ft_first.assign(2, 99);
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "Range assignation -   ";
	int myints[] = {1776,7,4};
	third.assign (myints, myints + 3);
	ft_third.assign (myints, myints + 3);
	if (!compareStdFtLists(third, ft_third))
		passed();
}

void ListTester::testCapacity() {
	int flag = 0;

	std::cout << "size() -              ";
	std::list<int> first (6, 7);
	ft::list<int> ft_first (6, 7);
	int myints[] = { 12, 10, 8, 6, 4, 2, 1 };


	first.assign (myints, myints + 7);
	ft_first.assign (myints, myints + 7);
	if (first.size() == ft_first.size())
		passed();
	else
		std::cout << RED << "FAIL ❌\n" << "Ft list size: " << ft_first.size() \
		<< "\nStd list size: " << first.size() << NC << "\n";

 	std::cout << "max_size() -          ";
 	if (first.max_size() == ft_first.max_size())
 		passed();
 	else
 		std::cout << RED << "FAIL ❌\n" << "Ft list size: " << ft_first.size() \
 		<< "\nStd list size: " << first.size() << NC << "\n";


 	std::cout << "empty() -             ";
 	std::list<int> second;
 	ft::list<int> ft_second;
 	if (first.empty() == ft_first.empty() && second.empty() == ft_second.empty())
 		passed();
 	else
 		std::cout << RED << "FAIL ❌\n" << NC;
 }

 void ListTester::testElementAccess() {
 	std::list<int> first (3, 4);   // 10 zero-initialized elements
 	ft::list<int> ft_first (3, 4);   // 10 zero-initialized elements
 	std::list<int>::size_type sz = first.size();
 	ft::list<int>::size_type ft_sz = ft_first.size();
	first.resize(5);
	 ft_first.resize(5);

	 printStdFtLists(first, ft_first);

 	std::cout << "front() -             ";
 	if (first.front() == ft_first.front())
 			passed();
 	else
 		std::cout << RED << "FAIL ❌\n" << NC;
 	std::cout << "back() -              ";
 	if (first.back() == ft_first.back())
 			passed();
 	else
 		std::cout << RED << "FAIL ❌\n" << NC;
}

void ListTester::testIterators() {
	std::list<int> first (5);  // 5 ints 0
	ft::list<int> ft_first (5);  // 5 ints 0

	std::cout << "rbegin() and rend() - ";

	std::list<int>::reverse_iterator rit = first.rbegin();
	ft::list<int>::reverse_iterator ft_rit = ft_first.rbegin();

	int i = 0;
	for (; rit != first.rend(); ++rit)
		*rit = ++i;

	int k = 0;
	for (; ft_rit != ft_first.rend(); ++ft_rit)
		*ft_rit = ++k;

	printStdFtLists(first, ft_first);
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "begin() and end() -   ";
	for (std::list<int>::iterator it = first.begin(); it != first.end(); ++it)
		*(it) += 1;

	for (ft::list<int>::iterator ft_it = ft_first.begin(); ft_it != ft_first.end(); ++ft_it)
		*(ft_it) += 1;

	printStdFtLists(first, ft_first);
	if (!compareStdFtLists(first, ft_first))
		passed();

}

void ListTester::testModifiers() {
	std::list<int> first (5);  // 5 default-constructed ints
	ft::list<int> ft_first (5);  // 5 default-constructed ints

	std::cout << "--- Range assign ---";
	int myints[] = {1776,7,4};
	first.assign (myints,myints + 3);
	ft_first.assign(myints,myints + 3);
	printStdFtLists(first, ft_first);
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "--- Fill assign ---";
	first.assign (2,99);
	ft_first.assign(2,99);
	printStdFtLists(first, ft_first);
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "--- push_front() ---";
	first.push_front(1);
	first.push_front(0);
	ft_first.push_front(1);
	ft_first.push_front(0);
	printStdFtLists(first, ft_first);
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "--- pop_front() ---";
	first.pop_front();
	ft_first.pop_front();
	printStdFtLists(first, ft_first);
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "--- push_back() ---";
	first.push_back(7);
	first.push_back(14);
	ft_first.push_back(7);
	ft_first.push_back(14);
	printStdFtLists(first, ft_first);
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "--- pop_back() ---";
	first.pop_back();
	ft_first.pop_back();
	printStdFtLists(first, ft_first);
	if (!compareStdFtLists(first, ft_first))
		passed();

	std::cout << "--- resize() ---";
 	first.resize(2);
 	ft_first.resize(2);
	printStdFtLists(first, ft_first);
	int flag = 0;
 	if (compareStdFtLists(first, ft_first))
 		flag = 1;
 	first.resize(10);
 	ft_first.resize(10);
	printStdFtLists(first, ft_first);			// 99 99 0 0 0 0 0 0 0 0
	if (compareStdFtLists(first, ft_first))
 		flag = 1;
 	if (!flag)
 		passed();

	 std::cout << "--- Insert single element ---";
	std::list<int>::iterator it;
	ft::list<int>::iterator ft_it;
	 it = first.begin();
	 ft_it = ft_first.begin();
	 ++it;
	 ++ft_it;
	 it = first.insert (it, 200 );
	 ft_it = ft_first.insert (ft_it, 200 );
	printStdFtLists(first, ft_first);			// 99 200 99 0 0 0 0 0 0 0 0
	 if (!compareStdFtLists(first, ft_first))
	 	passed();

	 std::cout << "--- Insert fill ---";
	 it = first.begin();
	 ft_it = ft_first.begin();
	 first.insert (it,2,300);
	 ft_first.insert (ft_it,2,300);
	printStdFtLists(first, ft_first);
	 if (!compareStdFtLists(first, ft_first))
	 	passed();

	 std::cout << "--- Insert range ---";
	 int myarray [] = { 501,502,503 };
	 first.insert (first.end(), myarray, myarray + 3);
	 ft_first.insert (ft_first.end(), myarray, myarray + 3);
	printStdFtLists(first, ft_first);
	 if (!compareStdFtLists(first, ft_first))
	 	passed();

	 std::cout << "--- Erase single element ---";

	std::list<int> second;
	std::list<int>::iterator it1, it2;

	ft::list<int> ft_second;
	ft::list<int>::iterator ft_it1, ft_it2;

	for (int i=1; i<10; ++i) {
		second.push_back(i * 10);
		ft_second.push_back(i * 10);
	}
												// 10 20 30 40 50 60 70 80 90
	it1 = it2 = second.begin();
	ft_it1 = ft_it2 = ft_second.begin();
	++it1;
	++ft_it1;
	for (int i=0; i<6; ++i) {
		++it2;
		++ft_it2;
	}
	printStdFtLists(second, ft_second);
	it1 = second.erase (it1);
	ft_it1 = ft_second.erase (ft_it1);   // 10 30 40 50 60 70 80 90

	it2 = second.erase (it2);
	ft_it2 = ft_second.erase (ft_it2);   // 10 30 40 50 60 80 90
	printStdFtLists(second, ft_second);
	if (!compareStdFtLists(second, ft_second))
		passed();
	++it1;
	++ft_it1;

	--it2;
	--ft_it2;
	std::cout << "--- Erase range ---";
	second.erase (it1, it2);
	ft_second.erase (ft_it1,ft_it2);     // 10 30 60 80 90

	printStdFtLists(second, ft_second);
	if (!compareStdFtLists(second, ft_second))
		passed();
}

void ListTester::testOperations() {
	std::list<int> first;
	ft::list<int> ft_first;
	for (int i = 1; i < 10; ++i) {
		first.push_back(i * 10);
		ft_first.push_back(i * 10);
	}
	std::list<int> second;
	ft::list<int> ft_second;
	for (int i = 1; i < 8; ++i) {
		second.push_back(i);
		ft_second.push_back(i);
	}

	std::cout << "\n--- splice() single element ---\n";
	printStdlist(first);
	printStdlist(second);
	printFtlist(ft_first);
	printFtlist(ft_second);

/// a d v a n c i n g
	std::list<int>::iterator itt = first.begin();
	for (int i = 0; i < 5; ++i)
		++itt;
	ft::list<int>::iterator ft_itt = ft_first.begin();
	for (int i = 0; i < 5; ++i)
		++ft_itt;

	std::list<int>::iterator it = second.begin();
	for (int i = 0; i < 3; ++i)
		++it;
	ft::list<int>::iterator ft_it = ft_second.begin();
	for (int i = 0; i < 3; ++i)
		++ft_it;
/// - - - - - - - - -

	std::cout << "\n\n  *splicing . . .*\n";
	first.splice(itt, second, it);
	ft_first.splice(ft_itt, ft_second, ft_it);

	printStdlist(first);
	printStdlist(second);
	printFtlist(ft_first);
	printFtlist(ft_second);
	std::cout << "\n";
	if (!compareStdFtLists(first, ft_first) && !compareStdFtLists(second, ft_second))
		passed();

	std::cout << "--- splice() range ---\n";

	/// a d v a n c i n g
	//	source iterators
	itt = first.end();
	for (int i = 0; i < 7; ++i)
		--itt;
	ft_itt = ft_first.end();
	for (int i = 0; i < 7; ++i)
		--ft_itt;

	it = first.end();
	for (int i = 0; i < 4; ++i)
		--it;
	ft_it = ft_first.end();
	for (int i = 0; i < 4; ++i)
		--ft_it;
	//	destination iterators
	std::list<int>::iterator it_dest = second.begin();
	for (int i = 0; i < 3; ++i)
		++it_dest;
	ft::list<int>::iterator ft_it_dest = ft_second.begin();
	for (int i = 0; i < 3; ++i)
		++ft_it_dest;

	//	std::cout << "*it_dest is at [" << *it_dest << "] and *ft_it_dest is at [" << *ft_it_dest << "]\n";
	//	std::cout << "*itt is at [" << *itt << "] and *ft_itt is at [" << *ft_itt << "]\n";
	//	std::cout << "*it is at [" << *it << "] and *ft_it is at [" << *ft_it << "]\n";
	/// - - - - - - - - -


	std::cout << "\n  *splicing . . .*\n";
	second.splice(it_dest, first, itt, it);
	ft_second.splice(ft_it_dest, ft_first, ft_itt, ft_it);

	printStdlist(first);
	printStdlist(second);
	printFtlist(ft_first);
	printFtlist(ft_second);
	std::cout << "\n";
	if (!compareStdFtLists(first, ft_first) && !compareStdFtLists(second, ft_second))
		passed();


	std::cout << "\n--- splice() entire list ---\n";
	std::cout << "\n  *splicing . . .*\n";
	second.splice(second.begin(), first);
	ft_second.splice(ft_second.begin(), ft_first);

	printStdlist(first);
	printStdlist(second);
	printFtlist(ft_first);
	printFtlist(ft_second);
	std::cout << "\n";
	if (!compareStdFtLists(first, ft_first) && !compareStdFtLists(second, ft_second))
		passed();

	std::cout << "--- remove() ---\n";

	second.remove(90);
	second.remove(4);
	ft_second.remove(90);
	ft_second.remove(4);

	printStdFtLists(second, ft_second);
	if (!compareStdFtLists(second, ft_second))
		passed();

	std::cout << "--- remove_if() ---";

	int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
	std::list<int> third (myints, myints + 8);   // 15 36 7 17 20 39 4 1
	ft::list<int> ft_third (myints, myints + 8);
	printStdlist(third);
	printFtlist(ft_third);

	third.remove_if(single_digit);        		   // 15 36 17 20 39
	third.remove_if(is_odd());               // 36 20
	ft_third.remove_if(single_digit);        		   // 15 36 17 20 39
	ft_third.remove_if(is_odd());               // 36 20

	printStdlist(third);
	printFtlist(ft_third);
	std::cout << "\n";
	if (!compareStdFtLists(third, ft_third))
		passed();

	std::cout << "--- unique() ---";
	int myints2[] = {15, 15, 7, 17, 17, 17, 4, 3};
	std::list<int> fourth (myints2, myints2 + 8);
	ft::list<int> ft_fourth (myints2, myints2 + 8);
	printStdlist(fourth);
	printFtlist(ft_fourth);

	fourth.unique();
	ft_fourth.unique();

	printStdlist(fourth);
	printFtlist(ft_fourth);
	std::cout << "\n";
	if (!compareStdFtLists(fourth, ft_fourth))
		passed();

	std::cout << "--- sort() ---";

	double mydoubles[] = { 12.15,  2.72, 73.0,  12.77,  3.14,
						 12.77, 73.35, 72.25, 15.3,  72.25 };
	std::list<double> fifth (mydoubles,mydoubles+10);
	ft::list<double> ft_fifth (mydoubles,mydoubles+10);
	printStdFtLists(fifth, ft_fifth);

	fifth.sort();             		//  2.72,  3.14, 12.15, 12.77, 12.77, 15.3,  72.25, 72.25, 73.0,  73.35
	ft_fifth.sort();             	//  2.72,  3.14, 12.15, 12.77, 12.77, 15.3,  72.25, 72.25, 73.0,  73.35
	printStdFtLists(fifth, ft_fifth);
	if (!compareStdFtLists(fifth, ft_fifth))
		passed();
	std::cout << "--- unique() ---";

	fifth.unique();          		 //  2.72,  3.14, 12.15, 12.77, 15.3,  72.25, 73.0,  73.35
	ft_fifth.unique();        		 //  2.72,  3.14, 12.15, 12.77, 15.3,  72.25, 73.0,  73.35
	printStdFtLists(fifth, ft_fifth);
	if (!compareStdFtLists(fifth, ft_fifth))
		passed();
	std::cout << "\n--- unique(BinaryPredicate) ---";
	std::cout << "\n\t--- (same_integral_part) ---";
	fifth.unique (same_integral_part); 		 	//  2.72,  3.14, 12.15, 15.3,  72.25, 73.0
	ft_fifth.unique (same_integral_part); 		 //  2.72,  3.14, 12.15, 15.3,  72.25, 73.0
	printStdFtLists(fifth, ft_fifth);
	std::cout << "\n\t--- (is_near) ---";
	fifth.unique (is_near());         	  //  2.72, 12.15, 72.25
	ft_fifth.unique (is_near());           //  2.72, 12.15, 72.25
	printStdFtLists(fifth, ft_fifth);
	if (!compareStdFtLists(fifth, ft_fifth))
		passed();

	std::cout << "--- merge(list) ---";
  	std::list<double> std_d_first, std_d_second;
  	ft::list<double> ft_d_first, ft_d_second;

	std_d_first.push_back (3.1);
	std_d_first.push_back (2.2);
	std_d_first.push_back (2.9);
	std_d_second.push_back (3.7);
	std_d_second.push_back (7.1);
	std_d_second.push_back (1.4);

	ft_d_first.push_back (3.1);
	ft_d_first.push_back (2.2);
	ft_d_first.push_back (2.9);
	ft_d_second.push_back (3.7);
	ft_d_second.push_back (7.1);
	ft_d_second.push_back (1.4);

	printStdlist(std_d_first);
	printStdlist(std_d_second);
	printFtlist(ft_d_first);
	printFtlist(ft_d_second);

	std::cout << "\n\n  *sorting . . .*\n";

	std_d_first.sort();
	std_d_second.sort();
	ft_d_first.sort();
	ft_d_second.sort();

	printStdlist(std_d_first);
	printStdlist(std_d_second);
	printFtlist(ft_d_first);
	printFtlist(ft_d_second);

	std::cout << "\n\n  *merging . . .*\n";
	std_d_first.merge(std_d_second);
	ft_d_first.merge(ft_d_second);
	printStdlist(std_d_first);
	printStdlist(std_d_second);
	printFtlist(ft_d_first);
	printFtlist(ft_d_second);

	std::cout << std::endl;
	if (!compareStdFtLists(std_d_first, ft_d_first) && !compareStdFtLists(std_d_second, ft_d_second))
		passed();

	std::cout << "\n--- merge(list, Compare) ---";
	std_d_second.push_back (2.1);
	ft_d_second.push_back (2.1);

	printStdlist(std_d_first);
	printStdlist(std_d_second);
	printFtlist(ft_d_first);
	printFtlist(ft_d_second);
	std_d_first.merge(std_d_second, mycomparison);
	ft_d_first.merge(ft_d_second, mycomparison);
	printStdlist(std_d_first);
	printStdlist(std_d_second);
	printFtlist(ft_d_first);
	printFtlist(ft_d_second);

	std::cout << std::endl;
	if (!compareStdFtLists(std_d_first, ft_d_first) && !compareStdFtLists(std_d_second, ft_d_second))
		passed();

//	std::cout << "--- sort(Compare) ---";
//
//
//	std::cout << "--- reverse() ---";


}

void ListTester::testSwap() {
	 std::cout << "--- swap() ---";

	 std::list<int> first (3,100);   // three ints with a value of 100
	 ft::list<int> ft_first (3,100);   // three ints with a value of 100

	 std::list<int> second (5,200);   // five ints with a value of 200
	 ft::list<int> ft_second (5,200);   // five ints with a value of 200
	printStdFtLists(first, ft_first);
	printStdFtLists(second, ft_second);

	 first.swap(second);
	 ft_first.swap(ft_second);

	printStdFtLists(first, ft_first);
	printStdFtLists(second, ft_second);

	 if (!compareStdFtLists(first, ft_first) && !compareStdFtLists(second, ft_second))
	 	passed();
}

void ListTester::testRelationalOperators() {
	// std::cout << "--- relational operators ---\n";

	// std::list<int> first (3,100);   // three ints with a value of 100
	// std::list<int> second (2,200);   // two ints with a value of 200
	// ft::list<int> ft_first (3,100);   // three ints with a value of 100
	// ft::list<int> ft_second (2,200);   // two ints with a value of 200

	// if ((first==second) == (ft_first==ft_second) && \
	// 	(first!=second) == (ft_first!=ft_second) && \
	// 	(first< second) == (ft_first< ft_second)  && \
	// 	(first> second) == (ft_first> ft_second)  && \
	// 	(first<=second) == (ft_first<=ft_second) && \
	// 	(first>=second) == (ft_first>=ft_second))
	// 		passed();
	// else
	// 	std::cout << RED << "FAIL ❌\n" << NC;
}

void ListTester::passed() {
	const unsigned int microseconds = 250000; //1000000 microseconds = 1 sec
	std::cout << GREEN << "PASSED ✅" << NC << "\n\n";
	usleep(microseconds);
}

template <class T>
int ListTester::compareStdFtLists(std::list<T> &std_list, ft::list<T> &ft_list) {
	int fail = 0;

	for (typename std::list<T>::iterator it = std_list.begin(); it != std_list.end(); it++) {
		stdString << *it << ' ';
	}
	for (typename ft::list<T>::iterator ft_it = ft_list.begin(); ft_it != ft_list.end(); ft_it++) {
		ftString << *ft_it << ' ';
	}
	if (ftString.str().compare(stdString.str())) {
		std::cout << RED << "FAIL ❌\n" << "Ft list : " << ftString.str() \
		<< "\nStd list: " << stdString.str() << NC << "\n";
		fail = 1;
	}

	if (std_list.size() != ft_list.size()) {
		std::cout << RED << "SIZE FAIL ❌\n" << "Ft list size: " << ft_list.size() \
		<< "\nStd list size: " << std_list.size() << NC << "\n";
		fail = 1;
	}
	stdString.str(std::string());
	ftString.str(std::string());
	return fail;
}

template <class T>
void ListTester::printStdFtLists(std::list<T> &std_list, ft::list<T> &ft_list) {
	std::cout << "\nFt list : ";
	for (typename ft::list<T>::iterator ft_it = ft_list.begin(); ft_it != ft_list.end(); ft_it++) {
		std::cout << *ft_it << ' ';
	}
	std::cout << "\nStd list: ";
	for (typename std::list<T>::iterator it = std_list.begin(); it != std_list.end(); it++) {
		std::cout << *it << ' ';
	}
	std::cout << "\n";
}

template <class T>
void ListTester::printStdlist(std::list<T> &std_list) {
	std::cout << "\nStd list: ";
	for (typename std::list<T>::iterator it = std_list.begin(); it != std_list.end(); it++) {
		std::cout << *it << ' ';
	}
}

template <class T>
void ListTester::printFtlist(ft::list<T> &ft_list) {
	std::cout << "\nFt list:  ";
	for (typename ft::list<T>::iterator ft_it = ft_list.begin(); ft_it != ft_list.end(); ft_it++) {
		std::cout << *ft_it << ' ';
	}
}

#pragma clang diagnostic pop