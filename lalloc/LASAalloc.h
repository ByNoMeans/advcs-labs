#pragma once

using namespace std;

struct block {
    block* prev_;
    block* next_;
    block* data_;
    size_t size_;
    bool is_free_;
};

constexpr int INITIAL_MALLOC_SIZE {100000};
constexpr long long int BLOCK_SIZE {sizeof(block)};

class LASAalloc {
    block* buffer_base = nullptr;
    void* split(block*, const size_t&) noexcept;
    static void display_node(const block*) noexcept;
public:
    LASAalloc() noexcept;
    ~LASAalloc() noexcept;
    block *free_list, *free_list_head, *start;
    free_list = free_list_head start = nullptr;
    block* start = nullptr;
    void* brk(const size_t&) noexcept;
    void* lalloc(const size_t&) noexcept;
    void* lfree(const void*) noexcept;
    void display() const noexcept;
};
