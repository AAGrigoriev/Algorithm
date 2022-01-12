#pragma once

#include <algorithm>
#include <iterator>
#include <utility>
#include <iostream>

///@brief Функция сортировки пузырьком.
template<typename RandomIter>
void  bubble_sort(RandomIter first, RandomIter last) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (auto temp = std::next(first); temp < last; ++temp) {
      if (*(temp - 1) > *temp) {
        std::swap(*(temp - 1), *temp);
        swapped = true;
      }
    }
    --last;
  }
}


///@brief Функция сортировки вставк
template<typename RandomIter>
void insert_sort(RandomIter first, RandomIter last) {
  for (auto beg = first + 1; beg != last; ++beg) {
    for (auto j = beg; j > first && *(j - 1) > *j; --j) {
      std::swap(*(j - 1), *j);
    }
  }
}


///@brief Функция сортировки вставками с оптимизацией всатвки и поиска места в массиве.
template<typename RandomIter>
void fast_insert_sort(RandomIter first, RandomIter last) {
  for (auto beg = first + 1; beg != last; ++beg) {
    auto iter = std::lower_bound(first, beg, *beg);
    if (iter != beg) {
      auto temp = std::move(*beg);
      std::move_backward(iter, beg, beg + 1);
      *iter = std::move(temp);
    }
  }
}


///@brief Функция сортировки Шелла.
template <typename RandomIter, typename Comp>
void shell_sort(RandomIter first, RandomIter last, Comp comp) {
  for (auto d = (last - first) / 2; d > 0; d -= 2) {
    for (auto i = first + d; i != last; ++i) {
      for (auto j = i; j - first >= d && comp(*j, *(j - d)); j -= d) {
        std::swap(*j, *(j - d));
      }
    }
  }
}
