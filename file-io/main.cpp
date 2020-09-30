#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

string skipCellsReturnNext(const string& in, const int& stop) {
    stringstream iss{in};
    string out{};
    for (int i{}; i < stop + 1; i++)
        getline(iss, out, ',');
    return out;
}

int main() {

    fstream in{"../WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv"};

    if (!in.is_open() || in.bad())
        exit(EXIT_FAILURE);

    const vector<string> developedCountryNames{"\"Japan\"", "\"EUROPE\"", "\"NORTHERN AMERICA\"", "\"Australia/New Zealand\""};
    vector<pair<string, double>> developedCountryData{};
    vector<pair<string, double>> allData{};
    string line{};
    bool isDeveloped{};
    bool isRegion{};

    for (int i{}; i < 29; i++) getline(in, line);

    while (getline(in, line)) {
        string countryName = skipCellsReturnNext(line, 2);
        double countryAge = stod(skipCellsReturnNext(line, 15));
        isRegion = all_of(countryName.begin(), countryName.end(), [](char c){ return std::isupper(c) || c == '"'; });
        if (isRegion) {
            isDeveloped = find(developedCountryNames.begin(), developedCountryNames.end(), countryName) != developedCountryNames.end()
                    || countryName == "\"United States of America\"";
            getline(in, line);
        }
        if (isDeveloped)
            developedCountryData.emplace_back(countryName, countryAge);
        allData.emplace_back(countryName, countryAge);
    }

    in.close();

    auto sortVP = [](
            const pair<string, double> &a,
            const pair<string, double> &b
    ) { return a.second > b.second; };

    sort(allData.begin(), allData.end(), sortVP);
    sort(developedCountryData.begin(), developedCountryData.end(), sortVP);

    for (int i = 0; i < allData.size(); i++)
        if (allData.at(i).first == "\"United States of America\"")
            printf("The US is rank #%d of all regions in life expectancy.\n", i+1);

    for (int i = 0; i < developedCountryData.size(); i++)
        if (developedCountryData.at(i).first == "\"United States of America\"")
            printf("The US is rank #%d of all developed regions in life expectancy.\n", i+1);

}
