#include <cstdlib>
#include <iostream>
#include <regex>
#include <sstream>

#include "parser.hpp"

namespace csv_parser
{

void parse_date(const std::string& str, record::r_date& d)
{
    char sink;
    std::stringstream ss(str);

    ss >> d.year >> sink >> d.month >> sink >> d.day >> sink >> 
          d.hour >> sink >> d.minutes >> sink >> d.seconds;
}

unsigned int parse_account_number(const std::string& str, std::string& acc)
{
    unsigned int colon_pos = str.find(",");
    acc = str.substr(0, colon_pos);
    return colon_pos;
}

void parse_float(const std::string& str, float& f)
{
    f = std::atof(str.c_str());
}

std::optional<record> parse_line(std::string line)
{
    const unsigned int first_acc_pos = 21;
    const unsigned int colon_ws_size = 2;

    std::regex csv_line_re("[0-9]{4}.[0-9]{2}.[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}, [0-9]{2}(\\s?[0-9]{4}){6}, [0-9]{2}(\\s?[0-9]{4}){6}, [0-9]+.[0-9]+");
    std::smatch match_result;

    bool ret = std::regex_search(line, match_result, csv_line_re);

    if(ret && match_result.str().length() == line.length())
    {
        record r;
        parse_date(line, r.date);
        unsigned int second_acc_pos = parse_account_number(line.substr(first_acc_pos), r.source_account);
        unsigned int float_pos = parse_account_number(line.substr(first_acc_pos+second_acc_pos+colon_ws_size), r.dest_account);
        parse_float(line.substr(first_acc_pos+second_acc_pos+float_pos+2*colon_ws_size), r.ammount);
        return std::make_optional(r);
    }
    else
    {
        return {};
    }
}

} // namespace csv_parser
