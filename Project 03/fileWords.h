/*
Programmer Name: S. Miller
Purpose: Opens a file and reads one word as a time from the file
Date Updated: 2020-11-4
*/

#ifndef FREQPROJECT_FILEWORDS_H
#define FREQPROJECT_FILEWORDS_H

#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <stdexcept>

namespace DS {

    class fileWords {
    public:
        //Default constructor - NONE
        // do not allow default constructor
        fileWords() = delete;

        //VALUE Constructors
        //Create an object wrapper around the file_name passed
        //Precondition: file exists and is readable
        //Postcondition: File is opened, will crash if file is unable to be read
        fileWords(const std::string &);

        fileWords(const char *);

        //Destructor
        //Precondition: n/a
        //Postcondition: Closes the file
        virtual ~fileWords();

        //Accessors
        //Precondition: n/a
        //Postcondition: Returns true if the file has at least one word left and EOF has not been reached yet
        bool hasWords() const;

        //Mutators
        //Precondition: File still has words to read
        //Postcondition: Returns the next word in the file converted to lowercase. File pointer is moved to the start of
        //  the next word.
        std::string getNextWord();


    private:
        //Open the file
        bool open();

        //The file used for reading
        std::string file_name;

        //File stream, maintains seek pointer
        std::ifstream fin;

    };

    fileWords::fileWords(const std::string &f) : file_name(f) {
        open();
    }

    fileWords::fileWords(const char *f) : file_name(f) {
        open();
    }

    bool fileWords::open() {
        fin.open(file_name.c_str(), std::ifstream::in);
        if (fin.fail()) {
            throw std::runtime_error("Unable to open and/or read " + file_name);
        }

        //Move file pointer to start of first word
        while (fin && !isalpha(fin.peek()))
            fin.ignore();

        return true;
    }

    bool fileWords::hasWords() const {
        return !fin.eof();
    }

    std::string fileWords::getNextWord() {

        std::ostringstream s;

        if (fin && isalpha(fin.peek())) {
            //fin.ignore();
            //Possible HTML Tagname, tagnames end in >, SPACE, [, or newline (carriage return too)
            while (fin && isalpha(fin.peek()))
                s << static_cast<char>(tolower(fin.get()));

            //Move file pointer to start of next word
            while (fin && !isalpha(fin.peek()))
                fin.ignore();

            return s.str();
        } else
            throw std::runtime_error("Unexpected end of file reached.");

    }

    fileWords::~fileWords() {
        fin.close();
    }

}
#endif //FREQPROJECT_FILEWORDS_H