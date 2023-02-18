#ifndef MATRIX_H
#define MATRIX_H

const int MAXROWS=2;
const int MAXCOLS=3;

template <class Item>
class Matrix {
private:
    Item doubleArray[MAXROWS][MAXCOLS];
    size_t rows;
    size_t cols;

public:
    //Constructor
    Matrix();  //Set rows to MAXROWS and cols to MAXCOLS
    //Initialize all the values of doubleArray to zero

    //Getter Functions
    void printMatrix();

    //Setter Functions
    void setMatrix(Item [][MAXCOLS]); //set the doubleArray to what is sent
    void addMatrix(Item [][MAXCOLS]); //add an array to doubleArray
    void addMatrix(Matrix otherMatrix);

    //No destructor needed
};


template <class Item>
Matrix<Item>::Matrix()
{
    rows = MAXROWS;
    cols = MAXCOLS;
    for (size_t i=0; i< rows; i++)
    {
        for(size_t j=0; j< cols; j++)
        {
            doubleArray[i][j] = '\0';
        }
    }
}
template <class Item>
void Matrix<Item>::printMatrix()
{
    for (size_t i=0; i< rows; i++)
    {
        for(size_t j=0; j< cols; j++)
        {
            std::cout << doubleArray[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}
template <class Item>
void Matrix<Item>::setMatrix(Item otherArray[][MAXCOLS])
{
    for (size_t i=0; i< rows; i++)
    {
        for(size_t j=0; j< cols; j++)
        {
            doubleArray[i][j] = otherArray[i][j];
        }
    }
}

template <class Item>
void Matrix<Item>::addMatrix(Item otherArray[][MAXCOLS])
{
    for (size_t i=0; i< rows; i++)
    {
        for(size_t j=0; j< cols; j++)
        {
            doubleArray[i][j] += otherArray[i][j];
        }
    }
}

template <class Item>
void Matrix<Item>::addMatrix(Matrix otherMatrix)
{
    addMatrix(otherMatrix.doubleArray);
}

#endif