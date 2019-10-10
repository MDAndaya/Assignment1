
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
    cout << "matrix destructed" << endl;
}

ostream& operator<<(ostream& os, matrix& m) {
    for (int i = 0; i < m.values.size(); i++) {
        for (int j = 0; j < m.values[i].size(); j++)
            os << m.values[i][j] << "  ";
        cout << endl;
    }
}

