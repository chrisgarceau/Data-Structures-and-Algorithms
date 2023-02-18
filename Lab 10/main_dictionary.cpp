#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include "hashTable.h"
#include "fileTokens.h"

namespace DS {

    //Precondition: key is a lowercase string with no padded spaces, max is the physical size of the hash table
    //Postcondition: Returns the first index that should be tried to enter the item, it may be a collision, collisions
    //  are NOT handled here.
    size_t string_hash(const std::string &key, size_t max);

}

std::string awesomeLine(size_t n);

using namespace DS;

int main(int argc, char* argv[]) {
    if ( argc != 2 ) {
        std::cerr << "Error: Missing command line argument of data filename." << std::endl;
        return EXIT_FAILURE;
    }
    fileTokens dictionary_raw(argv[1], '$');
    hashTable<std::string, std::string> dictionayTable(811, &string_hash);

    std::string nextKey, sBuffer;
    while ( dictionary_raw.hasToken() ) {
        nextKey = dictionary_raw.getNextToken(true);
        if ( !dictionayTable.insert(nextKey, dictionary_raw.getNextToken()) )
            throw std::runtime_error("Error: Hash table full!!");
    }
    std::cout << "Welcome to the C++ Dictionary" << std::endl
              << dictionayTable.size() << " dictionary terms loaded with "
              << std::setprecision(3) << dictionayTable.getUtilization() <<"% utilization and "
              << dictionayTable.getCollisions() << " collisions." << std::endl;
    do {

        std::cout << std::endl << "Term to define or enter to quit: ";
        getline(std::cin,sBuffer);
        //Convert to lowercase to match stored keys which were loaded from datafile in lowercase
        sBuffer = strToLower(sBuffer);

        if ( !sBuffer.empty() ) {
            std::string *definition = dictionayTable.find(sBuffer);

            if ( definition != nullptr ) {
                std::cout << "\nDefinition for \"" << sBuffer << "\":" << std::endl
                          << awesomeLine(sBuffer.length() + 20) << std::endl
                          << *definition << std::endl;
            } else {
                std::cout << "\n" << sBuffer << " not found in dictionary." << std::endl;
            }
        }

    } while (  !sBuffer.empty() );

    return EXIT_SUCCESS;
}

std::string awesomeLine(size_t n) {
    std::string s;
    for ( size_t i = 0 ; i < n ; ++i )
        s += '-';
    return s;
}

