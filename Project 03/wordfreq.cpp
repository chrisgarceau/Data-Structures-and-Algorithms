/*
Program Name: Project 03: Word Frequency
Programmer Name: Christopher Garceau
Date Submitted: November 18, 2020
Purpose:
Date Updated:
Purpose for Update:
Global Variable List: {avoid these}
*/

#include <iostream>
#include "fileWords.h"
#include "bst_tree.h"

using namespace DS;

int main(int argc, const char* argv[]) {

    if (argc==2) {
        //Create object that opens file
        fileWords inputfile(argv[1]);

        //While the file still has words waiting to be read
        while (inputfile.hasWords()) {

            //Output the word to standard out
            std::cout << inputfile.getNextWord() << std::endl;

        }
    } else {
        //Command line arguments not configured, give error
        std::cerr << "Usage: " << argv[0] << " name_of_input_file" << std::endl;
    }

    //Initializes a BST to contain all words within text file
    bst_tree<std::string> wordTreeAll;
    //Initializes a BST to contain only one copy of every word within text file
    bst_tree<std::string> wordTreeOne;

    //Inserts all words in text file into wordTreeAll BST
    if (argc == 2) {
        fileWords input(argv[1]);
        while (input.hasWords()) {
            wordTreeAll.insertAll(input.getNextWord());
        }
    }

    //Inserts one copy of every word into wordTreeOne BST
    if (argc == 2) {
        fileWords input(argv[1]);
        while (input.hasWords()) {
            wordTreeOne.insertOne(input.getNextWord());
        }
    }

    //Outputs word frequency in alphabetical order
    std::cout << std::endl;
    std::cout << "WORD FREQUENCY - Alphabetical" << std::endl;
    std::cout << "[";
    std::cout << wordTreeOne.toStringAlpha(wordTreeAll);
    std::cout << "]" << std::endl;

    //Outputs word frequency from lowest to highest frequency
    std::cout << std::endl;
    std::cout << "WORD FREQUENCY - Lowest to Highest" << std::endl;
    std::cout << "[";
    wordTreeOne.printLH(wordTreeAll, wordTreeOne);
    std::cout << "]" << std::endl;

    return 0;
}
