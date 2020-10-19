#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Entry {
public:
    string date{}, rep{}, region{}, item{};
    int units{};
    double unitCost{};
    Entry(string& d, string& r, string& re,string& i, int& un, double& uc) {
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
        cout << "Record: " << date << ", " << region << ", " << rep << ", " << item << ", "  << units <<
             ", " << unitCost << ", " << total() << '\n';
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
    fstream in {"SalesDataDyn.csv"};
    string line{};
    auto** entries_p = new Entry*[30];
    int ind{};

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
        entries_p[ind++] = new Entry(date, region, rep, item, units, unitCost);
    }
    in.close();
    for (int i {}; i < 30; i++)
        for (int j {}; j < 30; j++)
            if (entries_p[i]->total() < entries_p[j]->total())
                swap(entries_p[i], entries_p[j]);
    cout << "Record: OrderDate, Region, Rep, Item, 0, 0, 0\n";
    for_each(entries_p, entries_p + 30, [](const auto& e) { e->print(); } );
    delete[] entries_p;
    return 0;
}
