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

auto sortVP = [](
        const pair<string, double> &a,
        const pair<string, double> &b
) { return a.second > b.second; };

void printUSPlace(const vector<pair<string, double>>& in, const string& developed="") {
    for (int i = 0; i < in.size(); i++)
        if (in.at(i).first == "United States of America")
            printf("The US is rank #%d of all %sregions in life expectancy.\n", i+1, developed.c_str());
}

int main() {

    fstream in{"../WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv"};

    if (!in.is_open() || in.bad())
        exit(EXIT_FAILURE);

    const vector<string> developedCountryNames{"Japan", "EUROPE", "NORTHERN AMERICA", "Australia/New Zealand"};
    vector<pair<string, double>> developedCountryData{};
    vector<pair<string, double>> allData{};
    string line{};
    bool isDevelopedRegion;
    bool isRegion;
    bool currentIsRegion;

    for (int i{}; i < 29; i++) getline(in, line);
    while (getline(in, line)) {
        string countryName = skipCellsReturnNext(line, 2);
        countryName = countryName.substr(1, countryName.size() - 2);
        double countryAge = stod(skipCellsReturnNext(line, 15));
        isRegion = all_of(countryName.begin(), countryName.end(), [](char c){ return std::isupper(c) || c == ' ';});
        if (isRegion) {
            currentIsRegion = true;
            isDevelopedRegion = find(developedCountryNames.begin(), developedCountryNames.end(), countryName) !=
                                developedCountryNames.end()
                                || countryName == "United States of America"
                                || countryName == "Australia/New Zealand";
        }
        if (!currentIsRegion && countryName.find("Europe") == string::npos) {
            if (isDevelopedRegion)
                developedCountryData.emplace_back(countryName, countryAge);
            allData.emplace_back(countryName, countryAge);
        } else
            currentIsRegion = false;
    }

    in.close();

    sort(allData.begin(), allData.end(), sortVP);
    sort(developedCountryData.begin(), developedCountryData.end(), sortVP);

    printUSPlace(allData);
    printUSPlace(developedCountryData, "developed ");

}
