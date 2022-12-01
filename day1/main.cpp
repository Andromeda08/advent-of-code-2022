#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

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

namespace Day1
{
    void part_1()
    {
        auto input = read_input("input.txt");
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
        auto input = read_input("input.txt");

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

int main()
{
    execute([](){ Day1::part_1(); });
    execute([](){ Day1::part_2(); });

    return 0;
}
