#pragma once

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>

struct Airport {
    char code_[5];
    double longitude_;
    double latitude_;
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
    bool equals(const slist&) const;
    Node* get(const int&) const;
    void insert(Airport&, const int&);
    void exchg(const int&, const int&);
    void swap(const int&, const int&);
    bool isEmpty() const;
    void remove(const int&);
    void set(const int&, Airport&);
    int size() const;
    slist subList(const int&, const int&) const;
    std::string toString() const;
};
