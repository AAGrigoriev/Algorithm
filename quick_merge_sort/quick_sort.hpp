#pragma once

#include <algorithm>
#include <cstdlib>
#include <iostream>


template <typename RandomIter>
void iter_quick_sort_impl(RandomIter first, RandomIter last) {
 auto pivot = *first;
 auto i = first;
 auto j = last;

 while (i <= j) {
   while (*i < pivot) ++i;
   while (*j > pivot) --j;

   if (i <= j)
     std::iter_swap(i++, j--);

   if (first < j)
     iter_quick_sort_impl(first, j);
   if (last > i)
     iter_quick_sort_impl(i, last);
 }
}


template<typename RandomIter>
void iter_quick_sort_impl_2(RandomIter first, RandomIter last) {
  auto part_func = [] (auto first, auto end) {
    auto i = first;
    auto last = std::prev(end);
    auto pivot = *end;
    for (auto beg = first; beg != last; ++beg) {
      if (*beg < pivot) {
        std::iter_swap(i++, beg);
      }
    }
    std::iter_swap(i, end);
    return i;
  };

  if (first < last) {
  auto p = part_func(first, last);

  iter_quick_sort_impl_2(first, std::prev(p));
  iter_quick_sort_impl_2(std::next(p), last);\
  }
}


template<typename RandomIter>
void iter_quick_sort(RandomIter first, RandomIter last) {
  if (first == last) return;

  iter_quick_sort_impl_2 (first, std::prev(last));
}






