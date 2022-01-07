#pragma once

#include <algorithm>
#include <vector>

#include <cstdint>
#include <cstdlib>

/// Класс реализующий простой динамический контейнер.
/// Не доделан. Нет поддержки аллокаторов, итераторов, опараций копирования и перемещения.
/// Типы должны иметь конструктор по умолчанию (не забыть ассерт на T и multiplier).

template<typename T, std::size_t multiplier>
class simple_vector final {
public:
  typedef T value_type;

  simple_vector();
  simple_vector(const simple_vector&) = delete;
  simple_vector(simple_vector&&)      = delete;
  simple_vector& operator= (const simple_vector&) = delete;
  simple_vector& operator= (simple_vector&&)      = delete;

  void add(const T& elem);

  void remove_last();

  void insert(const T& elem, std::size_t index);
  std::size_t size();
  void remove(std::size_t index);
  T &get(std::size_t index);

private:
  bool need_resize();

  std::size_t size_;     ///< Количетсво элементов.
  std::size_t capacity_; ///< Выделенная память.
  T*          mem_;      ///< Указатель на выделенную память.
};


template <typename T, std::size_t multiplier>
simple_vector<T, multiplier>::simple_vector()
 : size_{}, capacity_{}, mem_{} {
}


template <typename  T, std::size_t multiplier>
bool simple_vector<T, multiplier>::need_resize() {
  return size_ + 1 > capacity_;
}


template <typename T, std::size_t multiplier>
void simple_vector<T, multiplier>::add(const T &elem) {
  if (need_resize()) {
    capacity_ = size_ * multiplier + 1;
    auto new_mem = new T[capacity_];
    std::move(mem_, mem_ + size_, new_mem);
    delete[] mem_;
    mem_ = new_mem;
  }
  mem_[size_++] = elem;
}


template <typename T, std::size_t multiplier>
void simple_vector<T, multiplier>::remove_last() {
  --size_;
}


template <typename T, std::size_t multiplier>
void simple_vector<T, multiplier>::insert(const T& elem, std::size_t index) {
  if (need_resize()) {
    capacity_ = size_ * multiplier + 1;
    auto new_mem = new T[capacity_];
    std::move_backward(mem_ + index, mem_ + size_, new_mem + ++size_);
    new_mem[index] = elem;
    delete[] mem_;
    mem_ = new_mem;
  } else {
    std::move_backward(mem_ + index, mem_ + size_, mem_ + ++size_);
    mem_[index] = elem;
  }
}


template <typename T, std::size_t multiplier>
void simple_vector<T, multiplier>::remove(std::size_t index) {
  std::move(mem_ + index + 1, mem_ + size_, mem_ + index);
  --size_;
}


template <typename T, std::size_t multiplier>
T& simple_vector<T, multiplier>::get(std::size_t index) {
  return mem_[index];
}


template <typename T, std::size_t multiplier>
std::size_t simple_vector<T, multiplier>::size() {
  return size_;
}



///@brief Класс упрощённой std::deque.
template<typename T, std::size_t N>
class matrix_array final {
public:
  matrix_array()                               = default;
  matrix_array(const matrix_array&)            = delete;
  matrix_array(matrix_array&&) = delete;
  matrix_array& operator=(const matrix_array&) = delete;
  matrix_array& operator=(matrix_array&&)      = delete;

  void insert(const T& elem, std::size_t pos);
  void remove(std::size_t pos);

  std::size_t size();
  T& get(std::size_t index);

private:
  std::size_t size_{};                   ///< Количество занятых элементов.
  simple_vector<std::vector<T>, 2> map_; ///< Матрица.
};


template <typename T, std::size_t N>
void matrix_array<T, N>::insert(const T& elem, std::size_t pos) {
  if (size_ == map_.size() * N) {
    map_.add(std::vector<T>(N));
  }
  
  for (auto end = size_; end > pos; --end) {
    map_.get(end / N)[end % N] = std::move_if_noexcept(map_.get((end - 1) / N )[(end - 1) % N ]);
  }

  map_.get(pos / N)[pos % N] = elem;
  ++size_;
}


template <typename T, std::size_t N>
void matrix_array<T, N>::remove(std::size_t pos) {
  for (auto beg = pos; beg < size_ - 1; ++beg) {
    map_.get(beg / N)[beg % N] = std::move_if_noexcept(map_.get((beg + 1) / N)[(beg + 1) % N]);
  }

  if (--size_ == map_.size() * N) {
    map_.remove_last();
  }
}


template<typename T, std::size_t N>
std::size_t matrix_array<T, N>::size() {
  return size_;
}


template<typename  T, std::size_t N>
T &matrix_array<T, N>::get(std::size_t index) {
  return map_.get(index / N)[index % N];
}
