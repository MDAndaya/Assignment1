//
// Created by MDand on 2019-10-11.
//

#include "connectivitymatrix.hpp"
#include <iomanip>

using namespace std;

connectivitymatrix::connectivitymatrix(): matrix() {}

connectivitymatrix::connectivitymatrix(int n) : matrix(n) {}

connectivitymatrix::connectivitymatrix(double *a, int n) : matrix(a, n) {}

connectivitymatrix::connectivitymatrix(const connectivitymatrix &m) : matrix(m) {}

connectivitymatrix::~connectivitymatrix() {}

std::ostream & operator << (std::ostream &os, const connectivitymatrix &m){
    for (int r = 0; r< m.get_row(); ++r) {
        for (int c = 0; c< m.get_row(); ++c)
            os << fixed << setprecision(0) << m.get_value(r, c) << "  ";
        os << "\n";
    }
    return os;
}
