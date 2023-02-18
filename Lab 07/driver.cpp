//Recursion Lab

#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include "myrecursion.h"


bool doTestOnArray(const std::string&, bool(*f)(const long[],const size_t));

int main() {

    std::string s="Indiana Jones";
    std::cout <<  mirrorString(s) << std::endl;

    std::queue<int> fq;
    fq.push(1);
    fq.push(2);
    fq.push(4);
    fq.push(8);

    outRevQueue(fq);
    std::cout << std::endl;

    std::cout << "{ " << myseries( 0  );
    for ( int i = 1 ; i < 10 ; ++i )
        std::cout << ", " << myseries( i );
    std::cout << " }" << std::endl;

    std::cout << count7(717) << std::endl;
    std::cout << count7(7) << std::endl;
    std::cout << count7(123) << std::endl;

    std::cout << std::boolalpha << doTestOnArray("[1,1]", &split13_3) << std::endl;
    std::cout << std::boolalpha << doTestOnArray("[1,1,1]", &split13_3) << std::endl;
    std::cout << std::boolalpha << doTestOnArray("[2,4,2]", &split13_3) << std::endl;
    std::cout << std::boolalpha << doTestOnArray("[7,3,7,9,2]", &split13_3) << std::endl;
    std::cout << std::boolalpha << doTestOnArray("[21,9,9,3]", &split13_3) << std::endl;
    std::cout << std::boolalpha << doTestOnArray("[21,7,7,7]", &split13_3) << std::endl;

    std::cout << repeat("DS!! ",3) << std::endl;
    std::cout << mult(1,0) << std::endl;
    std::cout << mult(1,1) << std::endl;
    std::cout << mult(2,4) << std::endl;
    std::cout << mult(2,-4) << std::endl;
    std::cout << mult(-2,4) << std::endl;
    std::cout << mult(-2,-4) << std::endl;

    std::list<std::string> permutations;
    std::string ps("aBc");
    string_permutations(ps, ps.length(), permutations);
    for ( auto i = permutations.cbegin() ; i != permutations.cend() ; ++i )
        std::cout << *i << std::endl;

    return 0;
}

bool doTestOnArray(const std::string& data, bool(*f)(const long[],const size_t) ) {
    //Must construct array first
    std::istringstream ssin(data.substr(1,data.length()-2));
    int index = 0;
    size_t arrayLength = count(data.begin(), data.end(), ',') + 1;
    long * arrayData = new long[arrayLength];
    while ( !ssin.fail() ) {
        if ( isdigit(ssin.peek())  ) {
            ssin >> arrayData[index];
            ++index;
        } else {
            ssin.ignore(1);
        }
    }

    bool result = f(arrayData, arrayLength);
    delete [] arrayData;
    return result;
}