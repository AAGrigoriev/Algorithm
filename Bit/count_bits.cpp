#include "count_bits.hpp"

#include <array>
#include <bitset>

///@brief Итеративный алгоритм поиска количетсва единичных битов в числе.
///       Используя вычитание.
int count_bits(std::uint64_t number) {
  int out{};
  while (number > 0) {
    number &= (number - 1);
    ++out;
  }

  return out;
}


auto make_bit_array() {
  std::array<std::uint8_t, 256> out;
  for (auto i = 0u; i < 256; ++i) {
    out[i] = count_bits(i);
  }
  return out;
}


///@brief Алгоритм поиска количества единичных битов в числе с кешированием.
/// std::popcount доступна в  с++20 или std::bitset.
/// Просто учебный вариант.
std::size_t cahs_count_bits(std::uint64_t number) {
  static auto cash = make_bit_array(); // Количетсво единиц в каждом числе от 0 до 255 (FF);
  return cash[number & 0XFF] +
         cash[(number >> 8) & 0XFF]  +
         cash[(number >> 16) & 0XFF] +
         cash[(number >> 24) & 0XFF] +
         cash[(number >> 32) & 0XFF] +
         cash[(number >> 40) & 0XFF] +
         cash[(number >> 48) & 0XFF] +
         cash[(number >> 56) & 0XFF];
}
