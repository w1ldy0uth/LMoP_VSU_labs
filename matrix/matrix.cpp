#include "matrix.h"
#include <iostream>

void create(int **&matrix ,int rows, int cols) {
    matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
}

void del(int **&matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void input(int **matrix, int rows, int cols) {
    std::cout << "Enter matrix' elements\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void print(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int sum(int **matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}