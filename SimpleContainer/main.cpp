#include <iostream>

#include "simple_vector.hpp"


using namespace std;

int main() {

    simple_vector<int, 2> vec;

    vec.add(4);
    vec.insert(56, 0);

    std::cout << vec.get(0) << " " << vec.get(1) << std::endl;

    vec.remove(0);
    std::cout << vec.get(0) << " " << std::endl;

    std::cout <<"---------------" <<" matrix " << "-------------------------" << std::endl;

    matrix_array<int, 3> matrix;

    matrix.insert(1, 0);
    matrix.insert(2, 0);
    std::cout << matrix.size() << " " << matrix.get(0) << " " << matrix.get(1) << std::endl;

    matrix.remove(0);
    std::cout << matrix.size() << " " << matrix.get(0) << std::endl;

    return 0;
}
