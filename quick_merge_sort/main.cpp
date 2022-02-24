#include <iostream>
#include <iterator>

#include "counting_sort.hpp"
#include "bucket_sort.hpp"
#include "quick_sort.hpp"


auto create_vector() {
  return std::vector<std::uint16_t> {3, 1, 4, 2};
}

int main() {

  {
    auto quick_vector = create_vector();

    iter_quick_sort(quick_vector.begin(), quick_vector.end());

    std::copy(quick_vector.begin(), quick_vector.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
  }

  {
    auto bucket_vector = create_vector();

    bucket_sort(bucket_vector.begin(), bucket_vector.end());

    std::copy(bucket_vector.begin(), bucket_vector.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
  }

  {
    auto count_vector = create_vector();

    count_sort(count_vector.begin(), count_vector.end());

    std::copy(count_vector.begin(), count_vector.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
  }

  return 0;
}
