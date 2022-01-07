#include <iostream>
#include "fibonacci.hpp"
#include "pow.hpp"
#include "prime.hpp"
#include "simple_matrix.hpp"

using namespace std;

int main()
{

  simple_matrix<int> m(2, 2);

  m[0][0] = 1;
  m[0][1] = 1;
  m[1][0] = 1;
  m[1][1] = 0;

  simple_matrix<int> m1(2, 2);

  m1[0][0] = 1;
  m1[0][1] = 1;
  m1[1][0] = 1;
  m1[1][1] = 0;

  auto m3 = mult_matrix(m, m1);

  for (auto i = 0; i < 2; ++i) {
    for (auto j = 0; j < 2; ++j) {
      std::cout << m3[i][j] << std::endl;
    }
  }
  std::cout << endl;

  auto m4 = matrix_pow(m, 2);

  for (auto i = 0; i < 2; ++i) {
    for (auto j = 0; j < 2; ++j) {
      std::cout << m4[i][j] << std::endl;
    }
  }

  std::cout << endl;

  auto m5 = matrix_fibonacci(7);

  std::cout << "7 fibbo = " << m5 << std::endl;

 return 0;
}
