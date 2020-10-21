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
public:
    char date[10];
    int units;

    void setUnitCost(float newUnitCost) {
        unitCost = newUnitCost;
    }

    float getUnitCost() {
        return unitCost;
    }

    float Total() {
        return static_cast<float>(units) * unitCost;
    }

    void displayRec() {
        cout << "Record: " << date << ", " << region << ", " << rep << ", " << item << ", " << units << ", " << unitCost
             << ", " << Total() << endl;
    }
};

void simpleSortTotal(SALESREC* s[], int c);

int main() {
    ifstream infile;
    char cNum[10];
    SALESREC* salesArr[40];
    int salesArrayCount;
    SALESREC* s[30];

    infile.open("SalesDataP3.csv");
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
            salesArr[c]->setUnitCost(inputUnitCost); //store in salesArr[c]
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

    cout << " Unsorted Sales Record Array\n";
    for (int i{}; i < salesArrayCount; i++)
        salesArr[i]->displayRec();

    simpleSortTotal(s, salesArrayCount);

    printf("%s\n", " - - - - - - - - - - - -");
    printf("%s\n", " Sorted Sales Record Array");

    for (int i{}; i < salesArrayCount; i++)
        s[i]->displayRec();

    for (int i{}; i < salesArrayCount; i++)
        delete salesArr[i];
}

void simpleSortTotal(SALESREC* s[], int c) {
    for (int i{}; i < c; i++)
        for (int j{}; j < c; j++)
            if (s[i]->Total() > s[j]->Total())
              swap(s[i], s[j]);
}
