#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {
    cout << "Hello, World!" << std::endl;

    matrix m(3, 4);
    matrix m2(4, 2);

    m++;m++;m2++;

    cout << m << endl;
    cout << m2 << endl;

    m*=m2;

    cout << "multiply" << endl;
    cout << m << endl;
    return 0;
}