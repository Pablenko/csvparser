#include <chrono>
#include <cstdlib>
#include <experimental/filesystem>
#include <thread>
#include <mutex>
#include <memory>
#include <condition_variable>

#include "calculator.hpp"
#include "common.hpp"
#include "parser.hpp"
#include "reader.hpp"
#include "reporter.hpp"

namespace fs = std::experimental::filesystem;

int main(int argc, const char** argv)
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
    csv_parser::record_calculator calculator;

    std::thread t(csv_parser::file_reader_thread, std::ref(m), std::ref(cv), file_location, std::ref(data));
    bool create_report = false;
    std::unique_ptr<csv_parser::reporter> reporter(new csv_parser::console_reporter());

    while(1)
    {
        std::unique_lock<std::mutex> lock(m);
        auto now = std::chrono::system_clock::now();
        cv.wait_until(lock, now + std::chrono::seconds(1), [&]() { return !data.empty(); });

        create_report = !data.empty();

        for(const auto& elem : csv_parser::transform_queue(data))
        {
            calculator.update_report(elem);
        }

        if(create_report)
        {
            reporter->report(calculator.get_new_amount(), calculator.get_summary());
        }

        lock.unlock();
        cv.notify_one();
    }

    t.join();
}
