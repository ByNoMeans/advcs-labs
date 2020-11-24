#include <iostream>
#include <limits>
#include <fstream>
#include <cmath>
#include "slist.h"

void simpleSortTotal(const slist* in) {
    for (int i=0; i<in->size(); i++)
        for (int j=i; j<in->size(); j++)
            if (in->get(i)->data->distance_au_ > in->get(j)->data->distance_au_)
                in->exchg(i, j);
}

int main() {
    std::ifstream infile;
    int i = 0;
    auto* airports = new slist();

    infile.open("USAirportCodes.csv", std::ifstream::in);

    if (!infile.is_open() || infile.bad()) {
        std::cout << "Error opening file";
        std::exit(EXIT_FAILURE);
    }

    infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Airport* furthest;

    while (infile.good()) {
        char code[5], temp[10];
        double latitude, longitude;
        infile.getline(code, 5, ',');
        infile.getline(temp, 10, ',');
        latitude = std::stod(temp);
        infile.getline(temp, 10, '\n');
        longitude = std::stod(temp);
        auto *airport = new Airport(code, latitude, longitude);
        furthest = airport->distance_au_ > furthest->distance_au_ ? airport : furthest;
        if (airport->distance_au_ <= 100.0)
            airports->add(airport);
    }
    infile.close();

    simpleSortTotal(airports);
    std::cout << "The furthest Airport from AUS is " << furthest->code_ << "; " << furthest->distance_au_
              << " miles away.\n\n"
              << "All airports within 100 miles of AUS:\n";
    airports->toString();
    delete airports;
}
