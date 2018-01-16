#ifndef CSV_PARSER_COMMON_HPP
#define CSV_PARSER_COMMON_HPP

#include <queue>
#include <iostream>
#include <string>
#include <vector>

#include "record.hpp"

namespace csv_parser
{

std::string parse_user_input(int argc, const char** argv);

std::vector<record> transform_queue(std::queue<std::string>& q);

} // namespace csv_parser

#endif
