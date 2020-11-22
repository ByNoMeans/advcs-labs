#include <iostream>
#include <limits>
#include <fstream>
#include <cmath>
#include "slist.h"

void simpleSortTotal(slist& in) {
    for (int i=0; i<in.size(); i++)
        for (int j=i; j<in.size(); j++)
            if (in.get(i)->data->distance_au_ > in.get(j)->data->distance_au_)
                in.exchg(i, j);
}

int main() {
    std::ifstream infile;
    int i = 0;
    slist airports;

    infile.open("USAirportCodes.csv", std::ifstream::in);

    if (!infile.is_open() || infile.bad()) {
        std::cout << "Error opening file";
        std::exit(EXIT_FAILURE);
    }

    infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (infile.good()) {
        char code[5], temp[10];
        double latitude, longitude;
        infile.getline(code, 5, ',');
        infile.getline(temp, 10, ',');
        latitude = std::stod(temp);
        infile.getline(temp, 10, '\n');
        longitude = std::stod(temp);
        auto *airport = new Airport(code, latitude, longitude);
        if (airport->distance_au_ <= 100.0)
            airports.add(airport);
    }
    infile.close();

    simpleSortTotal(airports);
    const auto *last = airports.get(airports.size() - 1);
    std::cout << "The furthest Airport from AUS is " << last->data->code_ << "; " << last->data->distance_au_
              << " kilometers away.\n\n"
              << "All airports within 100 miles of AUS:\n";
    airports.toString();
}
