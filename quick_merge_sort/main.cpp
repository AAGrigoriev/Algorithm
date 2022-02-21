#include <iostream>
#include <iterator>
#include "quick_sort.hpp"

using namespace std;

int main() {

  std::array<int, 4> not_sorted = {3,1,4,2};

  iter_quick_sort(not_sorted.begin(), not_sorted.end());

  std::copy(not_sorted.begin(), not_sorted.end(), std::ostream_iterator<int>(std::cout, " "));



  return 0;
}
