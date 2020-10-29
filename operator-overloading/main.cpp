#include <set>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class SalesRep {
public:
    char rep[50];
    char region[50];
};

class ItemCatalog {
    friend class SALESREC;
public:
    char item[50];
private:
    float unitCost;
};

class SALESREC: public SalesRep, public ItemCatalog {
    friend ostream& operator << (ostream&, const SALESREC&);
public:
    char date[10];
    int units;
    void setUnitCost(float in) {
        unitCost = in;
    }
    float getUnitCost() const {
        return unitCost;
    }
    float Total() const {
        return  static_cast<float>(units) * unitCost;
    }
    bool operator ==(const SALESREC& in) {
        return in.item == item && in.date == date && in.rep == rep;
    }
    void operator +(const SALESREC& in) {
        units += in.units;
    }
};

ostream &operator <<(ostream &out, const SALESREC& in) {
    return out << "Record: " << in.date << ", " << in.region << ", "
             << in.rep << ", " << in.item << ", " << in.units << ", "
             << in.getUnitCost() << ", " << in.Total() << '\n';
}

int main() {
    ifstream in;
    char cNum[10];
    SALESREC* salesArr[40];
    int salesArrayCount = 0;

    in.open ("SalesDataP5.csv");
    if (in.is_open()) {
        int c{};
        float inputUnitCost;
        while (in.good()) {
            salesArr[c] = new SALESREC();
            in.getline(salesArr[c]->date, 256, ',');
            in.getline(salesArr[c]->region, 256, ',');
            in.getline(salesArr[c]->rep, 256, ',');
            in.getline(salesArr[c]->item, 256, ',');
            in.getline(cNum, 256, ',');
            salesArr[c]->units = atoi(cNum);
            in.getline(cNum, 256, '\n');
            inputUnitCost = atof(cNum);
            salesArr[c]->setUnitCost(inputUnitCost);
            c++;
        }
        salesArrayCount = c-1;
        in.close();
    } else
        cout << "Error opening file";

    auto comp = [](SALESREC l, SALESREC r) {
        return l.Total() < r.Total();
    };

    set<SALESREC, decltype(comp)> uniqueRecs(comp);

    cout << " Unsorted Sales Record Array\n" ;
    for (int i{}; i < salesArrayCount; i++) cout << *salesArr[i];

    for (int i{}; i < salesArrayCount; ++i) {
        for (int j{}; j < salesArrayCount; ++j)
            if (salesArr[i] == salesArr[j] && i != j)
                *salesArr[i] + *salesArr[j];
        uniqueRecs.insert(*salesArr[i]);
    }

    SALESREC t[uniqueRecs.size()];
    copy(uniqueRecs.begin(), uniqueRecs.end(), t);
    SALESREC* s[uniqueRecs.size()];

    for (int i{}; i < uniqueRecs.size(); i++) s[i] = &t[i];
    cout << " - - - - - - - - - - - -\n" ;
    cout << " Sorted Sales Record Array\n";
    for (int i{}; i < uniqueRecs.size(); i++) cout << *s[i];
    for (int i{}; i < salesArrayCount; i++) delete salesArr[i];
}