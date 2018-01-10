#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "parser.hpp"

namespace csv_parser
{

TEST(reader_tests, parse_line_test)
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
