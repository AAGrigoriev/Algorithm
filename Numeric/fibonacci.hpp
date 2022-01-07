#pragma once

#include <array>
#include <cstddef>


///@brief Рекурсивный алгоритм вычисления числа Фибоначчи
constexpr unsigned long long r_fibonacci(std::size_t number) {
  return number <= 2 ? 1 : r_fibonacci(number - 1) + r_fibonacci(number - 2);
}


///@brief Итеративный алгоритм Фибоначчи.
constexpr unsigned long long i_fibonacci(std::size_t number) {
  std::array<std::size_t, 2> first_second_number {1, 1};
  for (std::size_t i = 3; i <= number; ++i) {
    first_second_number[i % 2] = first_second_number[0] + first_second_number[1];
  }
  return first_second_number[number % 2];
}


///@brief Алгоритм нахождения числа Фибоначчи через умножение матриц.
unsigned long long matrix_fibonacci(std::size_t number);
