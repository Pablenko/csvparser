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

TEST(parser_tests, parse_float_test)
{
    float res = 0.0;
    parse_float(std::string("20.45"), res);

    EXPECT_FLOAT_EQ(20.45, res);
}

TEST(parser_tests, parse_date_test)
{
    record::r_date expected_date =
    {
        1901,
        7,
        18,
        1,
        32,
        46
    };
    record::r_date actual_date = {};
    parse_date(std::string("1901:07:18T01:32:46"), actual_date);

    EXPECT_EQ(expected_date, actual_date);
}

TEST(parser_tests, parse_account_number_test)
{
    std::string actual;
    unsigned int pos = parse_account_number(std::string("112222 33334444 5555 6666 7777,"), actual);

    EXPECT_EQ(std::string("112222 33334444 5555 6666 7777"), actual);
    EXPECT_EQ(std::string("112222 33334444 5555 6666 7777").length(), pos);
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
    
    EXPECT_EQ(expected, *parse_line(input));
}

TEST(parser_test, empty_optional_for_wrong_date_format)
{
    auto ret1 = parse_line(std::string("201.11.02T13:15:24, 11 2222 3333 4444 5555 6666 7777, 77 6666 5555 4444 3333 2222 1111, 21.41"));
    auto ret2 = parse_line(std::string("2017.1.02T13:15:24, 11 2222 3333 4444 5555 6666 7777, 77 6666 5555 4444 3333 2222 1111, 21.41"));
    auto ret3 = parse_line(std::string("2017.1.02T:15:24, 11 2222 3333 4444 5555 6666 7777, 77 6666 5555 4444 3333 2222 1111, 21.41"));

    EXPECT_FALSE(ret1.has_value());
    EXPECT_FALSE(ret2.has_value());
    EXPECT_FALSE(ret3.has_value());
}

TEST(parser_test, empty_optional_for_wrong_account_number_format)
{
    auto ret1 = parse_line(std::string("2016.11.02T13:15:24, 11 2222 3333 5555 6666 7777, 77 6666 5555 4444 3333 2222 1111, 21.41"));
    auto ret2 = parse_line(std::string("2016.11.02T13:15:24, 11 2222 3333 4444 5555 6666 77778, 77 6666 5555 4444 3333 2222 1111, 21.41"));
    auto ret3 = parse_line(std::string("2016.11.02T13:15:24, 11 2222 3333 4444 5555 6666 7777, 77 6666 555 4444 3333 2222 1111, 21.41"));

    EXPECT_FALSE(ret1.has_value());
    EXPECT_FALSE(ret2.has_value());
    EXPECT_FALSE(ret3.has_value());
}

TEST(parser_test, corrupted_line_is_ignored)
{
    auto ret1 = parse_line(std::string("a2016.11.02T13:15:24, 11 2222 3333 4444 5555 6666 7777, 77 6666 5555 4444 3333 2222 1111, 21.41"));
    auto ret2 = parse_line(std::string("2016.11.02T13:15:24, 11 2222 3333 4444 5555 6666 7777, 77 6666 5555 4444 3333 2222 1111, 21.41$"));

    EXPECT_FALSE(ret1.has_value());
    EXPECT_FALSE(ret2.has_value());
}

} // namespace csv_parser
