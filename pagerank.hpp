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

    void print_results();
    connectivitymatrix generate_g();
    matrix generate_s(const matrix &g);
    matrix generate_sblank(const matrix &g);
    matrix generate_q();
    matrix generate_m(const matrix &s, const matrix &q);
    matrix generate_rank(const matrix &m);

    matrix multiply_rank(const matrix &rank, const matrix &m);
    matrix divide_rank(const matrix &m);
};


#endif //ASSIGNMENT1_PAGERANK_HPP
