#pragma once
#include <vector>
#include "disc.h"

class Stack {
	std::vector<Disc*> stack_;

	public:
		Stack() = default;
        ~Stack() noexcept { while(!stack_.empty()) stack_.pop_back(); };
		void push(Disc* in) noexcept { stack_.push_back(in); };
        Disc* pop() noexcept;
        [[nodiscard]] Disc* top() const noexcept { return stack_.empty() ? nullptr : stack_.back(); };
		[[nodiscard]] bool empty() const noexcept { return stack_.empty(); };
		void display() const noexcept;
};
