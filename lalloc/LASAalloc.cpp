#include<iostream>
#include <cstdlib>
#include "LASAalloc.h"

#define INITIAL_MALLOC_SIZE 100000
#define MAX_MALLOC_SIZE 100000

block* free_head_b;

unsigned char buffer[MAX_MALLOC_SIZE];

LASAalloc::LASAalloc() {
    brk(INITIAL_MALLOC_SIZE);

    free_head_b = (block*)buffer_base;
    free_list_b = free_head_b;

    free_head_b->size_ = (int)(buffer_size_t - sizeof(block));
    free_head_b->prev_ = nullptr;
    free_head_b->next_ = nullptr;
    free_head_b->allocated_ = (void*)((long long int)buffer_base + (long long int)sizeof(block));

    std::cout << "Constructing:\n"
              << "\tbuffer space allocated: " << buffer_base << " - " << brk(0) << '\n'
              << "\tfree head location: " << free_list_b << " - " << brk(0) << '\n'
              << "\tblock head size: " << sizeof(block) << '\n';

    display_node(free_list_b);
}

void* LASAalloc::lalloc(size_t to_alloc) {
    block* head_b = free_head_b;
    while (head_b) {
        if (to_alloc > head_b->size_) {
            head_b = head_b->next_;
            if (!head_b)
                return nullptr;
            continue;
        }
        if (to_alloc + 32 >= head_b->size_) {
            head_b->size_ = to_alloc;
            if (!head_b->next_ && !head_b->prev_)
                free_head_b = nullptr;
            else if (!head_b->next_ && head_b->prev_) {
                head_b->prev_->next_ = nullptr;
                head_b->prev_ = nullptr;
            } else if (head_b->next_ && !head_b->prev_) {
                head_b->next_->prev_ = nullptr;
                free_head_b = head_b->next_;
                head_b->next_ = nullptr;
            } else {
                head_b->next_->prev_ = head_b->prev_;
                head_b->prev_->next_ = head_b->next_;
                head_b->prev_ = nullptr;
                head_b->next_ = nullptr;
            }
            return head_b;
        } else {
            block* new_head_b = head_b + 32 + to_alloc;
            new_head_b->size_ = head_b->size_ - 32 - to_alloc;
            if (!head_b->next_ && !head_b->prev_) {
                new_head_b->next_ = nullptr;
                new_head_b->prev_ = nullptr;
                free_head_b = new_head_b;
            } else if (head_b->next_ && !head_b->prev_) {
                new_head_b->next_ = head_b->next_;
                new_head_b->prev_ = nullptr;
                free_head_b = new_head_b;
            } else if (!head_b->next_ && head_b->prev_ ) {
                new_head_b->next_ = nullptr;
                new_head_b->prev_ = head_b->prev_;
            } else {
                new_head_b->next_ = head_b->next_;
                new_head_b->prev_ = head_b->prev_;
            }
            return new_head_b;
        }
    }
    return nullptr;
}

LASAalloc::~LASAalloc() {

}

void* LASAalloc::lfree(void* in_b) {

}

void LASAalloc::display_node(block* in_b) {
    std::cout << "block: " << in_b->allocated_
              << "\n\tsize: " << in_b->size_
              << "\n\tnext: " << in_b->next_
              << "\n\tprev: " << in_b->prev_
              << "\n\tbuffer: " << in_b->allocated_
              << "\n";
}

void LASAalloc::printFreeList() {
    block* begin_b = free_head_b;
    if (!begin_b) {
        std::cout << "List is empty\n";
        return;
    }
    std::cout << "List is:\n";
    while(begin_b) {
        display_node(begin_b);
        begin_b = begin_b->next_;
    }
    std::cout << '\n';
}

void* LASAalloc::brk(size_t size) {
    if (size != 0) {
        if (!buffer_base) {
            buffer_base = malloc(size);
            buffer_size_t = size;
        } else {
            std::cout << "buffer already locked\n";
            return nullptr;
        }
    }
    return buffer_size_t + (char*) buffer_base;
}