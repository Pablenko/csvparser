#ifndef CSV_PARSER_PARSER_HPP
#define CSV_PARSER_PARSER_HPP

#include <string>
#include <vector>

#include "record.hpp"

namespace csv_parser
{

record parse_line(std::string line);

} // namespace csv_parser

#endif
