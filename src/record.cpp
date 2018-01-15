#include <iomanip>

#include "record.hpp"

namespace csv_parser
{

std::ostream& operator <<(std::ostream& str, const record::r_date& r)
{
    str << "\nDate: \n";
    str << "    year:    "     << std::setw(10) << r.year << "\n";
    str << "    month:   "     << std::setw(10) << r.month << "\n";
    str << "    day:     "     << std::setw(10) << r.day << "\n";
    str << "    hour:    "     << std::setw(10) << r.hour << "\n";
    str << "    minutes: "     << std::setw(10) << r.minutes << "\n";
    str << "    seconds: "     << std::setw(10) << r.seconds << "\n";
    return str;
}

std::ostream& operator <<(std::ostream& str, const record& r)
{
    str << r.date;

    str << "Source account:      " << r.source_account << "\n";    
    str << "Destination account: " << r.dest_account << "\n";
    str << "Ammount: " << r.ammount << "\n";
    return str;
}

} // namespace csv_parser
