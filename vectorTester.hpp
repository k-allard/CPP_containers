#include "header.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define NC "\033[0m"

class VectorTester {

public:
	std::vector<int> stdVector;
	std::vector<int> stdVector2;
	ft::vector<int> ftVector;
	ft::vector<int> ftVector2;

	VectorTester() {
		std::cout << "\n" << " - - - - - - - - V E C T O R - - - - - - - - " << "\n";
	}

	void testConstructors() {
		std::vector<int> first;
		std::vector<int> second (4,100);
		std::vector<int> third (second.begin(),second.end());
		std::vector<int> fourth (third);

		ft::vector<int> ft_first;
		ft::vector<int> ft_second (4,100);
		ft::vector<int> ft_third (ft_second.begin(),ft_second.end());
		ft::vector<int> ft_fourth (ft_second);

		std::cout << "Default constructor - ";
		if (!compareCustomVectors(first, ft_first))
			passed();
		std::cout << "Fill constructor - ";
		if (!compareCustomVectors(second, ft_second))
			passed();
		std::cout << "Range constructor - ";
		if (!compareCustomVectors(third, ft_third))
			passed();
		std::cout << "Copy constructor - ";
		if (!compareCustomVectors(fourth, ft_fourth))
			passed();
	}

	void testAssignations() {
		std::vector<int> first(3,0);
		std::vector<int> second(5,0);
		std::vector<int> third;


		ft::vector<int> ft_first(3,0);
		ft::vector<int> ft_second(5,0);
		ft::vector<int> ft_third;

		first = second;
		ft_first = ft_second;

		std::cout << "operator= - ";
		if (!compareCustomVectors(first, ft_first))
			passed();

		std::cout << "Fill assignation - ";
		first.assign(2, 99);
		ft_first.assign(2, 99);
		if (!compareCustomVectors(first, ft_first))
			passed();
		
		std::cout << "Range assignation - ";
		int myints[] = {1776,7,4};
  		third.assign (myints, myints + 3);
		ft_third.assign (myints, myints + 3);
		if (!compareCustomVectors(third, ft_third))
			passed();
	}

	void testCapacity() {
		int flag = 0;

		std::cout << "size() - ";
		std::vector<int> first;
		ft::vector<int> ft_first;
		int myints[] = { 12, 10, 8, 6, 4, 2, 1 };
  		first.assign (myints, myints + 7);
		ft_first.assign (myints, myints + 7);
		if (first.size() == ft_first.size())
			passed();
		else
			std::cout << RED << "FAIL\n" << "Ft vector size: " << ft_first.size() << "\nStd vector size: " << first.size() << NC << "\n";

		std::cout << "max_size() - ";
		if (first.max_size() == ft_first.max_size())
			passed();
		else
			std::cout << RED << "FAIL\n" << "Ft vector size: " << ft_first.size() << "\nStd vector size: " << first.size() << NC << "\n";

		std::cout << "capacity() - ";
		if (first.capacity() == ft_first.capacity())
			passed();
		else
			std::cout << RED << "FAIL\n" << "Ft vector capacity: " << ft_first.capacity() << "\nStd vector capacity: " << first.capacity() << NC << "\n";
		
		std::cout << "empty() - ";
		std::vector<int> second;
		ft::vector<int> ft_second;
		if (first.empty() == ft_first.empty() && second.empty() == ft_second.empty())
			passed();
		else
			std::cout << RED << "FAIL\n" << NC;

		std::cout << "reserve() - ";
		first.reserve(100);
		ft_first.reserve(100);
		if (first.capacity() == ft_first.capacity())
			passed();
		else
			std::cout << RED << "FAIL\n" << NC;
		
		std::cout << "resize() - ";
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

	void passed() {
		std::cout << GREEN << "PASSED" << NC << "\n";
	}

	// void compareVectors() {
	// 	for (int i = 0; i < stdVector.size(); i++) {
	// 		stdString << stdVector.at(i) << " ";
	// 	}
	// 	for (int i = 0; i < ftVector.size(); i++) {
	// 		ftString << ftVector.at(i) << " ";
	// 	}
	// 	if (ftString.str().compare(stdString.str()) == 0)
	// 		std::cout << "\n" << GREEN << "PASSED" << NC << "\n";
	// 	else
	// 		std::cout << RED << "FAIL\n" << "Ft vector : " << ftString.str() << "\nStd vector: " << stdString.str() << NC << "\n";
	// 	stdString.str(std::string());
	// 	stdVector.clear();
	// 	ftString.str(std::string());
	// 	ftVector.clear();
	// }

	int compareCustomVectors(std::vector<int> &std_vetor, ft::vector<int> &ft_vector) {
		int fail = 0;
		for (int i = 0; i < std_vetor.size(); i++) {
			stdString << std_vetor.at(i) << " ";
		}
		for (int i = 0; i < ft_vector.size(); i++) {
			ftString << ft_vector.at(i) << " ";
		}
		if (ftString.str().compare(stdString.str())) {
			std::cout << RED << "FAIL\n" << "Ft vector : " << ftString.str() << "\nStd vector: " << stdString.str() << NC << "\n";
			fail = 1;
		}
		stdString.str(std::string());
		ftString.str(std::string());
		return fail;
	}

	void printCustomVectors(std::vector<int> &std_vetor, ft::vector<int> &ft_vector) {
		std::cout << "\nFt vector : ";
		for (int i = 0; i < std_vetor.size(); i++) {
			std::cout << std_vetor.at(i) << " ";
		}
		std::cout << "\nStd vector: ";
		for (int i = 0; i < ft_vector.size(); i++) {
			std::cout << ft_vector.at(i) << " ";
		}
		std::cout << "\n";
	}

	void printVectors()
	{
		std::cout << "STD vector: ";
		for (int i = 0; i < stdVector.size(); i++) {
			std::cout << stdVector.at(i) << " ";
		}
		std::cout << "\nFT vector : ";
		for (int i = 0; i < ftVector.size(); i++) {
			std::cout << ftVector.at(i) << " ";
		}
		std::cout << std::endl;
	}

	void printVectors2()
	{
		std::cout << "STD vector 1: ";
		for (int i = 0; i < stdVector.size(); i++) {
			std::cout << stdVector.at(i) << " ";
		}

		std::cout << "STD vector 1: ";
		for (int i = 0; i < stdVector2.size(); i++) {
			std::cout << stdVector2.at(i)<< " ";
		}

		std::cout << "\nFT vector 1: ";
		for (int i = 0; i < ftVector.size(); i++) {
			std::cout << ftVector.at(i) << " ";
		}
		std::cout << "\nFT vector 2: ";
		for (int i = 0; i < ftVector2.size(); i++) {
			std::cout << ftVector2.at(i) << " ";
		}
		std::cout << std::endl;
	}

private:
	std::stringstream stdString;
	std::stringstream ftString;
};