#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
private:
  int rows;
  int cols;
  double* data;
public:
  void allocate(int rows, int cols);
  void deallocate();
  double get(int row, int col) const;
  void set(int row, int col, double value);
  Matrix multiply(const Matrix& other);
  void print() const;
};
#endif // MATRIX_H
