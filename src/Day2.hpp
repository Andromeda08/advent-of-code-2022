#pragma once

#include <Common.hpp>
#include <numeric>
#include <set>
#include <unordered_map>

namespace Day2
{
    void part_1()
    {
        auto input = Common::read_input("input_day2.txt");

        std::unordered_map<char, char> wins {
            { 'X', 'C' }, { 'Y', 'A' }, { 'Z', 'B' }
        };

        auto get_result = [wins](int sum, const std::string& str) {
            sum += str[2] - 87;

            if ((char)(str[2] - 23) == str[0]) sum += 3;
            if (wins.at(str[2])     == str[0]) sum += 6;

            return sum;
        };

        auto result = std::accumulate(std::begin(input), std::end(input), 0, get_result);

        std::cout << "Score: " << result << std::endl;
    }

    void part_2()
    {
        auto input = Common::read_input("input_day2.txt");
        std::unordered_map<char, char> maps {
            { 'C', 'X' }, { 'A', 'Y' }, { 'B', 'Z' }
        };

        auto get_result = [maps](int sum, const std::string& str) {
            std::set<char> loser_pick = { 'X', 'Y', 'Z' };
            char pick = 0;

            switch (str[2])
            {
                case 'X':
                    loser_pick.erase((char)(str[0] + 23));
                    loser_pick.erase(maps.at(str[0]));
                    pick = *loser_pick.begin();
                    break;
                case 'Y':
                    pick = (char)(str[0] + 23);
                    sum += 3;
                    break;
                case 'Z':
                    pick = maps.at(str[0]);
                    sum += 6;
                    break;
            }

            sum += pick - 87;

            return sum;
        };

        auto result = std::accumulate(std::begin(input), std::end(input), 0, get_result);
        std::cout << "Score: " << result << std::endl;
    }
}