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

using namespace std;

void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main() {
    ifstream infile;
    int i=0;
    char cNum[10];
    slist airports;
    int airportCount;
    constexpr double AUS_LAT = 30.1944;
    constexpr double AUS_LON = 97.6700;

    infile.open ("./USAirportCodes.csv", ifstream::in);
    if (infile.is_open()) {
        int c=0; std::string u;
        std::getline(infile,u);
        while (infile.good()) {
            auto* airport = new Airport();
            infile.getline(airport->code_, 256, ',');
            infile.getline(cNum, 256, ',');
            airport->longitude_ = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airport->latitude_ = atof(cNum);
            if (distanceEarth(AUS_LAT, AUS_LON, airport->latitude_, airport->longitude_) <= static_cast<double>(100))
                airports.add(*airport);
            i++;
            c++;
        }
        airportCount = c-1;
        infile.close();

        cout << airports.toString();

//        for (int c=0; c < airportCount; c++) {
//            if (c % 1000 != 0) {
//                cout << airportArr[c]->code_ << " long: " << airportArr[c]->longitude_ << " lat: "
//                     << airportArr[c]->latitude_ << endl;
//                cout << airportArr[c + 1]->code_ << " long: " << airportArr[c + 1]->longitude_ << " lat: "
//                     << airportArr[c + 1]->latitude_ << endl;
//                cout << "Distance between " << airportArr[c]->code_ << " and " << airportArr[c + 1]->code_ << " is "
//                     << distanceEarth(airportArr[c]->longitude_, airportArr[c]->latitude_,
//                                      airportArr[c + 1]->longitude_, airportArr[c + 1]->latitude_) << endl;
//            }
//        }
    } else {
        cout << "Error opening file";
        std::exit(EXIT_FAILURE);
    }
}

double deg2rad(double deg) {
    return (deg * M_PI / 180);
}

double rad2deg(double rad) {
    return (rad * 180 / M_PI);
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

/*
	Provide sort routine on linked list
*/

// HOW? The distance is not a mf property of each node

void simpleSortTotal(slist& in) {
    for (int i=0; i<in.size(); i++)
        for (int j=i; j<in.size(); j++)
            if (in->Total() > s[j]->Total())
                swap(s[i], s[j]);
}

