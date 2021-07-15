#include "../header.hpp"
#include <stack>
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define NC "\033[0m"

class StackTester {

public:
	StackTester() {
		std::cout << " - - - - - - - - - - - - - - - - - - - - - - - -";
		std::cout << "\n" << " - - - - - - - - - S T A C K - - - - - - - - - - " << "\n";
		std::cout << " - - - - - - - - - - - - - - - - - - - - - - - -\n";
	}

	void testConstructors();

	void testCapacity();

	void testElementAccess();

	void testModifiers();

	void testRelationalOperators();

private:
	std::stringstream stdString;
	std::stringstream ftString;

	void passed();
	template<class T>
	void printStdFtStacks(std::stack <T, std::vector<T> > &std_stack, ft::stack<T, ft::vector<T> > &ft_stack);
};

void StackTester::testConstructors() {
	std::cout << "--- Constructor --- ";

	std::vector<int> std_vector (2,200);        // vector with 2 elements
	ft::vector<int> ft_vector (2,200);        // vector with 2 elements

	std::stack<int,std::vector<int> > std_stack;  // empty stack using vector
	ft::stack<int,ft::vector<int> > ft_stack;  // empty stack using vector

	std::stack<int,std::vector<int> > std_stack2 (std_vector);
	ft::stack<int,ft::vector<int> > ft_stack2 (ft_vector);

	printStdFtStacks(std_stack2, ft_stack2);
}

void StackTester::testCapacity() {
	std::vector<int> first;
	ft::vector<int> ft_first;
	int myints[] = { 1, 12, 10, 8, 6, 4, 2 };
	first.assign (myints, myints + 7);
	ft_first.assign (myints, myints + 7);
	std::stack<int,std::vector<int> > std_stack (first);
	ft::stack<int,ft::vector<int> > ft_stack (ft_first);
	int std_stack_size = std_stack.size();
	int ft_stack_size = ft_stack.size();
	printStdFtStacks(std_stack, ft_stack);
	std::cout << "Ft stack size: " << ft_stack_size \
		<< "\nStd stack size: " << std_stack_size << "\n";
	std::cout << "size() -              ";
	if (std_stack_size == ft_stack_size) {
		passed();
	}
	else
		std::cout << RED << "FAIL ❌\n" << "Ft stack size: " << ft_stack_size \
		<< "\nStd stack size: " << std_stack_size << NC << "\n";

	std::cout << "* After popping elements out for print *\n Is ft_stack empty? - " << ft_stack.empty() \
		<< "\n Is ft_stack empty? - " << std_stack.empty() << "\n";
	std::cout << "empty() -             ";
	if (std_stack.empty() == ft_stack.empty())
		passed();
	else
		std::cout << RED << "FAIL ❌\n";
}

void StackTester::testElementAccess() {
	std::vector<std::string> first;
	ft::vector<std::string> ft_first;
	std::string myints[] = { "ololo", "alala", "zoooo" };
	first.assign (myints, myints + 3);
	ft_first.assign (myints, myints + 3);
	std::stack<std::string,std::vector<std::string> > std_stack (first);
	ft::stack<std::string,ft::vector<std::string> > ft_stack (ft_first);

	std::cout << "top() -               ";

	if (std_stack.top() == ft_stack.top())
			passed();
	else
		std::cout << RED << "FAIL ❌\n" << NC;
	printStdFtStacks(std_stack, ft_stack);

}

void StackTester::testModifiers() {

	std::cout << "\n--- push() and pop() ---";
	std::stack<int> mystack;
	ft::stack<int> ft_mystack;
	std::cout << "\n* Pushing in elements to fill stacks . . . *";
	for (int i=0; i<5; ++i) {
		mystack.push(i);
		ft_mystack.push(i);
	}
	std::cout << "\n* Popping out elements to print . . . *\nFt stack : ";
	while (!ft_mystack.empty()) {
		std::cout << ' ' << ft_mystack.top();
		ft_mystack.pop();
	}
	std::cout << "\nStd stack :";
	while (!mystack.empty()) {
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

}

void StackTester::testRelationalOperators() {
	std::cout << "\n--- relational operators ---\n";

	std::stack<char> first;
	std::stack<char> second;
	ft::stack<char> ft_first;
	ft::stack<char> ft_second;

	first.push('z');
	first.push('s');
	first.push('w');
	first.push('q');

	second.push('c');
	second.push('a');
	second.push('b');

	ft_first.push('z');
	ft_first.push('s');
	ft_first.push('w');
	ft_first.push('q');

	ft_second.push('c');
	ft_second.push('a');
	ft_second.push('b');

	if ((first==second) == (ft_first==ft_second) && \
		(first!=second) == (ft_first!=ft_second) && \
		(first< second) == (ft_first< ft_second)  && \
		(first> second) == (ft_first> ft_second)  && \
		(first<=second) == (ft_first<=ft_second) && \
		(first>=second) == (ft_first>=ft_second))
			passed();
	else
		std::cout << RED << "FAIL ❌\n" << NC;
}

void StackTester::passed() {
	const unsigned int microseconds = 250000; //1000000 microseconds = 1 sec
	std::cout << GREEN << "PASSED ✅" << NC << "\n\n";
	usleep(microseconds);
}

template <class T>
void StackTester::printStdFtStacks(std::stack<T, std::vector<T> > &std_stack, ft::stack<T, ft::vector<T> > &ft_stack) {
	std::cout << "\nFt stack : ";
	while (!ft_stack.empty()) {
		std::cout << '[' << ft_stack.top()<< "] ";
		ft_stack.pop();
	}
	std::cout << "\nStd stack: ";
	while (!std_stack.empty()) {
		std::cout << '[' << std_stack.top()<< "] ";
		std_stack.pop();
	}
	std::cout << "\n";
}
