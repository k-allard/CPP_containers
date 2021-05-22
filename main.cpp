#include "header.hpp"

int main()
{

    VectorTester *vectorTester = new VectorTester;

    for (int i = 1; i <= 5; i++) {
        vectorTester->stdVector.push_back(i);
    }
    for (int i = 1; i <= 5; i++) {
        vectorTester->ftVector.push_back(i);
    }
    vectorTester->compareVectors();
    
    


}