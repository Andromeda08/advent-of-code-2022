#pragma once

#include <chrono>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace Common
{
    static std::vector<std::string> read_input(const std::string& input_file)
    {
        std::vector<std::string> result;
        std::ifstream file(input_file);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                result.push_back(line);
            }

            file.close();

            return result;
        }

        throw std::runtime_error("Failed to open \" " + input_file + "\"!");
    }

    template <typename L>
    static void execute(const L func)
    {
        auto start = std::chrono::high_resolution_clock::now();
        func();
        auto stop = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms" << std::endl;
    }

}