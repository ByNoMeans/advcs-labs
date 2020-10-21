#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class SalesRep {
public:
    char* rep[];        // A character array for ‘rep’ last name.
    char* region[];        // A character array for the rep’s ‘region’
};

class ItemCatalog {
    ______ _____
    __________;
public:
    char ________;    // character array for ‘item’ name.
    _______
            ____
    ________;    // a real number for ‘unitCost’.

};

class SALESREC : public SalesRep, public ItemCatalog {
public:
    char date[10];
    int units;

    void setUnitCost(_____ _________) {
        __________
    }

    static float getUnitCost() {
        ______ _______
    }

    static float Total() {
        return ______
        ______ ________;
    }

    void displayRec() {
        cout << "Record: " << date << ", " << region << ", " << rep << ", " << item << ", " << units << ", " << unitCost
             << ", " << Total() << endl;
    }
};

void simpleSortTotal(SALESREC *s[], int c);

int main() {
    ifstream infile;
    int array[20];
    char cNum[10];
    SALESREC *salesArr[40];
    int salesArrayCount;
    SALESREC *s[40];

    infile.open("SalesDataP3.csv");
    if (infile.is_open()) {
        int c{};
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
            _________________________;  //store in salesArr[c]
            c++;
        }
        salesArrayCount = c - 1;
        infile.close();
    } else {
        cout << "Error opening file";
    }

    for (int i{}; i < salesArrayCount; i++)
        s[i] = salesArr[i];

    cout << " Unsorted Sales Record Array\n";
    for (int i{}; i < salesArrayCount; i++)
        salesArr[i]->displayRec();

    simpleSortTotal(s, salesArrayCount);

    cout << " - - - - - - - - - - - -\n";
    printf("%s\n", " Sorted Sales Record Array");

    for (int i = 0; i < salesArrayCount; i++)
        s[i]->displayRec();

    //clean up (remove from memory) allocated sales records
    for (int i{}; i < salesArrayCount; i++)
        ________ salesArr[i];

}


void simpleSortTotal(SALESREC *s[], int c) {
    SALESREC *temp;
    for (int i{}; i < c; i++)
        for (int j{}; j < c; j++)
            if (_______________) {
                ___________;
                ___________;
                ___________;
            }
}
