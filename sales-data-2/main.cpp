#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Entry {
public:
    string date{}, rep{}, region{}, item{};
    int units{};
    double unitCost{};
    Entry(const string& d, const string& r, const string& re, const string& i, const int& un, const double& uc) {
        date = d;
        region = r;
        rep = re;
        item = i;
        units = un;
        unitCost = uc;
    }
    double total() const {
        return units * unitCost;
    };
    void print() const {
        cout << date << ',' << region << ',' << rep << ',' << item << ',' << units <<
             ',' << unitCost << ',' << total() << '\n';
    }
};

string getValueAtIndex(const string& in, const int& index) {
    stringstream iss{in};
    string out{};
    for (int i{}; i < index + 1; i++)
        getline(iss, out, ',');
    return out;
}

int main() {
    fstream in {"SalesDataPt2.csv"};
    string line{};
    vector<Entry> entries{};

    if (!in.is_open() || in.bad())
        exit(EXIT_FAILURE);

    getline(in, line);

    while (getline(in, line)) {
        string date = getValueAtIndex(line, 0);
        string region = getValueAtIndex(line, 1).erase(0, 1);
        string rep = getValueAtIndex(line, 2).erase(0, 1);
        string item = getValueAtIndex(line, 3).erase(0, 1);
        int units = stoi(getValueAtIndex(line, 4));
        double unitCost = stod(getValueAtIndex(line, 5));
        Entry entry {date, region, rep, item, units, unitCost};
        entries.push_back(entry);
    }
    in.close();
    std::stable_sort(entries.begin(), entries.end(), [](
            const auto& a, const auto& b) {
                return a.total() > b.total();
            }
    );
    cout << "OrderDate,Region,Rep,Item,Units,UnitCost,Total\n";
    for (const auto& e : entries) e.print();
}