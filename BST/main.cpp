#include <iostream>
#include "bst.hpp"

using namespace std;

int main() {
  using namespace bst_tree;
  BST<int> bst_tree;

  for (std::size_t i = 0; i < 100; ++i) {
    bst_tree.insert(i);
  }

  for (std::size_t i = 99; i > 50; --i) {
    bst_tree.remove(i);
  }

  for (std::size_t i = 0; i <= 50; ++i) {
    std::cout << bst_tree.search(i)->val << std::endl;
  }

  return 0;
}
