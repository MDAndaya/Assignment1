//
// Created by MDand on 2019-7-11.
//

#include <iostream>
#include <iomanip>
#include <cmath>

#include "matrix.hpp"

using namespace std;


matrix::matrix():matrix(1) {}

matrix::matrix(int n): matrix(n,n) {}

matrix::matrix(int r, int c) {
    row = r;
    col = c;
    values = new double*[row];
    for(int i = 0; i < row; i++)
        values[i] = new double[col];

    for(int j = 0; j < row; j++)
        for(int k = 0; k < col; k++)
            values[j][k] = 0.0;
}

matrix::matrix(double a[], int n) {
    row = sqrt(n);
    col = row;
    values = new double*[row];
    for(int i = 0; i < row; i++) {
        values[i] = new double[col];
    }
    int j = 0;
    for(int k = 0; k < row; k++)
        for (int l = 0; l < col; l++)
            values[k][l] = a[j++];
}

matrix::matrix(const matrix &m) {
    row=m.row;
    col=m.col;
    values = new double*[row];
    for(int i = 0; i < row; i++)
        values[i] = new double[col];

    for(int j = 0; j < row; j++)
        for(int k = 0; k < col; k++)
            values[j][k] = m.values[j][k];
}

int matrix::get_row() const {
    return row;
}

int matrix::get_col() const {
    return col;
}

void matrix::set_value(int r, int c, double d) {
    values[r][c] = d;
}

double matrix::get_value(int r, int c) const {
    return values[r][c];
}

void matrix::clear() {
    for(int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            values[i][j] = 0.0;
}

matrix::~matrix() {
   for(int i = 0; i < row; i++)
           delete[] values[i];
    delete[] values;
}

std::ostream & operator << (std::ostream &os, const matrix &m){
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.col; ++j)
            os << fixed << setprecision(2) << m.get_value(i, j) << "  ";
        os << "\n";
    }
    return os;
}

bool operator==(const matrix& left, const matrix& right){
    if (left.row != right.row && left.col != right.col){
        return false;
    } else {
        for(int i = 0; i < left.row; i++)
            for (int j = 0; j < left.col; j++)
                if((left.get_value(i, j) - right.get_value(i, j)) > TOLERANCE)
                    return false;
    }
    return true;
}

bool operator!=(const matrix& left, const matrix& right){
    return !operator==(left, right);
}

matrix &matrix::operator++() {
    for(int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            set_value(i, j, (get_value(i, j) + 1));
    return *this;
}

matrix &matrix::operator--() {
    for(int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            set_value(i, j, (get_value(i, j) - 1));
    return *this;
}

matrix matrix::operator++(int) {
    matrix temp = *this;
    ++(*this);
    return temp;
}

matrix matrix::operator--(int) {
    matrix temp = *this;
    --(*this);
    return temp;
}

matrix &matrix::operator=(matrix other) {
    matrixswap(*this, other);
    return *this;
}

void matrix::matrixswap(matrix& first, matrix& second) {
    using std::swap;
    swap(first.values, second.values);
    swap(first.row, second.row);
    swap(first.col, second.col);
}

matrix &matrix::operator+=(const matrix &right) {
    for(int i = 0; i < right.row; ++i)
        for (int j = 0; j < right.row; ++j)
            values[i][j] = values[i][j] + right.values[i][j];
    return *this;
}

matrix operator+(matrix left, const matrix& right) {
    matrix m(left.row, left.row);
    for(int i = 0; i < left.row; ++i)
        for (int j = 0; j < left.row; ++j)
            m.values[i][j] = left.values[i][j] + right.values[i][j];
    return m;
}

matrix &matrix::operator-=(const matrix &right) {
    for(int i = 0; i < right.row; ++i) {
        for (int j = 0; j < right.row; ++j) {
            values[i][j] = values[i][j] - right.values[i][j];
        }
    }
    return *this;
}

matrix operator-(matrix left, const matrix& right) {
    matrix m(left.row, left.row);
    for(int i = 0; i < left.row; ++i)
        for (int j = 0; j < left.row; ++j)
            m.values[i][j] = left.values[i][j] - right.values[i][j];
    return m;
}

matrix &matrix::operator*=(const matrix &right) {
    matrix m(row, right.col);

    for(int j = 0; j < m.row; ++j) {
        for (int k = 0; k < right.col; ++k) {
            for (int l = 0; l < m.col; ++l) {
                m.values[j][k] += values[j][l] * right.values[l][k];
            }
        }
    }
    *this = m;
    return *this;
}

matrix operator*(matrix lhs, const matrix& rhs) {
    matrix m(lhs.row, rhs.col);
    for(int i = 0; i < lhs.row; ++i) {
        for (int j = 0; j < rhs.col; ++j) {
            for (int k = 0; k < lhs.col; ++k) {
                m.values[i][j] += lhs.values[i][k] * rhs.values[k][j];
            }
        }
    }
    return m;
}
