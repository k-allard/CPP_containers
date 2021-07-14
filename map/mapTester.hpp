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
	void testCapacityAndElementAccess();
	void testModifiers() ;
	void testObservers();
	void testOperations();
	void testRelationalOperators();
	void testSwap();

 private:
 	std::stringstream stdString;
 	std::stringstream ftString;
 	static void passed();
 	template <class Key, class T> int compareStdFtmaps(std::map<Key,T> &std_map, ft::map<Key,T> &ft_map);
 	template <class Key, class T> void printStdFtmaps(std::map<Key, T> &std_map, ft::map<Key, T> &ft_map);
	template <class Key, class T> void printStdmap(std::map<Key,T> &std_map);
	template <class Key, class T> void printFtmap(ft::map<Key, T> &ft_map);
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
	std::cout << "--- constructors ---\n";

	std::map<int, std::string> first;
	std::map<int, std::string> second;
	second[1]="test";
	second[2]="test2";
	std::map<int, std::string> third (second.begin(),second.end());
	std::map<int, std::string> fourth (second);


	ft::map<int, std::string> ft_first;
//	ft_first.printTree();
	ft::map<int, std::string> ft_second;
	ft_second[1]="test";
	ft_second[2]="test2";
	ft::map<int, std::string> ft_third (ft_second.begin(),ft_second.end());
	ft::map<int, std::string> ft_fourth (ft_second);

	 std::cout << "Default constructor - ";
	 if (!compareStdFtmaps(first, ft_first))
	 	passed();
	printStdFtmaps(second, ft_second);
	std::cout << "Fill constructor -    ";
	if (!compareStdFtmaps(second, ft_second))
	 	passed();
	printStdFtmaps(third, ft_third);
	std::cout << "Range constructor -   ";
	if (!compareStdFtmaps(third, ft_third))
	  	passed();
	printStdFtmaps(fourth, ft_fourth);
	std::cout << "Copy constructor -    ";
	if (!compareStdFtmaps(fourth, ft_fourth))
	 	passed();
}

void MapTester::testAssignations() {
// 				std::cout << "--- assignation ---\n";
// -------------------------------------------------------------------------
//	operator= - Copy container content (public member function )
// -------------------------------------------------------------------------

	std::map<std::string, int> first;
	first["test1"] = 1;
	first["test2"] = 2;
	std::map<std::string, int> second;
	second["test3"] = 3;
	second["test4"] = 4;

	ft::map<std::string, int> ft_first;
	ft_first["test1"] = 1;
	ft_first["test2"] = 2;
	ft::map<std::string, int> ft_second;
	ft_second["test3"] = 3;
	ft_second["test4"] = 4;

	printStdmap(first);
	printFtmap(ft_first);
	std::cout << "	* assigning . . . *	\n";
	first = second;
	ft_first = ft_second;
	printStdmap(first);
	printFtmap(ft_first);

	std::cout << "operator= -           ";
	if (!compareStdFtmaps(first, ft_first) && !compareStdFtmaps(second, ft_second))
		passed();
}

void MapTester::testIterators() {
 				std::cout << "--- iterators ---\n";
// -------------------------------------------------------------------------
//				public member functions:
//	begin - Return iterator to beginning
//	end - Return iterator to end
//	rbegin - Return reverse iterator to reverse beginning
//	rend - Return reverse iterator to reverse end
// -------------------------------------------------------------------------

	std::map<char, int> first;
	first['x'] = 100;
	first['y'] = 200;
	first['z'] = 300;
	ft::map<char, int> ft_first;
	ft_first['x'] = 100;
	ft_first['y'] = 200;
	ft_first['z'] = 300;

	printStdFtmaps(first, ft_first);

	std::map<char, int>::iterator it = --(first.end());
	ft::map<char, int>::iterator ft_it = --(ft_first.end());
	std::cout << "\nStd map: last element is [" << (*it).first << ":" << (*it).second << "]" << std::endl;
	std::cout << "Ft map : last element is [" << (*ft_it).first << ":" << (*ft_it).second << "]" << std::endl;

	it = first.begin();
	ft_it = ft_first.begin();
	std::cout << "\nStd map: first element is [" << (*it).first << ":" << (*it).second << "]" << std::endl;
	std::cout << "Ft map : first element is [" << (*ft_it).first << ":" << (*ft_it).second << "]" << std::endl;
	std::cout << "begin() and end() -   ";
	if (!compareStdFtmaps(first, ft_first))
	 	passed();

	std::map<char,int>::reverse_iterator rit;
	ft::map<char,int>::reverse_iterator ft_rit;

	int i = 0;
	for (rit = first.rbegin(); rit != first.rend(); ++rit)
		rit->second += ++i;
	printStdmap(first);

	i = 0;
	for (ft_rit = ft_first.rbegin(); ft_rit != ft_first.rend(); ++ft_rit)
		ft_rit->second += ++i;
	printFtmap(ft_first);
	std::cout << "rbegin() and rend() - ";
	if (!compareStdFtmaps(first, ft_first))
		passed();


}

void MapTester::testCapacityAndElementAccess() {
				std::cout << "--- element access ---\n";
// -------------------------------------------------------------------------
//	 operator[] - Access element (public member function )
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
//				std::cout << "--- capacity ---\n";
//	empty - Test whether container is empty (public member function )
//	size - Return container size (public member function )
//	max_size - Return maximum size (public member function )
// -------------------------------------------------------------------------

	std::map<char, std::string> first;
	ft::map<char, std::string> ft_first;
	bool empty = first.empty();
	bool ft_empty = ft_first.empty();

	first['x'] = "xoor";
	first['y'] = "yooh";
	first['x'] = "zoom";

	std::cout << "	* inserting element with a new key *	\n";
	ft_first['x'] = "xoor";
	ft_first['y'] = "yooh";
	std::cout << "	* changing element with existing key *	\n";
	ft_first['x'] = "zoom";

	printStdFtmaps(first, ft_first);
	std::cout << "operator[] -          ";
	if (!compareStdFtmaps(first, ft_first))
		passed();


	std::cout << "--- capacity ---\n";
	std::cout << "empty() -             ";
	bool empty2 = first.empty();
	bool ft_empty2 = ft_first.empty();

	if (empty == ft_empty && empty2 == ft_empty2)
	 	passed();
	 else
	 	std::cout << RED << "FAIL ❌\n" << NC;

	std::cout << "size() -              ";
	if (first.size() == ft_first.size())
		passed();
	else
		std::cout << RED << "FAIL ❌\n" << NC << "\n";

	std::cout << "max_size() -          ";
	if (first.max_size() == ft_first.max_size())
		passed();
	else
		std::cout << RED << "FAIL ❌\n" << NC << "\n";
 }

void MapTester::testModifiers() {
 				std::cout << "--- modifiers ---\n";
// -------------------------------------------------------------------------
//	insert - Insert elements (public member function )
//	erase - Erase elements (public member function )
//	swap - Swap content (public member function )
//	clear - Clear content (public member function )
// -------------------------------------------------------------------------
	 std::map<char, int> first;
	 ft::map<char, int> ft_first;

	std::cout << "--- Insert single element ---";
	first.insert ( std::pair<char,int>('a',100) );
	first.insert ( std::pair<char,int>('z',200) );
	std::cout << "\n	* inserting element with a new key *	\n";
	ft_first.insert ( ft::pair<char,int>('a',100) );
	ft_first.insert ( ft::pair<char,int>('z',200) );

	printStdFtmaps(first, ft_first);
	std::cout << "insert() -            ";
	if (!compareStdFtmaps(first, ft_first)) {
		passed();
	}

	std::pair<std::map<char,int>::iterator,bool> ret;
	ft::pair<ft::map<char,int>::iterator,bool> ft_ret;

	std::cout << "	* inserting element with existing key *	\n";
	ret = first.insert ( std::pair<char,int>('z',500) );
	if (ret.second == false) {
		std::cout << "Std map: element 'z' already exists with value " << ret.first->second << '\n';
	}
	ft_ret = ft_first.insert ( ft::pair<char,int>('z',500) );
	if (ft_ret.second == false) {
		std::cout << "Ft map : element 'z' already exists with value " << ft_ret.first->second << '\n';
	}
	std::cout << "insert() -            ";
	if (!compareStdFtmaps(first, ft_first)) {
		passed();
	}

	// The function optimizes its insertion time if position points to the element that will precede the inserted element.
	std::cout << "--- Insert with hint ---\n";
	std::map<char,int>::iterator it = first.begin();
	first.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	first.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

	ft::map<char,int>::iterator ft_it = ft_first.begin();
	ft_first.insert (ft_it, ft::pair<char,int>('b',300));  // max efficiency inserting
	ft_first.insert (ft_it, ft::pair<char,int>('c',400));  // no max efficiency inserting

	printStdFtmaps(first, ft_first);
	std::cout << "insert() -            ";
	if (!compareStdFtmaps(first, ft_first))
		passed();

	std::cout << "--- Insert range ---\n";
	std::map<char,int> second;
	second.insert(first.begin(),first.find('c'));
	ft::map<char,int> ft_second;
	ft_second.insert(ft_first.begin(),ft_first.find('c'));

	printStdFtmaps(second, ft_second);
	std::cout << "insert() -            ";
	if (!compareStdFtmaps(second, ft_second))
		passed();

	  std::cout << "--- Erase by iterator ---\n";
	second.erase(second.find('b'));
	ft_second.erase(ft_second.find('b'));
	printStdFtmaps(second, ft_second);
	std::cout << "erase() -             ";
	if (!compareStdFtmaps(second, ft_second))
		passed();

	std::cout << "--- Erase by key ---\n";
	second.erase('a');
	ft_second.erase('a');
	printStdFtmaps(second, ft_second);
	std::cout << "erase() -             ";
	if (!compareStdFtmaps(second, ft_second))
		passed();

	printStdFtmaps(first, ft_first);
	std::cout << "\n--- Erase by range ---\n";
	it = first.find ('c');
	ft_it = ft_first.find ('c');
	first.erase ( it, first.end() );
	ft_first.erase ( ft_it, ft_first.end() );
	printStdFtmaps(first, ft_first);
	std::cout << "erase() -             ";
	if (!compareStdFtmaps(first, ft_first))
		passed();

	std::cout << "--- Swap ---\n";
	second.insert ( std::pair<char,int>('m',50) );
	second.insert ( std::pair<char,int>('l',20) );
	second.insert ( std::pair<char,int>('k', 90) );

	ft_second.insert ( ft::pair<char,int>('m',50) );
	ft_second.insert ( ft::pair<char,int>('l', 20) );
	ft_second.insert ( ft::pair<char,int>('k', 90) );

	std::cout << "	Before swap:\n";
	printStdmap(first);
	printStdmap(second);
	std::cout << "\n";
	printFtmap(ft_first);
	printFtmap(ft_second);
	std::cout << "	* swapping . . .*\n";

	first.swap(second);
	ft_first.swap(ft_second);

	std::cout << "	After swap:\n";
	printStdmap(first);
	printStdmap(second);
	std::cout << "\n";
	printFtmap(ft_first);
	printFtmap(ft_second);

	std::cout << "swap() -              ";
	if (!compareStdFtmaps(first, ft_first) && !compareStdFtmaps(second, ft_second))
		passed();

	std::cout << "--- Clear ---\n";
	first.clear();
	ft_first.clear();
	printStdFtmaps(first, ft_first);
	std::cout << "clear() -             ";
	if (!compareStdFtmaps(first, ft_first))
		passed();
}

void MapTester::testObservers() {
 				std::cout << "--- observers ---\n";
// -------------------------------------------------------------------------
//	key_comp - Return key comparison object (public member function )
//	value_comp - Return value comparison object (public member function )
// -------------------------------------------------------------------------
	std::map<char, int> first;
	ft::map<char, int> ft_first;

	std::cout << "--- key_comp() ---\n";

	std::map<char,int>::key_compare mycomp = first.key_comp();
	first['c']=100;
	first['b']=200;
	first['a']=300;

	ft::map<char,int>::key_compare ft_mycomp = ft_first.key_comp();
	ft_first['c']=100;
	ft_first['b']=200;
	ft_first['a']=300;

	std::cout << "	* printing maps using key_comp() *	\n";
	char highest_key = first.rbegin()->first;     		// key value of last element
	char ft_highest_key = ft_first.rbegin()->first;     // key value of last element

	std::map<char,int>::iterator it = first.begin();
	std::cout << "Std map: ";
	do {
		std::cout << "[" << it->first << ":" << it->second << "] ";
	} while ( mycomp((*it++).first, highest_key) );
	std::cout << '\n';

	ft::map<char,int>::iterator ft_it = ft_first.begin();
	std::cout << "Ft map:  ";
	do {
		std::cout << "[" << ft_it->first << ":" << ft_it->second << "] ";
	} while ( ft_mycomp((*ft_it++).first, ft_highest_key) );
	std::cout << '\n';

	std::cout << "--- value_comp() ---\n";
	std::cout << "	* printing maps using value_comp() *	\n";
	std::pair<char,int> highest_elem = *first.rbegin();          	// last element
	ft::pair<char,int> ft_highest_elem = *ft_first.rbegin();          // last element

	it = first.begin();
	std::cout << "Std map: ";
	do {
		std::cout << "[" << it->first << ":" << it->second << "] ";
	} while ( first.value_comp()(*it++, highest_elem) );
	std::cout << '\n';

	ft_it = ft_first.begin();
	std::cout << "Ft map:  ";
	do {
		std::cout << "[" << ft_it->first << ":" << ft_it->second << "] ";
	} while ( ft_first.value_comp()(*ft_it++, ft_highest_elem) );
	std::cout << '\n';

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

void MapTester::testOperations() {
// 				std::cout << "--- operations ---\n";
// -------------------------------------------------------------------------
//	find - Get iterator to element (public member function )
//	count - Count elements with a specific key (public member function )
//	lower_bound - Return iterator to lower bound (public member function )
//	upper_bound - Return iterator to upper bound (public member function )
//	equal_range - Get range of equal elements (public member function )
// -------------------------------------------------------------------------


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
//	 std::cout <<"\n first std_map element is: "<< (*std_map.begin()).first << ":" << (*std_map.begin()).second << std::endl;
//	 std::cout <<"\n first ft_map element is: "<< (*ft_map.begin()).first << ":" << (*ft_map.begin()).second << std::endl;

//	 std::cout <<" last std_map element is: "<< (*std_map.end()).first << ":" << (*std_map.end()).second << std::endl;
//	 std::cout <<" last ft_map element is: "<< (*ft_map.end()).first << ":" << (*ft_map.end()).second << std::endl;

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

template <class Key, class T>
 void MapTester::printStdFtmaps(std::map<Key,T> &std_map, ft::map<Key,T> &ft_map) {
	printFtmap(ft_map);
	printStdmap(std_map);
 }

template <class Key, class T>
 void MapTester::printStdmap(std::map<Key,T> &std_map) {
	std::cout << "Std map: ";
	for (typename std::map<Key, T>::iterator it = std_map.begin(); it != std_map.end(); it++) {
		std::cout << '[';
		std::cout << (*it).first << ':';
		std::cout << (*it).second << "] ";
	}
	std::cout << "\n";
 }

template <class Key, class T>
 void MapTester::printFtmap(ft::map<Key, T> &ft_map) {
	std::cout << "Ft map : ";
	for (typename ft::map<Key, T>::iterator ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++) {
		std::cout << '[';
		std::cout << (*ft_it).first << ':';
		std::cout << (*ft_it).second << "] ";
	}
	std::cout << "\n";
}

#pragma clang diagnostic pop
