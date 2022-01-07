#pragma once

#include <vector>
#include <assert.h>


///@brief Класс матрица. Реализован на двух std::vector.
/// Нужен только для реализации умножения матриц и Фиббоначи.
/// Т.е он не эффективен и не доработан.
template<typename T>
class simple_matrix {
public:
  using matrix_type = std::vector<std::vector<int>>;
  using size_type = matrix_type::size_type;
  static_assert (std::is_integral_v<T>, "Need integral type");

public:
  simple_matrix(std::size_t row, std::size_t col);
  
  std::vector<int>& operator[](std::size_t row_index);
  const std::vector<int>& operator[](std::size_t row_index) const;
  simple_matrix& operator=(const simple_matrix&);


  bool is_square_matrix();
  size_type row_count() const;
  size_type column_count() const;

private:
  std::vector<std::vector<int>> matrix_;
};


template<typename T>
simple_matrix<T>::simple_matrix(std::size_t count_row, std::size_t count_col) {
  matrix_.resize(count_row);
  for (auto& col : matrix_) {
    col.resize(count_col);
  }
}


template<typename T>
simple_matrix<T>& simple_matrix<T>::operator=(const simple_matrix& other) {
  assert(matrix_.size() == other.matrix_.size() && matrix_.front().size() == matrix_.front().size());

  for (size_type row{}; row < matrix_.size(); ++row) {
    for (size_type col{}; col < matrix_[row].size(); ++col) {
      matrix_[row][col] = other[row][col];
    }
  }
  return *this;
}


template<typename T>
std::vector<int>& simple_matrix<T>::operator[](std::size_t row_index) {
  return matrix_[row_index];
}


template<typename T>
const std::vector<int>& simple_matrix<T>::operator[](std::size_t row_index) const {
  return matrix_[row_index];
}


template <typename T>
typename simple_matrix<T>::size_type simple_matrix<T>::column_count() const {
  return matrix_.front().size();
}


template <typename T>
typename simple_matrix<T>::size_type simple_matrix<T>::row_count() const {
  return matrix_.size();
}


template <typename T>
bool simple_matrix<T>::is_square_matrix() {
  return matrix_.front().size() == matrix_.size();
}


template<typename T>
simple_matrix<T> mult_matrix(const simple_matrix<T>& first, const simple_matrix<T>& second) {
  using matrix = simple_matrix<T>;
  assert(first.column_count() == second.row_count());
  matrix out(first.row_count(), second.column_count());

  for (typename matrix::size_type i{}; i < first.row_count(); ++i) {
    for (typename matrix::size_type j{}; j < second.column_count(); ++j) {
      for (typename matrix::size_type k{}; k < first.column_count(); ++k) {
        out[i][j] += first[i][k] * second[k][j];
      }
    }
  }

  return out;
}


