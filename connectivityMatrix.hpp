//
// Created by MDand on 2019-10-11.
//

#ifndef ASSIGNMENT1_CONNECTIVITYMATRIX_HPP
#define ASSIGNMENT1_CONNECTIVITYMATRIX_HPP

#include "matrix.hpp"

class connectivitymatrix : public matrix {

protected:

public:
    connectivitymatrix();
    connectivitymatrix(int n);
    connectivitymatrix(double a[], int n);
    connectivitymatrix(const connectivitymatrix& m);
    virtual ~connectivitymatrix();
    friend std::ostream & operator << (std::ostream &os, const connectivitymatrix &m);

};


#endif //ASSIGNMENT1_CONNECTIVITYMATRIX_HPP
