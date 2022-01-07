#pragma once

#include <cstdint>

///@brief Рассчитать все ходы от текущей позиции Короля.
std::uint64_t king_position(std::size_t start_pos);


///@brief Рассчитать все ходы от текущей позиции Коня.
std::uint64_t knight_position(std::size_t start_pos);


///@brief Рассчитать все ходы от текущей позиции Ладьи.
std::uint64_t rook_position(std::size_t start_pos);
