//
// Created by MDand on 2019-10-04.
//

#include <iostream>;
#include "matrix.hpp"

using namespace std;

void Matrix::allocArray() {
        value = new int*[col];
        for (int i = 0; i < col; i++)
            value[i] = new int[row];
}

Matrix::Matrix(): Matrix(1, 1) {
    allocArray();
}

Matrix::Matrix(int n): Matrix(n, n) {
    allocArray();
}

Matrix::Matrix(int col, int row) {
    allocArray();
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
            value[col][row];
}