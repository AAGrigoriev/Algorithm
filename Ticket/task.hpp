#pragma once

#include <algorithm>
#include <charconv>
#include <cstddef>
#include <string>
#include <vector>
#include <iostream>


namespace test_system  {

template<typename T>
class i_task {
public:
  std::string run(const std::string& data) const {
    return static_cast<const T*>(this)->run(data);
  }
};

class string_task final : public i_task<string_task> {
public:
  std::string run(const std::string& data) const {
    return std::to_string(data.length());
  }
};


class tickets_task final : public i_task<tickets_task> {
public:
  std::string run(const std::string& data) const {
    int result{};

    auto [ptr, ec] { std::from_chars(data.data(), data.data() + data.size(), result) };
    if (ec == std::errc() && result > 0) {
      return std::to_string(run_impl(result));
    }
    return {};
  }
private:
//   Таблица. Для 1 значного билета ( x | x).
//     0 1 2 3 4 5 6 7 8 9 <- левая/правая часть билета  ( [0..9] | [0..9] )
//   0 1                              1
//   1   1                            1
//   2     1                          1
//   3       1                        1
//   4         1 -- количество        1 <-- сумма левой/правой части.
//   5           1                    1
//   6             1                  1
//   7               1                1
//   8                 1              1
//   9                   1            1
//   |
// максимальная сумма в левой/правой части.

  unsigned long long run_impl(std::size_t ticket_size) const {
    // Пример: Для поиска двухзначных билетов будет максимальная полусумма -> 18. (99|99)
    // Получатеся двумерный динамический вектор с полусуммами. Для левой или правой стороны.
    // 9 - В билете могут быть цифры от 1 до 9. Отсюда и 9-ка.
    std::vector<std::vector<std::uint64_t>> matrix(ticket_size);
    using index_type = std::vector<std::vector<std::uint32_t>>::size_type;
    // Максимальная цифра в любой позиции билета. Это 9-ка.
    int max_ticket_number = 9;
    // Выделим сразу память под все объекты.
    for (index_type i{}; i < ticket_size; ++i) {
      matrix[i].resize(max_ticket_number * (i + 1) + 1);
    }

    // Заполняем полусуммы для однозначного билтета. ( x|x )
    for (index_type i{}; i <= max_ticket_number; ++i) {
      matrix[0][i] = 1;
    }

    // Цикл по n значным билетам. Начинаем с 1 - двухзначный.
    for (index_type i = 1; i < ticket_size; ++i) {
      // Второй цикл доходит до максимальной суммы n значного билета.
      // Для каждого n значного билета нужно рассчитать суммы. От 0 до (i + 1) * 9.
      for (int j = 0; j <= (i + 1) * max_ticket_number; ++j) {
        // Если смотреть на это как на таблицу, то нужно рассчитывать в таком виде.
        for (index_type k = 0; k <= max_ticket_number; ++k) {
          if (j - k >= 0 && j - k <= i * max_ticket_number) {
            matrix[i][j] += matrix[i - 1][j - k];
          }
        }
      }
    }

    // Получив левую/правую полусумму, можно рассчитать общее количество билетов.
    unsigned long long count_tickets{};
    for (index_type i{}; i <= ticket_size * max_ticket_number; ++i) {
      //std::cout << " i = " << i << "matrix = " << matrix[ticket_size - 1][i] << std::endl;
      count_tickets += matrix[ticket_size - 1][i] * matrix[ticket_size - 1][i];
    }
    std::cout << count_tickets << std::endl;
    return count_tickets;
  }
};

}
