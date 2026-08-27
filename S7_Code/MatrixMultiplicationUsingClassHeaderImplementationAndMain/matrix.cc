#include "matrix.h"
#include <iostream>
using namespace std;
void Matrix::allocate(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  data = new double[rows * cols];
}
void Matrix::deallocate() {
  delete[] data;
}
double Matrix::get(int row, int col) const {
  return data[row * cols + col];
}
void Matrix::set(int row, int col, double value) {
  data[row * cols + col] = value;
}
Matrix Matrix::multiply(const Matrix& other) {
  if (cols != other.rows) {
  cerr << "Error: Incompatible matrix dimensions for multiplication" << endl;
  }
  Matrix result;
  result.allocate(rows, other.cols);
  for (int i = 0; i < rows; ++i) {
  for (int j = 0; j < other.cols; ++j) {
    double sum = 0;
    for (int k = 0; k < cols; ++k) {
      sum += get(i, k) * other.get(k, j);
    }
    result.set(i, j, sum);
  }
  }
  return result;
}
void Matrix::print() const {
  for (int i = 0; i < rows; ++i) {
  for (int j = 0; j < cols; ++j) {
    cout << get(i, j) << " ";
  }
  cout << endl;
  }
}
