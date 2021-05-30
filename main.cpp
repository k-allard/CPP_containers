//clang++ main.cpp -g -fsanitize-address-poison-custom-array-cookie -fsanitize-address-use-after-scope -fsanitize-address-use-odr-indicator -fsanitize=address
#include "header.hpp"

int main()
{
	VectorTester *vectorTester = new VectorTester;
    vectorTester->testConstructors();
	vectorTester->testAssignations();
	vectorTester->testCapacity();
	vectorTester->testElementAccess();
	vectorTester->testIterators();
	vectorTester->testModifiers();
	vectorTester->testSwap();
	vectorTester->testRelationalOperators();



    return 0;
}
