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

	void testConstructors() {
		std::vector<int> first;
		std::vector<int> second (4,100);
		std::vector<int> third (second.begin(),second.end());
		std::vector<int> fourth (third);

		ft::vector<int> ft_first;
		ft::vector<int> ft_second (4,100);
		ft::vector<int> ft_third (ft_second.begin(),ft_second.end());
		ft::vector<int> ft_fourth (ft_second);

		std::cout << "\n" << "Default constructor - ";
		if (!compareCustomVectors(first, ft_first))
			passed();
		std::cout << "\n" << "Fill constructor - ";
		if (!compareCustomVectors(second, ft_second))
			passed();
		std::cout << "\n" << "Range constructor - ";
		if (!compareCustomVectors(third, ft_third))
			passed();
		std::cout << "\n" << "Copy constructor - ";
		if (!compareCustomVectors(fourth, ft_fourth))
			passed();

		//d e s t r u c t o r//
		
	}

	void passed() {
		std::cout << GREEN << "PASSED" << NC << "\n";
	}

	void compareVectors() {
		for (int i = 0; i < stdVector.size(); i++) {
			stdString << stdVector.at(i) << " ";
		}
		for (int i = 0; i < ftVector.size(); i++) {
			ftString << ftVector.at(i) << " ";
		}
		if (ftString.str().compare(stdString.str()) == 0)
			std::cout << "\n" << GREEN << "PASSED" << NC << "\n";
		else
			std::cout << RED << "FAIL\n" << "Ft vector : " << ftString.str() << "\nStd vector: " << stdString.str() << NC << "\n";
		stdString.str(std::string());
		stdVector.clear();
		ftString.str(std::string());
		ftVector.clear();
	}

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