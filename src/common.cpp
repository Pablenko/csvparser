#include "common.hpp"
#include "parser.hpp"

namespace csv_parser
{

std::string parse_user_input(int argc, const char** argv)
{
    if(argc < 2)
    {
        std::string ret;
        std::cout << "Please provide csv file location: \n";
        std::cin >> ret;
        return ret;
    }
    else
    {
        return argv[1];
    }
}

std::vector<record> transform_queue(std::queue<std::string>& q)
{
    std::vector<record> ret;
    while(!q.empty())
    {
        auto opt = parse_line(q.front());
        if(opt.has_value())
        {
            ret.push_back(*opt);
        }
        q.pop();
    }
    return ret;
}

} // namespace csv_parser
