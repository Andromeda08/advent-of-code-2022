#pragma once

#include <Common.hpp>
#include <numeric>

namespace Day1
{
    void part_1()
    {
        auto input = Common::read_input("input_day1.txt");
        int current = 0, result = 0;

        auto it = std::begin(input);
        while (it != std::end(input))
        {
            if (it->empty())
            {
                if (current >= result) result = current;
                current = 0;
            }
            else
            {
                current += std::stoi(*it);
            }

            it++;
        }

        std::cout << "The top consumer: " << std::to_string(result) << std::endl;
    }

    void part_2()
    {
        auto input = Common::read_input("input_day1.txt");

        std::vector<int> calories;
        int current = 0;

        auto it = std::begin(input);
        while (it != std::end(input))
        {
            if (it->empty())
            {
                calories.push_back(current);
                current = 0;
            }
            else
            {
                current += std::stoi(*it);
            }

            it++;
        }

        std::sort(std::begin(calories), std::end(calories), std::greater());

        std::cout << "Sum of top 3: " << std::accumulate(std::begin(calories), std::begin(calories) + 3, 0) << std::endl;
    }
}