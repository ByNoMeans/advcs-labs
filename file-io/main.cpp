#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main() {

    std::fstream in { "WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv" };
    std::string line;
    constexpr int skip = 17;

    if (!in.is_open())
        std::exit(EXIT_FAILURE);

    for (int i = 0; i < skip; i++)
        std::getline(in, line);

    while (std::getline(in, line)) {

        std::stringstream iss { line };
        std::string each;

        while (std::getline(iss, each, ','))
            std::cout << each << " ";
        std::cout << std::endl;
    }
}