#include <bitset>
#include <iostream>

#include "count_bits.hpp"
#include "bitboard_calculation.hpp"

using namespace std;

int main()
{
    cout << rook_position(53)   << std::endl;
    cout << cahs_count_bits(rook_position(53)) << std::endl;

    cout << rook_position(11)   << std::endl;
    cout << cahs_count_bits(rook_position(11)) << std::endl;

    cout << rook_position(33)   << std::endl;
    cout << cahs_count_bits(rook_position(33)) << std::endl;

    cout << knight_position(8)  << std::endl;
    cout << cahs_count_bits(knight_position(8)) << std::endl;

    cout << knight_position(23) << std::endl;
    cout << cahs_count_bits(knight_position(23)) << std::endl;

    cout << knight_position(59) << std::endl;
    cout << cahs_count_bits(knight_position(59)) << std::endl;

    cout << knight_position(4) << std::endl;
    cout << cahs_count_bits(knight_position(4)) << std::endl;

    cout << king_position(1)  << std::endl;
    cout << cahs_count_bits(king_position(1)) << std::endl;

    cout << king_position(56) << std::endl;
    cout << cahs_count_bits(king_position(56)) << std::endl;

    cout << king_position(55) << std::endl;
    cout << cahs_count_bits(king_position(55)) << std::endl;

    cout << king_position(15) << std::endl;
    cout << cahs_count_bits(king_position(15)) << std::endl;

    return 0;
}
