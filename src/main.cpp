#include <cstdlib>
#include <experimental/filesystem>
#include <queue>
#include <iostream>
#include <thread>

#include "parser.hpp"
#include "reader.hpp"
#include "reporter.hpp"

namespace fs = std::experimental::filesystem;

int main()
{
    fs::path file_location;

    std::cout << "Please provide csv file location: \n";
    std::cin >> file_location;

    if(!fs::exists(file_location))
    {
        std::cerr << "Error! Improper file location!\n";
        std::exit(1);
    }

    std::queue<std::string> data;
    
    std::thread t([&] () { csv_parser::file_reader reader(file_location, data); reader.read();});
    t.join();

    while(!data.empty())
    {
        std::string& elem = data.front();
        std::cout << elem << "\n";
        data.pop();
    }
}
