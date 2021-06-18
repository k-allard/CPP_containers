//clang++ main.cpp -g -fsanitize-address-poison-custom-array-cookie -fsanitize-address-use-after-scope -fsanitize-address-use-odr-indicator -fsanitize=address
#include "header.hpp"

int main()
{
	// VectorTester *vectorTester = new VectorTester;
    // vectorTester->testConstructors();
	// vectorTester->testAssignations();
	// vectorTester->testCapacity();
	// vectorTester->testElementAccess();
	// vectorTester->testIterators();
	// vectorTester->testModifiers();
	// vectorTester->testSwap();
	// vectorTester->testRelationalOperators();

	// ListTester *listTester = new ListTester;
	// listTester->testConstructors();
	// listTester->testAssignations();
	// listTester->testCapacity();
	// listTester->testElementAccess();
	// listTester->testIterators();
	// listTester->testModifiers();
	// listTester->testOperations();
	// listTester->testSwap();
	// listTester->testRelationalOperators();

	MapTester *mapTester = new MapTester;
	mapTester->testConstructors();
	// mapTester->testAssignations();
	// mapTester->testIterators();
	// mapTester->testCapacity();
	// mapTester->testElementAccess();
	// mapTester->testModifiers() ;
	// mapTester->testObservers();
	// mapTester->testSwap();
	// mapTester->testRelationalOperators();
    return 0;
}

