#ifndef CSV_PARSER_REPORTER_HPP
#define CSV_PARSER_REPORTER_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace csv_parser
{

class reporter
{
public:
    virtual void report(float new_ammount, const std::vector<std::pair<std::string, float>>& summary) = 0;
};

class console_reporter : public reporter
{
    virtual void report(float new_ammount, const std::vector<std::pair<std::string, float>>& summary)
    {
        std::cout << "Report: \n";
        std::cout << "   New ammount of money: " << std::fixed <<std::setprecision(2) << new_ammount << "\n";
        std::cout << "   Accounts balance: \n";
        for(const auto& elem : summary)
        {
            std::cout << "      Number: " << elem.first << ", balance: " << std::fixed <<std::setprecision(2) << elem.second << "\n";
        }
         std::cout << "\n";
    }
};

} // namespace csv_parser

#endif