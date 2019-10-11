
#include <iostream>
#include <cmath>
#include "matrix.hpp"

matrix::matrix(): matrix(1, 1) {}

matrix::matrix(int n): matrix(n, n) {}

matrix::matrix(int r, int c) {
    values.resize(r);
    for (int i = 0; i < r; i++) {
        values[i].resize(c);
        for (int j = 0; j < c; j++)
            values[i][j] = 0;
    }
}

bool isPerfectSquare(long double x) {
    long double sr = sqrt(x);
    return ((sr - floor(sr)) == 0);
}

matrix::matrix(vector<double> vector): matrix(sqrt(vector.size())) {
    if (!isPerfectSquare(vector.size()))
        throw "Given vector size is not a perfect square";

    int matsize = sqrt(vector.size());
    int pointer = 0;
    for (int i = 0; i < matsize; i++)
        for (int j = 0; j < matsize; j++)
            values[i][j] = vector[pointer++];
}

void matrix::set_value(int r, int c, double value) {
    values[r][c] = value;
}

double matrix::get_value(int r, int c) {
    return values[r][c];
}

void matrix::clear() {
    for (int i = 0; i < values.size(); i++)
        for (int j = 0; j < values[i].size(); j++)
            values[i][j] = 0;
}

matrix::~matrix() {
    cout  << "matrix destructed" << endl;
}

ostream& operator<<(ostream& os, const matrix& m) {
    for (int i = 0; i < m.values.size(); i++) {
        for (int j = 0; j < m.values[i].size(); j++)
            os << m.values[i][j] << "  ";
        os << endl;
    }
    return os;
}

bool matrix::operator==(const matrix& other) const {
    if (values.size() != other.values.size())
        return false;
    for (int i = 0; i < values.size(); i++) {
        if (values[i].size() != other.values.size())
            return false;
        for (int j = 0; j < values[i].size(); j++)
            if (values[i][j] != other.values[i][j])
                return false;
    }
    return true;
}

bool matrix::operator!=(const matrix& other) const {
    if (values.size() != other.values.size())
        return true;
    for (int i = 0; i < values.size(); i++) {
        if (values[i].size() != other.values.size())
            return true;
        for (int j = 0; j < values[i].size(); j++)
            if (values[i][j] != other.values[i][j])
                return true;
    }
    return false;
}

matrix& matrix::operator++() {
    for (int i = 0; i < values.size(); i++)
        for (int j = 0; j < values[i].size(); j++)
            values[i][j]++;
    return *this;
}

matrix matrix::operator++(int) {
    matrix temp = *this;
    ++*this;
    return temp;
}

matrix& matrix::operator--() {
    for (int i = 0; i < values.size(); i++)
        for (int j = 0; j < values[i].size(); j++)
            values[i][j]--;
    return *this;
}

matrix matrix::operator--(int) {
    matrix temp = *this;
    --*this;
    return temp;
}

void swap(matrix& first, matrix& second) { // nothrow
    // enable ADL (not necessary in our case, but good practice)
    using std::swap;

    // by swapping the members of two objects,
    // the two objects are effectively swapped
    for (int i = 0; i < first.values.size(); i++)
        for (int j = 0; j < first.values[i].size(); j++)
            swap(first.values[i][j], second.values[i][j]);
}

matrix& matrix::operator=(const matrix& other) {
    matrix temp(other);
    swap(*this, temp);
    return *this;
}

matrix matrix::operator*(const matrix& other) {
    if (values[0].size() != other.values.size())
        throw "matrices are not equal col to row, or vice versa";

    matrix c(values.size(), other.values[0].size());
    for(int i=0; i < values.size(); ++i)
        for(int j=0; j < other.values[0].size(); ++j)
            for(int k=0; k < values[0].size(); ++k)
                c.values[i][j] += values[i][k] * other.values[k][j];
    return c;
}

matrix& matrix::operator*=(const matrix& other) {

    matrix c = *this * other;

    for(int i=0; i < values.size(); ++i)
        values[i].resize(other.values[0].size());
    *this = c;
    return *this;
}