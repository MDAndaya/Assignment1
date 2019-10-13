//
// Created by MDand on 2019-10-11.
//

#ifndef ASSIGNMENT1_PAGERANK_HPP
#define ASSIGNMENT1_PAGERANK_HPP


#include "connectivitymatrix.hpp"

class pagerank {
protected:
    int webpages;
    double *connectivityArray;

public:
    pagerank();
    virtual ~pagerank();

    void printResults();
    connectivitymatrix generateG();
    matrix generateS(const matrix &g);
    matrix generateSBlank(const matrix &g);
    matrix generateQ();
    matrix generateM(const matrix &s, const matrix &q);
    matrix generateRank(const matrix &m);

    matrix multiplyRank(const matrix &rank, const matrix &m);
    matrix divideRank(const matrix &m);
};


#endif //ASSIGNMENT1_PAGERANK_HPP
