#ifndef CSV_PARSER_READER_HPP
#define CSV_PARSER_READER_HPP

#include <string>
#include <vector>

#include "record.hpp"

namespace csv_parser
{

record parse_line(std::string line);

std::vector<record> read_new_records();

} // namespace csv_parser

#endif
