#ifndef CSV_PARSER_COMMON_HPP
#define CSV_PARSER_COMMON_HPP

#include <iostream>
#include <string>

namespace csv_parser
{

inline std::string parse_user_input(int argc, char** argv)
{
    if(argc < 2)
    {
        std::string ret;
        std::cout << "Please provide csv file location: \n";
        std::cin >> ret;
        return ret;
    }
    else
    {
        return argv[1];
    }
}

} // namespace csv_parser

#endif
