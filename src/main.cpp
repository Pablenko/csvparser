#include <chrono>
#include <cstdlib>
#include <experimental/filesystem>
#include <queue>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "common.hpp"
#include "parser.hpp"
#include "reader.hpp"
#include "reporter.hpp"

namespace fs = std::experimental::filesystem;

int main(int argc, char** argv)
{
    fs::path file_location = csv_parser::parse_user_input(argc, argv);

    if(!fs::exists(file_location))
    {
        std::cerr << "Error! Improper file location!\n";
        std::exit(1);
    }

    std::queue<std::string> data;
    std::mutex m;
    std::condition_variable cv;

    std::thread t(csv_parser::file_reader_thread, std::ref(m), std::ref(cv), file_location, std::ref(data));

    while(1)
    {
        std::unique_lock<std::mutex> lock(m);
        auto now = std::chrono::system_clock::now();
        cv.wait_until(lock, now + std::chrono::seconds(1), [&]() { return !data.empty(); });

        while(!data.empty())
        {
            std::string& elem = data.front();
            std::cout << elem << "\n";
            data.pop();
        }

        lock.unlock();
        cv.notify_one();
    }

    t.join();
}
