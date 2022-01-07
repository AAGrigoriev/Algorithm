#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>

#include "task.hpp"


namespace  test_system {

namespace  {
  std::filesystem::path create_file_name(const std::filesystem::path& path, std::size_t number, std::string_view in_out) {
    return path / ("test." + std::to_string(number) + std::string{in_out});
  }
}



class tester final {
public:
  template<typename Task>
  void run(const std::filesystem::path& path, const i_task<Task>& task) {
    if (std::filesystem::is_directory(path)) {
      std::size_t count{};
      std::filesystem::path in_file  = create_file_name(path, count, ".in");
      std::filesystem::path out_file = create_file_name(path, count, ".out");
      // todo: Iterator
      while (std::filesystem::exists(in_file) && std::filesystem::exists(out_file)) {
        std::ifstream in{in_file};
        std::ifstream out{out_file};
        if (in.is_open() && out.is_open()) {
          std::string data;
          std::string result;
          in  >> data;
          out >> result;
          if (task.run(data) == result) {
            std::cout << "test №" << count << " passed" << std::endl;
          }
        }
        ++count;
        in_file  = create_file_name(path, count, ".in");
        out_file = create_file_name(path, count, ".out");
      }
    }
  }
};
}
