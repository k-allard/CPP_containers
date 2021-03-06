#include "../header.hpp"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define NC "\033[0m"

class VectorTester {

public:
	VectorTester() {
		std::cout << " - - - - - - - - - - - - - - - - - - - - - - - -";
		std::cout << "\n" << " - - - - - - - - - V E C T O R - - - - - - - - - " << "\n";
		std::cout << " - - - - - - - - - - - - - - - - - - - - - - - -\n";
	}
	void testConstructors();
	void testAssignations();
	void testCapacity();
	void testElementAccess();
	void testIterators();
	void testModifiers() ;
	void testSwap();
	void testRelationalOperators();
	void testIteratorsComparability();

private:
	std::stringstream stdString;
	std::stringstream ftString;
	void passed();
	template <class T> int compareCustomVectors(std::vector<T> &std_vector, ft::vector<T> &ft_vector);
	template <class T> void printCustomVectors(std::vector<T> &std_vector, ft::vector<T> &ft_vector);
	template <class T> void printStdVector(std::vector<T> &std_vector);
	template <class T> void printFtVector(ft::vector<T> &ft_vector);
};

void VectorTester::testConstructors() {
	std::vector<int> first;
	std::vector<int> second (4,100);
	std::vector<int> third (second.begin(),second.end());
	std::vector<int> fourth (third);

	ft::vector<int> ft_first;
	ft::vector<int> ft_second (4,100);
	ft::vector<int> ft_third (ft_second.begin(),ft_second.end());
	ft::vector<int> ft_fourth (ft_third);
	std::cout << "Default constructor - ";
	if (!compareCustomVectors(first, ft_first))
		passed();
	std::cout << "Fill constructor -    ";
	if (!compareCustomVectors(second, ft_second))
		passed();
	std::cout << "Range constructor -   ";
	if (!compareCustomVectors(third, ft_third))
		passed();
	std::cout << "Copy constructor -    ";
	if (!compareCustomVectors(fourth, ft_fourth))
		passed();
}

void VectorTester::testAssignations() {
	std::vector<int> first(3,0);
	std::vector<int> second(5,0);
	std::vector<int> third;

	ft::vector<int> ft_first(3,0);
	ft::vector<int> ft_second(5,0);
	ft::vector<int> ft_third;

	first = second;
	ft_first = ft_second;

	std::cout << "operator= -           ";
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "Fill assignation -    ";
	first.assign(2, 99);
	ft_first.assign(2, 99);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "Range assignation -   ";
	int myints[] = {1776,7,4};
	third.assign (myints, myints + 3);
	ft_third.assign (myints, myints + 3);
	if (!compareCustomVectors(third, ft_third))
		passed();
}

void VectorTester::testCapacity() {
	int flag = 0;

	std::cout << "size() -              ";
	std::vector<int> first;
	ft::vector<int> ft_first;
	int myints[] = { 12, 10, 8, 6, 4, 2, 1 };
	first.assign (myints, myints + 7);
	ft_first.assign (myints, myints + 7);
	if (first.size() == ft_first.size())
		passed();
	else
		std::cout << RED << "FAIL ???\n" << "Ft vector size: " << ft_first.size() \
		<< "\nStd vector size: " << first.size() << NC << "\n";

	std::cout << "max_size() -          ";
	if (first.max_size() == ft_first.max_size())
		passed();
	else
		std::cout << RED << "FAIL ???\n" << "Ft vector size: " << ft_first.size() \
		<< "\nStd vector size: " << first.size() << NC << "\n";

	std::cout << "capacity() -          ";
	if (first.capacity() == ft_first.capacity())
		passed();
	else
		std::cout << RED << "FAIL ???\n" << "Ft vector capacity: " << ft_first.capacity() \
		<< "\nStd vector capacity: " << first.capacity() << NC << "\n";

	std::cout << "empty() -             ";
	std::vector<int> second;
	ft::vector<int> ft_second;
	if (first.empty() == ft_first.empty() && second.empty() == ft_second.empty())
		passed();
	else
		std::cout << RED << "FAIL ???\n" << NC;

	std::cout << "reserve() -           ";
	first.reserve(100);
	ft_first.reserve(100);
	if (first.capacity() == ft_first.capacity())
		passed();
	else
		std::cout << RED << "FAIL ???\n" << NC;

	std::cout << "resize() -            ";
	first.resize(3);
	ft_first.resize(3);
	flag = 0;
	if (compareCustomVectors(first, ft_first))
		flag = 1;
	first.resize(10);
	ft_first.resize(10);
	if (compareCustomVectors(first, ft_first))
		flag = 1;
	if (!flag)
		passed();
}

void VectorTester::testElementAccess() {
	std::cout << "operator[] -          ";
	std::vector<int> first (10);   // 10 zero-initialized elements
	ft::vector<int> ft_first (10);   // 10 zero-initialized elements
	std::vector<int>::size_type sz = first.size();
	ft::vector<int>::size_type ft_sz = ft_first.size();
	// assign values:
	for (unsigned i = 0; i < sz; i++) first[i]=i;
	for (unsigned i = 0; i < ft_sz; i++) ft_first[i]=i;

	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "at() -                ";
	// reverse std vector using function at:
	for (unsigned i = 0; i < sz / 2; i++) {
		int temp;
		temp = first.at(sz - 1 - i);
		first.at(sz - 1 - i) = first.at(i);
		first.at(i)=temp;
	}
	// reverse ft vector using operator[]:
	for (unsigned i = 0; i < ft_sz / 2; i++) {
		int temp;
		temp = ft_first.at(ft_sz - 1 - i);
		ft_first.at(ft_sz - 1 - i) = ft_first.at(i);
		ft_first.at(i)=temp;
	}
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "front() -             ";
	if (first.front() == ft_first.front())
			passed();
	else
		std::cout << RED << "FAIL ???\n" << NC;
	std::cout << "back() -              ";
	if (first.back() == ft_first.back())
			passed();
	else
		std::cout << RED << "FAIL ???\n" << NC;
}

void VectorTester::testIterators() {
	std::vector<int> first (5);  // 5 default-constructed ints
	ft::vector<int> ft_first (5);  // 5 default-constructed ints

	std::cout << "rbegin() and rend() - ";

	std::vector<int>::reverse_iterator rit = first.rbegin();
		ft::vector<int>::reverse_iterator ft_rit = ft_first.rbegin();

	int i = 0;
	for (; rit!= first.rend(); ++rit)
		*rit = ++i;

	int k=0;
	for (; ft_rit!= ft_first.rend(); ++ft_rit)
		*ft_rit = ++k;

	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "begin() and end() -   ";
	for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		*(it) += 1;

	for (ft::vector<int>::iterator ft_it = ft_first.begin(); ft_it != ft_first.end(); ++ft_it)
		*(ft_it) += 1;

	if (!compareCustomVectors(first, ft_first))
		passed();

}

void VectorTester::testModifiers() {
	std::vector<int> first (5);  // 5 default-constructed ints
	ft::vector<int> ft_first (5);  // 5 default-constructed ints

	std::cout << "--- Range assign ---";
	int myints[] = {1776,7,4};
	first.assign (myints,myints + 3);
	ft_first.assign(myints,myints + 3);
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "--- Fill assign ---";
	first.assign (2,99);
	ft_first.assign(2,99);
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "--- push_back() ---";
	first.push_back(7);
	first.push_back(14);
	ft_first.push_back(7);
	ft_first.push_back(14);
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "--- pop_back() ---";
	first.pop_back();
	ft_first.pop_back();
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "--- Insert single element ---";
	std::vector<int>::iterator it;
	ft::vector<int>::iterator ft_it;
	it = first.begin();
	ft_it = ft_first.begin();
	it = first.insert ( it + 1, 200 );
	ft_it = ft_first.insert ( ft_it + 1, 200 );
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "--- Insert fill ---";
	it = first.begin();
	ft_it = ft_first.begin();
	first.insert (it,2,300);
	ft_first.insert (ft_it,2,300);
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "--- Insert range ---";
	int myarray [] = { 501,502,503 };
	first.insert (first.end() - 1, myarray, myarray + 3);
	ft_first.insert (ft_first.end() - 1, myarray, myarray + 3);
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "--- Erase single element ---";
	first.erase(first.begin() + 3);
	ft_first.erase(ft_first.begin() + 3);
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();

	std::cout << "--- Erase range ---";
	first.erase(first.begin() + 3, first.end());
	ft_first.erase(ft_first.begin() + 3, ft_first.end());
	printCustomVectors(first,ft_first);
	if (!compareCustomVectors(first, ft_first))
		passed();
}

void VectorTester::testSwap() {
	std::cout << "--- swap() ---";
//	std::cout << "\n\nstd vectors before swap:";
	std::vector<int> first (3,100);   // three ints with a value of 100
	first.push_back(101);
	std::vector<int> second (5,200);   // five ints with a value of 200
	second.push_back(201);
//	printStdVector(first);
//	printStdVector(second);
	first.swap(second);
//	std::cout << "\n\nstd vectors after swap:";
//	printStdVector(first);
//	printStdVector(second);

	std::cout << "\n\nft vectors before swap:";
	ft::vector<int> ft_first (3,100);   // three ints with a value of 100
	ft_first.push_back(101);
	ft::vector<int> ft_second (5,200);   // five ints with a value of 200
	ft_second.push_back(201);

	printFtVector(ft_first);
	printFtVector(ft_second);
	ft_first.swap(ft_second);
	std::cout << "\n\nft vectors after swap:";
	printFtVector(ft_first);
	printFtVector(ft_second);

	if (!compareCustomVectors(first, ft_first) && !compareCustomVectors(second, ft_second))
		passed();

	std::cout << "\n--- non-member swap() ---\n";
	std::cout << "\n------ testing iterators persistence ------\n";
	ft::vector<int>::iterator ft_it = ft_first.begin();
	ft::vector<int>::iterator ft_ite = --ft_first.end();

	ft::vector<int>::iterator ft_it2 = ft_second.begin();
	ft::vector<int>::iterator ft_ite2 = --ft_second.end();

	std::cout << "ft_vector 1: iterator returned by begin() points to [" << *ft_it << "]\n";
	std::cout << "ft_vector 1: iterator returned by --end() points to [" << *ft_ite << "]\n";
	std::cout << "ft_vector 2: iterator returned by begin() points to [" << *ft_it2 << "]\n";
	std::cout << "ft_vector 2: iterator returned by --end() points to [" << *ft_ite2 << "]\n";
	std::cout << "\n-------------------------------------------\n";


	std::swap(first, second);
//	std::cout << "\n\nstd vectors after 2nd swap:";
//	printStdVector(first);
//	printStdVector(second);

	ft::swap(ft_first, ft_second);
	std::cout << "\nft vectors after 2nd swap:";
	printFtVector(ft_first);
	printFtVector(ft_second);
	if (!compareCustomVectors(first, ft_first) && !compareCustomVectors(second, ft_second))
		passed();

	std::cout << "\n\n------ testing iterators persistence ------\n";
	std::cout << "ft_vector 1: iterator returned by begin() points to [" << *ft_it << "]\n";
	std::cout << "ft_vector 1: iterator returned by --end() points to [" << *ft_ite << "]\n";
	std::cout << "ft_vector 2: iterator returned by begin() points to [" << *ft_it2 << "]\n";
	std::cout << "ft_vector 2: iterator returned by --end() points to [" << *ft_ite2 << "]\n";
	std::cout << "\n-------------------------------------------\n";

}

void VectorTester::testRelationalOperators() {
	std::cout << "--- relational operators ---\n";

	std::vector<int> first (3,100);   // three ints with a value of 100
	std::vector<int> second (2,200);   // two ints with a value of 200
	ft::vector<int> ft_first (3,100);   // three ints with a value of 100
	ft::vector<int> ft_second (2,200);   // two ints with a value of 200

	if ((first==second) == (ft_first==ft_second) && \
		(first!=second) == (ft_first!=ft_second) && \
		(first< second) == (ft_first< ft_second)  && \
		(first> second) == (ft_first> ft_second)  && \
		(first<=second) == (ft_first<=ft_second) && \
		(first>=second) == (ft_first>=ft_second))
			passed();
	else
		std::cout << RED << "FAIL ???\n" << NC;
}

void VectorTester::testIteratorsComparability() {
	std::cout << "--- testIteratorsComparability() ---\n";


//	const std::vector<int> const_first(4, 100);	//?????????????????????? ????????????
//	std::vector<int>::const_iterator const_it;			//?????????????????????? ????????????????
//
//	const_it = const_first.begin();						//begin() ???????????? ?????????????????????? ???????????????? ?????? ?????? ???????????? ?? ??????????_??????????????
//	passed();											//?????????? ??????????????????: const_it ?????????????? ???? ?????????????????????? - ?????? ???? ????????????????????????
//
//	std::vector<int> first(4, 100);				//non-const ????????????
//	std::vector<int>::iterator it;						//non-const ????????????????
//	std::vector<int>::const_iterator ite;				//const ????????????????
//
//	it = first.begin();
//	ite = first.end();
//
//	if (ite>it)											//testing comparability of const and non_const iterators
//		passed();

	std::cout << "* Testing that if the vector object is const-qualified, \n\t" <<
			  "the function returns a const_iterator. \n\tOtherwise, it returns an iterator *\n";
	const ft::vector<int> ft_const_first(4, 100);	//?????????????????????? ????????????
	ft::vector<int>::const_iterator ft_const_it;			//?????????????????????? ????????????????

	ft_const_it = ft_const_first.begin();						//begin() ???????????? ?????????????????????? ???????????????? ?????? ?????? ???????????? ?? ??????????_??????????????
	passed();											//?????????? ??????????????????: const_it ?????????????? ???? ?????????????????????? - ?????? ???? ????????????????????????

	std::cout << "* Testing comparability of const and non_const iterators *\n";
	ft::vector<int> ft_first(4, 100);				//non-const ????????????
	ft::vector<int>::iterator ft_it;						//non-const ????????????????
	ft::vector<int>::const_iterator ft_ite;				//const ????????????????

	ft_it = ft_first.begin();
	ft_ite = ft_first.end();

	if (ft_ite > ft_it)
		passed();

	if (ft_it < ft_ite)
		passed();
}

void VectorTester::passed() {
	const unsigned int microseconds = 250000; //1000000 microseconds = 1 sec
	std::cout << GREEN << "PASSED ???" << NC << "\n\n";
	usleep(microseconds);
}

template <class T>
int VectorTester::compareCustomVectors(std::vector<T> &std_vector, ft::vector<T> &ft_vector) {
	int fail = 0;
	for (typename std::vector<T>::size_type i = 0; i < std_vector.size(); i++) {
		stdString << std_vector.at(i) << " ";
	}
	for (typename ft::vector<T>::size_type i = 0; i < ft_vector.size(); i++) {
		ftString << ft_vector.at(i) << " ";
	}
	if (ftString.str().compare(stdString.str())) {
		std::cout << RED << "FAIL ???\n" << "Ft vector : " << ftString.str() \
		<< "\nStd vector: " << stdString.str() << NC << "\n";
		fail = 1;
	}
	stdString.str(std::string());
	ftString.str(std::string());
	return fail;
}

template <class T>
void VectorTester::printCustomVectors(std::vector<T> &std_vector, ft::vector<T> &ft_vector) {
	std::cout << "\nStd vector : ";
	for (typename std::vector<T>::size_type i = 0; i < std_vector.size(); i++) {
		std::cout << std_vector.at(i) << " ";
	}
	std::cout << "\nFt vector: ";
	for (typename ft::vector<T>::size_type i = 0; i < ft_vector.size(); i++) {
		std::cout << ft_vector.at(i) << " ";
	}
	std::cout << "\n";
}

template <class T>
void VectorTester::printStdVector(std::vector<T> &std_vector) {
	std::cout << "\nStd vector: ";
	for (typename std::vector<T>::size_type i = 0; i < std_vector.size(); i++) {
		std::cout << std_vector.at(i) << " ";
	}
}

template <class T>
void VectorTester::printFtVector(ft::vector<T> &ft_vector) {
	std::cout << "\nFt vector: ";
	for (typename ft::vector<T>::size_type i = 0; i < ft_vector.size(); i++) {
		std::cout << ft_vector.at(i) << " ";
	}
}
