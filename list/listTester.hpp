#include "../header.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define NC "\033[0m"

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
	void testSwap();
	void testRelationalOperators();

private:
	std::stringstream stdString;
	std::stringstream ftString;
	void passed();
	int compareCustomlists(std::list<int> &std_list, ft::list<int> &ft_list);
	void printCustomlists(std::list<int> &std_list, ft::list<int> &ft_list);
};

void ListTester::testConstructors() {
	std::list<int> first;
	std::list<int> second (4,100);
	// std::list<int> third (second.begin(),second.end());
	// std::list<int> fourth (third);

	ft::list<int> ft_first;
	ft::list<int> ft_second(4, 100);
	// ft::list<int> ft_third (ft_second.begin(),ft_second.end());
	// ft::list<int> ft_fourth (ft_third);
	std::cout << "Default constructor - ";
	if (!compareCustomlists(first, ft_first))
		passed();
	std::cout << "Fill constructor -    ";
	if (!compareCustomlists(second, ft_second))
		passed();
	// std::cout << "Range constructor -   ";
	// if (!compareCustomlists(third, ft_third))
	// 	passed();
	// std::cout << "Copy constructor -    ";
	// if (!compareCustomlists(fourth, ft_fourth))
	// 	passed();
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
	if (!compareCustomlists(first, ft_first))
		passed();

	// std::cout << "Fill assignation -    ";
	// first.assign(2, 99);
	// ft_first.assign(2, 99);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "Range assignation -   ";
	// int myints[] = {1776,7,4};
	// third.assign (myints, myints + 3);
	// ft_third.assign (myints, myints + 3);
	// if (!compareCustomlists(third, ft_third))
	// 	passed();
}

void ListTester::testCapacity() {
// 	int flag = 0;

	std::cout << "size() -              ";
	std::list<int> first (6, 7);
	ft::list<int> ft_first (6, 7);
	// int myints[] = { 12, 10, 8, 6, 4, 2, 1 };


// 	first.assign (myints, myints + 7);
// 	ft_first.assign (myints, myints + 7);
	// if (first.size() == ft_first.size())
	// 	passed();
	// else
	// 	std::cout << RED << "FAIL ❌\n" << "Ft list size: " << ft_first.size() \
	// 	<< "\nStd list size: " << first.size() << NC << "\n";

// 	std::cout << "max_size() -          ";
// 	if (first.max_size() == ft_first.max_size())
// 		passed();
// 	else
// 		std::cout << RED << "FAIL ❌\n" << "Ft list size: " << ft_first.size() \
// 		<< "\nStd list size: " << first.size() << NC << "\n";

// 	std::cout << "capacity() -          ";
// 	if (first.capacity() == ft_first.capacity())
// 		passed();
// 	else
// 		std::cout << RED << "FAIL ❌\n" << "Ft list capacity: " << ft_first.capacity() \
// 		<< "\nStd list capacity: " << first.capacity() << NC << "\n";

// 	std::cout << "empty() -             ";
// 	std::list<int> second;
// 	ft::list<int> ft_second;
// 	if (first.empty() == ft_first.empty() && second.empty() == ft_second.empty())
// 		passed();
// 	else
// 		std::cout << RED << "FAIL ❌\n" << NC;

// 	std::cout << "reserve() -           ";
// 	first.reserve(100);
// 	ft_first.reserve(100);
// 	if (first.capacity() == ft_first.capacity())
// 		passed();
// 	else
// 		std::cout << RED << "FAIL ❌\n" << NC;

// 	std::cout << "resize() -            ";
// 	first.resize(3);
// 	ft_first.resize(3);
// 	flag = 0;
// 	if (compareCustomlists(first, ft_first))
// 		flag = 1;
// 	first.resize(10);
// 	ft_first.resize(10);
// 	if (compareCustomlists(first, ft_first))
// 		flag = 1;
// 	if (!flag)
// 		passed();
// }

// void ListTester::testElementAccess() {
// 	std::cout << "operator[] -          ";
// 	std::list<int> first (10);   // 10 zero-initialized elements
// 	ft::list<int> ft_first (10);   // 10 zero-initialized elements
// 	std::list<int>::size_type sz = first.size();
// 	ft::list<int>::size_type ft_sz = ft_first.size();
// 	// assign values:
// 	for (unsigned i = 0; i < sz; i++) first[i]=i;
// 	for (unsigned i = 0; i < ft_sz; i++) ft_first[i]=i;

// 	if (!compareCustomlists(first, ft_first))
// 		passed();

// 	std::cout << "at() -                ";
// 	// reverse std list using function at:
// 	for (unsigned i = 0; i < sz / 2; i++) {
// 		int temp;
// 		temp = first.at(sz - 1 - i);
// 		first.at(sz - 1 - i) = first.at(i);
// 		first.at(i)=temp;
// 	}
// 	// reverse ft list using operator[]:
// 	for (unsigned i = 0; i < ft_sz / 2; i++) {
// 		int temp;
// 		temp = ft_first.at(ft_sz - 1 - i);
// 		ft_first.at(ft_sz - 1 - i) = ft_first.at(i);
// 		ft_first.at(i)=temp;
// 	}
// 	if (!compareCustomlists(first, ft_first))
// 		passed();

// 	std::cout << "front() -             ";
// 	if (first.front() == ft_first.front())
// 			passed();
// 	else
// 		std::cout << RED << "FAIL ❌\n" << NC;
// 	std::cout << "back() -              ";
// 	if (first.back() == ft_first.back())
// 			passed();
// 	else
// 		std::cout << RED << "FAIL ❌\n" << NC;
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

	printCustomlists(first, ft_first);
	if (!compareCustomlists(first, ft_first))
		passed();

	std::cout << "begin() and end() -   ";
	for (std::list<int>::iterator it = first.begin(); it != first.end(); ++it)
		*(it) += 1;

	for (ft::list<int>::iterator ft_it = ft_first.begin(); ft_it != ft_first.end(); ++ft_it)
		*(ft_it) += 1;

printCustomlists(first, ft_first);
	if (!compareCustomlists(first, ft_first))
		passed();

}

void ListTester::testModifiers() {
	// std::list<int> first (5);  // 5 default-constructed ints
	// ft::list<int> ft_first (5);  // 5 default-constructed ints

	// std::cout << "--- Range assign ---";
	// int myints[] = {1776,7,4};
	// first.assign (myints,myints + 3);
	// ft_first.assign(myints,myints + 3);
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "--- Fill assign ---";
	// first.assign (2,99);
	// ft_first.assign(2,99);
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "--- push_back() ---";
	// first.push_back(7);
	// first.push_back(14);
	// ft_first.push_back(7);
	// ft_first.push_back(14);
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "--- pop_back() ---";
	// first.pop_back();
	// ft_first.pop_back();
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "--- Insert single element ---";
	// std::list<int>::iterator it;
	// ft::list<int>::iterator ft_it;
	// it = first.begin();
	// ft_it = ft_first.begin();
	// it = first.insert ( it + 1, 200 );
	// ft_it = ft_first.insert ( ft_it + 1, 200 );
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "--- Insert fill ---";
	// it = first.begin();
	// ft_it = ft_first.begin();
	// first.insert (it,2,300);
	// ft_first.insert (ft_it,2,300);
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "--- Insert range ---";
	// int myarray [] = { 501,502,503 };
	// first.insert (first.end() - 1, myarray, myarray + 3);
	// ft_first.insert (ft_first.end() - 1, myarray, myarray + 3);
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "--- Erase single element ---";
	// first.erase(first.begin() + 3);
	// ft_first.erase(ft_first.begin() + 3);
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();

	// std::cout << "--- Erase range ---";
	// first.erase(first.begin() + 3, first.end());
	// ft_first.erase(ft_first.begin() + 3, ft_first.end());
	// printCustomlists(first,ft_first);
	// if (!compareCustomlists(first, ft_first))
	// 	passed();
}

void ListTester::testSwap() {
	// std::cout << "--- non-member swap() ---";

	// std::list<int> first (3,100);   // three ints with a value of 100
	// ft::list<int> ft_first (3,100);   // three ints with a value of 100

	// std::list<int> second (5,200);   // five ints with a value of 200
	// ft::list<int> ft_second (5,200);   // five ints with a value of 200
	// printCustomlists(first, ft_first);
	// printCustomlists(second, ft_second);

	// first.swap(second);
	// ft_first.swap(ft_second);

	// printCustomlists(first, ft_first);
	// printCustomlists(second, ft_second);

	// if (!compareCustomlists(first, ft_first) && !compareCustomlists(second, ft_second))
	// 	passed();
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

int ListTester::compareCustomlists(std::list<int> &std_list, ft::list<int> &ft_list) {
	int fail = 0;

	for (std::list<int>::iterator it = std_list.begin(); it != std_list.end(); it++) {
		stdString << *it << ' ';
	}
	for (ft::list<int>::iterator ft_it = ft_list.begin(); ft_it != ft_list.end(); ft_it++) {
		ftString << *ft_it << ' ';
	}
	if (ftString.str().compare(stdString.str())) {
		std::cout << RED << "FAIL ❌\n" << "Ft list : " << ftString.str() \
		<< "\nStd list: " << stdString.str() << NC << "\n";
		fail = 1;
	}
	stdString.str(std::string());
	ftString.str(std::string());
	return fail;
}

void ListTester::printCustomlists(std::list<int> &std_list, ft::list<int> &ft_list) {
	std::cout << "\nFt list : ";
	for (ft::list<int>::iterator ft_it = ft_list.begin(); ft_it != ft_list.end(); ft_it++) {
		std::cout << *ft_it << ' ';
	}
	std::cout << "\nStd list: ";
	for (std::list<int>::iterator it = std_list.begin(); it != std_list.end(); it++) {
		std::cout << *it << ' ';
	}
	std::cout << "\n";
}