#include <algorithm>
#include <iostream>

#include "calculator.hpp"

namespace csv_parser
{

void record_calculator::update_report(const record& new_record)
{
    new_ammount += new_record.ammount;

    auto account_update_func = [&](const std::string& acc, float ammount) {
        auto iter = std::find_if(summary.begin(), summary.end(), [&](const auto& elem) { return elem.first == acc; });
        if(iter != summary.end())
        {
            (*iter).second += ammount;
        }
        else
        {
            summary.push_back(std::make_pair(acc, ammount));
        }
    };

    account_update_func(new_record.source_account, -new_record.ammount);
    account_update_func(new_record.dest_account, new_record.ammount);
    std::sort(summary.begin(), summary.end(), [](const auto& lhs, const auto& rhs) { return lhs.second > rhs.second; });
}

float record_calculator::get_new_amount()
{
    float ret = new_ammount;
    new_ammount = 0;
    return ret;
}

std::vector<record_calculator::account_summary>& record_calculator::get_summary()
{
    return summary;
}

} // namesace csv_parser
