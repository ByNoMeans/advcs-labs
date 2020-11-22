#pragma once

#include <cassert>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>

static double deg2rad(double deg) { return deg * M_PI / 180; }

struct Airport {
    char code_[5];
    double longitude_;
    double latitude_;
    double distance_au_;
    Airport() : code_{0}, latitude_{0.0}, longitude_{0.0}, distance_au_{0.0} {}
    Airport(const char* code, const double& lat, const double& lon) : code_{5}, latitude_(lat), longitude_(lon) {
        std::strcpy(code_, code);
        distance_au_ = {distanceKm() / 1.609};
    }
    void print() const noexcept {
        std::cout << "{" << code_ <<  ": (" <<
               std::to_string(longitude_) << ", " <<
               std::to_string(latitude_) << ") distance_au: " <<
               std::to_string(distance_au_) << "}\n";
    }
    [[nodiscard]] double distanceKm() const noexcept {
        double lat1r, lon1r, lat2r, lon2r, u, v;
        lat1r = deg2rad(latitude_);
        lon1r = deg2rad(longitude_);
        lat2r = deg2rad(30.1944);
        lon2r = deg2rad(97.6700);
        u = sin((lat2r - lat1r)/2);
        v = sin((lon2r - lon1r)/2);
        return 2.0 * 6371.0 * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
    }
};

struct Node {
    Airport* data;
    Node* next;
    void print() const { data->print(); }
};

class slist {
private:
    Node* head_, * tail_;
    int length;
public:
    slist();
    ~slist();
    void add(Airport*) noexcept;
    void clear() noexcept;
    [[nodiscard]] bool equals(const slist&) const noexcept;
    [[nodiscard]] Node* get(const int&) const noexcept;
    void insert(Airport*, const int&) noexcept;
    void exchg(const int&, const int&) const noexcept;
    void swap(const int&, const int&) noexcept;
    [[nodiscard]] bool isEmpty() const noexcept { return length == 0; }
    void remove(const int&) noexcept;
    void set(const int&, Airport*) const noexcept;
    [[nodiscard]] int size() const noexcept;
    [[nodiscard]] slist* subList(const int&, const int&) const noexcept;
    void toString() const noexcept;
};
