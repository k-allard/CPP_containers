#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
#include "../header.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define NC "\033[0m"

class MapTester {
public:
	MapTester() {
		std::cout << " - - - - - - - - - - - - - - - - - - - - - - - -";
		std::cout << "\n" << " - - - - - - - - - - M A P - - - - - - - - - - - " << "\n";
		std::cout << " - - - - - - - - - - - - - - - - - - - - - - - -\n";
	}
	void testConstructors();
	void testAssignations();
	void testIterators();
	void testCapacity();
	void testElementAccess();
	void testModifiers() ;
	void testObservers();

	void testSwap();
	void testRelationalOperators();

 private:
 	std::stringstream stdString;
 	std::stringstream ftString;
 	static void passed();
 	template <class Key, class T> int compareStdFtmaps(std::map<Key,T> &std_map, ft::map<Key,T> &ft_map);
// 	template <class T> void printStdFtmaps(std::map<T> &std_map, ft::map<T> &ft_map);
// 	template <class T> void printStdmap(std::map<T> &std_map);
// 	template <class T> void printFtmap(ft::map<T> &ft_map);

// 	// a predicate implemented as a class:
// 	struct is_odd {
// 		bool operator() (const int& value) { return (value % 2) == 1; }
// 	};

// 	// a binary predicate implemented as a class:
// 	struct is_near {
// 		bool operator() (double first, double second)
// 		{ return (fabs(first-second) < 5.0); }
// 	};
};

void MapTester::testConstructors() {
	std::map<int, std::string> first;
	std::map<int, std::string> second;
	//  std::map<int, string> third (second.begin(),second.end());
	std::map<int, std::string> fourth (second);

	ft::map<int, std::string> ft_first;
	ft::map<int, std::string> ft_second;
	//  ft::map<int, string> ft_third (ft_second.begin(),ft_second.end());
	ft::map<int, std::string> ft_fourth (ft_second);

	 std::cout << "Default constructor - ";
	 if (!compareStdFtmaps(first, ft_first))
	 	passed();
	// std::cout << "Fill constructor -    ";
	// if (!compareStdFtmaps(second, ft_second))
	// 	passed();
	//  std::cout << "Range constructor -   ";
	//  if (!compareStdFtmaps(third, ft_third))
	//  	passed();
	// std::cout << "Copy constructor -    ";
	// if (!compareStdFtmaps(fourth, ft_fourth))
	// 	passed();
}

void MapTester::testAssignations() {
	// std::map<int> first(3,0);
	// std::map<int> second(5,0);
	// std::map<int> third;

	// ft::map<int> ft_first(3,0);
	// ft::map<int> ft_second(5,0);
	// ft::map<int> ft_third;

	// first = second;
	// ft_first = ft_second;

	// std::cout << "operator= -           ";
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "Fill assignation -    ";
	// first.assign(2, 99);
	// ft_first.assign(2, 99);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "Range assignation -   ";
	// int myints[] = {1776,7,4};
	// third.assign (myints, myints + 3);
	// ft_third.assign (myints, myints + 3);
	// if (!compareStdFtmaps(third, ft_third))
	// 	passed();
}

void MapTester::testIterators() {
	// std::map<int> first (5);  // 5 ints 0
	// ft::map<int> ft_first (5);  // 5 ints 0

	// std::cout << "rbegin() and rend() - ";

	// std::map<int>::reverse_iterator rit = first.rbegin();
	// ft::map<int>::reverse_iterator ft_rit = ft_first.rbegin();

	// int i = 0;
	// for (; rit != first.rend(); ++rit)
	// 	*rit = ++i;

	// int k = 0;
	// for (; ft_rit != ft_first.rend(); ++ft_rit)
	// 	*ft_rit = ++k;

	// printStdFtmaps(first, ft_first);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "begin() and end() -   ";
	// for (std::map<int>::iterator it = first.begin(); it != first.end(); ++it)
	// 	*(it) += 1;

	// for (ft::map<int>::iterator ft_it = ft_first.begin(); ft_it != ft_first.end(); ++ft_it)
	// 	*(ft_it) += 1;

	// printStdFtmaps(first, ft_first);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();
}

void MapTester::testCapacity() {
	// int flag = 0;

	// std::cout << "size() -              ";
	// std::map<int> first (6, 7);
	// ft::map<int> ft_first (6, 7);
	// int myints[] = { 12, 10, 8, 6, 4, 2, 1 };


	// first.assign (myints, myints + 7);
	// ft_first.assign (myints, myints + 7);
	// if (first.size() == ft_first.size())
	// 	passed();
	// else
	// 	std::cout << RED << "FAIL ❌\n" << "Ft map size: " << ft_first.size() \
	// 	<< "\nStd map size: " << first.size() << NC << "\n";

 	// std::cout << "max_size() -          ";
 	// if (first.max_size() == ft_first.max_size())
 	// 	passed();
 	// else
 	// 	std::cout << RED << "FAIL ❌\n" << "Ft map size: " << ft_first.size() \
 	// 	<< "\nStd map size: " << first.size() << NC << "\n";


 	// std::cout << "empty() -             ";
 	// std::map<int> second;
 	// ft::map<int> ft_second;
 	// if (first.empty() == ft_first.empty() && second.empty() == ft_second.empty())
 	// 	passed();
 	// else
 	// 	std::cout << RED << "FAIL ❌\n" << NC;
 }

 void MapTester::testElementAccess() {
 	// std::map<int> first (3, 4);   // 10 zero-initialized elements
 	// ft::map<int> ft_first (3, 4);   // 10 zero-initialized elements
 	// std::map<int>::size_type sz = first.size();
 	// ft::map<int>::size_type ft_sz = ft_first.size();
	// first.resize(5);
	//  ft_first.resize(5);

	//  printStdFtmaps(first, ft_first);

 	// std::cout << "front() -             ";
 	// if (first.front() == ft_first.front())
 	// 		passed();
 	// else
 	// 	std::cout << RED << "FAIL ❌\n" << NC;
 	// std::cout << "back() -              ";
 	// if (first.back() == ft_first.back())
 	// 		passed();
 	// else
 	// 	std::cout << RED << "FAIL ❌\n" << NC;
}

void MapTester::testModifiers() {
	// std::map<int> first (5);  // 5 default-constructed ints
	// ft::map<int> ft_first (5);  // 5 default-constructed ints

	// std::cout << "--- Range assign ---";
	// int myints[] = {1776,7,4};
	// first.assign (myints,myints + 3);
	// ft_first.assign(myints,myints + 3);
	// printStdFtmaps(first, ft_first);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "--- Fill assign ---";
	// first.assign (2,99);
	// ft_first.assign(2,99);
	// printStdFtmaps(first, ft_first);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "--- push_front() ---";
	// first.push_front(1);
	// first.push_front(0);
	// ft_first.push_front(1);
	// ft_first.push_front(0);
	// printStdFtmaps(first, ft_first);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "--- pop_front() ---";
	// first.pop_front();
	// ft_first.pop_front();
	// printStdFtmaps(first, ft_first);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "--- push_back() ---";
	// first.push_back(7);
	// first.push_back(14);
	// ft_first.push_back(7);
	// ft_first.push_back(14);
	// printStdFtmaps(first, ft_first);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "--- pop_back() ---";
	// first.pop_back();
	// ft_first.pop_back();
	// printStdFtmaps(first, ft_first);
	// if (!compareStdFtmaps(first, ft_first))
	// 	passed();

	// std::cout << "--- resize() ---";
 	// first.resize(2);
 	// ft_first.resize(2);
	// printStdFtmaps(first, ft_first);
	// int flag = 0;
 	// if (compareStdFtmaps(first, ft_first))
 	// 	flag = 1;
 	// first.resize(10);
 	// ft_first.resize(10);
	// printStdFtmaps(first, ft_first);			// 99 99 0 0 0 0 0 0 0 0
	// if (compareStdFtmaps(first, ft_first))
 	// 	flag = 1;
 	// if (!flag)
 	// 	passed();

	//  std::cout << "--- Insert single element ---";
	// std::map<int>::iterator it;
	// ft::map<int>::iterator ft_it;
	//  it = first.begin();
	//  ft_it = ft_first.begin();
	//  ++it;
	//  ++ft_it;
	//  it = first.insert (it, 200 );
	//  ft_it = ft_first.insert (ft_it, 200 );
	// printStdFtmaps(first, ft_first);			// 99 200 99 0 0 0 0 0 0 0 0
	//  if (!compareStdFtmaps(first, ft_first))
	//  	passed();

	//  std::cout << "--- Insert fill ---";
	//  it = first.begin();
	//  ft_it = ft_first.begin();
	//  first.insert (it,2,300);
	//  ft_first.insert (ft_it,2,300);
	// printStdFtmaps(first, ft_first);
	//  if (!compareStdFtmaps(first, ft_first))
	//  	passed();

	//  std::cout << "--- Insert range ---";
	//  int myarray [] = { 501,502,503 };
	//  first.insert (first.end(), myarray, myarray + 3);
	//  ft_first.insert (ft_first.end(), myarray, myarray + 3);
	// printStdFtmaps(first, ft_first);
	//  if (!compareStdFtmaps(first, ft_first))
	//  	passed();

	//  std::cout << "--- Erase single element ---";

	// std::map<int> second;
	// std::map<int>::iterator it1, it2;

	// ft::map<int> ft_second;
	// ft::map<int>::iterator ft_it1, ft_it2;

	// for (int i=1; i<10; ++i) {
	// 	second.push_back(i * 10);
	// 	ft_second.push_back(i * 10);
	// }
	// 											// 10 20 30 40 50 60 70 80 90
	// it1 = it2 = second.begin();
	// ft_it1 = ft_it2 = ft_second.begin();
	// ++it1;
	// ++ft_it1;
	// for (int i=0; i<6; ++i) {
	// 	++it2;
	// 	++ft_it2;
	// }
	// printStdFtmaps(second, ft_second);
	// it1 = second.erase (it1);
	// ft_it1 = ft_second.erase (ft_it1);   // 10 30 40 50 60 70 80 90

	// it2 = second.erase (it2);
	// ft_it2 = ft_second.erase (ft_it2);   // 10 30 40 50 60 80 90
	// printStdFtmaps(second, ft_second);
	// if (!compareStdFtmaps(second, ft_second))
	// 	passed();
	// ++it1;
	// ++ft_it1;

	// --it2;
	// --ft_it2;
	// std::cout << "--- Erase range ---";
	// second.erase (it1, it2);
	// ft_second.erase (ft_it1,ft_it2);     // 10 30 60 80 90

	// printStdFtmaps(second, ft_second);
	// if (!compareStdFtmaps(second, ft_second))
	// 	passed();
}

void MapTester::testObservers() {
// 	std::map<int> first;
// 	ft::map<int> ft_first;
// 	for (int i = 1; i < 10; ++i) {
// 		first.push_back(i * 10);
// 		ft_first.push_back(i * 10);
// 	}
// 	std::map<int> second;
// 	ft::map<int> ft_second;
// 	for (int i = 1; i < 8; ++i) {
// 		second.push_back(i);
// 		ft_second.push_back(i);
// 	}

// 	std::cout << "\n--- splice() single element ---\n";
// 	printStdmap(first);
// 	printStdmap(second);
// 	printFtmap(ft_first);
// 	printFtmap(ft_second);

// /// a d v a n c i n g
// 	std::map<int>::iterator itt = first.begin();
// 	for (int i = 0; i < 5; ++i)
// 		++itt;
// 	ft::map<int>::iterator ft_itt = ft_first.begin();
// 	for (int i = 0; i < 5; ++i)
// 		++ft_itt;

// 	std::map<int>::iterator it = second.begin();
// 	for (int i = 0; i < 3; ++i)
// 		++it;
// 	ft::map<int>::iterator ft_it = ft_second.begin();
// 	for (int i = 0; i < 3; ++i)
// 		++ft_it;
// /// - - - - - - - - -

// 	std::cout << "\n\n  *splicing . . .*\n";
// 	first.splice(itt, second, it);
// 	ft_first.splice(ft_itt, ft_second, ft_it);

// 	printStdmap(first);
// 	printStdmap(second);
// 	printFtmap(ft_first);
// 	printFtmap(ft_second);
// 	std::cout << "\n";
// 	if (!compareStdFtmaps(first, ft_first) && !compareStdFtmaps(second, ft_second))
// 		passed();

// 	std::cout << "--- splice() range ---\n";

// 	/// a d v a n c i n g
// 	//	source iterators
// 	itt = first.end();
// 	for (int i = 0; i < 7; ++i)
// 		--itt;
// 	ft_itt = ft_first.end();
// 	for (int i = 0; i < 7; ++i)
// 		--ft_itt;

// 	it = first.end();
// 	for (int i = 0; i < 4; ++i)
// 		--it;
// 	ft_it = ft_first.end();
// 	for (int i = 0; i < 4; ++i)
// 		--ft_it;
// 	//	destination iterators
// 	std::map<int>::iterator it_dest = second.begin();
// 	for (int i = 0; i < 3; ++i)
// 		++it_dest;
// 	ft::map<int>::iterator ft_it_dest = ft_second.begin();
// 	for (int i = 0; i < 3; ++i)
// 		++ft_it_dest;

// 	//	std::cout << "*it_dest is at [" << *it_dest << "] and *ft_it_dest is at [" << *ft_it_dest << "]\n";
// 	//	std::cout << "*itt is at [" << *itt << "] and *ft_itt is at [" << *ft_itt << "]\n";
// 	//	std::cout << "*it is at [" << *it << "] and *ft_it is at [" << *ft_it << "]\n";
// 	/// - - - - - - - - -


// 	std::cout << "\n  *splicing . . .*\n";
// 	second.splice(it_dest, first, itt, it);
// 	ft_second.splice(ft_it_dest, ft_first, ft_itt, ft_it);

// 	printStdmap(first);
// 	printStdmap(second);
// 	printFtmap(ft_first);
// 	printFtmap(ft_second);
// 	std::cout << "\n";
// 	if (!compareStdFtmaps(first, ft_first) && !compareStdFtmaps(second, ft_second))
// 		passed();


// 	std::cout << "\n--- splice() entire map ---\n";
// 	std::cout << "\n  *splicing . . .*\n";
// 	second.splice(second.begin(), first);
// 	ft_second.splice(ft_second.begin(), ft_first);

// 	printStdmap(first);
// 	printStdmap(second);
// 	printFtmap(ft_first);
// 	printFtmap(ft_second);
// 	std::cout << "\n";
// 	if (!compareStdFtmaps(first, ft_first) && !compareStdFtmaps(second, ft_second))
// 		passed();

// 	std::cout << "--- remove() ---\n";

// 	second.remove(90);
// 	second.remove(4);
// 	ft_second.remove(90);
// 	ft_second.remove(4);

// 	printStdFtmaps(second, ft_second);
// 	if (!compareStdFtmaps(second, ft_second))
// 		passed();

// 	std::cout << "--- remove_if() ---";

// 	int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
// 	std::map<int> third (myints, myints + 8);   // 15 36 7 17 20 39 4 1
// 	ft::map<int> ft_third (myints, myints + 8);
// 	printStdmap(third);
// 	printFtmap(ft_third);

// 	third.remove_if(single_digit);        		   // 15 36 17 20 39
// 	third.remove_if(is_odd());               // 36 20
// 	ft_third.remove_if(single_digit);        		   // 15 36 17 20 39
// 	ft_third.remove_if(is_odd());               // 36 20

// 	printStdmap(third);
// 	printFtmap(ft_third);
// 	std::cout << "\n";
// 	if (!compareStdFtmaps(third, ft_third))
// 		passed();

// 	std::cout << "--- unique() ---";
// 	int myints2[] = {15, 15, 7, 17, 17, 17, 4, 3};
// 	std::map<int> fourth (myints2, myints2 + 8);
// 	ft::map<int> ft_fourth (myints2, myints2 + 8);
// 	printStdmap(fourth);
// 	printFtmap(ft_fourth);

// 	fourth.unique();
// 	ft_fourth.unique();

// 	printStdmap(fourth);
// 	printFtmap(ft_fourth);
// 	std::cout << "\n";
// 	if (!compareStdFtmaps(fourth, ft_fourth))
// 		passed();

// 	std::cout << "--- sort() ---";

// 	double mydoubles[] = { 12.15,  2.72, 73.0,  12.77,  3.14,
// 						 12.77, 73.35, 72.25, 15.3,  72.25 };
// 	std::map<double> fifth (mydoubles,mydoubles+10);
// 	ft::map<double> ft_fifth (mydoubles,mydoubles+10);
// 	printStdFtmaps(fifth, ft_fifth);

// 	fifth.sort();             		//  2.72,  3.14, 12.15, 12.77, 12.77, 15.3,  72.25, 72.25, 73.0,  73.35
// 	ft_fifth.sort();             	//  2.72,  3.14, 12.15, 12.77, 12.77, 15.3,  72.25, 72.25, 73.0,  73.35
// 	printStdFtmaps(fifth, ft_fifth);
// 	if (!compareStdFtmaps(fifth, ft_fifth))
// 		passed();
// 	std::cout << "--- unique() ---";

// 	fifth.unique();          		 //  2.72,  3.14, 12.15, 12.77, 15.3,  72.25, 73.0,  73.35
// 	ft_fifth.unique();        		 //  2.72,  3.14, 12.15, 12.77, 15.3,  72.25, 73.0,  73.35
// 	printStdFtmaps(fifth, ft_fifth);
// 	if (!compareStdFtmaps(fifth, ft_fifth))
// 		passed();
// 	std::cout << "\n--- unique(BinaryPredicate) ---";
// 	std::cout << "\n\t--- (same_integral_part) ---";
// 	fifth.unique (same_integral_part); 		 	//  2.72,  3.14, 12.15, 15.3,  72.25, 73.0
// 	ft_fifth.unique (same_integral_part); 		 //  2.72,  3.14, 12.15, 15.3,  72.25, 73.0
// 	printStdFtmaps(fifth, ft_fifth);
// 	std::cout << "\n\t--- (is_near) ---";
// 	fifth.unique (is_near());         	  //  2.72, 12.15, 72.25
// 	ft_fifth.unique (is_near());           //  2.72, 12.15, 72.25
// 	printStdFtmaps(fifth, ft_fifth);
// 	if (!compareStdFtmaps(fifth, ft_fifth))
// 		passed();

// 	std::cout << "--- merge(map) ---";
//   	std::map<double> std_d_first, std_d_second;
//   	ft::map<double> ft_d_first, ft_d_second;

// 	std_d_first.push_back (3.1);
// 	std_d_first.push_back (2.2);
// 	std_d_first.push_back (2.9);
// 	std_d_second.push_back (3.7);
// 	std_d_second.push_back (7.1);
// 	std_d_second.push_back (1.4);

// 	ft_d_first.push_back (3.1);
// 	ft_d_first.push_back (2.2);
// 	ft_d_first.push_back (2.9);
// 	ft_d_second.push_back (3.7);
// 	ft_d_second.push_back (7.1);
// 	ft_d_second.push_back (1.4);

// 	printStdmap(std_d_first);
// 	printStdmap(std_d_second);
// 	printFtmap(ft_d_first);
// 	printFtmap(ft_d_second);

// 	std::cout << "\n\n  *sorting . . .*\n";

// 	std_d_first.sort();
// 	std_d_second.sort();
// 	ft_d_first.sort();
// 	ft_d_second.sort();

// 	printStdmap(std_d_first);
// 	printStdmap(std_d_second);
// 	printFtmap(ft_d_first);
// 	printFtmap(ft_d_second);

// 	std::cout << "\n\n  *merging . . .*\n";
// 	std_d_first.merge(std_d_second);
// 	ft_d_first.merge(ft_d_second);
// 	printStdmap(std_d_first);
// 	printStdmap(std_d_second);
// 	printFtmap(ft_d_first);
// 	printFtmap(ft_d_second);

// 	std::cout << std::endl;
// 	if (!compareStdFtmaps(std_d_first, ft_d_first) && !compareStdFtmaps(std_d_second, ft_d_second))
// 		passed();

// 	std::cout << "\n--- merge(map, Compare) ---";
// 	std_d_second.push_back (2.1);
// 	ft_d_second.push_back (2.1);

// 	printStdmap(std_d_first);
// 	printStdmap(std_d_second);
// 	printFtmap(ft_d_first);
// 	printFtmap(ft_d_second);
// 	std::cout << "\n\n  *merging . . .*\n";

// 	std_d_first.merge(std_d_second, mycomparison);
// 	ft_d_first.merge(ft_d_second, mycomparison);
// 	printStdmap(std_d_first);
// 	printStdmap(std_d_second);
// 	printFtmap(ft_d_first);
// 	printFtmap(ft_d_second);

// 	std::cout << std::endl;
// 	if (!compareStdFtmaps(std_d_first, ft_d_first) && !compareStdFtmaps(std_d_second, ft_d_second))
// 		passed();

// 	std::cout << "--- sort(Compare) ---";
// 	std_d_first.clear();
// 	ft_d_first.clear();

// 	std_d_first.push_back (3.1);
// 	std_d_first.push_back (2.9);
// 	std_d_first.push_back (2.2);

// 	ft_d_first.push_back (3.1);
// 	ft_d_first.push_back (2.9);
// 	ft_d_first.push_back (2.2);

// 	printStdFtmaps(std_d_first, ft_d_first);
// 	std::cout << "\n\n  *sorting . . .*\n";
// 	std_d_first.sort(mycomparison);
// 	ft_d_first.sort(mycomparison);
// 	printStdFtmaps(std_d_first, ft_d_first);
// 	if (!compareStdFtmaps(std_d_first, ft_d_first))
// 		passed();


// 	std::cout << "--- reverse() ---";
// 	std_d_first.reverse();
// 	ft_d_first.reverse();
// 	printStdFtmaps(std_d_first, ft_d_first);
// 	if (!compareStdFtmaps(std_d_first, ft_d_first))
// 		passed();

}

void MapTester::testSwap() {
	// std::cout << "--- swap() ---";

	// std::map<int> first (3,100);   // three ints with a value of 100
	// ft::map<int> ft_first (3,100);   // three ints with a value of 100

	// std::map<int> second (5,200);   // five ints with a value of 200
	// ft::map<int> ft_second (5,200);   // five ints with a value of 200
	// printStdFtmaps(first, ft_first);
	// printStdFtmaps(second, ft_second);

	// std::cout << "\n\n  *swaping . . .*\n";
	// first.swap(second);
	// ft_first.swap(ft_second);

	// printStdFtmaps(first, ft_first);
	// printStdFtmaps(second, ft_second);

	// if (!compareStdFtmaps(first, ft_first) && !compareStdFtmaps(second, ft_second))
	//  	passed();

	// std::cout << "--- swap() non-member overload ---";
	// std::cout << "\n\n  *swaping . . .*\n";
	// std::swap(first, second);
	// ft::swap(ft_first, ft_second);

	// printStdFtmaps(first, ft_first);
	// printStdFtmaps(second, ft_second);

	// if (!compareStdFtmaps(first, ft_first) && !compareStdFtmaps(second, ft_second))
	//  	passed();
}

void MapTester::testRelationalOperators() {
	// std::cout << "--- relational operators ---\n";

	// std::map<int> first (3,100);   // three ints with a value of 100
	// std::map<int> second (2,200);   // two ints with a value of 200
	// ft::map<int> ft_first (3,100);   // three ints with a value of 100
	// ft::map<int> ft_second (2,200);   // two ints with a value of 200

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

 void MapTester::passed() {
 	const unsigned int microseconds = 250000; //1000000 microseconds = 1 sec
 	std::cout << GREEN << "PASSED ✅" << NC << "\n\n";
 	usleep(microseconds);
 }

 template <class Key, class T>
 int MapTester::compareStdFtmaps(std::map<Key,T> &std_map, ft::map<Key,T> &ft_map) {
 	int fail = 0;

 	for (typename std::map<Key,T>::iterator it = std_map.begin(); it != std_map.end(); it++) {
 		stdString << (*it).first << ':';
        stdString << (*it).second << ' ';
 	}
 	for (typename ft::map<Key,T>::iterator ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++) {
 		ftString << (*ft_it).first << ':';
        ftString << (*ft_it).second << ' ';
 	}
 	if (ftString.str().compare(stdString.str())) {
 		std::cout << RED << "FAIL ❌\n" << "Ft map : " << ftString.str() \
 		<< "\nStd map: " << stdString.str() << NC << "\n";
 		fail = 1;
 	}

 	if (std_map.size() != ft_map.size()) {
 		std::cout << RED << "SIZE FAIL ❌\n" << "Ft map size: " << ft_map.size() \
 		<< "\nStd map size: " << std_map.size() << NC << "\n";
 		fail = 1;
 	}
 	stdString.str(std::string());
 	ftString.str(std::string());
 	return fail;
 }

// template <class T>
// void MapTester::printStdFtmaps(std::map<T> &std_map, ft::map<T> &ft_map) {
// 	std::cout << "\nFt map : ";
// 	for (typename ft::map<T>::iterator ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++) {
// 		std::cout << *ft_it << ' ';
// 	}
// 	std::cout << "\nStd map: ";
// 	for (typename std::map<T>::iterator it = std_map.begin(); it != std_map.end(); it++) {
// 		std::cout << *it << ' ';
// 	}
// 	std::cout << "\n";
// }

// template <class T>
// void MapTester::printStdmap(std::map<T> &std_map) {
// 	std::cout << "\nStd map: ";
// 	for (typename std::map<T>::iterator it = std_map.begin(); it != std_map.end(); it++) {
// 		std::cout << *it << ' ';
// 	}
// }

// template <class T>
// void MapTester::printFtmap(ft::map<T> &ft_map) {
// 	std::cout << "\nFt map:  ";
// 	for (typename ft::map<T>::iterator ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++) {
// 		std::cout << *ft_it << ' ';
// 	}
// }

#pragma clang diagnostic pop
