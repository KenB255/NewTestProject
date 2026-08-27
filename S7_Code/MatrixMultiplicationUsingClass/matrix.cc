#include <iostream>
using namespace std;
class Matrix {
private:
  int rows;
  int cols;
  double* data;
public:
  void allocate(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	data = new double[rows * cols];
  }
  void deallocate() {
	delete[] data;
  }
  double get(int row, int col) const {
	return data[row * cols + col];
  }
  void set(int row, int col, double value) {
	data[row * cols + col] = value;
  }
  Matrix multiply(const Matrix& other) {
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
  void print() const {
	for (int i = 0; i < rows; ++i) {
  	for (int j = 0; j < cols; ++j) {
    	cout << get(i, j) << " ";
  	}
  	cout << endl;
	}
  }
};
int main() {
  Matrix A, B;
  A.allocate(2, 3);
  B.allocate(3, 2);
  for (int i = 0; i < 2; ++i) {
	for (int j = 0; j < 3; ++j) {
  	A.set(i, j, i * 3 + j);
	}
  }
  for (int i = 0; i < 3; ++i) {
	for (int j = 0; j < 2; ++j) {
  	B.set(i, j, i * 2 + j + 1);
	}
  }
  cout << "Matrix A:" << endl;
  A.print();
  cout << "Matrix B:" << endl;
  B.print();
  Matrix C = A.multiply(B);
  cout << "Result of A * B:" << endl;
  C.print();
  A.deallocate();
  B.deallocate();
  C.deallocate();
  return 0;
}