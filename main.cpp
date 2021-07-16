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
	 vectorTester->testIteratorsComparability();
	 delete vectorTester;

//	 ListTester *listTester = new ListTester;
//	 listTester->testConstructors();
//	 listTester->testAssignations();
//	 listTester->testCapacity();
//	 listTester->testElementAccess();
//	 listTester->testIterators();
//	 listTester->testModifiers();
//	 listTester->testOperations();
//	 listTester->testSwap();
//	 listTester->testRelationalOperators();
//	 delete listTester;

	MapTester *mapTester = new MapTester;
	mapTester->testRBTree();
	mapTester->testConstructors();
	 mapTester->testAssignations();
	 mapTester->testIterators();
	 mapTester->testCapacityAndElementAccess();
	 mapTester->testModifiers() ;
	 mapTester->testObservers();
	 mapTester->testSwap();
	 mapTester->testOperations();
	 mapTester->testRelationalOperators();
	delete mapTester;

	StackTester *stackTester = new StackTester;
	stackTester->testConstructors();
	stackTester->testCapacity();
	stackTester->testElementAccess();
	stackTester->testModifiers();
	stackTester->testRelationalOperators();
	delete stackTester;

    return 0;
}
