#pragma once

#include <array>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>


template<typename RandomIter>
void count_sort(RandomIter first, RandomIter last) {
  static_assert (std::numeric_limits<typename RandomIter::value_type>::max() <=
                std::numeric_limits<std::uint16_t>::max());

  std::array<std::size_t, std::numeric_limits<std::uint16_t>::max()> count;

  for (auto beg = first; beg != last; ++beg) {
    count[*beg]++;
  }

  for (auto prev_beg = count.begin(), beg = std::next(count.begin()); beg != count.end(); ++beg, ++prev_beg) {
    *beg += *prev_beg;
  }

  std::vector<typename RandomIter::value_type> out;
  out.resize(std::distance(first, last));

  for (auto beg = std::make_reverse_iterator(last), end = std::make_reverse_iterator(first); beg != end; ++beg) {
    count[*beg]--;
    out[count[*beg]] = std::move(*beg);
  }

  std::move(out.begin(), out.end(), first);
}
