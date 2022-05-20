#include <iostream>
#include <cstddef>
#include <math.h>

using namespace std;

long karatsuba_mult(long x, long y) {
  const auto x_len = static_cast<unsigned>(std::log10(x)) + 1;
  const auto y_len = static_cast<unsigned>(std::log10(y)) + 1;
  auto max_len = x_len > y_len ? x_len : y_len;
  if (max_len == 1) {
    return x * y;
  } else {
    if (max_len % 2 != 0) {
        max_len +=  1;
    }
    const auto pow = std::pow(10, max_len / 2);
    const auto a = x / static_cast<long>(pow);
    const auto b = x % static_cast<long>(pow);
    const auto c = y / static_cast<long>(pow);
    const auto d = y % static_cast<long>(pow);

    const auto a_c = karatsuba_mult(a, c);
    const auto b_d = karatsuba_mult(b, d);

    const auto a_b_c_d = karatsuba_mult(a + b, c + d);
    const auto a_d_plus_b_c = a_b_c_d - a_c - b_d;
    return std::pow(10, max_len) * a_c + pow * (a_d_plus_b_c) + b_d;
  }
}


int main() {
    std::cout << "result = " << karatsuba_mult(5678, 1234) << std::endl;

    return 0;
}
