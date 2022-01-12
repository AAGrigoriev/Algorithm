#include <cstdlib>
#include <iostream>
#include <vector>

#include "simple_sort.hpp"

using namespace std;

auto get_random_vector() {
  std::vector<int> out;
  for (auto i = 0; i < 10; ++i) {
    out.push_back(std::rand() % 100);
  }
  return out;
}


int main() {

  auto bubble_vec = get_random_vector();
  std::copy(bubble_vec.begin(), bubble_vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  bubble_sort(bubble_vec.begin(), bubble_vec.end());

  std::copy(bubble_vec.begin(), bubble_vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;


  auto insert_vec = get_random_vector();
  std::copy(insert_vec.begin(), insert_vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  insert_sort(insert_vec.begin(), insert_vec.end());

  std::copy(insert_vec.begin(), insert_vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;


  auto fast_insert_vec = get_random_vector();
  std::copy(fast_insert_vec.begin(), fast_insert_vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  fast_insert_sort(fast_insert_vec.begin(), fast_insert_vec.end());

  std::copy(fast_insert_vec.begin(), fast_insert_vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  auto shell_sort_vec = get_random_vector();
  std::copy(shell_sort_vec.begin(), shell_sort_vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  auto comp = [](auto f, auto s) {
    return f < s;
  };
  shell_sort(shell_sort_vec.begin(), shell_sort_vec.end(), comp);

  std::copy(shell_sort_vec.begin(), shell_sort_vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  return 0;
}
