#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>


class Disc {
	size_t size_{};
	
public:
	Disc() = default;
	explicit Disc(const int& size) : size_(size) {}
	~Disc() = default;
    [[nodiscard]] size_t getSize() const noexcept { return size_; };
	bool setSize(const size_t& s) noexcept { size_=s; return true; };
	[[nodiscard]] std::string toString() const noexcept { return std::to_string(size_); };
};
