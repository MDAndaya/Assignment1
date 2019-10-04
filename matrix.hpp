//
// Created by MDand on 2019-10-04.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

#endif //ASSIGNMENT1_MATRIX_HPP

class Matrix {
private:
    int col;
    int row;
    int** value;

    void allocArray();
public:

    Matrix();
    Matrix(int n);
    Matrix(int col, int row);
    void setVal(int col, int row);
    ~Matrix();


};