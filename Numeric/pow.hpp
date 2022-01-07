#pragma once

#include <assert.h>
#include <cstddef>

#include "simple_matrix.hpp"


///@brief Итеративный алгоритм возведения в степень.
constexpr long double brute_i_pow(double number, std::size_t pow) {
  long double temp = number;
  for (std::size_t i{}; i < pow; ++i) {
    temp *= number;
  }
  return number;
}



///@brief Итеративный алгоритм возведения в степень. Через домножение.
/// Сложность N/2 + LongN
constexpr long double mult_i_pow(double number, std::size_t pow) {
  if (pow == 1) return number;
  std::size_t current_pow = 2;
  long double temp = number;
  for (;current_pow <= pow; current_pow *= current_pow) {
    temp *= temp;
  }
  for (;current_pow <= pow; ++current_pow) {
    temp *= number;
  }
  return number;
}


///@brief Более правильный алгоритм быстрого возведения в степень. 2LogN.
/// Путем двоичного разоложения степени.
constexpr long long unsigned fast_pow(long number, std::size_t pow) {
  int r = (pow%2) ? number : 1;
  while (pow/=2) {
    number*=number;
    if (pow%2) r*=number;
  }
  return r;
}


///@brief Возведение квадратной матрицы в степень.
template <typename T>
simple_matrix<T> matrix_pow(simple_matrix<T> matrix, std::size_t pow) {
  assert(matrix.is_square_matrix());
  // Сначала нужно создать единичную матрицу.
  using mat = simple_matrix<T>;

  mat f_m{matrix.row_count(), matrix.column_count()};
  for (typename mat::size_type i = 0; i < matrix.row_count(); ++i) {
    f_m[i][i] = 1;
  }

  auto ret = (pow%2) ? matrix : f_m;
  while(pow/=2) {
    matrix = mult_matrix(matrix, matrix);
    if (pow%2) ret = mult_matrix(ret, matrix);
  }
  return ret;
}
