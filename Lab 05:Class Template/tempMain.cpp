#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

template <typename Item>
void demoTemplate(Matrix<Item>& M, Item array1[][MAXCOLS], Item array2[][MAXCOLS]);

int main()
{
    string Str1[MAXROWS][MAXCOLS] =
            {
                    {"Congra", "y", "ar"},
                    {"alm", "don", "La"}
            };
    string Str2[MAXROWS][MAXCOLS] =
            {
                    {"tulations", "ou", "e"},
                    {"ost", "e    the", "b!"}
            };
    int Num1[MAXROWS][MAXCOLS] =
            {
                    {1,2,3},
                    {4,5,6}
            };
    int Num2[MAXROWS][MAXCOLS] =
            {
                    {6,5,4},
                    {3,2,1}
            };
    string Str3[MAXROWS][MAXCOLS] =
            {
                    {"Ho", "com", "e"},
                    {"m", "l", "Ch"}
            };
    string Str4[MAXROWS][MAXCOLS] =
            {
                {"la", "o", "stas"},
                {"e", "lamo", "ristopher"}
            };
    float F1[MAXROWS][MAXCOLS] =
            {
                    {123.654, 432.55, 556.8},
                    {1.4567, 43.9871, 336.99}
            };
    float F2[MAXROWS][MAXCOLS] =
            {
                    {2.4, 3.8, 5.9},
                    {12.5, 7.90, 3.21}
            };
    bool b1[MAXROWS][MAXCOLS] =
            {
                    {true, false, false},
                    {true, true, false}
            };
    bool b2[MAXROWS][MAXCOLS] =
            {
                    {false, true, false},
                    {false, false, false}
            };



    Matrix<string> stringMatrix;
    Matrix<int> intMatrix;
    Matrix<float> floatMatrix;
    Matrix<bool> boolMatrix;

    cout << "\nDemonstrating with string matrix:" << endl;
    demoTemplate(stringMatrix, Str1, Str2);

    cout << "\nDemonstrating with int matrix:" << endl;
    demoTemplate(intMatrix, Num1, Num2);

    cout << "\nDemonstrating with string matrix:" << endl;
    demoTemplate(stringMatrix, Str3, Str4);

    cout << "\nDemonstrating with float matrix:" << endl;
    demoTemplate(floatMatrix, F1, F2);

    cout << "\nDemonstrating with bool matrix:" << endl;
    demoTemplate(boolMatrix, b1, b2);


    cout << "\n" << endl;

    return 0;
}


template <typename Item>
void demoTemplate(Matrix<Item>& M, Item array1[][MAXCOLS], Item array2[][MAXCOLS])
{
    M.setMatrix(array1);
    cout << "\nMatrix set to first array" << endl;
    M.printMatrix();

    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl;
    M.printMatrix();
}
