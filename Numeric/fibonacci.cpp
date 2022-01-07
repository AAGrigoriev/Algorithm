#include "fibonacci.hpp"
#include "pow.hpp"
#include "simple_matrix.hpp"


///@brief Алгоритм нахождения числа Фибоначчи через умножение матриц.
unsigned long long matrix_fibonacci(std::size_t number) {
  if (number == 0) return 0;
  if (number <= 2) return 1;

  using matr = simple_matrix<int>;

  matr fibo(2, 2);
  fibo[0][0] = 1;
  fibo[0][1] = 1;
  fibo[1][0] = 1;
  fibo[1][1] = 0;

  return matrix_pow(fibo, number - 1)[0].front();
}
