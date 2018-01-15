#ifndef CSV_PARSER_RECORD_HPP
#define CSV_PARSER_RECORD_HPP

#include <ostream>
#include <string>

namespace csv_parser
{

struct record
{
    struct r_date
    {
        unsigned int year;
        unsigned short month;
        unsigned short day;
        unsigned short hour;
        unsigned short minutes;
        unsigned short seconds;
    };
    r_date date;
    std::string source_account, dest_account;
    float ammount;
};

inline bool operator==(const record::r_date& lhs, const record::r_date& rhs)
{
    return lhs.year == rhs.year &&
           lhs.month == rhs.month &&
           lhs.day == rhs.day &&
           lhs.hour == rhs.hour &&
           lhs.minutes == rhs.minutes &&
           lhs.seconds == rhs.seconds;
}

inline bool operator!=(const record::r_date& lhs, const record::r_date& rhs)
{
    return not (lhs == rhs);
}

inline bool operator==(const record& lhs, const record& rhs)
{
    return lhs.date == rhs.date &&
           lhs.source_account == rhs.source_account &&
           lhs.dest_account == rhs.dest_account &&
           lhs.ammount == rhs.ammount;
}

inline bool operator!=(const record& lhs, const record& rhs)
{
    return not (lhs == rhs);
}

std::ostream& operator <<(std::ostream& str, const record& r);

std::ostream& operator <<(std::ostream& str, const record::r_date& d);

} // namespace csv_parser

#endif