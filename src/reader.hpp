#ifndef CSV_PARSER_READER_HPP
#define CSV_PARSER_READER_HPP

#include <fstream>
#include <queue>

namespace csv_parser
{

class file_reader
{
public:
    file_reader(const std::string& file_location, std::queue<std::string>& sink) : source(file_location), sink(sink)
    {}

    void read();

    bool ready();

private:
    std::ifstream source;
    std::queue<std::string>& sink;
};

} // namespace csv_parser

#endif
