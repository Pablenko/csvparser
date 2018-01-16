#ifndef CSV_PARSER_READER_HPP
#define CSV_PARSER_READER_HPP

#include <experimental/filesystem>
#include <fstream>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace csv_parser
{

void file_reader_thread(std::mutex& m, std::condition_variable& cv, const std::experimental::filesystem::path& path,
    std::queue<std::string>& q);

class file_reader
{
public:
    file_reader(const std::experimental::filesystem::path& path, std::queue<std::string>& sink) :
        source(path), sink(sink), path(path), last_time_write()
    {}

    void read();

    bool ready();

private:
    std::ifstream source;
    std::queue<std::string>& sink;
    std::experimental::filesystem::path path;
    std::experimental::filesystem::file_time_type last_time_write;
};

} // namespace csv_parser

#endif
