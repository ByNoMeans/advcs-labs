#pragma once

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>

struct Airport {
    char code_[5];
    double longitude_;
    double latitude_;
    double distance_au_;
};

struct Node {
    Airport* data;
    Node* next;
};

class slist {
private:
    Node* head_, * tail_;
    int length;
public:
    slist();
    ~slist();
    void add(Airport&);
    void clear();
    [[nodiscard]] bool equals(const slist&) const;
    [[nodiscard]] Node* get(const int&) const;
    void insert(Airport&, const int&);
    void exchg(const int&, const int&);
    void swap(const int&, const int&);
    [[nodiscard]] bool isEmpty() const;
    void remove(const int&);
    void set(const int&, Airport&);
    [[nodiscard]] int size() const;
    [[nodiscard]] slist subList(const int&, const int&) const;
    [[nodiscard]] std::string toString() const;
};
