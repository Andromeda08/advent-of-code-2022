#pragma once

#include <Common.hpp>
#include <numeric>

namespace Day3
{
    void part_1()
    {
        auto input = Common::read_input("input_day3.txt");

        auto get_result = [](int sum, const std::string& str) {
            auto c0 = str.substr(0, str.length() / 2);
            auto c1 = str.substr(str.length() / 2, str.length());

            std::sort(c0.begin(), c0.end());
            std::sort(c1.begin(), c1.end());

            std::string item;
            std::set_intersection(c0.begin(), c0.end(), c1.begin(), c1.end(), std::back_inserter(item));

            if (item[0] <= 'Z') sum += (item[0] - 38);
            if (item[0] >= 'a') sum += (item[0] - 96);

            return sum;
        };

        int result = std::accumulate(std::begin(input), std::end(input), 0, get_result);

        std::cout << result << std::endl;
    }

    void part_2()
    {
        auto input = Common::read_input("input_day3.txt");
        auto it = std::begin(input);

        int result = 0;
        while (it != std::end(input)) {
            auto a = *it++;
            std::sort(a.begin(), a.end());

            auto b = *it++;
            std::sort(b.begin(), b.end());

            auto c = *it++;
            std::sort(c.begin(), c.end());

            std::string ab;
            std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(ab));

            std::string abc;
            std::set_intersection(ab.begin(), ab.end(), c.begin(), c.end(), std::back_inserter(abc));

            if (abc[0] <= 'Z') result += (abc[0] - 38);
            if (abc[0] >= 'a') result += (abc[0] - 96);
        }

        std::cout << result << std::endl;
    }
}