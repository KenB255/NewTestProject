#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
  private:
    int rows;
    int cols;
    double* data;
  public:
  Matrix(int rows, int cols);
  ~Matrix();
  double getValue(int row, int col) const;
  void setValue(int row, int col, double value);
  Matrix multiply(const Matrix& other) const;
  void print() const;
};
#endif // MATRIX_H
