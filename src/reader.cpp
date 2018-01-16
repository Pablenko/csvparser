#include <iostream>

#include "reader.hpp"

namespace csv_parser
{

namespace fs = std::experimental::filesystem;

void file_reader_thread(std::mutex& m, std::condition_variable& cv, const fs::path& path, std::queue<std::string>& q)
{
    file_reader reader(path, q);

    while(1)
    {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [&](){ return reader.ready(); });

        reader.read();
        
        lock.unlock();
        cv.notify_one();
    }
}

void file_reader::read()
{
    source.seekg(last_pos, std::ios::beg);
    for(std::string line; std::getline(source, line); )
    {
        sink.push(std::move(line));
    }
    source.clear();
    source.seekg(0, std::ios::end);
    last_pos = source.tellg();
}

bool file_reader::ready()
{
    fs::file_time_type current_write_time = fs::last_write_time(path);
    if(current_write_time != last_time_write)
    {
        last_time_write = current_write_time;
        return true;
    }
    else
    {
        return false;
    }
}

} // namespace csv_parser
