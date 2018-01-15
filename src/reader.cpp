#include "reader.hpp"

namespace csv_parser
{

void file_reader::read()
{
    for(std::string line; std::getline(source, line); )
    {
        sink.push(std::move(line));
    }
}

bool file_reader::ready()
{
    return true;
}

} // namespace csv_parser
