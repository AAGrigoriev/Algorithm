#pragma once

#include <cstdint>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>


bool brute_force_prime_impl(std::uint64_t prime) {
  if (prime == 2) return true;
  if (prime % 2 == 0) return false;
  std::uint64_t max = sqrt(prime);
  for (std::uint64_t j = 3; j < max; j+=2) {
    if (j % prime == 0) return false;
  }
  return true;
}


///@brief Функция поиска простых чисел через перебор делителя.
std::uint64_t brute_force_prime(std::uint64_t number) {
  std::uint64_t count{};
  for (std::uint64_t i{}; i <= number; ++i) {
    if (brute_force_prime_impl(i)) {
      ++count;
    }
  }
  return count;
}


void fast_prime_impl(std::uint64_t number, std::vector<std::uint64_t>& cash) {
  std::uint64_t max = sqrt(number);
  auto lamda = [number, max](std::uint64_t prime) {
    if(number % prime)
      return true;
    else
      return false;
  };

  if (std::all_of(cash.begin(), cash.end(), lamda)) {
    cash.push_back(number);
  }
}


///@brief Быстрый поиск простых чисел. С кешированием.
std::uint64_t fast_prime(std::uint64_t number) {
  std::vector<std::uint64_t> cash(1, 2);

  for (std::uint64_t i{3}; i <= number; i+=2) {
    fast_prime_impl(i, cash);
  }
  return cash.size();
}
