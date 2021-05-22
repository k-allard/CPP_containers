#include "header.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define NC "\033[0m"

class VectorTester {
    public:
    	std::vector<int> stdVector;
    	ft::vector<int> ftVector;

		void compareVectors()
        {
			for (int i = 0; i < stdVector.size(); i++) {
        		stdString << stdVector.at(i) << " ";
    		}
			for (int i = 0; i < stdVector.size(); i++) {
        		ftString << ftVector.at(i) << " ";
    		}
			if (ftString.str().compare(stdString.str()) == 0)
				std::cout << GREEN << "PASSED\n" << NC;
			else
				std::cout << RED << "FAIL\n" << "Ft result : " << ftString.str() << "\nStd result: " << stdString.str() << NC << "\n";
			stdString.str(std::string());
			ftString.str(std::string());
        }

    private:
        std::stringstream stdString;
    	std::stringstream ftString;
};