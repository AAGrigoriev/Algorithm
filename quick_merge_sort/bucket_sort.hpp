#pragma once

#include <algorithm>
#include <list>
#include <vector>
#include <iostream>

template<typename RandomIter>
void bucket_sort(RandomIter first, RandomIter end) {
  using list_type = std::list<typename RandomIter::value_type>;

  // Ищем максимум среди диапазона
  auto max_element = *std::max_element(first, end);
  auto distance    = std::distance(first, end);
  std::vector<list_type> bucket_vector(distance);

  auto add_element_to_list = [](list_type& list, auto&& elem) {
    if (auto it = std::find_if(list.begin(), list.end(), [&elem](auto& elem_list) {
          return elem_list > elem;
    }); it != list.end()) {
      list.insert(it, std::move(elem));
    } else {
      list.push_back(std::move(elem));
    }
  };

  // Формула для получения позиции в векторе a[i] * N / (max_element + 1)
  // Получаются индексы между [0..N)
  for (auto beg = first; beg != end; ++beg) {
    auto pos = *beg * distance / (max_element + 1);
    add_element_to_list(bucket_vector.at(pos), std::move(*beg));
  }


  auto beg = first;
  for (auto& list : bucket_vector) {
    for (auto&& elem : list) {
      *beg++ = std::move(elem);
    }
  }
}
