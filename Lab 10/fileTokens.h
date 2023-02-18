/*
Programmer Name: S. Miller
Purpose: Opens a file and reads one word as a time from the file
Date Updated: 2020-11-4
*/

#ifndef FILETOKENS_H
#define FILETOKENS_H

#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <stdexcept>

namespace DS {

    class fileTokens {
    public:
        //Default constructor - NONE
        // do not allow default constructor
        fileTokens() = delete;

        //VALUE Constructors
        //Create an object wrapper around the file_name passed
        //Precondition: file exists and is readable
        //Postcondition: File is opened, will crash if file is unable to be read
        fileTokens(const std::string &, char fieldDelimiter=',', char recordDelimiter='\n');

        fileTokens(const char *, char fieldDelimiter=',', char recordDelimiter='\n');

        //Destructor
        //Precondition: n/a
        //Postcondition: Closes the file
        virtual ~fileTokens();

        //Accessors
        //Precondition: n/a
        //Postcondition: Returns true if the file has at least one word left and EOF has not been reached yet
        bool hasToken() const;

        //Mutators
        //Precondition: File still has words to read
        //Postcondition: Returns the next word in the file converted to lowercase. File pointer is moved to the start of
        //  the next word.
        std::string getNextToken(bool force_lowercase=false, bool numbers_only=false);

        long getNextLong();

    private:
        //Open the file
        bool open();

        //The file used for reading
        std::string file_name;

        //File stream, maintains seek pointer
        std::ifstream fin;

        char fieldDelimiter;
        char recordDelimiter;
    };

    long strToLong(const std::string&);
    std::string strToLower(const std::string&);

    fileTokens::fileTokens(const std::string &f, char fieldDelimiter, char recordDelimiter) : file_name(f) {
        this->fieldDelimiter = fieldDelimiter;
        this->recordDelimiter = recordDelimiter;
        open();
    }

    fileTokens::fileTokens(const char *f, char fieldDelimiter, char recordDelimiter) : file_name(f) {
        this->fieldDelimiter = fieldDelimiter;
        this->recordDelimiter = recordDelimiter;
        open();
    }

    bool fileTokens::open() {
        fin.open(file_name.c_str(), std::ifstream::in);
        if (fin.fail()) {
            throw std::runtime_error("Unable to open and/or read " + file_name);
        }

        return true;
    }

    bool fileTokens::hasToken() const {
        return !fin.eof();
    }

    std::string fileTokens::getNextToken(bool force_lowercase/*=false*/, bool numbers_only/*=false*/) {

        std::ostringstream s;
        size_t spaces = 0;
        char character;

        if (fin) {

            //Move over initial spaced
            while (fin && isspace(fin.peek()) )
                fin.ignore();

            while (fin && fin.peek() != fieldDelimiter and fin.peek() != recordDelimiter ) {
                character = fin.get();
                if ( !numbers_only || isdigit(character)) {
                    if (isspace(character)) {
                        ++spaces;
                    } else {
                        for (size_t i = 0; i < spaces; ++i)
                            s << ' ';
                        s << static_cast<char>(force_lowercase ? tolower(character) : character);
                        spaces = 0;
                    }
                }
            }

            //Move file pointer to start of next word
            if (fin)
                fin.ignore();

            while (fin && isspace(fin.peek()) )
                fin.ignore();

            return s.str();
        } else
            throw std::runtime_error("Unexpected end of file reached.");

    }

    fileTokens::~fileTokens() {
        fin.close();
    }

    long fileTokens::getNextLong() {
        std::string token = getNextToken(false, true);
        std::istringstream iss(token);
        long result;
        iss >> result;
        return result;

    }

    long strToLong(const std::string& s) {
        long n = 0;
        char c;
        std::istringstream iss(s);
        std::ostringstream oss;

        while ( iss >> c ) {
            if ( isdigit(c) )
                oss << c;
        }
        std::istringstream fss(oss.str());
        fss >> n;
        return n;
    }

    std::string strToLower(const std::string& s) {
        std::ostringstream oss;
        for ( auto c = s.begin() ; c != s.end() ; ++c )
            oss << static_cast<char>(tolower(*c));
        return oss.str();
    }
}
#endif //FILETOKENS_H