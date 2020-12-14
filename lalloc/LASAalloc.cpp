#include <cstdlib>
#include <iostream>

#include "LASAalloc.h"

void* LASAalloc::brk(const size_t& size) noexcept {
    if (size) {
        if (!buffer_base)
            buffer_base = (block*)malloc(size);
        else
            std::cout << "buffer already locked\n";
    }
    return nullptr;
}

LASAalloc::LASAalloc() noexcept {
    brk(INITIAL_MALLOC_SIZE);

    auto* first_b = buffer_base;
    free_list_head = start = first_b;

    first_b->next_ = first_b->prev_ = nullptr;
    first_b->size_ = INITIAL_MALLOC_SIZE;
    first_b->data_ = (block*)((long long int)buffer_base + BLOCK_SIZE);
    first_b->is_free_ = true;

    // Show initial statistics
    std::cout << "Allocated buffer: " << buffer_base << " - " << brk(0) << '\n'
              << "Free list: " << free_list_head << " - " << brk(0) << '\n'
              << "Block size: " << BLOCK_SIZE << '\n'
              << "Size of integer: " << sizeof(int) << '\n';

    display_node(free_list_head);
}

LASAalloc::~LASAalloc() noexcept {
    free(buffer_base);
    free_list = free_list_head = start = nullptr;
}

void LASAalloc::display_node(const block* in_b) noexcept {
    std::cout << "Prev: " << in_b->prev_ << "\tNext: " << in_b->next_
              << "\tFree: " << in_b->is_free_ << "\tSize: " << in_b->size_
              << "\tThis: " << in_b->data_ << '\n'
              << '\n';
}

void LASAalloc::display() const noexcept {
    block* curr_b = start;
    if (!curr_b){
        std::cout<<"List is empty\n";
        return;
    }
    std::cout<<"List is :\n";
    while (curr_b){
        display_node(curr_b);
        curr_b = curr_b->next_;
    }
    std::cout << "\n";
}

void* LASAalloc::lalloc(const size_t& size) noexcept {
    if (size + BLOCK_SIZE <= free_list_head->size_){
        split(free_list_head, size);
        free_list = (block*)((long long int)free_list + BLOCK_SIZE);
        return free_list;
    } else if (size + BLOCK_SIZE > free_list_head->size_){
        if (!free_list_head->next_)
            return nullptr;
        else {
            block* curr_b = free_list_head;
            while (curr_b){
                if (curr_b->size_ > size + BLOCK_SIZE && curr_b->is_free_){
                    split(curr_b, size);
                    free_list = (block*)((long long int)free_list + BLOCK_SIZE);
                    return free_list;
                } else
                    curr_b = curr_b->next_;
            }
        }
    }
    return nullptr;
}

void* LASAalloc::lfree(const void* in_b) noexcept {

    auto* to_free_b = (block*)((long long int)in_b - BLOCK_SIZE);
    block* to_free_next = to_free_b->next_;
    block* to_free_prev = to_free_b->prev_;
    size_t to_free_t = to_free_b->size_;

    to_free_b->next_ = to_free_next;
    to_free_b->prev_ = to_free_prev;
    to_free_b->size_ = to_free_t;
    to_free_b->is_free_ = true;
    to_free_b->data_ = (block*)(BLOCK_SIZE + (long long int)(block*)in_b);

    block* curr_b = start;
    block* curr_b_next = curr_b->next_;
    while (curr_b_next){
        if (curr_b->is_free_ && curr_b_next->is_free_) {
            curr_b->size_ = BLOCK_SIZE + curr_b->size_ + curr_b_next->size_;
            curr_b->next_ = curr_b_next->next_;
            curr_b_next = curr_b->next_;
        } else {
            curr_b = curr_b_next;
            curr_b_next = curr_b_next->next_;
        }
    }

    curr_b = start;
    while (curr_b){
        if (curr_b->is_free_){
            free_list_head = curr_b;
            break;
        }
        curr_b = curr_b->next_;
    }

    return nullptr;
}

void* LASAalloc::split(block* to_split_b, const size_t& size) noexcept {
    auto* to_free_b = (block*)((long long int)to_split_b + size + BLOCK_SIZE);
    block* to_return_b = to_split_b;
    size_t to_split_t = to_split_b->size_;

    if (to_split_t != INITIAL_MALLOC_SIZE) to_split_t += BLOCK_SIZE;

    block* to_split_next = to_split_b->next_;
    block* to_split_prev = to_split_b->prev_;

    to_return_b->next_ = to_free_b;
    to_return_b->prev_ = to_split_prev;
    to_return_b->size_ = size;
    to_return_b->is_free_ = false;
    to_return_b->data_ = (block*)((long long int)to_return_b + BLOCK_SIZE);
    free_list = to_return_b;

    to_free_b->next_ = to_split_next;
    to_free_b->prev_ = to_return_b;

    free_list_head = to_free_b;

    to_free_b->size_ = to_split_t - size - 2 * BLOCK_SIZE;
    to_free_b->is_free_ = true;
    to_free_b->data_ = (block*)((long long int)to_free_b + BLOCK_SIZE);

    return to_return_b;
}