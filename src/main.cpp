#include <iostream>
#include <thread>

#include "report.hpp"
#include "parser.hpp"

int main()
{
    csv_parser::create_report();

    std::thread t([](){std::cout << "init";});
    t.join();
}