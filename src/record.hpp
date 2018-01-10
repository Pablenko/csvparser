#ifndef CSV_PARSER_RECORD_HPP
#define CSV_PARSER_RECORD_HPP

#include <string>

namespace csv_parser
{

struct record
{
    struct record_date
    {
        unsigned int year;
        unsigned short month;
        unsigned short day;
        unsigned short hour;
        unsigned short minutes;
        unsigned short seconds;
    } date;
    std::string source_account, dest_account;
    float ammount;
};

inline bool operator==(const record& lhs, const record& rhs)
{
    return lhs.date.year == rhs.date.year &&
           lhs.date.month == rhs.date.month &&
           lhs.date.day == rhs.date.day &&
           lhs.date.hour == rhs.date.hour &&
           lhs.date.minutes == rhs.date.minutes &&
           lhs.date.seconds == rhs.date.seconds &&
           lhs.source_account == rhs.source_account &&
           lhs.dest_account == rhs.dest_account &&
           lhs.ammount == rhs.ammount;
}

} // namespace csv_parser

#endif