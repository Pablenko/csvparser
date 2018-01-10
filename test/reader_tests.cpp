#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "parser.hpp"

namespace csv_parser
{

TEST(parser_tests, white_space_in_account_number_matters)
{
    record r1 = {
        {
            2016,
            11,
            2,
            13,
            15,
            24
        },
        "11 2222 3333 4444 5555 6666 7777",
        "77 6666 5555 4444 3333 2222 1111",
        21.41
    };

    record r2 = {
        {
            2016,
            11,
            2,
            13,
            15,
            24
        },
        "112222 3333 4444 5555 6666 7777",
        "77 6666 5555 4444 3333 2222 1111",
        21.41
    };

    record r3 = {
        {
            2016,
            11,
            2,
            13,
            15,
            24
        },
        "11 2222 3333 4444 5555 6666 7777",
        "77 6666 5555 4444 3333 22221111",
        21.41
    };

    EXPECT_NE(r1, r2);
    EXPECT_NE(r1, r3);
}

TEST(parser_tests, parse_line_test)
{
    std::string input = "2016.11.02T13:15:24, 11 2222 3333 4444 5555 6666 7777, 77 6666 5555 4444 3333 2222 1111, 21.41";
    record expected = {
        {
            2016,
            11,
            2,
            13,
            15,
            24
        },
        "11 2222 3333 4444 5555 6666 7777",
        "77 6666 5555 4444 3333 2222 1111",
        21.41
    };
    
    EXPECT_EQ(expected, parse_line(input));
}

} // namespace csv_parser
