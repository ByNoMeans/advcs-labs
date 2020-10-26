#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class SalesRep {
public:
    char rep[30];        // A character array for ‘rep’ last name.
    char region[30];        // A character array for the rep’s ‘region’
};

class ItemCatalog {
    friend class SALESREC;
public:
    char item[20];    // character array for ‘item’ name.
private:
    float unitCost;    // a real number for ‘unitCost’.
};

class SALESREC : public SalesRep, public ItemCatalog {
    friend ostream& operator<<(ostream& out, const SALESREC& in);
public:
    char date[10];
    int units;

    void setUnitCost(float newUnitCost) {
        unitCost = newUnitCost;
    }

    float getUnitCost() const {
        return unitCost;
    }

    float Total() const {
        return static_cast<float>(units) * unitCost;
    }

    void operator+(const SALESREC& in) {
        units += in.units;
    }

    bool operator==(const SALESREC& in) {
        return rep == in.rep &&
                date == in.date &&
                item == in.item;
    }

};

ostream& operator<<(ostream& out, const SALESREC& in) {
    return out << "Record: " << in.date << ", " << in.region << ", "
               << in.rep << ", " << in.item << ", " << in.units << ", "
               << in.getUnitCost() << ", " << in.Total() << endl;
}

void simpleSortTotal(SALESREC* s[], int c);
int main() {
    ifstream infile;
    char cNum[10];
    SALESREC* salesArr[40];
    int salesArrayCount;
    SALESREC* s[40];

    infile.open("SalesDataP5.csv");
    if (infile.is_open()) {
        int c = 0;
        float inputUnitCost;
        while (infile.good()) {
            salesArr[c] = new SALESREC();
            infile.getline(salesArr[c]->date, 256, ',');
            infile.getline(salesArr[c]->region, 256, ',');
            infile.getline(salesArr[c]->rep, 256, ',');
            infile.getline(salesArr[c]->item, 256, ',');
            infile.getline(cNum, 256, ',');
            salesArr[c]->units = atoi(cNum);
            infile.getline(cNum, 256, '\n');
            inputUnitCost = atof(cNum);
            salesArr[c]->setUnitCost(inputUnitCost);
            c++;
        }
        salesArrayCount = c - 1;
        infile.close();
    } else {
        printf("%s", "Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i{}; i < salesArrayCount; i++)
        s[i] = salesArr[i];

    cout << "Unsorted Sales Record Array\n";
    for (int i{}; i < salesArrayCount; i++)
        cout << *salesArr[i];

    simpleSortTotal(s, salesArrayCount);

    printf("%s\n", " - - - - - - - - - - - -");
    printf("%s\n", " Sorted Sales Record Array");

    for (int i{}; i < salesArrayCount; i++)
        cout << *s[i];

    for (int i{}; i < salesArrayCount; i++)
        delete salesArr[i];
}

void simpleSortTotal(SALESREC* s[], int c) {
    for (int i{}; i < c; i++)
        for (int j{}; j < c; j++)
            if (s[i]->Total() < s[j]->Total())
              swap(s[i], s[j]);
}
