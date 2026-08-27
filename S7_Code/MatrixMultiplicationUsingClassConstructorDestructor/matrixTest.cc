#include <iostream>
#include "matrix.h"
using namespace std;
int main() {
  Matrix A(2, 3), B(3, 2);
  
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      A.setValue(i, j, i * 3 + j);
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      B.setValue(i, j, i * 2 + j + 1);
    }
  }
  cout << "Matrix A:" << endl;
  A.print();
  cout << "Matrix B:" << endl;
  B.print();
  Matrix C = A.multiply(B);
  cout << "Result of A * B:" << endl;
  C.print();
  return 0;
}
