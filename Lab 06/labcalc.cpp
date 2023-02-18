//============================================================================
// Author      : S. Miller
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>

/*
Preconditon: argc is the number of arguments provided. Right is the expected number of arguments, ignoring the first one (ie: name of exe)
	that is ALWAYS present.  Usage is the error message that is displayed if number of args does not match.
Postcondition: Outputs message and returns false when it fails to validate, true otherwise. */
bool validate_argc(int argc, int right, const char usage[] );

//A function that opens a file for input and checks that the opening process did not fail. The specification for this function is:
// Postcondition: The ifstream f has been opened for
// reading using the given filename. If any errors
// occurred then an error message has been printed
// and the program has been halted.
void open_for_read(std::ifstream& f, const char filename[ ]);

//A boolean function that determines whether a specified file still has valid input. The specification is:
// Postcondition: The return value is true if f still has
// more valid input to read; otherwise the return
// valid is false.
bool is_more(std::istream& f);

/*
Reads the next line of input (including the newline character at the end of the line). It treats this input line as an arithmetic expression.
If the expression has an error (such as division by zero), then the function returns nan("Invalid").
Otherwise, the function sets okay to true and sets answer to the value of the expression.

Here are a few considerations:
   The input expressions are postfix expressions.
   Use the evaluation algorithm from Figure 7.10 in the textbook.

   The possible errors that will cause a return of nan("Invalid"):
   	   (a) division by zero,
   	   (b) an operation symbol is read but the stack does not have at least two numbers,
   	   (c) the entire expression has been read and evaluated but the numbers stack does not have exactly one number on it.
*/
double process_line(std::istream&);
//Student implements this function in processline.cpp


int main(int argc, char *argv[]) {
    if ( validate_argc(argc,1, "Usage: calc input_file") ) {

        std::ifstream input;

        open_for_read(input, argv[1]);

        double answer;

        while ( is_more(input) ) {

            answer = process_line(input);
            std::cout << answer << std::endl;

        }

        input.close();

        std::cout << "\ndone\n";
    }

    return 0;
}

void open_for_read(std::ifstream& f, const char filename[ ]) {
    f.open(filename);
    if ( f.fail() ) {
        std::cerr << "Could not open input file" << std::endl;
        std::exit(1);
    }
}

bool validate_argc(int argc, int right, const char usage[] ) {
    if ( (argc-1) == right )
        return true;
    std::cerr << usage << std::endl;
    return false;
}

bool is_more(std::istream& f) {
    return f && f.peek() != EOF;
}