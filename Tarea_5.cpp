
#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;

void printMenu() {


}

int main() {

    int rows;

    cout << "";

    cin >> rows;

    int cols;

    cout << "";

    cin >> cols;

    Matrix<int>* m = nullptr;

    try {

        m = new Matrix<int>(rows, cols);
    }

    catch (runtime_error& e) {

    }

    delete m;

    return 0;
}

