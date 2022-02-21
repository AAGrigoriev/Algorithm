#pragma once

#include <algorithm>
#include <vector>
#include <utility>


template <typename RandomIter>
void merge_sort(RandomIter first, RandomIter last) {
  auto n = std::distance(first, last);

  if (n > 1) {
    auto l_first = first;
    auto l_last  = std::advance(l_first, n/2);
    merge_sort(l_first, l_last);

    auto r_first = l_last;
    auto r_last = last;
    merge_sort(r_first, r_last);

    std::vector<typename RandomIter::value_type> temp;
    temp.reserve(n);
    while (l_first != l_last && r_first != r_last) {
      if (*l_first < *r_first) {
        temp.emplace_back(std::move(*l_first++));
      } else {
        temp.emplace_back(std::move(*r_first++));
      }

      if (l_first == l_last) {
        std::copy(std::make_move_iterator(r_first), std::make_move_iterator(r_last), temp.end());
        break;
      }

      if (r_first == r_last) {
        std::copy(std::make_move_iterator(l_first), std::make_move_iterator(l_last), temp.end());
        break;
      }
    }

    std::copy(std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()), first);
  }
}
