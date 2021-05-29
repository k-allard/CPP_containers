//clang++ main.cpp -g -fsanitize-address-poison-custom-array-cookie -fsanitize-address-use-after-scope -fsanitize-address-use-odr-indicator -fsanitize=address
#include "header.hpp"

int main()
{
	VectorTester *vectorTester = new VectorTester;
    vectorTester->testConstructors();
	vectorTester->testAssignations();
	vectorTester->testCapacity();
	vectorTester->testElementAccess();

    // for (int i = 1; i <= 5; i++) {
    //     vectorTester->stdVector.push_back(i);
    // }
    // for (int i = 1; i <= 5; i++) {
    //     vectorTester->ftVector.push_back(i);
    // }
    // vectorTester->printVectors();
    // vectorTester->compareVectors();
    // vectorTester->printVectors();

    
    // for (int i = 1; i <= 5; i++) {
    //     vectorTester->stdVector.push_back(i);
    // }
    // for (int i = 5; i >= 1; i--) {
    //     vectorTester->ftVector.push_back(i);
    // }
    // vectorTester->printVectors();


    // std::cout << "\nFT vector 2: ";
    // for (int i = 0; i < vectorTester->ftVector2.size(); i++) {
    //     std::cout << vectorTester->ftVector2.at(i) << " ";
    // }
    // std::cout << std::endl;

    // vectorTester->ftVector2.swap(vectorTester->ftVector);

    // std::cout << "\nFT vector 2: ";
    // for (int i = 0; i < vectorTester->ftVector2.size(); i++) {
    //     std::cout << vectorTester->ftVector2.at(i) << " ";
    // }
    // std::cout << std::endl;

    return 0;
}
