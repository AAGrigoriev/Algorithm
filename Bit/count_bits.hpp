#pragma once

#include <cstdint>

///@brief Итеративный алгоритм поиска количетсва единичных битов в числе.
///       Используя вычитание.
int count_bits(std::uint64_t number);


auto make_bit_array();


///@brief Алгоритм поиска количества единичных битов в числе с кешированием.
std::size_t cahs_count_bits(std::uint64_t number);
