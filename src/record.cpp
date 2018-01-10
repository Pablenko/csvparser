#include <iomanip>

#include "record.hpp"

namespace csv_parser
{

std::ostream& operator <<(std::ostream& str, const record& r)
{
    str << "\nDate: \n";
    str << "    year:    "     << std::setw(10) << r.date.year << "\n";
    str << "    month:   "     << std::setw(10) << r.date.month << "\n";
    str << "    day:     "     << std::setw(10) << r.date.day << "\n";
    str << "    hour:    "     << std::setw(10) << r.date.hour << "\n";
    str << "    minutes: "     << std::setw(10) << r.date.minutes << "\n";
    str << "    seconds: "     << std::setw(10) << r.date.seconds << "\n";

    str << "Source account:      " << r.source_account << "\n";    
    str << "Destination account: " << r.dest_account << "\n";
    str << "Ammount: " << r.ammount << "\n";
    return str;
}

} // namespace csv_parser
