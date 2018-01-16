#include <gtest/gtest.h>

#include "common.hpp"

namespace csv_parser
{

TEST(common_tests, parse_user_input)
{
    const char* input[2] = {"program", "/home/user/file.csv"};
    EXPECT_EQ(std::string("/home/user/file.csv"), parse_user_input(2, input));
}

TEST(common_tests, transform_queue)
{
    std::queue<std::string> q;
    q.push(std::string("2016.11.02T13:15:24, 11 2222 3333 4444 5555 6666 7777, 77 6666 5555 4444 3333 2222 1111, 21.41"));
    q.push(std::string("wrong line"));

    auto ret = transform_queue(q);
    EXPECT_EQ(1, ret.size());
    EXPECT_FLOAT_EQ(21.41, ret[0].ammount);
}

} // namespace csv_parser
