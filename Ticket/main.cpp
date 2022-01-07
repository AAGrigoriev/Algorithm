#include <filesystem>
#include <iostream>


#include "tester.hpp"

using namespace std;

int main()
{
    test_system::tester tester;

    std::cout << std::numeric_limits<unsigned long long>::max() << std::endl;
    //tester.run(filesystem::current_path() / "0.String",  test_system::string_task{});
    tester.run(filesystem::current_path() / "2.Tickets", test_system::tickets_task{});
    return 0;
}
