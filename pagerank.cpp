//
// Created by MDand on 2019-10-11.
//

#include <fstream>
#include <iomanip>
#include "pagerank.hpp"
#include "matrix.hpp"
#include "connectivitymatrix.hpp"

using namespace std;

pagerank::pagerank() {
    int readings = 0;
    double temp_double = 0.0;
    ifstream file;

    file.open("connectivity.txt");
    while (file >> temp_double) {
        readings++;
    }
    webpages = readings;
    file.close();

    connectivityArray[webpages - 1];
    int i = 0;

    file.open("connectivity.txt");

    while (file >> temp_double) {
        connectivityArray[i] = temp_double;
        i++;
    }
    file.close();
}

pagerank::~pagerank() {

}

void pagerank::print_results(){
    connectivitymatrix g = generate_g();
    cout << g << endl;
    matrix s = generate_s(g);
    matrix s2 = generate_sblank(s);
    matrix q = generate_q();
    matrix m = generate_m(s2, q);
    matrix rank = generate_rank(s2);
    matrix result = multiply_rank(rank, m);
    matrix ranked = divide_rank(result);
    char page ='A';
    for (int i = 0; i < ranked.get_row(); i++)
        cout << fixed << setprecision(2) << "page " << (char)(page++) << ": " << ranked.get_value(i, 0) << "%" << endl;
}

connectivitymatrix pagerank::generate_g() {
    connectivitymatrix g(connectivityArray, webpages);
    return g;
}

matrix pagerank::generate_s(const matrix &g) {
    double sumval = 0;
    matrix s(connectivityArray, webpages);
    s = g;
    for (int i = 0; i < s.get_col(); i++) {
        sumval = 0;
        for (int j = 0; j < s.get_row(); j++)
            if (s.get_value(j, i) == 1)
                sumval++;
        if (sumval != 0)
            for (int k = 0; k < s.get_row(); ++k)
                s.set_value(k, i, s.get_value(k, i) / sumval);
    }
    return s;
}

matrix pagerank::generate_sblank(const matrix &g) {
    matrix s(connectivityArray, webpages);
    s = g;
    for (int i = 0; i < s.get_col(); i++) {
        bool noColumns = true;
        for (int j = 0; j < s.get_row(); j++)
            if (s.get_value(j, i) != 0)
                noColumns = false;

        if (noColumns)
            for (int k = 0; k < s.get_row(); k++)
                s.set_value(k, i, 1.0 / s.get_row());
    }
    return s;
}

matrix pagerank::generate_q() {
    matrix q(connectivityArray, webpages);
    for (int i = 0; i < q.get_col(); i++)
        for (int j = 0; j < q.get_row(); j++)
            q.set_value(i, j, 1.0 / q.get_row());
    return q;

}

matrix pagerank::generate_m(const matrix &s, const matrix &q) {
    matrix m1;
    m1 = s;
    for (int i = 0; i < m1.get_col(); i++)
        for (int j = 0; j < m1.get_row(); j++)
            m1.set_value(i, j, (m1.get_value(i, j) * 0.85));
    matrix m2;
    m2 = q;
    for (int i = 0; i < m2.get_col(); i++)
        for (int j = 0; j < m2.get_row(); j++)
            m2.set_value(i, j, (m2.get_value(i, j) * (1.0 - 0.85)));

    matrix m;
    m = m1 + m2;
    return m;
}

matrix pagerank::generate_rank(const matrix &m) {
    matrix rank(m.get_row(), 1);
    for (int i = 0; i < m.get_row(); i++)
        rank.set_value(i, 0, 1.0);
    return rank;
}

matrix pagerank::multiply_rank(const matrix &rank, const matrix &m) {
    matrix result = m*rank;
    if((m*rank)!=rank)
        result = multiply_rank(result, m);
    return result;
}

matrix pagerank::divide_rank(const matrix &m) {
    double sum = 0;
    for (int i = 0; i < m.get_row(); i++)
        sum += m.get_value(i, 0);

    matrix rank = m;
    for (int j = 0; j < rank.get_row(); j++)
        rank.set_value(j, 0, (rank.get_value(j, 0) / sum) * 100.0);
    return rank;

}
