#include "bitboard_calculation.hpp"
#include <iostream>

std::uint64_t king_position(std::size_t start_pos) {
  std::uint64_t out = 1UL << start_pos;
  // Из за того, что есть запретные зоны переходов. Для короля это столбец A и H.
  // Из столбца А нужно заблокировать переходы влево, а из столбца H - вправо.

  std::uint64_t noKingH = out & 0x7f7f7f7f7f7f7f7f;
  std::uint64_t noKingA = out & 0xfefefefefefefefe;

  return (noKingA << 7) | (out << 8) | (noKingH << 9) |
               (noKingA >> 1) | (noKingH << 1) |
         (noKingA >> 9) | (out >> 8) | (noKingH >> 7);
}


std::uint64_t knight_position(std::size_t start_pos) {
  std::uint64_t out = 1UL << start_pos;
  // У коня более широкий закрытый диапазон. Нужно блокировать 2 столбца.
  // У сдивгов 6 и 10 блокируются 2 столбца. Так как конь находясь на предпоследней уже выходит из доски.
  // Только сделаем наоборот, сначала сделаем сдвиг, потом обрежем лишние позиции.

  auto noKnightA  = 0xfefefefefefefefe;
  auto noKnightAB = 0xfcfcfcfcfcfcfcfc;
  auto noKnightH  = 0x7f7f7f7f7f7f7f7f;
  auto noKnightGH = 0x3f3f3f3f3f3f3f3f;

  return noKnightH  & (out << 15 | out >> 17) |
         noKnightGH & (out << 6  | out >> 10) |
         noKnightAB & (out << 10 | out >> 6)  |
         noKnightA  & (out << 17 | out >> 15);
}


std::uint64_t rook_position(std::size_t start_pos) {
  // Для определения позиции ладьи нужно сдвинуть все биты на определённый row_offset = start_pos / 8 и column_offset = start_pos % 8;
  // И потом на пересечении убрать текущую позицию.
  std::uint64_t row_offset = start_pos / 8;
  std::uint64_t column_offset = start_pos % 8;
  std::uint64_t bottom_mask = 0xff;
  std::uint64_t left_mask   = 0x101010101010101;
  bottom_mask <<= row_offset * 8;
  left_mask   <<= column_offset;

  return bottom_mask ^ left_mask;
}
