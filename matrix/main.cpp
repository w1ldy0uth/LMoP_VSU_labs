#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
    int rows;
    int cols;

    cout << "Enter amount of rows: ";
    cin >> rows;
    cout << "Enter amount of cols: ";
    cin >> cols;

    int **matrix;
    create(matrix, rows, cols);

    input(matrix, rows, cols);
    print(matrix, rows, cols);

    cout << "Sum of matrix' elements is " << sum(matrix, rows, cols);

    del(matrix, rows);
    return 0;
}
