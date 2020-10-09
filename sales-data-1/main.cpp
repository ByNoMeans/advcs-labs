#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

struct SALESREC {
    char     date[10];
    char     region[10];
    char     rep[10];
    char     item[10];
    int      units;
    float    unitCost;
    float    Total;
};

void simpleSortTotal(SALESREC* in[], int c);

int main() {
    ifstream infile;
    int i {};
    char cNum[10];
    SALESREC salesArr[40];
    int salesArrayCount {};
    SALESREC* s[40];

    infile.open("SalesData.txt", ifstream::in);
    if (infile.is_open()){
        int c {};
        while (infile.good()){
            infile.getline(salesArr[c].date, 256, ',');
            infile.getline(salesArr[c].region, 256, ',');
            infile.getline(salesArr[c].rep, 256, ',');
            infile.getline(salesArr[c].item, 256, ',');
            infile.getline(cNum, 256, ',');
            salesArr[c].units = atof(cNum);
            infile.getline(cNum, 256, ',');
            salesArr[c].unitCost = atof(cNum);
            i++;
            c++;
        }
        salesArrayCount = c - 1;
        infile.close();
    } else
        cout << "Error opening file";

    // Initialize the sort array pointers
    for (int x {}; x < salesArrayCount; x++)
        s[x] = &salesArr[x];

    simpleSortTotal(s, salesArrayCount);

    for (int z {}; z < salesArrayCount; z++)
        cout << "Record: " << s[z]->date <<", " << s[z]->region << ", " << s[z]->rep << ", " << s[z]->item << ", " << s[z]->units << ", " << s[z]->unitCost << ", " << s[z]->Total << "\n";

}

// arguments will be an array of pointers and a count
void simpleSortTotal(SALESREC* in[], int c) {
    for (int i {}; i < c; i++)
        for (int j {}; j < c; j++)
            if (in[i]->Total < in[j]->Total)
                std::swap(in[i], in[j]);
}
