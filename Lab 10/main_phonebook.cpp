#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include "hashTable.h"
#include "fileTokens.h"

namespace DS {
//Implemented in student.cpp by Student
    size_t phonebookHashTableSize();
}

using namespace DS;

/*Part 1: Analyze the computational cost of this program using the order notation in terms of n the number
of assigned phone numbers in the phonebook, and N the largest possible phone number. What is the running
time of constructing the phonebook and of the add and identify functions? How much memory is used by
this program? Express this using order notation. What would happen if you extended this to a 7- or a
10-digit number? Would it work on a cell phone?
*/

int main(int argc, char* argv[]) {
    if ( argc != 2 ) {
        std::cerr << "Error: Missing command line argument of data filename." << std::endl;
        return EXIT_FAILURE;
    }
    fileTokens pb_raw(argv[1], '#');
    hashTable<long, std::string> phoneBook(phonebookHashTableSize());

    long nextNumber;
    while ( pb_raw.hasToken() ) {
        nextNumber = pb_raw.getNextLong();
        if ( !phoneBook.insert(nextNumber, pb_raw.getNextToken()) )
            throw std::runtime_error("Error: Hash table full!!");
    }
    std::cout << phoneBook.size() << " phone book entries loaded with "
              << std::setprecision(3) << phoneBook.getUtilization() <<"% utilization and "
              << phoneBook.getCollisions() << " collisions." << std::endl;

    char option;
    do {
        std::cout
                << "1. Lookup contact" << std::endl
                << "2. Add contact" << std::endl
                << "3. Remove contact" << std::endl
                << "4. Exit" << std::endl << "?: ";
        std::cin >> option;

        switch (option) {
            case '1':
            {
                std::string sNumber;
                long iNumber;
                std::string* psContact;
                std::cout << "Number: ";
                std::cin >> sNumber;
                iNumber = strToLong(sNumber);
                psContact = phoneBook.find(iNumber);
                if ( psContact == nullptr ) {
                    std::cout << "Error: No contact with that number!" << std::endl;
                } else
                    std::cout << *psContact << std::endl;
            }
                break;
            case '2':
            {
                std::string sNumber;
                long iNumber;
                std::string sName;
                std::cout << "Number: ";
                std::cin >> sNumber;
                std::cout << "Name: ";
                std::cin >> sName;
                iNumber = strToLong(sNumber);
                if ( !phoneBook.insert(iNumber, sName) )
                    throw std::runtime_error("Error: Hash table full!!");
            }
                break;
            case '3':
            {
                std::string sNumber;
                long iNumber;
                std::cout << "Number: ";
                std::cin >> sNumber;
                iNumber = strToLong(sNumber);
                if ( phoneBook.erase(iNumber))
                    std::cout << "Removed." << std::endl;
                else
                    std::cout << "Error: Unable to erase, no contact with that number!" << std::endl;

            }
                break;
            case '4':
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }
    } while ( option != '4' );

    return EXIT_SUCCESS;
}