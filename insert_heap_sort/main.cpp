#include <array>
#include <random>
#include <iostream>
#include <iterator>

#include "heap_sort.hpp"
#include "selection_sort.hpp"

using namespace std;

auto create_random_array() {
  std::array<int, 8> out;
  for (auto& elem : out) {
    elem = rand() % 20;
  }
  return out;
}


int main() {

  auto array = create_random_array();

  copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
  cout << std::endl;

  selection_sort(array);

  copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
  cout << std::endl;

  auto heap_array = create_random_array();

  copy(heap_array.begin(), heap_array.end(), ostream_iterator<int>(cout, " "));
  cout << std::endl;

  heap_sort(heap_array.begin(), heap_array.end());

  copy(heap_array.begin(), heap_array.end(), ostream_iterator<int>(cout, " "));
  cout << std::endl;

  return 0;
}
