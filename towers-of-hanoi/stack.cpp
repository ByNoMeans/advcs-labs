#include <algorithm>
#include <iostream>
#include <stack.h>

Disc* Stack::pop() noexcept {
    if (!stack_.empty()) {
        int data = stack_.back()->getSize();
        stack_.erase(stack_.end() - 1);
        return new Disc(data);
    }
    return nullptr;
}

void Stack::display() const noexcept {
    std::cout << "[";
	for(int i= static_cast<int>(stack_.size()) - 1; i > -1; i--) {
        std::cout << stack_.at(i)->toString();
        if (i) std::cout << ", ";
    }
	std::cout<<"]";
}
