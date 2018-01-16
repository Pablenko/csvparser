#ifndef CSV_PARSER_CALCULATOR_HPP
#define CSV_PARSER_CALCULATOR_HPP

#include <string>
#include <utility>
#include <vector>

#include "record.hpp"

namespace csv_parser
{

class record_calculator
{
public:
    typedef std::pair<std::string, float> account_summary;

    record_calculator() : new_ammount(0), summary() {}

    void update_report(const record& new_record);

    float get_new_amount();

    std::vector<account_summary>& get_summary();

private:
    float new_ammount;
    std::vector<account_summary> summary;
};

} // namespace csv_parser

#endif
