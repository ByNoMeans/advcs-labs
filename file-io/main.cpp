#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

void skipCells(stringstream &in, string &filler, const int &count) {
    for (int i{}; i < count; i++)
        getline(in, filler, ',');
}

bool sortVPData = [](
        const pair<string, double> &a,
        const pair<string, double> &b
        ) { return a.second > b.second; };

int main() {

    fstream in{"WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv"};

    if (!in.is_open())
        exit(EXIT_FAILURE);

    // NOTICE: start on line 28, excluding development, income, world; could be source of misalignments
    // Debug with debugger/printing out
    // Also make sure getting right columns
    constexpr int skip = 28;
    constexpr int countryAgeIndex = 14;
    constexpr int countryNameIndex = 3;
    const vector developedCountryNames{"EUROPE", "NORTHERN AMERICA", "Japan", "Australia/New Zealand",
                                       "United States of America"};

    vector<pair<string, double>> developedCountryData{};
    vector<pair<string, double>> countryData{};
    string line{};

    for (int i = 0; i < skip; i++)
        getline(in, line);

    while (getline(in, line)) {
        stringstream iss{line};
        string countryName{};
        double countryAge{};

        skipCells(iss, line, countryNameIndex - 1);
        getline(iss, line, ',');
        countryName = line.substr(1, line.length() - 2);


        skipCells(iss, line, countryAgeIndex - 1);
        getline(iss, line, ',');
        countryAge = stod(line);

        if (find(developedCountryNames.begin(), developedCountryNames.end(), countryName) !=
            developedCountryNames.end())
            developedCountryData.emplace_back(countryName, countryAge);
        countryData.emplace_back(countryName, countryAge);

        iss.str(string());
    }
    in.close();

    sort(countryData.begin(), countryData.end(), sortVPData);
    sort(developedCountryData.begin(), developedCountryData.end(), sortVPData);

    for (int i = 0; i < countryData.size(); i++)
        if (countryData.at(i).first == "United States of America")
            cout << "The U.S. Ranks " << i + 1 << "th in life expectancy overall."
                 << countryData.at(i).second << "\n";

    for (int i = 0; i < developedCountryData.size(); i++)
        if (developedCountryData.at(i).first == "United States of America")
            cout << "The U.S. Ranks " << i + 1 << "th in life expectancy with respect to developed countries." << "\n";
}
