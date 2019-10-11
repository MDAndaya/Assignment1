//
// Created by MDand on 2019-10-04.
//

#include <vector>
#include <ostream>

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

#endif //ASSIGNMENT1_MATRIX_HPP

using namespace std;

class matrix {
private:
    vector<vector<double>> values;

public:
    matrix();
    matrix(int n);
    matrix(int r, int c);
    matrix(vector<double> vector);

    void set_value(int r, int c, double value);
    double get_value(int r, int c);
    void clear();
    ~matrix();

    friend ostream& operator<<(ostream& os, const matrix& m);

    bool operator==(const matrix& other) const;
    bool operator!=(const matrix& other) const;

    matrix& operator++();
    matrix operator++(int);
    matrix& operator--();
    matrix operator--(int);

    friend void swap(matrix& first, matrix& second);
    matrix& operator=(const matrix& other);

    matrix operator*(matrix& other);
    matrix& operator*=(matrix& other);





};