#include "matrix.h"
#include <iostream>
using namespace std;
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
  data = new double[rows * cols];
}
Matrix::~Matrix() {
  delete[] data;
}
double Matrix::getValue(int row, int col) const {
  return data[row * cols + col];
}
void Matrix::setValue(int row, int col, double value) {
  data[row * cols + col] = value;
}
Matrix Matrix::multiply(const Matrix& other) const {
  if (cols != other.rows) {
  cerr << "Error: Incompatible matrix dimensions for multiplication" << endl;
  }
  Matrix result(rows, other.cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < other.cols; ++j) {
      double sum = 0;
      for (int k = 0; k < cols; ++k) {
        sum += getValue(i, k) * other.getValue(k, j);
      }
      result.setValue(i, j, sum);
    }
  }
  return result;
}
void Matrix::print() const {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << getValue(i, j) << " ";
    }
    cout << endl;
  }
}
