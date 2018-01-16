#ifndef CSV_PARSER_PARSER_HPP
#define CSV_PARSER_PARSER_HPP

#include <string>
#include <optional>
#include <vector>

#include "record.hpp"

namespace csv_parser
{

void parse_date(const std::string& str, record::r_date& r);

unsigned int parse_account_number(const std::string& str, std::string& acc);

void parse_float(const std::string& str, float& f);

std::optional<record> parse_line(const std::string& line);

} // namespace csv_parser

#endif
