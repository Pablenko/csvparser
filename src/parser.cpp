#include <regex>
#include <iostream>

#include "parser.hpp"

namespace csv_parser
{

record parse_line(std::string line)
{
    std::regex date_re("[0-9]{4}.[0-9]{2}.[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}");
    std::regex account_re("[0-9]{2}(\\s[0-9]{4}){6}");
    std::smatch match_result;

    if(std::regex_search(line, match_result, date_re))
    {
        std::cout << match_result.str() << "\n";
    }

    while(std::regex_search(line, match_result, account_re))
    {
        std::cout << match_result.str() << "\n";
        line = match_result.suffix();
    }

    return record();
}

std::vector<record> read_new_records()
{
    return std::vector<record>();
}

} // namespace csv_reader
