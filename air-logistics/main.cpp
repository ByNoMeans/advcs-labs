/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */


#include <iostream>
#include <fstream>
#include <cmath>
#include "slist.h"

constexpr double earthRadiusMi = 3'958.8;


double deg2rad(double deg) {
    return (deg * M_PI / 180);
}

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusMi * asin(sqrt(pow(u, 2) + cos(lat1r) * cos(lat2r) * pow(v, 2)));
}

void simpleSortTotal(slist& in) {
    for (int i=0; i<in.size(); i++)
        for (int j=i; j<in.size(); j++)
            if (in.get(i)->data->distance_au_ > in.get(j)->data->distance_au_)
                in.swap(i, j);
}

int main() {
    std::ifstream infile;
    int i=0;
    char cNum[10];
    slist airports;
    constexpr double AUS_LAT = 30.1944;
    constexpr double AUS_LON = 97.6700;

    infile.open ("./USAirportCodes.csv", std::ifstream::in);
    if (infile.is_open()) {
        int c=0;
        std::string u;
        std::getline(infile,u);
        while (infile.good()) {
            auto* airport = new Airport();
            infile.getline(airport->code_, 256, ',');
            infile.getline(cNum, 256, ',');
            airport->longitude_ = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airport->latitude_ = atof(cNum);
            airport->distance_au_ = distanceEarth(AUS_LAT, AUS_LON, airport->latitude_, airport->longitude_);
            if (airport->distance_au_ <= static_cast<double>(100))
                airports.add(*airport);
            std::cout << airports.toString();
            i++;
            c++;
        }
        infile.close();
        simpleSortTotal(airports);
        std::cout << airports.toString();
    } else {
        std::cout << "Error opening file";
        std::exit(EXIT_FAILURE);
    }
}
