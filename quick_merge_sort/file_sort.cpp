#include "file_sort.hpp"

#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <vector>


void memory_sort(std::filesystem::path in, std::size_t left, std::size_t right) {
  std::ifstream in_file(in);
  std::ofstream out_file(std::to_string(left) + std::to_string(right));

  in_file.seekg(left * sizeof (uint32_t));
  auto count = right - left + 1;
  std::vector<uint32_t> buf(count);
  in_file.read(reinterpret_cast<char*>(buf.data()), count);
  std::sort(buf.begin(), buf.end());

  out_file.write(reinterpret_cast<char*>(buf.data()), buf.size());
  out_file.close();
  in_file.close();
}


void merge(std::size_t left_left, std::size_t left_right, std::size_t right_left, std::size_t right_right) {
  std::ifstream in_1(std::to_string(left_left) + std::to_string(left_right), std::ios::binary);
  std::ifstream in_2(std::to_string(right_left) + std::to_string(right_right), std::ios::binary);

  std::ofstream out(std::to_string(left_left) + std::to_string(right_right), std::ios::binary);

  std::uint32_t value_1, value_2;
  if (in_1.is_open() || in_2.is_open()) {
    in_1.read(reinterpret_cast<char*>(value_1), sizeof(value_1));
    in_2.read(reinterpret_cast<char*>(value_2), sizeof(value_2));
  } else {
    throw std::runtime_error("files");
  }

  do {
    if (value_1 < value_2) {
      out.write(reinterpret_cast<char*>(value_1), sizeof(value_1));
      in_1.read(reinterpret_cast<char*>(value_1), sizeof(value_1));
    } else {
      out.write(reinterpret_cast<char*>(value_2), sizeof(value_2));
      in_1.read(reinterpret_cast<char*>(value_2), sizeof(value_2));
    }
  } while (!in_1.eof() && !in_2.eof());

  while (!in_1.eof()) {
    out.write(reinterpret_cast<char*>(value_1), sizeof(value_1));
    in_1.read(reinterpret_cast<char*>(value_1), sizeof(value_1));
  }

  while (!in_2.eof()) {
    out.write(reinterpret_cast<char*>(value_2), sizeof(value_2));
    in_1.read(reinterpret_cast<char*>(value_2), sizeof(value_2));
  }

  in_1.close();
  in_2.close();
  out.close();
}


void sort_files(std::filesystem::path in, std::size_t left, std::size_t right, std::size_t minimal_numer_count) {
  if (right - left <= minimal_numer_count) {
    memory_sort(in, left, right);
  } else {
    auto cast_left_right = right - left;
    auto middle = (0 + cast_left_right ) / 2;
    sort_files(in, left, left + middle, minimal_numer_count);
    sort_files(in, left + middle + 1, right);
    merge(left, left + middle, left + middle + 1, right);
  }
}


