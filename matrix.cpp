//
// Created by MDand on 2019-10-04.
//

#include <iostream>
#include <cmath>
#include "matrix.hpp"

using namespace std;

void Matrix::allocArray() {
    values = new int*[col];
        for (int i = 0; i < col; i++)
            values[i] = new int[row];
}

Matrix::Matrix(): Matrix(1, 1) {}

Matrix::Matrix(int n): Matrix(n, n) {}

Matrix::Matrix(int col, int row) {

    if (col <= 0 || row <= 0)
        throw "col and row cannot be zero or less";
    Matrix::col = col;
    Matrix::row = row;

    allocArray();
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            values[col][row] = 0;
}

Matrix::Matrix(double *darray) {
    long double arraySize = (double) sizeof(darray) / sizeof(darray[0]);
    long double sr = sqrt(arraySize);
    bool isPerfectSquare = ((sr - floor(sr) == 0));

    if (!isPerfectSquare)
        throw "size of array does not have an integer square root";

    col = sr;
    row = sr;
    allocArray();

    for (int i = 0; i < sr; i++)
        for (int j = 0; j < sr; j++)
            for (int k = 0; k < arraySize; k++)
                setValue(col, row, darray[k]);
}

void Matrix::setValue(int col, int row, double value) {
    values[col][row] = value;
}

double Matrix::getValue(int col, int row) {
    return values[col][row];
}

void Matrix::clear() {
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            values[col][row] = 0;
}


