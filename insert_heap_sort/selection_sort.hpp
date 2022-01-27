#pragma once

#include <array>
#include <cstdlib>
#include <utility>

template<typename T, std::size_t N>
void selection_sort(std::array<T, N>& arr ) {
  for (std::size_t i{}; i < N - 1; ++i) {
    std::size_t min_indx = i;
    for (std::size_t j{i + 1}; j < N; ++j) {
      min_indx = arr[j] < arr[min_indx] ? j : min_indx;
    }
    if (min_indx != i) {
      std::swap(arr[min_indx], arr[i]);
    }
  }
}


