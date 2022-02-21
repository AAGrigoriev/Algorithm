#pragma once

#include <filesystem>


///@biref Сортировка чисел в файле путем сортировки слиянием.
/// @param in - Сортируемый файл.
/// @param [left, right] - индексы чисел в файле [от 0 ... N], которые сортируются
/// @param minimal_numer_count - минимальный количество чисел, после которого включается алгоритм сортировки в памяти
void sort_files(std::filesystem::path in, std::size_t left, std::size_t right, std::size_t minimal_numer_count = 100);
