#include <iostream>
#include <thread>

#include "report.hpp"
#include "reader.hpp"

int main()
{
    csv_parser::read();
    csv_parser::create_report();

    std::thread t([](){std::cout << "init";});
    t.join();
}