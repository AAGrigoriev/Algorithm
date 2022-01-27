#pragma once

#include <algorithm>
#include <cstdint>
#include <utility>
#include <iterator>

template <typename RandomIter>
void move_max_to_root(RandomIter root, RandomIter start, RandomIter end) {
  auto dist = std::distance(start, root);

  auto L = start + (2 * dist + 1);
  auto R = start + (2 * dist + 2);

  auto X = root;
  if (L < end && *L > *X) X = L;
  if (R < end && *R > *X) X = R;

  if(X == root) return;

  std::iter_swap(X, root);

  move_max_to_root(X, start, end);
}


template<typename RandomIter>
void heap_sort(RandomIter start, RandomIter end) {

  for (auto i = std::distance(start, end) / 2 - 1; i >= 0; --i) {
    move_max_to_root(start + i, start, end);
  }

  for (auto i = std::distance(start, end) - 1; i >=0; --i) {
    std::iter_swap(start, start + i);
    move_max_to_root(start, start, start + i);
  }
}
