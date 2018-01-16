#include <gtest/gtest.h>

#include "calculator.hpp"

namespace csv_parser
{

struct calculator_tests : public testing::Test
{
    calculator_tests() : r1{{}, "11 1111 1111 1111 1111 1111 1111", "22 2222 2222 2222 2222 2222 2222", 134.76},
                         r2{{}, "11 1111 1111 1111 1111 1111 1111", "22 2222 2222 2222 2222 2222 2222", 24.11},
                         r3{{}, "11 1111 1111 1111 1111 1111 1111", "33 3333 3333 3333 3333 3333 3333", 0.19}
    {}

    record r1;
    record r2;
    record r3;
};

TEST_F(calculator_tests, new_ammount_is_calculated)
{
    record_calculator calculator;

    calculator.update_report(r1);
    calculator.update_report(r2);

    EXPECT_FLOAT_EQ(134.76+24.11, calculator.get_new_amount());
}

TEST_F(calculator_tests, new_ammount_is_reseted)
{
    record_calculator calculator;

    calculator.update_report(r1);
    calculator.get_new_amount();

    EXPECT_FLOAT_EQ(0, calculator.get_new_amount());
}

TEST_F(calculator_tests, accounts_are_created_in_summary)
{
    record_calculator calculator;

    calculator.update_report(r1);

    EXPECT_EQ(std::string("22 2222 2222 2222 2222 2222 2222"), calculator.get_summary()[0].first);
    EXPECT_EQ(std::string("11 1111 1111 1111 1111 1111 1111"), calculator.get_summary()[1].first);
}

TEST_F(calculator_tests, results_are_sorted_descending)
{
    record_calculator calculator;

    calculator.update_report(r1);
    calculator.update_report(r2);
    calculator.update_report(r3);

    EXPECT_FLOAT_EQ(134.76+24.11, calculator.get_summary()[0].second);
    EXPECT_FLOAT_EQ(0.19, calculator.get_summary()[1].second);
    EXPECT_FLOAT_EQ(-(134.76+24.11+0.19), calculator.get_summary()[2].second);
}

} // namespace csv_parser
