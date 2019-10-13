//
// Created by MDand on 2019-7-11.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

#include <iostream>

constexpr double TOLERANCE = 0.00001;

class matrix {

protected:
    double **values;
    int row;
    int col;

public:
    matrix();
    matrix(int n);
    matrix(int r, int c);
    matrix(double a[], int n);
    int get_row() const;
    int get_col() const;
    void set_value(int r, int c, double d);
    double get_value(int r, int c) const;
    void clear();
    matrix(const matrix&);
    virtual ~matrix();

    friend std::ostream & operator << (std::ostream &out, const matrix &m);
    friend bool operator==(const matrix& lhs, const matrix& rhs);
    friend bool operator!=(const matrix& lhs, const matrix& rhs);
    matrix& operator++();
    matrix& operator--();
    matrix operator++(int);
    matrix operator--(int);

    matrix& operator=(matrix other);
    void matrixswap(matrix& first, matrix& second);
    matrix& operator+=(const matrix& right);
    friend matrix operator+(matrix lhs, const matrix& rhs);
    matrix& operator-=(const matrix& right);
    friend matrix operator-(matrix lhs, const matrix& rhs);
    friend matrix operator*(matrix lhs, const matrix& rhs);
    matrix& operator*=(const matrix& right);
};


#endif //ASSIGNMENT1_MATRIX_HPP
